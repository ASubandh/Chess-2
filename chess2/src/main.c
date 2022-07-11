#include "chess_move.h"
//testing gamestateflow file
#include "gamestateflow.h"
#include "AI.h"
#include "chess_rules.h"

/*changes - revamped so that instead of typing a number to select which piece to move
and a number for a location, you can type in the coordinate to move it there */

int main(){

	//to tell us exact type of piece for debugging
	const char* pieceNames[7] = {"EMPTY", "PAWN", "ROOK", "KNIGHT","BISHOP","QUEEN","KING"};
	const char* Colors[3] = {"BLACK", "WHITE", "DNE"};
	int j,k, gamestate = 1;
	int CurPosition, NewPosition;
  int enpassant_pawn_location = 0;
	//added by abhishek - for translating location to coordinate plane
	char NewPositionText[60];
	char CurPositionText[60];
  int count1,count2;
  int firstChar;
  int secondChar;
  char letters[9] = "abcdefgh";
  char numbers[9] = "12345678";
	char initial_message[100] = "\nJungkook [BTS] - \"AYO LADIES AND GENTLEMENN--\n";
  char end_message[220] = "\nThank you for checking out JUNGKOOK CHESS. We have to let you go now ... \n Jungkook [BTS] - \"But you're my everything ... I NEED U GIRLL WAE\"";
  char winning_message[220] = "\nJungkook [BTS] - \"Another trophy, my hands carry 'em \n Too many that I can't even count 'em (Turn it up now) \n Mic drop, \t mic drop\"\n";

  // turn based by color:
  Chess_player_color Player_Turn_Color = WHITE;
  int userinputStage = 1;

  // CHANG MODE
  int AIorPvP = 1; // 1 is AI 0 is PVP. please dont delete

  int FillerValue = -10; // to use for kingcheck outside of checkmove
  int check;

	printf("Welcome to Chess! For now, you can only play as White against the computer.\n\n");
	//functions for the main menu - right now it doesnt really do anything
	MainMenuState1();
	//printf("game state has returned %d",MainMenuState1());
	MainMenuState2();
	MainMenuState3();
	


	//actual chess game starts here
	Chess_board_default();
	Chess_pieces_default();
	Get_board();
	Print_board();
	//printf("la la lalal allala the game state is %d\n", GameStateFlow());
	while (gamestate == 1){
if (playercolor == Player_Turn_Color|| AIorPvP ==0){
//check = kingcheck(FillerValue, FillerValue, Player_Turn_Color);

if (check==1){
    printf("%s king is in check \n", Colors[Player_Turn_Color]);}
// checkmate(check); <- function call

//here lies jungkook AI


  while (userinputStage == 1){
     printf("%s's turn\n", Colors[Player_Turn_Color]);

		//need to scan for the type of piece
		printf("Choose the piece you want to move.\n");
		//in an array, use Array instead of &
		scanf("%s",CurPositionText);
		//prints the piece that the user will move
    //printf("%s", CurPositionText);
    if (('a' <= CurPositionText[0] && 'h' >= CurPositionText[0]) &&
    '1' <= CurPositionText[1] && '8' >= CurPositionText[1] && strlen(CurPositionText)==2){
		//converter - converts input into a number
		for (count1=0; count1<8; count1++){
	    if (CurPositionText[0] == letters[count1]) {
	      firstChar = 'a' - 97 + count1;
	    }
	  }

	  for (count2=0; count2<8; count2++){
	    if (CurPositionText[1] == numbers[count2]) {
	      secondChar = '8' - (8*count2) ;
	    }
	  }
		CurPosition = firstChar + secondChar;

    // checks the current piece matches the turn color
    if (Pieces[CurPosition].Player.Color == Player_Turn_Color){
        userinputStage = 0;}
        else{
        printf("wrong color piece\n please try again \n");
    }}
    else{printf("invalid selection: move format is File (lower case letter a-f) Rank (1-8) ex: a5\n");
    printf("please try again:\n");}}
    /*
		if (CurPosition == 9999){
			gamestate = 1;
			break;
		}*/

		//test statements to see what piece is what
		printf("Moving piece %c%c\n", Pieces[CurPosition].Name[0],Pieces[CurPosition].Name[1]);
		printf("The Color and type of this piece is a %s %s\n", Colors[Pieces[CurPosition].Player.Color], pieceNames[Pieces[CurPosition].TYPE]);

    userinputStage = 1; // second userinput stage is true

    while (userinputStage == 1){
		printf("Choose the place to move.\n");
		scanf("%s",NewPositionText);
if (('a' <= NewPositionText[0] && 'h' >= NewPositionText[0])&&
    '1' <= NewPositionText[1] && '8' >= NewPositionText[1] && strlen(NewPositionText)==2){

		//converter - converts input into a number
		for (count1=0; count1<8; count1++){
	    if (NewPositionText[0] == letters[count1]) {
	      firstChar = 'a' - 97 + count1;
	    }
	  }

	  for (count2=0; count2<8; count2++){
	    if (NewPositionText[1] == numbers[count2]) {
	      secondChar = '8' - (8*count2) ;
	    }
	  }
		NewPosition = firstChar + secondChar;
    userinputStage = 0;}
    else{printf("invalid selection: move format is File (lower case letter a-f) Rank (1-8) ex: a5\n");
    printf("please try again:\n");}}


		//check validity
    while (CheckMove(CurPosition,NewPosition) == 0){
			printf("Invalid move! Choose the piece you want to move again.\n");
      userinputStage=1; // we need this to take in a new piece
    while (userinputStage == 1){
       printf("%s's turn\n", Colors[Player_Turn_Color]);

		//need to scan for the type of piece
		printf("Choose the piece you want to move.");

		//in an array, use Array instead of &
		scanf("%s",CurPositionText);
    if (('a' <= CurPositionText[0] && 'h' >= CurPositionText[0]) &&
    '1' <= CurPositionText[1] && '8' >= CurPositionText[1] && strlen(CurPositionText)==2){
//---------------------------------------------------------------------------------------------------
		//converter - converts input into a number
		for (count1=0; count1<8; count1++){
	    if (CurPositionText[0] == letters[count1]) {
	      firstChar = 'a' - 97 + count1;
	    }
	  }

	  for (count2=0; count2<8; count2++){
	    if (CurPositionText[1] == numbers[count2]) {
	      secondChar = '8' - (8*count2) ;
	    }
	  }
		CurPosition = firstChar + secondChar;
	//---------------------------------------------------------------------------------------------------

    // checks the current piece matches the turn color
    if (Pieces[CurPosition].Player.Color == Player_Turn_Color){
        userinputStage = 0;}
        else{
        printf("wrong color piece\n please try again \n");
    }}
    else{printf("invalid selection: move format is File (lower case letter a-f) Rank (1-8) ex: a5\n");
    printf("please try again:\n");}}

    		//test statements to see what piece is what
		printf("Moving piece %c%c\n", Pieces[CurPosition].Name[0],Pieces[CurPosition].Name[1]);
		printf("The Color and type of this piece is a %s %s\n", Colors[Pieces[CurPosition].Player.Color], pieceNames[Pieces[CurPosition].TYPE]);

    userinputStage = 1; // second userinput stage is true

    while (userinputStage == 1){
		printf("Choose the place to move.");
		scanf("%s",NewPositionText);
if (('a' <= NewPositionText[0] && 'h' >= NewPositionText[0])&&
    '1' <= NewPositionText[1] && '8' >= NewPositionText[1] && strlen(NewPositionText)==2){

		//converter - converts input into a number
		for (count1=0; count1<8; count1++){
	    if (NewPositionText[0] == letters[count1]) {
	      firstChar = 'a' - 97 + count1;
	    }
	  }

	  for (count2=0; count2<8; count2++){
	    if (NewPositionText[1] == numbers[count2]) {
	      secondChar = '8' - (8*count2) ;
	    }
	  }
		NewPosition = firstChar + secondChar;
    userinputStage = 0;}
    else{printf("invalid selection: move format is File (lower case letter a-f) Rank (1-8) ex: a5\n");
    printf("please try again:\n");}}
		}
		Move_Piece(CurPosition, NewPosition);
    Castling(NewPosition);
    enpassant_pawn_location = ENPASSANT(enpassant_pawn_location, NewPosition);
    Promotion(NewPosition);
		//Get_board();
	}
		else{Player_Turn_Color = !Player_Turn_Color; // changes from white to black to allow the player to play
		}
		//This part is the AI moving the piece - testing the AI out by moving pawns
if (AIorPvP ==1){
		AIMove();}
		Get_board();
		Print_board();
if (AIorPvP ==0){ // we need to to switch between ai or pvp mode
    Player_Turn_Color = !Player_Turn_Color;} // 0 to 1 black white;
    userinputStage = 1;

		//if (checkmate){gamestate = 0;}
	}
	/* if (gamestate = 0){
		MainMenuState4();
	}
	*/
	printf("%s",end_message);
	return 0;
}
