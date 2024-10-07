#include "ChessBoard.hpp"
#include "ChessPiece.hpp"

ChessBoard::ChessBoard() {
  // Initialize the squares stored in 8 columns and 8 rows:
  squares.resize(8);
  for (auto &square_column : squares)
    square_column.resize(8);
}

bool ChessBoard::move_piece(const std::string &from, const std::string &to) {
  int from_x = from[0] - 'a';
  int from_y = std::stoi(std::string() + from[1]) - 1;
  int to_x = to[0] - 'a';
  int to_y = std::stoi(std::string() + to[1]) - 1;

  auto &piece_from = squares[from_x][from_y];
  if (piece_from) {
    if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
      std::cout << piece_from->color_string() << " " << piece_from->type() << " is moving from " << from << " to " << to << std::endl;
      auto &piece_to = squares[to_x][to_y];
      if (piece_to) {
        if (piece_from->color != piece_to->color) {
          std::cout << piece_from->color_string() << " " << piece_to->type() << " is being removed from " << to << std::endl;
          if (auto king = dynamic_cast<King *>(piece_to.get())) {
            std::cout << king->color_string() << " lost the game" << std::endl;
          }
        } else {
          std::cout << "cannot move " << piece_from->type() << " from " << from << " to " << to << " (same color)" << std::endl;
          return false;
        }
      }
      piece_to = std::move(piece_from);

      if (after_move_callback) {
        after_move_callback();
      }
      return true;
    } else {
      std::cout << "can not move " << piece_from->type() << " from " << from << " to " << to << std::endl;
      return false;
    }
  } else {
    std::cout << "no piece at " << from << std::endl;
    return false;
  }
}

void ChessBoardPrint::print() const {
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            if(board.squares[x][y]) {
                std::cout << board.squares[x][y]->short_representation() << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}