
#include "lslistitem_regexp.h"


lsListItem_Regexp::lsListItem_Regexp()
{
    m_Memsize = 0;
}

void lsListItem_Regexp::Add_Match(lsListItem_Regexp *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_Regexp::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_Regexp::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_Regexp *chk_item = (lsListItem_Regexp*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes" << endl;
        }
        chk_item = (lsListItem_Regexp*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base regexp : " << Memsize() << " bytes" << endl;
    }
}


// ***** get set

string lsListItem_Regexp::Address() const
{
    return m_Address;
}

void lsListItem_Regexp::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_Regexp::Memsize() const
{
    return m_Memsize;
}

void lsListItem_Regexp::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

