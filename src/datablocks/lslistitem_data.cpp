
#include "lslistitem_data.h"


lsListItem_Data::lsListItem_Data()
{
    m_Memsize = 0;
}

void lsListItem_Data::Add_Match(lsListItem_Data *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_Data::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_Data::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_Data *chk_item = (lsListItem_Data*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes" << endl;
        }
        chk_item = (lsListItem_Data*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base data : " << Memsize() << " bytes" << endl;
    }
}


// ***** get set

string lsListItem_Data::Address() const
{
    return m_Address;
}

void lsListItem_Data::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_Data::Memsize() const
{
    return m_Memsize;
}

void lsListItem_Data::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

