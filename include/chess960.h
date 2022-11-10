/**
 * Copyright 2022 Juan A. Sauceda <jasauceda@skibur.com>
 *
 * This program is free software; you can redistribute itand /or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111 - 1307  USA
 */

#ifndef CHESS960_INCLUDE_CHESS960_H_
#define CHESS960_INCLUDE_CHESS960_H_

#include <array>
#include <cstring>
#include <random>

using std::array;
using std::default_random_engine;
using std::random_device;
using std::string;
using std::uniform_int_distribution;

enum
{
    empty = '_',
    rook = 'R',
    knight = 'N',
    bishop = 'B',
    queen = 'Q',
    king = 'K',
};

class Chess960
{
public:
    Chess960();
    ~Chess960();
    string get_fen();

private:
    random_device r;
    string fen;
    void get_position();
};

#endif /* CHESS960_INCLUDE_CHESS960_H_ */