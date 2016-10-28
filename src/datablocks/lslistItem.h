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

#ifndef LSLISTITEM_H
#define LSLISTITEM_H

#include <iostream>

const int LSIT_NONE         = 0;
const int LSIT_CAL_EVENT    = 1;

using namespace std;

class lsListItem
{
public:
    lsListItem();
    virtual ~lsListItem();

    int getItem_type() const;
    void setItem_type( int value );

    int getIndex() const;
    void setIndex(int value);

    lsListItem *getNext_item() const;
    void setNext_item( lsListItem *value );

    lsListItem *getPrev_item() const;
    void setPrev_item(lsListItem *value);

private:
    lsListItem *next_item;
    lsListItem *prev_item;

    int item_type;
    int index;
};

#endif // LSLISTITEM_H
