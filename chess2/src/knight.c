//knight code
// uses abs() from stdlib.h
#include stdlib.h

if (Pieces[Cur_Position].TYPE == KNIGHT){
	int cur_row = Cur_Position / 8;
	int cur_col = Cur_Position % 8;
	int new_row = New_Position / 8;
	int new_col = New_Position % 8;
	if (Pieces[New_Position].Player.Color != Pieces[Cur_Position].Player.Color){
		if ((abs(new_col-cur_col)==2 && abs(new_row-cur_row)==1)||(abs(new_col-cur_col)==1 && abs(new_row-cur_row)==2)){
			printf("move is legal\n");}
			}
		else(
			printf("Error movement\n");}
else{
	printf("its not legal to kill ur teammates : / \n");}









}