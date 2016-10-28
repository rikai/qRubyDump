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

#include <iostream>

// Qt
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>

#include "lsjson.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication app( argc, argv );

    std::cout << "qRubyDump v0.1 by Lee A. Stripp" << std::endl;
    std::cout << "====================================" << std::endl;

    if( argc > 1 )
    {
        QDir dir( argv[1] );
        if(! dir.exists() )
        {
            qWarning( "The directory does not exist" );
            return 1;
        }

        dir.setFilter( QDir::Files );
        dir.setSorting( QDir::Time | QDir::Reversed );

        lsJSON json;

        QFileInfoList list = dir.entryInfoList();
        foreach( QFileInfo finfo, list )
        {
            QString name = finfo.fileName();
            json.parse( "data/" + name );
        }

        // Show results
        json.display();


    } else
    {
        cout << "Usage :      location of dump files" << endl;
        cout << "   qRubyDump [directory]" << endl;
    }

    return 0;
}
