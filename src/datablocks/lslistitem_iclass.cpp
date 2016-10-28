
#include "lslistitem_iclass.h"


lsListItem_Iclass::lsListItem_Iclass()
{
    m_Memsize = 0;
}

void lsListItem_Iclass::Add_Match(lsListItem_Iclass *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_Iclass::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_Iclass::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_Iclass *chk_item = (lsListItem_Iclass*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes" << endl;
        }
        chk_item = (lsListItem_Iclass*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base iclass : " << Memsize() << " bytes" << endl;
    }
}


// ***** get set

string lsListItem_Iclass::Address() const
{
    return m_Address;
}

void lsListItem_Iclass::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_Iclass::Memsize() const
{
    return m_Memsize;
}

void lsListItem_Iclass::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

