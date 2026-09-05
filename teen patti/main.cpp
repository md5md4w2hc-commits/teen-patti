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

std::vector<Card> Shuffel(std::vector<Card> &deck, int r)
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
    std::string name;
    double balance;
    int confidence;
    int bluff;
    int honesty;
    Player_Hand hand;
};

struct Player_Mood
{
    int currentConfidence;
    int streak; // wins/losses in a row
    int tilt; // rises after losses, may increase bluff frequency
};

int maxValue(int a, int b, int c)
{
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

Player Winner(Player p)
{
    std::cout << "the winner is : " << p.name << '\n';
    return p;
}

int main()
{
    std::vector<Card> deck =
    {
        {14,'H'},{2,'H'},{3,'H'},{4,'H'},{5,'H'},{6,'H'},{7,'H'},{8,'H'},{9,'H'},{10,'H'},{11,'H'},{12,'H'},{13,'H'},
        {14,'D'},{2,'D'},{3,'D'},{4,'D'},{5,'D'},{6,'D'},{7,'D'},{8,'D'},{9,'D'},{10,'D'},{11,'D'},{12,'D'},{13,'D'},
        {14,'C'},{2,'C'},{3,'C'},{4,'C'},{5,'C'},{6,'C'},{7,'C'},{8,'C'},{9,'C'},{10,'C'},{11,'C'},{12,'C'},{13,'C'},
        {14,'S'},{2,'S'},{3,'S'},{4,'S'},{5,'S'},{6,'S'},{7,'S'},{8,'S'},{9,'S'},{10,'S'},{11,'S'},{12,'S'},{13,'S'}
    };

    std::vector<Player_Hand> players(6);
    
    for (int i = 0; i < 6; ++i)
    {
        players[i] = DealHand(deck);
    }
    
    Player p1;
    p1.name = "Pranjal";
    p1.balance = 10000;
    p1.confidence = 100;
    p1.bluff = 10;
    p1.honesty = 80;
    p1.hand = players[0];
    
    Player p2;
    p2.name = "Paawani";
    p2.balance = 10000;
    p2.confidence = 90;
    p2.bluff = 40;
    p2.honesty = 50;
    p2.hand = players[1];
    
    Player p3;
    p3.name = "candy";
    p3.balance = 10000;
    p3.confidence = 70;
    p3.bluff = 0;
    p3.honesty = 100;
    p3.hand = players[2];
    
    Player p4;
    p4.name = "kishu";
    p4.balance = 10000;
    p4.confidence = 100;
    p4.bluff = 100;
    p4.honesty = 0;
    p4.hand = players[3];
    
    Player p5;
    p5.name = "anita";
    p5.balance = 10000;
    p5.confidence = 100;
    p5.bluff = 0;
    p5.honesty = 100;
    p5.hand = players[4];
    
    Player p6;
    p6.name = "popo";
    p6.balance = 10000;
    p6.confidence = 0;
    p6.bluff = 0;
    p6.honesty = 100;
    p6.hand = players[5];
    
    std::cout << p1.name << '\n';
    std::cout << p1.hand.card1.rank << p1.hand.card1.suit << '\n';
    std::cout << p1.hand.card2.rank << p1.hand.card2.suit << '\n';
    std::cout << p1.hand.card3.rank << p1.hand.card3.suit << '\n';
    
    std::cout << p2.name << '\n';
    std::cout << p2.hand.card1.rank << p2.hand.card1.suit << '\n';
    std::cout << p2.hand.card2.rank << p2.hand.card2.suit << '\n';
    std::cout << p2.hand.card3.rank << p2.hand.card3.suit << '\n';
    
    std::cout << p3.name << '\n';
    std::cout << p3.hand.card1.rank << p3.hand.card1.suit << '\n';
    std::cout << p3.hand.card2.rank << p3.hand.card2.suit << '\n';
    std::cout << p3.hand.card3.rank << p3.hand.card3.suit << '\n';
    
    std::cout << p4.name << '\n';
    std::cout << p4.hand.card1.rank << p4.hand.card1.suit << '\n';
    std::cout << p4.hand.card2.rank << p4.hand.card2.suit << '\n';
    std::cout << p4.hand.card3.rank << p4.hand.card3.suit << '\n';
    
    std::cout << p5.name << '\n';
    std::cout << p5.hand.card1.rank << p5.hand.card1.suit << '\n';
    std::cout << p5.hand.card2.rank << p5.hand.card2.suit << '\n';
    std::cout << p5.hand.card3.rank << p5.hand.card3.suit << '\n';
    
    std::cout << p6.name << '\n';
    std::cout << p6.hand.card1.rank << p6.hand.card1.suit << '\n';
    std::cout << p6.hand.card2.rank << p6.hand.card2.suit << '\n';
    std::cout << p6.hand.card3.rank << p6.hand.card3.suit << '\n';
        
    
    std::cin.get();
}
