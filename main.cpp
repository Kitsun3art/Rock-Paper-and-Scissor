#include <iostream>
#include <ctime>

char getUserChoice(){
    char player;
    
    do{
        std::cout << "Rock, Papper or Scissor?" << std::endl;
        std::cout << "R for Rock" << std::endl;
        std::cout << "P for Papper" << std::endl;
        std::cout << "S for Scissor" << std::endl;
        std::cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
};
char getComputerChoice(){
    std::srand(std::time(0));

    int num = std::rand() % 3 + 1;

    switch(num){
        case 1: return 'r';
        case 2: return 's';
        case 3: return 'p';
    }
    return 0;
};

void showChoice(char choice){
    switch(choice)
    {
    case 'r':
        std::cout << "Rock" << std::endl;
        break;
    case 'p':
        std::cout << "Papper" << std::endl;
        break;
    case 's':
        std::cout << "Scissor" << std::endl;
        break;
    }
};

void chooseWinner(char player, char computer){
    switch(player) {
        case 's': 
        if (computer == 'p') {std::cout << "You win!";}
        else if (computer == 'r') {std::cout << "You lose!";}
        else {std::cout << "Draw";}
        break;

        case 'r':
        if(computer == 's') { std::cout << "You Win!";}
        else if (computer == 'p') { std::cout << "You lose!";}
        else {std::cout << "Draw";}
        break;

        case 'p':
        if(computer == 'r') { std::cout << "You win!";}
        else if (computer == 's') {std::cout << "You lose!";}
        else {std::cout << "Draw";}
        break;
    }
};

int main() {
    char player;
    char computer;
    char response;

    do {
        player = getUserChoice();
        std::cout << "Your choice: ";
        showChoice(player);

        computer = getComputerChoice();
        std::cout << "Computer's choice: ";
        showChoice(computer);

        chooseWinner(player, computer);

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> response;
    } while (response == 'y' || response == 'Y');

    return 0;
}