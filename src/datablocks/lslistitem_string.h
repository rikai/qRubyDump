#ifndef LSLISTITEM_STRING_H
#define LSLISTITEM_STRING_H

#include <iostream>

// datablocks
#include "lslinkedlist.h"
#include "lslistItem.h"

using namespace std;

class lsListItem_String : public lsListItem
{
public:
    lsListItem_String();

    void Add_Match( lsListItem_String* item );

    // Stats
    int MatchCount();
    void Show_MatchCount();

    // set get
    string Address() const;
    void setAddress(const string &Address);

    double Memsize() const;
    void setMemsize(double Memsize);

    string Value() const;
    void setValue(const string &Value);

private:
    string  m_Address;
    double  m_Memsize;

    string  m_Value;

    // Matches
    lsLinkedList    m_Matches;

};

#endif // LSLISTITEM_STRING_H
