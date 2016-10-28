
#include "lslistitem_struct.h"


lsListItem_Struct::lsListItem_Struct()
{
    m_Memsize = 0;
}

void lsListItem_Struct::Add_Match(lsListItem_Struct *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_Struct::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_Struct::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_Struct *chk_item = (lsListItem_Struct*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes" << endl;
        }
        chk_item = (lsListItem_Struct*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base struct : " << Memsize() << " bytes" << endl;
    }
}


// ***** get set

string lsListItem_Struct::Address() const
{
    return m_Address;
}

void lsListItem_Struct::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_Struct::Memsize() const
{
    return m_Memsize;
}

void lsListItem_Struct::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

