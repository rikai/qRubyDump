#ifndef LSLISTITEM_ARRAY_H
#define LSLISTITEM_ARRAY_H

#include <iostream>

// datablocks
#include "lslinkedlist.h"
#include "lslistItem.h"

using namespace std;

class lsListItem_Array : public lsListItem
{
public:
    lsListItem_Array();

    void Add_Match( lsListItem_Array* item );

    // Stats
    int MatchCount();
    void Show_MatchCount();

    // set get
    string Address() const;
    void setAddress(const string &Address);

    double Memsize() const;
    void setMemsize(double Memsize);

private:
    string  m_Address;
    double  m_Memsize;

    // Matches
    lsLinkedList    m_Matches;

};

#endif // LSLISTITEM_ARRAY_H
