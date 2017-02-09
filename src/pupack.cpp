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

#include <iostream>

#include "resource.hpp"

int main (int argc, char* argv[]) {

    // test area
    pupack::ResourcePackRW* resRW;
    pupack::ResourcePackR* resR;

    resRW = new pupack::ResourcePackRW("res.prp");
    resRW->FileToMem("test.png", pupack::RES_TYPE_PNG);
    resRW->FileToMem("test2.png", pupack::RES_TYPE_PNG);
    resRW->FileToMem("test.mp3", pupack::RES_TYPE_MP3);
    resRW->WritePack();
    delete resRW;

    resRW = new pupack::ResourcePackRW("res.prp");
    resRW->ReadPack();
    resRW->LoadRes(1);
    resRW->LoadRes(2);
    resRW->MemToFile("out.png", 1);
    resRW->MemToFile("out2.png", 2);
    resRW->FreeRes(1);
    resRW->FreeRes(2);
    resRW->LoadRes(3);
    resRW->MemToFile("out.mp3", 3);
    delete resRW;

    resR = new pupack::ResourcePackR("res.prp");
    resR->ReadPack();
    resR->PrintPackInfo();
    delete resR;
    // end of test area

    return 0;
} // function main
