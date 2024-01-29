/*
      Creator: vinayak-kumar-sharma
      Task: Number Guessing Game
      
*/



#include<iostream>
#include<string>
#include<stdlib.h>      // for rand and srand
#include<time.h>        // for time
#include<windows.h> 

using namespace std;

// creating a class for Number Guessing game
class NumberGuessingGame {
    private:
        int guess;             // player guess
        int t;              // system generated number or target number
        int r;              // how many attempts remaining
        int total;          // total number of attempts
    public:
        NumberGuessingGame()
        {
            srand( time(NULL) );
            t = rand()%100 + 1;
            r = 0;
            total = 5;
        }

// For introduction and rules of the game
    void gamerules()
    {
        
        cout << "\n\n----- Number Guessing Game Rules -----\n";
        cout << "1. The computer will randomly select a number between 1 and 100.\n";
        cout << "2. Your goal is to guess the correct number.\n";
        cout << "3. After each guess, the computer will provide hints ('Too high' or 'Too low').\n";
        cout << "4. You have a limited number of attempts to guess the correct number.\n";
        cout << "5. If you guess the correct number, you win!\n";
        cout << "6. If you run out of attempts, the game ends.\n";
        cout << "--------------------------------------\n";
        // cout<<"-  You have :: " << total << " attempts. Good luck!"<<endl;
        
    }
    void startgame(){
        cout<<endl;
        cout<<"_____________Welcome to Number Guessing Game!_______________"<<endl;
        cout<<endl<<endl;
        cout<<"Press 1 for Play Game.\t\t Press 2 for Rules.\t\t Press 3 for Exit."<<endl;
        cout << "Enter your choice: ";
    }

// for processing of their gueses
    void playGame() {
        do {
            system("CLS"); // Clear screen for a clean display
            cout << " --------** Number Guessing Game! **------------ " << endl;
            cout<<endl<<endl;
            cout << "* Can you guess the correct number between 1 to 100? " << "\t\t";

            cout << "* Attempts remaining :: " << total - r << endl;
            cout<<endl;
            cout << " Enter your guess: ";
            cin >> guess;

            if (guess<= 0 || guess > 100) {
                cout << "Invalid input! Please enter a number between 1 and 100." << endl;
                return;
            }

            if (guess == t) {
                system("CLS");
                cout << "Congratulations! You guessed the correct number!" << endl;
                cout << "Number of attempts: " << r + 1 << endl;
                break;
            } 
            else {
                system("CLS");
                cout << "Oops! That's not the correct number." << endl;
                if (guess > t) {
                    cout << "Hint: Too high! Try again." << endl;
                } 
                else {
                    cout << "Hint: Too low! Try again." << endl;
                }
            }

            r++;

            if (r == total) {
                system("CLS");
                cout << "Sorry, you've run out of attempts." << endl;
                cout << "The correct number was: " << t << endl;
                break;
            }

            // Add a delay for a more interactive feel
            cout << "Loading next attempt...";
            for (int i = 0; i < 3; ++i) {
                cout << ".";
                Sleep(500);  // Sleep for 500 milliseconds
            }

        } while (true); 
    } 
};

int main()
{   
    NumberGuessingGame user; // creating a object
    
    while(true){

    user.startgame();

    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            {
                user.playGame();
                cout<<"\n\n_________ThankYou for playing NumberGuessing Game___________\n";

                break;
            }
        case 2:
            {
                user.gamerules();
                break;
            }
        case 3:
            {
                cout<<"\n\n_________Exiting from the NumberGuessing Game___________\n";
                cout<<endl;
                return 0;
            }
        default:
            cout<<"Please provide valid respond."<<endl;
    }

    }
    
    
    return 0;

    

}