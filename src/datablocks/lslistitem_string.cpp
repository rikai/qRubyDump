#include "lslistitem_string.h"

lsListItem_String::lsListItem_String()
{
    m_Memsize = 0;

}

void lsListItem_String::Add_Match(lsListItem_String *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_String::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_String::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_String *chk_item = (lsListItem_String*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes";
            cout << " Value :" << chk_item->Value() << endl;
        }
        chk_item = (lsListItem_String*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base string : " << Memsize() << " bytes";
        cout << " Value :" << Value() << endl << endl;
    }
}


// ***** get set

string lsListItem_String::Address() const
{
    return m_Address;
}

void lsListItem_String::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_String::Memsize() const
{
    return m_Memsize;
}

void lsListItem_String::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

string lsListItem_String::Value() const
{
    return m_Value;
}

void lsListItem_String::setValue(const string &Value)
{
    m_Value = Value;
}

