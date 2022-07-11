/*this is not used in the actual program. The actual function is defined in chess_rules.c*/

int kingcheck(int Cur_Position, int New_Position){
		int check = 0;
	//	int temp_opponent_attack_map[64]=[];

		int temp_holder_type = Pieces[Cur_Position].TYPE;
		Pieces[Cur_Position].TYPE= EMPTY;
		Pieces[New_Position].TYPE=temp_holder_type;

		int Current_color_turn = Pieces[Cur_Position].Player.Color;
		Pieces[Cur_Position].Player.Color = DNE;
		Pieces[New_Position].Player.Color = Current_color_turn;

for (int i=0; i<64; i++){ // iterates over the 64 space board
	int enemy_cur_row = i / 8;
	int enemy_cur_col = i % 8;

	if (Pieces[i].Player.Color == !Current_color_turn){ // looking for enemy pieces
		int temp;
		if(Pieces[i].TYPE == PAWN){
		// left attack
			if (enemy_cur_col-1>=0){
				if ((Pieces[i].Player.Color == WHITE && enemy_cur_row-1>=0){
					if (Pieces[i-9].Player.Color!=Pieces[i].Player.Color){
		//				temp_opponent_attack_map[i-9]= i-9;
						if (Pieces[i-(9)].TYPE == KING){
							check += 1;
              break;}}}
			if (Pieces[i].Player.Color==BLACK && enemy_cur_row+1<=7){
					if (Pieces[i+7].Player.Color!-Pieces[i].Player.Color}{
		//				temp_opponent_attack_map[i+7]= i+7;
					if (Pieces[i+7)].TYPE == KING){
							check += 1;
              break;}}}
		// right attack
			if (enemy_cur_col+1<=7){
				if ((Pieces[i].Player.Color == WHITE && enemy_cur_row-1>=0){
					if (Pieces[i-7].Player.Color!=Pieces[i].Player.Color){
		//				temp_opponent_attack_map[i-7]= i-7;
						if (Pieces[i-(7)].TYPE == KING){
							check += 1;
              break;}}}
			if (Pieces[i].Player.Color==BLACK && enemy_cur_row+1<=7){
					if (Pieces[i+9].Player.Color!-Pieces[i].Player.Color}{
		//				temp_opponent_attack_map[i+9]= i+9;}
					if (Pieces[i+(9)].TYPE == KING){
							check += 1;
              break}}}}

		if(Pieces[i].TYPE == ROOK){
			for (int z = 1; z<8;z++){
			// up
				if (enemy_cur_row-z>=0){
					if (Pieces[i].Player.Color!-Pieces[i-(z*8)].Player.Color){
					//	temp_opponent_attack_map[i-(z*8)]=(i-(z*8));
						if (Pieces[i-(z*8)].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i-(z*8)].TYPE != EMPTY){
							break;}}}}
			// down
      for (int z = 1; z<8;z++){
				if (enemy_cur_row+z<=7){
					if (Pieces[i].Player.Color!-Pieces[i+(z*8)].Player.Color){
					//	temp_opponent_attack_map[i+(z*8)]=i+(z*8);
						if (Pieces[i+(z*8)].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i+(z*8)].TYPE != EMPTY){
							break;}}}}

			// left
      for (int z = 1; z<8;z++){
				if (enemy_cur_col-z>=0){
					if (Pieces[i].Player.Color!-Pieces[i-z].Player.Color){
				//		temp_opponent_attack_map[i-z]=i-z;
						if (Pieces[i-(z)].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i-(z)].TYPE != EMPTY){
							break;}}}}
			// right
      for (int z = 1; z<8;z++){
				if (enemy_cur_col+z<=7){
					if (Pieces[i].Player.Color!-Pieces[i+z].Player.Color){
					//	temp_opponent_attack_map[i+z]=i+z;
						if (Pieces[i+z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i+z)].TYPE != EMPTY){
							break;}}}}
       if (check!=0){
         break;} // second break needed to get out of the forloop 0-63
              }

		if(Pieces[i].TYPE == BISHOP){
			for (int z = 1; z<8;z++){
				if (enemy_cur_row-z>=0&& enemy_cur_col-z>=0){
					if (Pieces[i-9*z].Player.Color != Pieces[i].Player.Color){
			//		temp_opponent_attack_map[i-9*z]=i-9*z;
						if (Pieces[i-9*z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i-(z*9)].TYPE != EMPTY){
							break;}}}}
      	for (int z = 1; z<8;z++){
				if (enemy_cur_row-z>=0 && enemy_cur_col+z<=7){
					if (Pieces[i-7*z].Player.Color != Pieces[i].Player.Color){
			//		temp_opponent_attack_map[i-7*z]=i-7*z;
						if (Pieces[i-7*z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i-(z*7)].TYPE != EMPTY){
							break;}}}}

			//down
      	for (int z = 1; z<8;z++){
			if (enemy_cur_row+z<=7 && enemy_cur_col-z>=0){
					if (Pieces[i+7*z].Player.Color != Pieces[i].Player.Color){
			//		temp_opponent_attack_map[i-z*7]=i-7*z;
						if (Pieces[i+7*z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i+(z*7)].TYPE != EMPTY){
							break;}}}}
       	for (int z = 1; z<8;z++){
				if (enemy_cur_row+z<=7 && enemy_cur_col+z<=7){
					if (Pieces[i+9*z].Player.Color != Pieces[i].Player.Color){
			//		temp_opponent_attack_map[i+9*z]=i+9*z;
						if (Pieces[i+9*z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i+(z*9)].TYPE != EMPTY){
							break;}}}	}
       if (check!=0){
         break;}// second break needed to get out of the forloop 0-63
                                     }



		if (Pieces[i].TYPE == KNIGHT){
			// 8 different possible moves
			if (enemy_cur_col-1 >=0 && enemy_cur_row-2 >= 0){
				if (Pieces[i-1-2*8].Player.Color != Pieces[i].Player.Color && Pieces[i-1-2*8].TYPE == KING){
					check += 1;
          break;}}

			if (enemy_cur_col-2 >=0 && enemy_cur_row-1 >= 0){
				if (Pieces[i-2-1*8].Player.Color != Pieces[i].Player.Color && Pieces[i-2-1*8].TYPE == KING){
					check += 1;
          break;}}
			if (enemy_cur_col+1 <=7 && enemy_cur_row-2 >= 0){
				if (Pieces[i+1-2*8].Player.Color != Pieces[i].Player.Color && Pieces[i+1-2*8].TYPE == KING){
					check += 1;
          break;}}
			if (enemy_cur_col-1 >=0 && enemy_cur_row+2 <= 7){
				if (Pieces[i-1+2*8].Player.Color != Pieces[i].Player.Color && Pieces[i-1+2*8].TYPE == KING){
					check += 1;
          break;}}
			if (enemy_cur_col+2 >= 0 && enemy_cur_row-1 <= 7){
				if (Pieces[i+2-1*8].Player.Color != Pieces[i].Player.Color && Pieces[i+2-1*8].TYPE == KING){
					check += 1;
          break;}}
			if (enemy_cur_col-2 >= 0 && enemy_cur_row+1 <= 7){
			if (Pieces[i-2+1*8].Player.Color != Pieces[i].Player.Color && Pieces[i-2+1*8].TYPE == KING){
					check += 1;
          break;}}
			if (enemy_cur_col+1 <=7 && enemy_cur_row+2 <= 7){
			if (Pieces[i+1+2*8].Player.Color != Pieces[i].Player.Color && Pieces[i+1+2*8].TYPE == KING){
					check += 1;
          break;}}
			if (enemy_cur_col+2 <=7 && enemy_cur_row+1 <= 7){
			if (Pieces[i+2+1*8].Player.Color != Pieces[i].Player.Color && Pieces[i+2+1*8].TYPE == KING){
					check += 1;
          break;}}

			}

		if(Pieces[i].TYPE == QUEEN){
			// 8 different directions
			for (int z = 1; z<8;z++){
			// up
				if (enemy_cur_row-z>=0){
					if (Pieces[i].Player.Color!-Pieces[i-(z*8)].Player.Color){
					//	temp_opponent_attack_map[i-(z*8)]=(i-(z*8));
						if (Pieces[i-(z*8)].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i-(z*8)].TYPE != EMPTY){
							break;}}}}
			// down
      for (int z = 1; z<8;z++){
				if (enemy_cur_row+z<=7){
					if (Pieces[i].Player.Color!-Pieces[i+(z*8)].Player.Color){
					//	temp_opponent_attack_map[i+(z*8)]=i+(z*8);
						if (Pieces[i+(z*8)].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i+(z*8)].TYPE != EMPTY){
							break;}}}}

			// left
      for (int z = 1; z<8;z++){
				if (enemy_cur_col-z>=0){
					if (Pieces[i].Player.Color!-Pieces[i-z].Player.Color){
				//		temp_opponent_attack_map[i-z]=i-z;
						if (Pieces[i-(z)].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i-(z)].TYPE != EMPTY){
							break;}}}}
			// right
      for (int z = 1; z<8;z++){
				if (enemy_cur_col+z<=7){
					if (Pieces[i].Player.Color!-Pieces[i+z].Player.Color){
					//	temp_opponent_attack_map[i+z]=i+z;
						if (Pieces[i+z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i+z)].TYPE != EMPTY){
							break;}}}}

			for (int z = 1; z<8;z++){
				if (enemy_cur_row-z>=0&& enemy_cur_col-z>=0){
					if (Pieces[i-9*z].Player.Color != Pieces[i].Player.Color){
			//		temp_opponent_attack_map[i-9*z]=i-9*z;
						if (Pieces[i-9*z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i-(z*9)].TYPE != EMPTY){
							break;}}}}
      	for (int z = 1; z<8;z++){
				if (enemy_cur_row-z>=0 && enemy_cur_col+z<=7){
					if (Pieces[i-7*z].Player.Color != Pieces[i].Player.Color){
			//		temp_opponent_attack_map[i-7*z]=i-7*z;
						if (Pieces[i-7*z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i-(z*7)].TYPE != EMPTY){
							break;}}}}

			//down
      	for (int z = 1; z<8;z++){
			if (enemy_cur_row+z<=7 && enemy_cur_col-z>=0){
					if (Pieces[i+7*z].Player.Color != Pieces[i].Player.Color){
			//		temp_opponent_attack_map[i-z*7]=i-7*z;
						if (Pieces[i+7*z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i+(z*7)].TYPE != EMPTY){
							break;}}}}
       	for (int z = 1; z<8;z++){
				if (enemy_cur_row+z<=7 && enemy_cur_col+z<=7){
					if (Pieces[i+9*z].Player.Color != Pieces[i].Player.Color){
			//		temp_opponent_attack_map[i+9*z]=i+9*z;
						if (Pieces[i+9*z].TYPE == KING){
							check += 1;
              break;}
						if (Pieces[i+(z*9)].TYPE != EMPTY){
							break;}}}	}
       if (check!=0){
         break;}}// second break needed to get out of the forloop 0-63






		if(Pieces[i].TYPE == KING){
			// up
			if (enemy_cur_row-1]>=0){
				if (Pieces[i-8].Player.Color != Pieces[i].Player.Color){
					temp_opponent_attack_map[i-8]=i-8;
						if (Pieces[i-8].TYPE == KING){
							check += 1;
              break;}}

				if (enemy_cur_col-1>=0){
					if (Pieces[i-9].Player.Color != Pieces[i].Player.Color){
					temp_opponent_attack_map[i-9]=i-9;
						if (Pieces[i-9].TYPE == KING){
							check += 1;
              break;}}}
				if (enemy_cur_col+1<=7){
					if (Pieces[i-7].Player.Color != Pieces[i].Player.Color){
					temp_opponent_attack_map[i-7]=i-7;
						if (Pieces[i-7].TYPE == KING){
							check += 1;
              break;}}}}

			if (enemy_cur_row+1<=7){
					if (Pieces[i].Player.Color!-Pieces[i+8)].Player.Color){
						temp_opponent_attack_map[i+8]=i+8;
						if (Pieces[i+8].TYPE == KING){
							check += 1;
              break;}}

				if (enemy_cur_col-1>=0){
					if (Pieces[i+7].Player.Color != Pieces[i].Player.Color){
					temp_opponent_attack_map[i+7]=i+7;
						if (Pieces[i+7].TYPE == KING){
							check += 1;
              break;}}}
				if (enemy_cur_col+1<=7){
					if (Pieces[i+9].Player.Color != Pieces[i].Player.Color){
					temp_opponent_attack_map[i+9]=i+9;
						if (Pieces[i+9].TYPE == KING){
							check += 1;
              break;}}}}
			// left
			if (enemy_cur_col-1>=0){
					if (Pieces[i].Player.Color!-Pieces[i-1].Player.Color){
						temp_opponent_attack_map[i-1]=i-1;
						if (Pieces[i-(1)].TYPE == KING){
							check += 1;
              break;}}}
			// right
				if (enemy_cur_col+1>=0){
					if (Pieces[i].Player.Color!-Pieces[i+1].Player.Color){
						temp_opponent_attack_map[i+1]=i+1;
						if (Pieces[i+1].TYPE == KING){
							check += 1;
              break;}}}
              }// end of king if statements
              }// end of if statements for color matching
              }// end of for loop

// switch back
		Pieces[New_Position].TYPE= EMPTY;
		Pieces[Cur_Position].TYPE=temp_holder_type;

		Pieces[New_Position].Player.Color = DNE;
		Pieces[Cur_Position].Player.Color = Current_color_turn;

   // return true or false of the check function
		if (check != 0){
		return 1;}
		return 0;
		}


//int checkmate ( movelist,)
	//-- taking AI generating moves list
	//	look at the length}
