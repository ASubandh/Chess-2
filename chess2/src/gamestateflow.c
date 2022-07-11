#include <stdio.h>

int MainMenuState = 1;
int PlayerGameOptionState = 5;
int PlayerColorChoiceState = 2;
int MainChessGame = 0;
int JungkookMode = 3;
int MainMenuState1OnSwitch = 0;
int MainMenuState2OnSwitch = 0;
int MainMenuState3OnSwitch = 0;


/*int GameStateFlow(){
  int sum = 21;
  return sum;
}*/


int MainMenuState1() {
//printf("Psuedo code for 4 GameStates\n\n");
while (MainMenuState1OnSwitch == 0){
  printf("Welcome to Jungkook Chess for Windows!\n");
  printf("Do you want to enable Jungkook mode?\n1 for yes\n0 for no\n");
  scanf("%d", &JungkookMode);
  if (JungkookMode == 1){
      printf("Jungkook Mode enabled\n");
      //MainMenuState = 0;
      MainMenuState1OnSwitch++;
      int sum = 11;
      return sum;
      //MainMenuState1OnSwitch++;
    }
  else if (JungkookMode == 0){
      printf("Jungkook Mode is not enabled\n");
      //MainMenuState = 0;
      MainMenuState1OnSwitch++;
      int sum = 22;
      return sum;
    }
  else {
      printf("invalid response. please try again\n");
      MainMenuState1OnSwitch = 0;
    }
  }
}

//----------------------------------------------------------
int MainMenuState2() {
while (MainMenuState2OnSwitch == 0){
        printf("Please choose game option:\n1 for Player v Player\n2 for AI \n");
        scanf("%d", &PlayerGameOptionState);
        if (PlayerGameOptionState == 1){
            printf("Chess game will be Player v Player\n");
            MainMenuState2OnSwitch++;
        }
        else if (PlayerGameOptionState == 2){
            printf("Chess game will be Player v AI\n");
            MainMenuState2OnSwitch++;
        }
        else {
            printf("invalid response. Please try again.\n");
            MainMenuState2OnSwitch = 0;
        }
      }
}
//----------------------------------------------------------
int MainMenuState3() {
    while ((MainMenuState3OnSwitch == 0)){
        printf("Please choose which color to play as:\n0 for black\n1 for white\n");
        scanf("%d", &PlayerColorChoiceState);
        if (PlayerColorChoiceState == 0){
            printf("Player chose black\n");
            printf("Beginning Chess Game! \n");
            MainMenuState3OnSwitch++;
            int sum = 33;
            return sum;

        }
        else if (PlayerColorChoiceState == 1){
            printf("Player chose white\n");
            printf("Beginning Chess Game! \n");
            MainMenuState3OnSwitch++;
            int sum = 44;
            return sum;
        }
        else{
            printf("invalid response. Please try again.\n");
            MainMenuState3OnSwitch = 0;
            //PlayerColorChoiceState = 2;
        }
      }

}
//----------------------------------------------------------
int MainMenuState4(){
    /*while (MainChessGame == 0){
        printf("Chess Game in progress");
        printf("Did checkmate happen (debugging statement): 1 for yes 0 for no\n");
        scanf("%d", &MainChessGame);
        if (MainChessGame == 0){
            printf("checkmate did not happen continuing\n");
        }
        if (MainChessGame == 1){
            printf("Checkmate happened. Ending game");
          }
        }*/
    printf("Exiting Program. Thank you for playing Jungkook Chess");
    //return 0;

  }
