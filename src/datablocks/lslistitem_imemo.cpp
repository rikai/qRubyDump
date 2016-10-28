
#include "lslistitem_imemo.h"


lsListItem_Imemo::lsListItem_Imemo()
{
    m_Memsize = 0;
}

void lsListItem_Imemo::Add_Match(lsListItem_Imemo *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_Imemo::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_Imemo::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_Imemo *chk_item = (lsListItem_Imemo*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes" << endl;
        }
        chk_item = (lsListItem_Imemo*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base imemo : " << Memsize() << " bytes" << endl;
    }
}


// ***** get set

string lsListItem_Imemo::Address() const
{
    return m_Address;
}

void lsListItem_Imemo::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_Imemo::Memsize() const
{
    return m_Memsize;
}

void lsListItem_Imemo::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

