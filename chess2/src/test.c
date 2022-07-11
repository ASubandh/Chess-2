#include "chess_board.h"

int main(){
	int j,k;
	Chess_board_default();
	Chess_pieces_default();
	Get_board();
	Print_board();
	Move_Piece(0,40);
	Get_board();
	Print_board();
	return 0;
}
