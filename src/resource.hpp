/*
    Puxel
    Copyright (C) 2015  Sergey Ivanov

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Sergey Ivanov <sivanov@openmailbox.org>
*/

#ifndef __RESOURCE_HPP
#define __RESOURCE_HPP

#include <vector>

namespace pupack {

    const unsigned char RES_STAT_NULL   = 0;
    const unsigned char RES_STAT_ONDISK = 1;
    const unsigned char RES_STAT_INMEM  = 2;

    const unsigned char RES_TYPE_PNG    = 1;
    const unsigned char RES_TYPE_MP3    = 2;

    typedef struct {
        unsigned int size;
        void* pointer;
        unsigned char id;
        unsigned char status;
        unsigned char type;
    } contentItem;

    class ResourcePackR {
    protected:

        char* fileName;
        int itemsQuantity;
        std::vector<contentItem*> itemsHeaders;
        int maxID;

        int GetItemIndexByID(int _id);

    public:

        ResourcePackR(char* _resFileName);
        ~ResourcePackR();

        int ReadPack();
        int LoadRes(int _id);
        int FreeRes(int _id);
        unsigned char GetResStatus(int _id);
        void PrintPackInfo();

    }; // class ResourcePack

    class ResourcePackRW : public ResourcePackR {
    public:

        ResourcePackRW(char* _resFileName) : ResourcePackR(_resFileName) {};

        int WritePack();
        int FileToMem(char* _resFileName, char _type);
        int MemToFile(char* _resFileName, int _id);

    }; // class ResourcePackRW

} // namespace puxel

#endif // __RESOURCE_HPP
