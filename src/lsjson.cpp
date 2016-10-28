
#include <QCoreApplication>
#include <QFile>
#include <QDebug>
// JSON
#include <QJsonObject>

// datablocks
#include "datablocks/lslinkedlist.h"
#include "datablocks/lslistItem.h"
#include "datablocks/lslistitem_string.h"
#include "datablocks/lslistitem_array.h"
#include "datablocks/lslistitem_hash.h"
#include "datablocks/lslistitem_object.h"
#include "datablocks/lslistitem_imemo.h"
#include "datablocks/lslistitem_data.h"
#include "datablocks/lslistitem_module.h"
#include "datablocks/lslistitem_iclass.h"
#include "datablocks/lslistitem_struct.h"
#include "datablocks/lslistitem_regexp.h"

#include "lsjson.h"

lsJSON::lsJSON(QObject *parent) : QObject(parent)
{

}

void lsJSON::parse( const QString &filename )
{
    // Stats
    cout << "Dump file : " << filename.toStdString() << endl;

    QString val;
    QFile file( filename );
    if(! file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        cout << "ERROR: opening file : " << filename.toStdString() << endl;
        return;
    }
    val = file.readAll();
    file.close();

    // Split dump file
    QStringList list;
    int count = 0;
    int top, tail;
    for( int i=0; i<val.size(); i++ )
    {
        if( val[i] == QLatin1Char('{'))
        {
            count++;
            if( count == 1 )
            {
                top = i;
            }
        }
        if( val[i] == QLatin1Char('}'))
        {
            count--;
            if( count == 0 )
            {
                tail = i;
                list.append( val.mid( top, (tail-top)+1 ) );
            }
        }
    }// for i

    // cycle through each JSON chunck and parse
    foreach( const QString& json, list )
    {
        // debug
        // qDebug() << json;

        QJsonParseError jerr;
        json_doc = QJsonDocument::fromJson( json.toUtf8(), &jerr );
        if( jerr.error != 0 )
        {
            // debug
            // cout << "ERROR :" << jerr.errorString().toStdString() << endl;
            continue;
        }

        // Check each object type
        QJsonObject jsonObject = json_doc.object();

        QString info;

        if( jsonObject["type"].toString().toUpper() == "STRING" )
        {
            // STRING

            lsListItem_String *item = new lsListItem_String();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                item->setMemsize( jsonObject["bytesize"].toDouble() );
                item->setValue( jsonObject["value"].toString().toStdString() );

                Add_String( item );
            }

        } else if( jsonObject["type"].toString().toUpper() == "ARRAY" )
        {
            // ARRAY
            // TODO: QString::number( jsonObject["length"].toDouble() );

            lsListItem_Array *item = new lsListItem_Array();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                item->setMemsize( jsonObject["memsize"].toDouble() );

                Add_Array( item );
            }

        } else if( jsonObject["type"].toString().toUpper() == "OBJECT" )
        {
            // OBJECT
            // TODO: info += QString::number( jsonObject["ivars"].toDouble() );

            // TODO: do OBJECTs have a memsize?
            lsListItem_Object *item = new lsListItem_Object();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                // item->setMemsize( jsonObject["memsize"].toDouble() );

                Add_Object( item );
            }

        } else if( jsonObject["type"].toString().toUpper() == "CLASS" )
        {
            // CLASS
            // Only holds a pointer to a class

        } else if( jsonObject["type"].toString().toUpper() == "IMEMO" )
        {
            // IMEMO

            lsListItem_Imemo *item = new lsListItem_Imemo();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                item->setMemsize( jsonObject["memsize"].toDouble() );

                Add_Imemo( item );
            }

        } else if( jsonObject["type"].toString().toUpper() == "DATA" )
        {
            //  "file":"/usr/lib/ruby/2.3.0/timeout.rb", "line":81, "method":"start", "generation":35, "memsize":1049656}
            // DATA
            // TODO: info += jsonObject["struct"].toString();

            lsListItem_Data *item = new lsListItem_Data();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                item->setMemsize( jsonObject["memsize"].toDouble() );

                Add_Data( item );
            }

        } else if( jsonObject["type"].toString().toUpper() == "HASH" )
        {
            // HASH

            lsListItem_Hash *item = new lsListItem_Hash();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                item->setMemsize( jsonObject["memsize"].toDouble() );

                Add_Hash( item );
            }

        } else if( jsonObject["type"].toString().toUpper() == "MODULE" )
        {
            // MODULE "type":"MODULE", "class":"0x10f0568", "name":"Zlib",
            // TODO: info += jsonObject["name"].toString();

            lsListItem_Module *item = new lsListItem_Module();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                item->setMemsize( jsonObject["memsize"].toDouble() );

                Add_Module( item );
            }

        }else if( jsonObject["type"].toString().toUpper() == "ICLASS" )
        {
            // ICLASS

            lsListItem_Iclass *item = new lsListItem_Iclass();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                item->setMemsize( jsonObject["memsize"].toDouble() );

                Add_Iclass( item );
            }

        } else if( jsonObject["type"].toString().toUpper() == "STRUCT" )
        {
            // STRUCT "type":"STRUCT", "class":"0x11210f0", "memsize":40,

            lsListItem_Struct *item = new lsListItem_Struct();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                item->setMemsize( jsonObject["memsize"].toDouble() );

                Add_Struct( item );
            }

        } else if( jsonObject["type"].toString().toUpper() == "REGEXP" )
        {
            // REGEXP

            lsListItem_Regexp *item = new lsListItem_Regexp();
            if( item )
            {
                item->setAddress( jsonObject["address"].toString().toStdString() );
                item->setMemsize( jsonObject["memsize"].toDouble() );

                Add_Regexp( item );
            }

        }

    }// foreach( const QString& json, list )

    // output stats
    // Strings
    cout << "Strings : " << m_Strings.getItem_count() << endl;
    // Arrays
    cout << "Arrays : " << m_Arrays.getItem_count() << endl;
    // Hashes
    cout << "Hashes : " << m_Hashes.getItem_count() << endl;
    // Objects
    cout << "Objects : " << m_objects.getItem_count() << endl;
    // Imemo
    cout << "Imemo : " << m_imemo.getItem_count() << endl;
    // Data
    cout << "Data : " << m_data.getItem_count() << endl;
    // Modules
    cout << "Modules : " << m_modules.getItem_count() << endl;
    // Iclass
    cout << "Iclass : " << m_iclass.getItem_count() << endl;
    // Struct
    cout << "Struct : " << m_struct.getItem_count() << endl;
    // Regexp
    cout << "Regexp : " << m_regexp.getItem_count() << endl;

}

void lsJSON::display()
{
    // Dump stats
    cout << endl;
    cout << "############ Stats" << endl;

    // Show matches

    cout << "SRRING" << endl;
    lsListItem_String *chk_item = (lsListItem_String*)m_Strings.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->MatchCount() > 0 )
        {
            // Show any mem increse
            chk_item->Show_MatchCount();
        }
        chk_item = (lsListItem_String*)chk_item->getNext_item();
    }

    cout << "ARRAY" << endl;
    lsListItem_Array *array_item = (lsListItem_Array*)m_Arrays.getItem_list();
    while( array_item )
    {
        // Check address
        if( array_item->MatchCount() > 0 )
        {
            // Show any mem increse
            array_item->Show_MatchCount();
        }
        array_item = (lsListItem_Array*)array_item->getNext_item();
    }

    cout << "HASH" << endl;
    lsListItem_Hash *hash_item = (lsListItem_Hash*)m_Hashes.getItem_list();
    while( hash_item )
    {
        // Check address
        if( hash_item->MatchCount() > 0 )
        {
            // Show any mem increse
            hash_item->Show_MatchCount();
        }
        hash_item = (lsListItem_Hash*)hash_item->getNext_item();
    }

    cout << "OBJECT" << endl;
    lsListItem_Object *object_item = (lsListItem_Object*)m_objects.getItem_list();
    while( object_item )
    {
        // Check address
        if( object_item->MatchCount() > 0 )
        {
            // Show any mem increse
            object_item->Show_MatchCount();
        }
        object_item = (lsListItem_Object*)object_item->getNext_item();
    }

    cout << "IMEMO" << endl;
    lsListItem_Imemo *imemo_item = (lsListItem_Imemo*)m_imemo.getItem_list();
    while( imemo_item )
    {
        // Check address
        if( imemo_item->MatchCount() > 0 )
        {
            // Show any mem increse
            imemo_item->Show_MatchCount();
        }
        imemo_item = (lsListItem_Imemo*)imemo_item->getNext_item();
    }

    cout << "DATA" << endl;
    lsListItem_Data *data_item = (lsListItem_Data*)m_data.getItem_list();
    while( data_item )
    {
        // Check address
        if( data_item->MatchCount() > 0 )
        {
            // Show any mem increse
            data_item->Show_MatchCount();
        }
        data_item = (lsListItem_Data*)data_item->getNext_item();
    }

    cout << "MODULE" << endl;
    lsListItem_Module *module_item = (lsListItem_Module*)m_modules.getItem_list();
    while( module_item )
    {
        // Check address
        if( module_item->MatchCount() > 0 )
        {
            // Show any mem increse
            module_item->Show_MatchCount();
        }
        module_item = (lsListItem_Module*)module_item->getNext_item();
    }

    cout << "ICLASS" << endl;
    lsListItem_Iclass *iclass_item = (lsListItem_Iclass*)m_iclass.getItem_list();
    while( iclass_item )
    {
        // Check address
        if( iclass_item->MatchCount() > 0 )
        {
            // Show any mem increse
            iclass_item->Show_MatchCount();
        }
        iclass_item = (lsListItem_Iclass*)iclass_item->getNext_item();
    }

    cout << "STRUCT" << endl;
    lsListItem_Struct *struct_item = (lsListItem_Struct*)m_struct.getItem_list();
    while( struct_item )
    {
        // Check address
        if( struct_item->MatchCount() > 0 )
        {
            // Show any mem increse
            struct_item->Show_MatchCount();
        }
        struct_item = (lsListItem_Struct*)struct_item->getNext_item();
    }

    cout << "REGEXP" << endl;
    lsListItem_Regexp *regexp_item = (lsListItem_Regexp*)m_regexp.getItem_list();
    while( regexp_item )
    {
        // Check address
        if( regexp_item->MatchCount() > 0 )
        {
            // Show any mem increse
            regexp_item->Show_MatchCount();
        }
        regexp_item = (lsListItem_Regexp*)regexp_item->getNext_item();
    }

}

// ##########################
// Add items, checking for matches

void lsJSON::Add_String( lsListItem_String *item )
{
    // Look for matches
    lsListItem_String *chk_item = (lsListItem_String*)m_Strings.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_String*)chk_item->getNext_item();
    }

    // No match found
    m_Strings.Add_item( item );
}

void lsJSON::Add_Array( lsListItem_Array *item )
{
    // Look for matches
    lsListItem_Array *chk_item = (lsListItem_Array*)m_Arrays.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_Array*)chk_item->getNext_item();
    }

    // No match found
    m_Arrays.Add_item( item );
}

void lsJSON::Add_Hash(lsListItem_Hash *item)
{
    // Look for matches
    lsListItem_Hash *chk_item = (lsListItem_Hash*)m_Hashes.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_Hash*)chk_item->getNext_item();
    }

    // No match found
    m_Hashes.Add_item( item );
}

void lsJSON::Add_Object(lsListItem_Object *item)
{
    // Look for matches
    lsListItem_Object *chk_item = (lsListItem_Object*)m_objects.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_Object*)chk_item->getNext_item();
    }

    // No match found
    m_objects.Add_item( item );
}

void lsJSON::Add_Imemo(lsListItem_Imemo *item)
{
    // Look for matches
    lsListItem_Imemo *chk_item = (lsListItem_Imemo*)m_imemo.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_Imemo*)chk_item->getNext_item();
    }

    // No match found
    m_imemo.Add_item( item );
}

void lsJSON::Add_Data(lsListItem_Data *item)
{
    // Look for matches
    lsListItem_Data *chk_item = (lsListItem_Data*)m_data.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_Data*)chk_item->getNext_item();
    }

    // No match found
    m_data.Add_item( item );
}

void lsJSON::Add_Module(lsListItem_Module *item)
{
    // Look for matches
    lsListItem_Module *chk_item = (lsListItem_Module*)m_modules.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_Module*)chk_item->getNext_item();
    }

    // No match found
    m_modules.Add_item( item );
}

void lsJSON::Add_Iclass(lsListItem_Iclass *item)
{
    // Look for matches
    lsListItem_Iclass *chk_item = (lsListItem_Iclass*)m_iclass.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_Iclass*)chk_item->getNext_item();
    }

    // No match found
    m_iclass.Add_item( item );
}

void lsJSON::Add_Struct(lsListItem_Struct *item)
{
    // Look for matches
    lsListItem_Struct *chk_item = (lsListItem_Struct*)m_struct.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_Struct*)chk_item->getNext_item();
    }

    // No match found
    m_struct.Add_item( item );
}

void lsJSON::Add_Regexp(lsListItem_Regexp *item)
{
    // Look for matches
    lsListItem_Regexp *chk_item = (lsListItem_Regexp*)m_regexp.getItem_list();
    while( chk_item )
    {
        // Check address
        if( chk_item->Address() == item->Address() )
        {
            // Add item to chk_item
            chk_item->Add_Match( item );
            return;
        }
        chk_item = (lsListItem_Regexp*)chk_item->getNext_item();
    }

    // No match found
    m_regexp.Add_item( item );
}
