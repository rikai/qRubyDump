
#include "lslistitem_module.h"


lsListItem_Module::lsListItem_Module()
{
    m_Memsize = 0;
}

void lsListItem_Module::Add_Match(lsListItem_Module *item)
{
    // Add matching address item
    m_Matches.Add_item( item );
}

int lsListItem_Module::MatchCount()
{
    return m_Matches.getItem_count();
}

void lsListItem_Module::Show_MatchCount()
{
    // Show matches
    bool match = false;

    lsListItem_Module *chk_item = (lsListItem_Module*)m_Matches.getItem_list();
    while( chk_item )
    {
        // Only show if mem size incresed
        if( chk_item->Memsize() > m_Memsize )
        {
            match = true;
            cout << "  Memory increase : " << chk_item->Memsize() << " bytes" << endl;
        }
        chk_item = (lsListItem_Module*)chk_item->getNext_item();
    }

    if( match )
    {
        cout << "  ^- Base array : " << Memsize() << " bytes" << endl;
    }
}


// ***** get set

string lsListItem_Module::Address() const
{
    return m_Address;
}

void lsListItem_Module::setAddress(const string &Address)
{
    m_Address = Address;
}

double lsListItem_Module::Memsize() const
{
    return m_Memsize;
}

void lsListItem_Module::setMemsize(double Memsize)
{
    m_Memsize = Memsize;
}

