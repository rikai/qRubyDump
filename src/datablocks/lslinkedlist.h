/*
 * Copyright (c) 2016 by Lee A. Stripp <leestripp@gmail.com>
 *
 * This file is part of the vortxGE library.
 *
 * vortxGE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * vortxGE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with vortxGE.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef LSLINKEDLIST_H
#define LSLINKEDLIST_H

#include <iostream>

// Qt5
#include <QString>

class lsListItem;

using namespace std;

/*! Linked List
 * Custon linked list storing generic items
 * 
 * */
class lsLinkedList
{
public:
    lsLinkedList();
    virtual ~lsLinkedList();

    void Add_item( lsListItem *item );
    void Add_itematEnd( lsListItem *item );
    void Insert_ItemAfter( lsListItem *item, lsListItem *pos  );
    void Insert_ItemBefore( lsListItem *item, lsListItem *pos  );

    // Find
    lsListItem *Find_item( int index );

    // cleanup
    void Clear();

    int getItem_count() const;

    lsListItem *getItem_list() const;
    void setItem_list(lsListItem *value);

private:
    lsListItem *item_list;
    lsListItem *last_item;
    int item_count;
};

#endif // LSLINKEDLIST_H
