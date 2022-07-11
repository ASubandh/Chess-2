#include <stdio.h>

//int main(int argc, char *argv[])//can be deleted 
char *player_type = "black"; //not permanent
char player_move_input[60] ; // string input
char player_chosen_piece[3]; // piece name 
char chosen_piece_start_File; // column
char chosen_piece_end_File; // row
int chosen_piece_start_Rank;
int chosen_piece_end_Rank;

int main()
{
    
  //  Chess_Position
    
    
printf("black's turn: \n");//, player_type); // prompts player1 or player2 
printf("Please make a move (ex: bP A2 to A4) : ");

fgets(player_move_input, 60, stdin);
 printf("%s is the input \n", player_move_input);
 
if (5 == sscanf(player_move_input, "%s %c%d to %c%d", player_chosen_piece, &chosen_piece_start_File, &chosen_piece_start_Rank, &chosen_piece_end_File, &chosen_piece_end_Rank)) 
{
    printf("%s is the input \n", player_move_input);
    printf("%s is the chosen piece \n", player_chosen_piece);
    printf("%c is the initial file (letter cord) \n", chosen_piece_start_File);
    printf("%c is the destinated file \n", chosen_piece_end_File);
    printf("%d is the initial rank (number) \n", chosen_piece_start_Rank);
    printf("%d is the final rank \n", chosen_piece_end_Rank);
    
    // converting into array index values 0-7 //
    int file = chosen_piece_start_File - 'A'; // values that need to be stored
    int rank = chosen_piece_end_Rank - 1; // values that need to be stored

    printf("%d %d ", file, rank);
}
}
