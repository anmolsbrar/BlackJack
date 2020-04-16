#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Dealer.h"
#include "Player.h"
#include <vector>
#include <ctime>
#include <Windows.h>

void initPlayers(std::vector<Person*>&, int, int);
void dealTwo(std::vector<Person*>&);
int localPlayerPos(int);
void localPlay(Person*);
void cPlay(Person*);
void dealerPlay(Person*);
void determineWinner(Person*, Person*);

Deck* Person::mDeck = new Deck(2);

int main()
{
    srand(time(0));
    //-----Vars------
    char ch;
    std::vector<Person*> tPlayers;
    Dealer* dealer = new Dealer();
    int pCount, localPos;
    std::cout << "Welcome to Black Jack!\n";
    std::cout << "Select number of players(1-3): ";
    std::cin >> pCount;
    if (pCount > 3)
    {
        std::cout << "Player count cannot be more than 3.\nSetting player count to 3 other players.\n";
        pCount = 3;
    }

    localPos = localPlayerPos(pCount);
    initPlayers(tPlayers, pCount, localPos);
    tPlayers.push_back(dealer);
    dealer->shuffle();
    do
    {
        if (dealer->totalDealt() > 75)
        {
            dealer->shuffle();
            {
                std::cout << "Shuffling cards.\n";
                Sleep(700);
            }

        }


        dealTwo(tPlayers);

        std::cout << "Press any key to continue...";
        std::cin.get();
        std::cout << std::endl << std::endl;

        for (size_t i = 0; i < tPlayers.size(); i++)
        {
            Sleep(1000);
            if (i == localPos - 1)
                localPlay(tPlayers[i]);
            else if (i == tPlayers.size() - 1)
                dealerPlay(dealer);
            else
                cPlay(tPlayers[i]);
        }
        determineWinner(tPlayers[localPos - 1], dealer);
        std::cout << "\n\nEnter any key to play another round, or 'E' to exit.\n";
        std::cin >> ch;
        if (ch != 'e' && ch != 'E')
        {
            for (Person* p : tPlayers)
                p->reset();
        }
    } while (ch != 'e' && ch != 'E');

    for (Person* p : tPlayers) //Release memory
        delete p;

    return 0;
}

void initPlayers(std::vector<Person*>& pVec, int num, int pPos)
{
    std::string playerName;

    std::cout << "Enter your name: ";
    std::cin >> playerName;
    std::cin.clear();
    std::cin.ignore(100, '\n');
    Player* localPlayer = new Player(playerName);
    for (int i = 0; i < num; i++)
    {
        if (i == (pPos - 1))
        {
            pVec.push_back(localPlayer);
            continue;
        }
        pVec.push_back(new Player(i + 1));
    }
}

void dealTwo(std::vector<Person*>& pVec)
{
    for (Person* player : pVec)
    {
        std::cout << player->name() << " drew: " << std::endl;
        player->initialDraw();
        std::cout << std::endl;
        Sleep(500);
    }
}

int localPlayerPos(int num)
{
    int pPos;
    std::cout << "Enter your siting position.\n";
    for (int i = 0; i < num; i++)
    {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    std::cin >> pPos;
    return pPos;
}

void localPlay(Person* lPlayer)
{
    char ch = 'e';
    std::cout << lPlayer->name() << "'s turn:" << std::endl;
    std::cout << "Initial hand:\n";
    lPlayer->showInitialHand();
    while (ch != 's' && ch != 'S')
    {
        std::cout << "Hit / Stand? ";
        std::cin >> ch;

        switch (ch)
        {
        case 'H':
        case 'h':
            lPlayer->hit();
            break;
        case 'S':
        case 's':
            break;
        default:
            std::cout << "Not a valid input.\n";
        }

        if (lPlayer->totalCount() > 21)
        {
            std::cout << "Bust!\n";
            break;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void cPlay(Person* aiPlayer)
{
    std::cout << aiPlayer->name() << "'s turn:" << std::endl;
    std::cout << "Initial hand:\n";
    aiPlayer->showInitialHand();
    std::cout << std::endl;
    int rPlay = rand() % 2;
    if (rPlay == 0)
    {
        while (aiPlayer->totalCount() < 17)
        {
            aiPlayer->hit();
            if (aiPlayer->totalCount() > 21)
            {
                std::cout << "Bust!\n";
                break;
            }
        }
    }
    else if (rPlay == 1)
    {
        while (aiPlayer->totalCount() <= 11)
        {
            aiPlayer->hit();
            if (aiPlayer->totalCount() > 21)
            {
                std::cout << "Bust!\n";
                break;
            }
        }
    }
    std::cout << std::endl << std::endl;
}

void dealerPlay(Person* dealer)
{
    std::cout << dealer->name() << "'s turn:" << std::endl;
    std::cout << "Initial hand:\n";
    dealer->showInitialHand();
    Sleep(1000);
    while (dealer->totalCount() < 17)
    {
        dealer->hit();
        if (dealer->totalCount() > 21)
        {
            std::cout << "Dealer Busted!\n";
            break;
        }
        Sleep(1000);
    }
    std::cout << std::endl << std::endl;
}

void determineWinner(Person* lPlayer, Person* dealer)
{
    int lCount = lPlayer->totalCount();
    int dCount = dealer->totalCount();
    if (lCount > 21)
        std::cout << "BUST! You lost this round.\nBetter luck next time!\n";
    else if (lCount == 21)
    {
        if (dCount == 21)
            std::cout << "PUSH!\nThis round is a tie.\n";
        else
            std::cout << "BLACKJACK!\n You won this round.\n";
    }
    else
    {
        if (lCount == dCount)
            std::cout << "PUSH!\nThis round is a tie.\n";
        else if (lCount > dCount)
            std::cout << "WINNER!\n You won this round\n";
        else if (lCount < dCount)
        {
            if (dCount > 21)
            {
                std::cout << "WINNER!\n You won this round\nDealer BUSTED!\n";
            }
            else
                std::cout << "You lost this round\nYour total " << lCount << std::endl;
            std::cout << "Dealer's total " << dCount << std::endl;
        }
    }
}