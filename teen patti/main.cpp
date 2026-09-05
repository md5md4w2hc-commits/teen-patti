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
        
        std::cout << "Deck size: " << deck.size() << '\n';
        std::cout << players[i].card1.rank << players[i].card1.suit << '\n';
        std::cout << players[i].card2.rank << players[i].card2.suit << '\n';
        std::cout << players[i].card3.rank << players[i].card3.suit << "\n\n";
    }
    
    
    
    
    std::cin.get();
}
