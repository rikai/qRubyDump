
#include "lslistitem_array.h"


lsListItem_Array::lsListItem_Array()
{
    m_Memsize = 0;

}

void lsListItem_Array::Add_Match(lsListItem_Array *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_Array::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_Array::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_Array *chk_item = (lsListItem_Array*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes" << endl;
        }
        chk_item = (lsListItem_Array*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base array : " << Memsize() << " bytes" << endl;
    }
}


// ***** get set

string lsListItem_Array::Address() const
{
    return m_Address;
}

void lsListItem_Array::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_Array::Memsize() const
{
    return m_Memsize;
}

void lsListItem_Array::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

