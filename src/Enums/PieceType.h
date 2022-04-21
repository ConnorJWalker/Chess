#pragma once

enum class PieceType : int {
    Pawn = 1,
    Bishop = 3,
    Knight = -3, // Must be different from bishop for texture lookup
    Castle = 5,
    King, // Value doesn't matter as game will end if taken
    Queen = 9,
    None = 0
};