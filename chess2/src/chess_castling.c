//Castling

//gameflow:
//get move -> check move -> check castling -> if no castling updating single move 
//-> check if king at check

void Castling(int Cur_Position, int New_Position){
	if (Pieces[Cur_Position].TYPE == KING && Pieces[Cur_Position].FirstMove == FIRST){
		// right castling update moving 2 pieces
		if (Pieces[New_Position+1].TYPE == ROOK && Pieces[New_Position+1].FirstMove == FIRST){
			Pieces[New_Position+1].FirstMove == NA; // deflagging rook
			Pieces[Cur_Position].FirstMove == NA; // deflagging king
			MovePiece(New_Position+1, New_Position-1); // moving rook
			MovePiece(Cur_Position, New_Position);//moving king
			}
		// left castling update moving 2 pieces
		if (Pieces[New_Position-2].TYPE == ROOK && Pieces[New_Position-2].FirstMove == FIRST){
			Pieces[New_Position-2].FirstMove == NA; // deflag rook
			Pieces[Cur_Position].FirstMove == NA; // deflag king
			MovePiece(New_Position-2, New_Position+1); // move rook
			MovePiece(Cur_Position,New_Position);  // move king
			}}}
