/*
 * Copyright (c) 2016 Lee A. Stripp <leestripp@gmail.com>
 *
 * This file is part of qBot
 *
 * qBot is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * qBot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with qBot.  If not, see <http://www.gnu.org/licenses/>
 */

// datablocks
#include "lslistItem.h"
#include "lslinkedlist.h"

lsLinkedList::lsLinkedList()
{
    item_list = NULL;
    last_item = NULL;
    item_count = 0;
}

lsLinkedList::~lsLinkedList()
{
    Clear();
}

void lsLinkedList::Add_item(lsListItem *item)
{
    // TOP
    item->setNext_item( item_list );
    item_list = item;
    if( item->getNext_item() ) item->getNext_item()->setPrev_item( item );
    item_list->setPrev_item( NULL );
    item_count++;

    //For add at end func
    if( last_item == NULL ) last_item = item;
}

void lsLinkedList::Add_itematEnd(lsListItem *item)
{
    if(  last_item == NULL )
    {
        Add_item( item );

    } else
    {
        // END
        last_item->setNext_item( item );
        item->setPrev_item( last_item );
        last_item = item;
        last_item->setNext_item( NULL );
        item_count++;
    }
}


//! Insert
/*!
 * Item and Pos must be set for this to work.
 *
 * \param item - item to insert
 * \param pos  - Item inserted after this position in the list.
 */
void lsLinkedList::Insert_ItemAfter( lsListItem *item, lsListItem *pos )
{
    if(! pos ) return;

    if( pos->getNext_item() == NULL )
    {
        Add_itematEnd( item );
        return;
    }

    if( item )
    {
        // INSERT AFTER
        item->setNext_item( pos->getNext_item() );
        item->setPrev_item( pos );
        pos->getNext_item()->setPrev_item( item );
        pos->setNext_item( item );

        item_count++;

    } else
    {
        cout << "ERROR: lsLinkedList::Insert_ItemAfter() item and pos nust be set." << endl;
    }
}

void lsLinkedList::Insert_ItemBefore(lsListItem *item, lsListItem *pos)
{
    if(! pos ) return;

    if( pos->getPrev_item() == NULL )
    {
        Add_item( item );
        return;
    }

    if( item )
    {
        // INSERT BEFORE
        item->setNext_item( pos );
        item->setPrev_item( pos->getPrev_item() );
        pos->getPrev_item()->setNext_item( item );
        pos->setPrev_item( item );

        item_count++;

    } else
    {
        cout << "ERROR: lsLinkedList::Insert_ItemAfter() item and pos nust be set." << endl;
    }
}

lsListItem *lsLinkedList::Find_item(int index)
{
    lsListItem *li = item_list;
    while( li )
    {
        if( li->getIndex() == index ) return li;
        li = li->getNext_item();
    }
    return li;
}

void lsLinkedList::Clear()
{
    lsListItem *item;
    while( item_list )
    {
        item = item_list->getNext_item();
        delete item_list;
        item_list = item;
    }
    item_list = NULL;
    last_item = NULL;
    item_count = 0;
}

int lsLinkedList::getItem_count() const
{
    return item_count;
}

lsListItem *lsLinkedList::getItem_list() const
{
    return item_list;
}

void lsLinkedList::setItem_list(lsListItem *value)
{
    item_list = value;
}

