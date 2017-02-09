#include "resource.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace pupack;

/*
 * ResourcePackR
 */

int ResourcePackR::GetItemIndexByID(int _id) {

    for (int _i = 0; _i < itemsHeaders.size(); _i++) {
        if (itemsHeaders[_i]->id == _id) { return _i; }
    } // for _i

    return -1;
} // function ResourcePackR::GetItemIndexByID

ResourcePackR::ResourcePackR(char* _resFileName) {

    fileName = _resFileName;
    maxID = 0;
    itemsQuantity = 0;

} // function ResourcePackR::ResourcePackR

ResourcePackR::~ResourcePackR() {

    for (int _i = 0; _i < itemsHeaders.size(); _i++) {
        if (itemsHeaders[_i]->status == RES_STAT_INMEM) {
            delete itemsHeaders[_i]->pointer;
        } // if
    } // for _i

} // function ResourcePackR::~ResourcePackR

int ResourcePackR::ReadPack() {

    void* _resContent;
    FILE* _inp;
    _inp = fopen(fileName, "rb");

    fread(&itemsQuantity, sizeof(itemsQuantity), 1, _inp);

    for (int _i = 0; _i < itemsQuantity; _i++) {
        _resContent = (char*)malloc(sizeof(contentItem));
        fread(_resContent, sizeof(contentItem), 1, _inp);
        ((contentItem*)_resContent)->status = RES_STAT_ONDISK;
        itemsHeaders.push_back((contentItem*)_resContent);
    } // for _i

    fclose(_inp);

    return -1;
} // function ResourcePackR::ReadPack

/*! @todo Free and reload resource if its status is RES_STAT_INMEM. */
int ResourcePackR::LoadRes(int _id) {

    int _i = GetItemIndexByID(_id);
    if (_i < 0) { return -2; }

    if (itemsHeaders[_i]->status == RES_STAT_ONDISK) {

        FILE* _inp;
        _inp = fopen(fileName, "rb");

        size_t _shift = sizeof(itemsQuantity) + sizeof(contentItem)*itemsQuantity;
        fseek(_inp, _shift, SEEK_SET);
        for (int _j = 0; _j < _i; _j++) {
            fseek(_inp, itemsHeaders[_j]->size, SEEK_CUR);
        } // for _j

        itemsHeaders[_i]->pointer = (char*)malloc(sizeof(char)*itemsHeaders[_i]->size);
        fread(itemsHeaders[_i]->pointer, sizeof(char), itemsHeaders[_i]->size, _inp);

        fclose(_inp);
        itemsHeaders[_i]->status = RES_STAT_INMEM;
        return 0;
    } // if

    return -1;
} // function ResourcePackR::LoadRes

int ResourcePackR::FreeRes(int _id) {

    int _i = GetItemIndexByID(_id);
    if (_i < 0) { return -2; }
    if (itemsHeaders[_i]->status == RES_STAT_INMEM) {
        delete itemsHeaders[_i]->pointer;
        itemsHeaders[_i]->status = RES_STAT_ONDISK;
        return 0;
    } // if

    return -1;
} // function ResourcePackR::FreeRes

unsigned char ResourcePackR::GetResStatus(int _id) {

    int _i = GetItemIndexByID(_id);
    if (_i < 0) { return RES_STAT_NULL; }

    return itemsHeaders[_i]->status;
} // function ResourcePackR::GetResStatus

void ResourcePackR::PrintPackInfo() {

    std::cout << "\n*===================*\n";
    std::cout << "Pupack resource pack: " << fileName << "\n";
    std::cout << "Items: " << itemsQuantity << "\n";
    std::cout << "*===================*\n\n";

    char* _type;
    float _totalSize = 0;
    for (int _i = 0; _i < itemsHeaders.size(); _i++) {

        switch (itemsHeaders[_i]->type) {
            case RES_TYPE_PNG: _type = "PNG image"; break;
            case RES_TYPE_MP3: _type = "MP3 audio"; break;
            default: _type = "Unknown type";
        } // switch

        std::cout << "ID #" << (int)itemsHeaders[_i]->id << "\n";
        std::cout << _type << " (" << itemsHeaders[_i]->size << " bytes)\n\n";

        _totalSize += itemsHeaders[_i]->size;
    } // for _i

    std::cout << "\n*===================*\n";
    std::cout << "Total data size: " << _totalSize/1000 << " kbytes\n";
    std::cout << "*===================*\n\n";

} // function ResourcePackR::PrintPackInfo

/*
 *  ResourcePackRW
 */

int ResourcePackRW::WritePack() {

    FILE* _out;
    _out = fopen(fileName, "wb");

    fwrite(&itemsQuantity, sizeof(itemsQuantity), 1, _out);

    for (int _i = 0; _i < itemsHeaders.size(); _i++) {
        fwrite((char*)itemsHeaders[_i], sizeof(contentItem), 1, _out);
    } // for _i

    for (int _i = 0; _i < itemsHeaders.size(); _i++) {

        switch (itemsHeaders[_i]->status) {
        case RES_STAT_INMEM:
            fwrite((char*)itemsHeaders[_i]->pointer, itemsHeaders[_i]->size, 1, _out);
        break; // case RES_STAT_INMEM

        case RES_STAT_ONDISK:
            LoadRes(itemsHeaders[_i]->id);
            fwrite((char*)itemsHeaders[_i]->pointer, itemsHeaders[_i]->size, 1, _out);
            FreeRes(itemsHeaders[_i]->id);
        break; // case RES_STAT_ONDISK

        } // switch
    } // for _i

    fclose(_out);

    return -1;
} // function ResourcePackRW::WritePack

int ResourcePackRW::FileToMem(char* _resFileName, char _type) {

    FILE* _inp;
    int _resSize;
    _inp = fopen(_resFileName, "rb");

    fseek(_inp, 0, SEEK_END);
    _resSize = ftell(_inp);
    rewind(_inp);

    void* _resContent = (char*)malloc(sizeof(char)*_resSize);
    fread(_resContent, sizeof(char), _resSize, _inp);
    fclose(_inp);

    contentItem* _item = new contentItem;
    _item->id = ++maxID;
    _item->size = _resSize;
    _item->type = _type;
    _item->status = RES_STAT_INMEM;
    _item->pointer = _resContent;
    itemsHeaders.push_back(_item);
    itemsQuantity++;

    return _item->id;
} // function ResourcePackRW::FileToMem

int ResourcePackRW::MemToFile(char* _resFileName, int _id) {

    void* _resContent;

    int _i = GetItemIndexByID(_id);
    if (_i < 0) { return -2; }

    if ( itemsHeaders[_i]->status == RES_STAT_INMEM ){
        _resContent = itemsHeaders[_i]->pointer;
    } else { return -1; }

    FILE* _inp;
    _inp = fopen(_resFileName, "wb");
    fwrite((char*)_resContent, sizeof(char), itemsHeaders[_i]->size, _inp);
    fclose(_inp);

    return 0;
} // function ResourcePackRW::MemToFile
