// enum FirstMove TRUE FALSE DNE
//need access to stdlib.h abs()


if (Pieces[Cur_Position].TYPE == PAWN ){

int cur_row = Cur_Position / 8;
int cur_col = Cur_Position % 8;
int new_row = New_Position / 8;
int new_col = New_Position % 8;

if (Pieces[New_Position].Player.Color != Pieces[Cur_Position].Player.Color){ // as long as colors dont match
		if (Pieces[Cur_Position].FirstMove == notfirst){
			//checks special first move (condition statement combines both black and white conditions)
			if ((((new_col-cur_col)==0)&&((new_row-cur_row)==2)&&(Pieces[Cur_Position].Player.Color == BLACK))||
			(((new_col-cur_col)==0)&&((new_row-cur_row)==-2)&&(Pieces[Cur_Position].Player.Color == WHITE))){       
				// check if moving through empty spaces
				int legalpassing = 0;
				for (int i = 1; i==2; i++){
					if (Pieces[Cur_Position+(i*8)].TYPE == EMPTY){
						legalpassing += 1;}}
				if (legalpassing == 2){
					printf("special firstmove is legal\n");
					Pieces[Cur_Position].FirstMove = first;
				}}}
		// normal move
		if ((((new_col-cur_col)==0)&&((new_row-cur_row)==1)&&(Pieces[Cur_Position].Player.Color == BLACK))||
		(((new_col-cur_col)==0)&&((new_row-cur_row)==-1)&&(Pieces[Cur_Position].Player.Color == WHITE))){ 
			if (Pieces[New_Position].TYPE == EMPTY){
				printf("legal move\n");
			 	Pieces[Cur_Position].FirstMove = N/A;
				}
		}
		// attack diagonal
		if ((abs(new_col-cur_col)==1)&&(((new_row-cur_row)==1 && Pieces[Cur_Position].Player.Color == BLACK)||
		((new_row-cur_row)==-1 && Pieces[Cur_Position].Player.Color == WHITE))){
			if (Pieces[New_Position].TYPE != EMPTY){ // normal attack
				printf("legal attack move\n");
				//if (Pieces[Cur_Position].FirstMove == notfirst){
				Pieces[Cur_Position].FirstMove = N/A;//}
			}
			// ENPASSANTE
			if ((Pieces[New_Position].TYPE == EMPTY) && (Pieces[New_Position-((new_row-cur_row)*8)].TYPE == PAWN) && (Pieces[New_Position-((new_row-cur_row)*8)].FirstMove == first)){
				printf("en passante is legal\n");}}
}}