#ifndef LSJSON_H
#define LSJSON_H

#include <iostream>

#include <QJsonDocument>
#include <QObject>

// datablocks
#include "datablocks/lslinkedlist.h"

class lsListItem_String;
class lsListItem_Array;
class lsListItem_Hash;
class lsListItem_Object;
class lsListItem_Imemo;
class lsListItem_Data;
class lsListItem_Module;
class lsListItem_Iclass;
class lsListItem_Struct;
class lsListItem_Regexp;


using namespace std;

class lsJSON : public QObject
{
    Q_OBJECT
public:
    explicit lsJSON(QObject *parent = 0);

    void parse( const QString& filename );
    void display();

    // Only interested in memory groth
    void Add_String( lsListItem_String *item );
    void Add_Array( lsListItem_Array *item );
    void Add_Hash( lsListItem_Hash *item );
    void Add_Object( lsListItem_Object *item );
    void Add_Imemo( lsListItem_Imemo *item );
    void Add_Data( lsListItem_Data *item );
    void Add_Module( lsListItem_Module *item );
    void Add_Iclass( lsListItem_Iclass *item );
    void Add_Struct( lsListItem_Struct *item );
    void Add_Regexp( lsListItem_Regexp *item );

signals:

public slots:

private:
    QJsonDocument   json_doc;

    // Object lists
    lsLinkedList    m_Strings;
    lsLinkedList    m_Arrays;
    lsLinkedList    m_Hashes;
    lsLinkedList    m_objects;
    lsLinkedList    m_imemo;
    lsLinkedList    m_data;
    lsLinkedList    m_modules;
    lsLinkedList    m_iclass;
    lsLinkedList    m_struct;
    lsLinkedList    m_regexp;

};

#endif // LSJSON_H
