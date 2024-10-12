#include <iostream>
#include <random>
#include <string>
using namespace std;

int player = 0;
int dealer = 0;
string playerMessage = "Las cartas del jugador son: ";
string dealerMessage = "Las cartas del dealer son: ";
int cards[52];

void createDeck() {
    int cardValue = 2;
    int cardCount = 0;
    for (int figure = 1; figure <= 4; figure++) {
        for (int card = 1; card <= 13; card++) {
            switch (card) {
                case 10:
                case 11:
                case 12:
                    cardValue = 10;
                    break;
                case 13:
                    cardValue = 11;
                    break;
                default:
                    break;
            }
            cards[cardCount] = cardValue;
            cardCount++;
            cardValue++;
        }
        cardValue = 2;
    }
}

int drawCard() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 52);
    int card = dist(gen);
    return cards[card - 1];
}

void initGame() {
    player = 0;
    dealer = 0;
    playerMessage = "Las cartas del jugador son: ";
    dealerMessage = "Las cartas del dealer son: ";
    for (int i = 0; i < 2; i++) {
        int card = drawCard();
        player += card;
        playerMessage += to_string(card) + " ";
    }
    for (int i = 0; i < 2; i++) {
        int card = drawCard();
        dealer += card;
        dealerMessage += to_string(card) + " ";
    }
}

void checkWinner() {
    cout << playerMessage << endl;
    cout << "Puntos del jugador: " << player << endl;
    cout << dealerMessage << endl;
    cout << "Puntos del dealer: " << dealer << endl;

    if (player == 21) {
        cout << "Ganaste con 21 puntos!" << endl;
    } else if (player > dealer && player <= 21) {
        cout << "Ganaste!" << endl;
    } else if (player == dealer) {
        cout << "Empate." << endl;
    } else {
        cout << "Perdiste." << endl;
    }
}
int main() {
    createDeck();
    initGame();
    checkWinner();
    return 0;
}
