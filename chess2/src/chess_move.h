#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include "chess_board.h"
#include "chess_rules.h"

//4/19/22 - changed the variable name from Cur_Position to Power
//Cur_position is the name of the piece

void Move_Piece(int Cur_Position, int New_Position);
int  CheckMove(int Cur_Position,int New_Position);
void Castling(int New_Position);
int ENPASSANT(int enpassant_risk_pawn_location, int New_Position);
void Promotion(int New_Position);


#endif
