#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


int money = 500;
int bet;
int debt;
void printData(int pTotal, int dCard) {

    std::cout<<"\nYour money " << money;

    std::cout << "\nYour total is " << pTotal;
    std::cout << "\nDealer has a " << dCard << " showing.\n";

}

int getCard() {

    return std::rand() % 11 + 2;

}

int debtsys() {
  int debtdec;
  std::cout<<"\nYour money is "<<money<<"\nYour current debt is "<<debt<<"\n(1) Take a load\n(2) Pay a loan\n(3) Play Game";
  std::cin >> debtdec;
  if (debtdec == 1){
    std::cout<<"How much would you like to take out.";
    std::cin>>debtdec;
    debt = debtdec + debt;
    money = debtdec + money;
  }else if (debtdec == 2){
    std::cout<<"How much would you like to pay.";
    std::cin>>debtdec;
    money = debtdec - money;
    debt = debtdec - debt;
    if (money >= 0) {
      std::cout<<"You failed to manage your money you have been banned";
      return 0;
    }
  }else{
    
  }
}
void turn(int& pTotal, char choice, bool& stay) {

    // If the user wants to hit
    if (choice == 'H' || choice == 'h') {

        // If the user hits 21 or above
        if ((pTotal += getCard()) >= 21) {

            std::cout << "Your total is " << pTotal;
            stay = true;

        }

        return;
    }

    // Since the only other option can be to stay, then stay
    stay = true;

}

int main() {
    bool stay;
    char choice = NULL;
    int intchoice;
    while (true) {
        debtsys();
        if (money < 1){
        std::cout<<"You need to borrow money!";
        debtsys();
        }
        std::cout << "\n================================\n";
        stay = false;

        // Initialize srand and get random card numbers
        std::srand(std::time(0));
        int dCard = getCard();
        int pTotal = getCard() + getCard();
        int dTotal = dCard + getCard();
        std::cout<<"How much are you going to bet you have ";
        std::cout<<money;
        std::cout<<"$\n";
        std::cin >> bet;
        money -= bet;


        // Player's turn
        while (!stay) {

            printData(pTotal, dCard);
            if(pTotal > 21){
                stay = true;
            }
            std::cout << "[H]it or [S]tay?\n";
            std::cin >> choice;
            turn(pTotal, choice, stay);

        }

        stay = false;
        std::cout << "\n\nIt is now the dealer's turn!\n";

        // Dealer's turn
        while (dTotal <= 21 && !stay) {

            if (dTotal >= 17)
                stay = true;
            else
                dTotal += getCard();

        }

        // Display winner
        bool win;
        bool lose;
        std::cout << "\n\nThe player has " << pTotal << ".\nThe dealer has " << dTotal << ".\n\n";
        if (pTotal > 21){
            std::cout<<"You lose, Sorry m8\n";
            lose = true;
        }else if (pTotal == 21){
            std::cout<<"It's your lucky day, you win!";
            win = true;
        }else if (dTotal == 21){
            std::cout<<"It's your unlucky day, you lose!";
            lose = true;
        }else if(dTotal > 21){
            std::cout<<"Dealer bust, you won\n";
            win = true;
        }else if(pTotal > dTotal){
            std::cout<<"You have a higher number than the dealer, you won\n";
            win = true;
        }else if (pTotal == dTotal){
            std::cout<<"Tie, dealer wins you lose\n";
            lose = true;
        }else {
            std::cout<<"Dealer has a higher number, you lose\n";
            lose = true;
        }
        if (win){
            money += bet*2;
            win = false;
            lose = false;
        }else {
          money = money;
          win = false;
          lose = false;
        }
    }

}
