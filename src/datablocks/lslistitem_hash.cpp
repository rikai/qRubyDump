
#include "lslistitem_hash.h"


lsListItem_Hash::lsListItem_Hash()
{
    m_Memsize = 0;

}

void lsListItem_Hash::Add_Match(lsListItem_Hash *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_Hash::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_Hash::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_Hash *chk_item = (lsListItem_Hash*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes" << endl;
        }
        chk_item = (lsListItem_Hash*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base hash : " << Memsize() << " bytes" << endl;
    }
}


// ***** get set

string lsListItem_Hash::Address() const
{
    return m_Address;
}

void lsListItem_Hash::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_Hash::Memsize() const
{
    return m_Memsize;
}

void lsListItem_Hash::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

