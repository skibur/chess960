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

#include "chess960.h"

Chess960::Chess960() { get_position(); }

Chess960::~Chess960()
{
    // TODO
}

void Chess960::get_position()
{
    string white_position;
    string black_position;
    default_random_engine e1(r());
    array<char, 8> start_position;
    start_position.fill(empty);

    // King position must be between the rooks
    uniform_int_distribution<int> king_range(1, 6);
    int king_position = king_range(e1);
    start_position[king_position] = king;

    // Rook position
    uniform_int_distribution<int> rook_left_range(0, king_position - 1);
    int position = rook_left_range(e1);
    start_position[position] = rook;
    uniform_int_distribution<int> rook_right_range(king_position + 1, 7);
    position = rook_right_range(e1);
    start_position[position] = rook;

    // Bishop position
    uniform_int_distribution<int> max_range(0, 7);
    // Dark color = 0, Light color = 1
    for (int color{0}; color < 2; color++)
    {
        do
        {
            position = max_range(e1);
        } while (position % 2 == color || start_position[position] != empty);
        start_position[position] = bishop;
    }

    // Knight position
    for (int repeat{0}; repeat < 2; repeat++)
    {
        do
        {
            position = max_range(e1);
        } while (start_position[position] != empty);
        start_position[position] = knight;
    }

    // Queen position
    for (int i{0}; i < start_position.size(); i++)
    {
        if (start_position[i] == empty)
        {
            start_position[i] = queen;
            break;
        }
    }

    // Convert array to string (White position)
    for (int index{0}; index < start_position.size(); index++)
        white_position += start_position.data()[index];

    // Black position
    for (int index{0}; index < white_position.size(); index++)
        black_position += tolower(white_position[index]);

    // FEN
    fen.append(black_position);
    fen.append("/pppppppp/8/8/8/8/PPPPPPPP/");
    fen.append(white_position);
    fen.append(" w KQkq - 0 1");
}

string Chess960::get_fen() { return fen; }