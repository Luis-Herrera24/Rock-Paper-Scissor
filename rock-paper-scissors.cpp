
#include <iostream>
#include <ctime>
#include <cctype>
using namespace std;

string toLowerCase(string input);   // Converts a string to lowercase
void getChoices(int& playerNumber, int& computerNumber); // Gets the player's and computer's choices
void playRound(int player, int computer, int& scorePoints); // Plays a single round and updates the score

int main()
{
    string firstName;
    string choice;
    int playerNumber;
    int computerNumber;
    int totalScore = 0;
    int points;
    
    srand(time(0));  // Seed the random number generator
    
    cout << "Welcome player to Rock Paper Scissor" << endl<< endl;
    
    
    cout << "Please enter your first name" << endl;
    cin >> firstName;
    
    cout << "Rules: Rock beats Scissors, Scissor beats Paper, Paper beats Rock. ";
    cout << "Best of 3 is the winner!" << endl << endl;
    cout << firstName << " Please enter your choice (rock, paper or scissor): " << endl;
    
    for (int i = 0; i < 3; i++){    // Loop for three rounds of the game

        getChoices(playerNumber, computerNumber); 
        
        playRound(playerNumber, computerNumber, points);
    
        totalScore += points;
        
        cout << endl;
        
        // Display current or final score based on the round number
        if (i != 2){
            cout << "Your current score is: " <<  totalScore << endl << endl;
        }
        else{
            cout << "Your final score is: " <<  totalScore << endl << endl;
        }
    
    }
    return 0;
}

string toLowerCase (string input){
    
    for (int i = 0; i < input.length(); i++){
        input[i]= tolower(input[i]);
    }
    return input;
    
}

void getChoices(int& playerNumber, int& computerNumber) {
    string playerChoice;

    // Get player choice
    cout << "Please enter your choice (rock, paper, or scissors): ";
    cin >> playerChoice;
    playerChoice = toLowerCase(playerChoice);

    // Input validation for the player choice
    while (playerChoice != "rock" && playerChoice != "paper" && playerChoice != "scissors") {
        cout << "Invalid input! Please choose rock, paper, or scissors: ";
        cin >> playerChoice;
        playerChoice = toLowerCase(playerChoice);
    }

    // Convert player's choice to a number
    if (playerChoice == "rock") playerNumber = 0;
    else if (playerChoice == "paper") playerNumber = 1;
    else playerNumber = 2;  // scissors

    // Generate a random choice for the computer
    computerNumber = rand() % 3;
    
    string choices[] = {"rock", "paper", "scissors"};
    cout << "The computer chose " << choices[computerNumber] << endl;
}

void playRound(int player, int computer, int& scorePoints){
     // Determine the outcome of the round
    string choices[] = {"rock", "paper", "scissors"};
    
    if (player == computer){
        scorePoints = 0;
        cout << "It's a Tie! Both chose " << choices[player] << "!" << endl;
    }
    else if ((player == 0 && computer == 2) || 
            (player == 1 && computer == 0) || 
            (player == 2 && computer == 1)) {
                
        cout << "You won! " << choices[player] << " beats " << choices[computer] << endl;
        scorePoints = 1;
    }
    else {
        cout << "You lose! " << choices[computer] << " beats " << choices[player] << endl;
        scorePoints = 0;
    }
}
