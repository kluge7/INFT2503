#ifndef CHESSPIECE_HPP
#define CHESSPIECE_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Piece {
public:
  enum class Color {
    WHITE,
    BLACK
  };

  Piece(Color color) : color(color) {}
  virtual ~Piece() {}

  Color color;

  std::string color_string() const {
    return color == Color::WHITE ? "white" : "black";
  }

  virtual std::string type() const = 0;
  virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
  virtual std::string short_representation() const = 0;
};

class King : public Piece {
public:
  King(Color color);

  std::string type() const override;
  bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
  std::string short_representation() const override;
};

class Knight : public Piece {
public:
  Knight(Color color);

  std::string type() const override;
  bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
  std::string short_representation() const override;
};

#endif // CHESSPIECE_HPP
