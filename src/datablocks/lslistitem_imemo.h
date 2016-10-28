#ifndef LSLISTITEM_IMEMO_H
#define LSLISTITEM_IMEMO_H

#include <iostream>

// datablocks
#include "lslinkedlist.h"
#include "lslistItem.h"

using namespace std;

class lsListItem_Imemo : public lsListItem
{
public:
    lsListItem_Imemo();

    void Add_Match( lsListItem_Imemo* item );

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

#endif // LSLISTITEM_IMEMO_H
