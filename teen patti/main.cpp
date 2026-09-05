#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

struct Card
{
    int rank;
    char suit;
};

struct Player_Hand
{
    Card card1;
    Card card2;
    Card card3;
};

int Random(int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, max - 1);
    int r = dist(gen);
    
    return r;
}

std::vector<Card> Shuffel(std::vector<Card>& deck, int r)
{
    deck.erase(deck.begin() + r);
    return deck;
}

Card Drawing(std::vector<Card> &deck)
{
    int r = Random(deck.size());
    Card x1 = deck.at(r);
    Shuffel(deck , r);
    return x1;
}

Player_Hand DealHand(std::vector<Card> &deck)
{
    Player_Hand hand;
    hand.card1 = Drawing(deck);
    hand.card2 = Drawing(deck);
    hand.card3 = Drawing(deck);
    
    return hand;
}

struct Player
{
    double balance;
    int confidence;
    int bluff;
    int honesty;
    Player_Hand hand;
};

int main()
{
    std::vector<Card> deck =
    {
        {1,'H'},{2,'H'},{3,'H'},{4,'H'},{5,'H'},{6,'H'},{7,'H'},{8,'H'},{9,'H'},{10,'H'},{11,'H'},{12,'H'},{13,'H'},
        {1,'D'},{2,'D'},{3,'D'},{4,'D'},{5,'D'},{6,'D'},{7,'D'},{8,'D'},{9,'D'},{10,'D'},{11,'D'},{12,'D'},{13,'D'},
        {1,'C'},{2,'C'},{3,'C'},{4,'C'},{5,'C'},{6,'C'},{7,'C'},{8,'C'},{9,'C'},{10,'C'},{11,'C'},{12,'C'},{13,'C'},
        {1,'S'},{2,'S'},{3,'S'},{4,'S'},{5,'S'},{6,'S'},{7,'S'},{8,'S'},{9,'S'},{10,'S'},{11,'S'},{12,'S'},{13,'S'}
    };

    std::vector<Player_Hand> players(6);
    
    for (int i = 0; i < 6; ++i)
    {
        players[i] = DealHand(deck);
    }
    
    Player pranjal;
    pranjal.balance = 10000;
    pranjal.confidence = 100;
    pranjal.bluff = 10;
    pranjal.honesty = 80;
    pranjal.hand = players[0];
    
    Player paawani;
    paawani.balance = 10000;
    paawani.confidence = 90;
    paawani.bluff = 40;
    paawani.honesty = 50;
    paawani.hand = players[1];
    
    Player candy;
    candy.balance = 10000;
    candy.confidence = 70;
    candy.bluff = 0;
    candy.honesty = 100;
    candy.hand = players[2];
    
    Player kishu;
    kishu.balance = 10000;
    kishu.confidence = 100;
    kishu.bluff = 90;
    kishu.hand = players[3];
    
    Player anita;
    anita.balance = 10000;
    anita.confidence = 100;
    anita.bluff = 0;
    anita.honesty = 100;
    anita.hand = players[4];
    
    Player popo;
    popo.balance = 10000;
    popo.confidence = 0;
    popo.bluff = 0;
    popo.honesty = 100;
    popo.hand = players[5];
    
    std::cout << "pranjal" << '\n';
    std::cout << pranjal.hand.card1.rank << popo.hand.card1.suit << '\n';
    std::cout << pranjal.hand.card2.rank << popo.hand.card2.suit << '\n';
    std::cout << pranjal.hand.card3.rank << popo.hand.card3.suit << '\n';
    
    std::cout << "paawani" << '\n';
    std::cout << paawani.hand.card1.rank << popo.hand.card1.suit << '\n';
    std::cout << paawani.hand.card2.rank << popo.hand.card2.suit << '\n';
    std::cout << paawani.hand.card3.rank << popo.hand.card3.suit << '\n';
    
    std::cout << "candy" << '\n';
    std::cout << candy.hand.card1.rank << popo.hand.card1.suit << '\n';
    std::cout << candy.hand.card2.rank << popo.hand.card2.suit << '\n';
    std::cout << candy.hand.card3.rank << popo.hand.card3.suit << '\n';
    
    std::cout << "kishu" << '\n';
    std::cout << kishu.hand.card1.rank << popo.hand.card1.suit << '\n';
    std::cout << kishu.hand.card2.rank << popo.hand.card2.suit << '\n';
    std::cout << kishu.hand.card3.rank << popo.hand.card3.suit << '\n';
    
    std::cout << "anita" << '\n';
    std::cout << anita.hand.card1.rank << popo.hand.card1.suit << '\n';
    std::cout << anita.hand.card2.rank << popo.hand.card2.suit << '\n';
    std::cout << anita.hand.card3.rank << popo.hand.card3.suit << '\n';
    
    std::cout << "popo" << '\n';
    std::cout << popo.hand.card1.rank << popo.hand.card1.suit << '\n';
    std::cout << popo.hand.card2.rank << popo.hand.card2.suit << '\n';
    std::cout << popo.hand.card3.rank << popo.hand.card3.suit << '\n';
        
    
    
    
    
    std::cin.get();
}
