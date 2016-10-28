
#include "lslistitem_object.h"


lsListItem_Object::lsListItem_Object()
{
    m_Memsize = 0;
}

void lsListItem_Object::Add_Match(lsListItem_Object *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_Object::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_Object::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_Object *chk_item = (lsListItem_Object*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes" << endl;
        }
        chk_item = (lsListItem_Object*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base object : " << Memsize() << " bytes" << endl;
    }
}


// ***** get set

string lsListItem_Object::Address() const
{
    return m_Address;
}

void lsListItem_Object::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_Object::Memsize() const
{
    return m_Memsize;
}

void lsListItem_Object::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

