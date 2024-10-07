#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include "ChessPiece.hpp"
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ChessBoard {
public:
  using AfterMoveCallback = std::function<void()>;
  ChessBoard();

  void set_after_move_callback(AfterMoveCallback callback) {
    after_move_callback = callback;
  }

  std::vector<std::vector<std::unique_ptr<Piece>>> squares;

  bool move_piece(const std::string &from, const std::string &to);

private:
  AfterMoveCallback after_move_callback;
};

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board) : board(board) {
    board.set_after_move_callback([this]() { print(); });
  }

  void print() const;

private:
  ChessBoard &board;
};

#endif // CHESSBOARD_HPP
