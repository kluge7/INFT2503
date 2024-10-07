#include "ChessPiece.hpp"

King::King(Piece::Color color) : Piece(color) {}

std::string King::type() const {
  return "king";
}

bool King::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  int dx = abs(to_x - from_x);
  int dy = abs(to_y - from_y);

  return (dx <= 1 && dy <= 1);
}

std::string King::short_representation() const {
    return "K";
}


Knight::Knight(Piece::Color color) : Piece(color) {}

std::string Knight::type() const {
  return "knight";
}

bool Knight::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  int dx = abs(to_x - from_x);
  int dy = abs(to_y - from_y);

  return ((dx == 2 && dy == 1) || (dx == 1 && dy == 2));
}

std::string Knight::short_representation() const {
    return "N";
}
