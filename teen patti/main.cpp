#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <array>
#include <algorithm>
#include <tuple>

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

int main()
{
    std::vector<Card> deck =
    {
        {1,'H'},{2,'H'},{3,'H'},{4,'H'},{5,'H'},{6,'H'},{7,'H'},{8,'H'},{9,'H'},{10,'H'},{11,'H'},{12,'H'},{13,'H'},
        {1,'D'},{2,'D'},{3,'D'},{4,'D'},{5,'D'},{6,'D'},{7,'D'},{8,'D'},{9,'D'},{10,'D'},{11,'D'},{12,'D'},{13,'D'},
        {1,'C'},{2,'C'},{3,'C'},{4,'C'},{5,'C'},{6,'C'},{7,'C'},{8,'C'},{9,'C'},{10,'C'},{11,'C'},{12,'C'},{13,'C'},
        {1,'S'},{2,'S'},{3,'S'},{4,'S'},{5,'S'},{6,'S'},{7,'S'},{8,'S'},{9,'S'},{10,'S'},{11,'S'},{12,'S'},{13,'S'}
    };

    Player_Hand player1;
    player1.card1 = Drawing(deck);
    player1.card2 = Drawing(deck);
    player1.card3 = Drawing(deck);
    
    std::cout << deck.size() << '\n';
    std::cout << player1.card1.rank << player1.card1.suit << '\n';
    std::cout << player1.card2.rank << player1.card2.suit << '\n';
    std::cout << player1.card3.rank << player1.card3.suit << '\n' << '\n';
    
    Player_Hand player2;
    player2.card1 = Drawing(deck);
    player2.card2 = Drawing(deck);
    player2.card3 = Drawing(deck);
    
    std::cout << deck.size() << '\n';
    std::cout << player2.card1.rank << player2.card1.suit << '\n';
    std::cout << player2.card2.rank << player2.card2.suit << '\n';
    std::cout << player2.card3.rank << player2.card3.suit << '\n' << '\n';
    
    Player_Hand player3;
    player3.card1 = Drawing(deck);
    player3.card2 = Drawing(deck);
    player3.card3 = Drawing(deck);
    
    std::cout << deck.size() << '\n';
    std::cout << player3.card1.rank << player3.card1.suit << '\n';
    std::cout << player3.card2.rank << player3.card2.suit << '\n';
    std::cout << player3.card3.rank << player3.card3.suit << '\n' << '\n';
    
    Player_Hand player4;
    player4.card1 = Drawing(deck);
    player4.card2 = Drawing(deck);
    player4.card3 = Drawing(deck);
    
    std::cout << deck.size() << '\n';
    std::cout << player4.card1.rank << player4.card1.suit << '\n';
    std::cout << player4.card2.rank << player4.card2.suit << '\n';
    std::cout << player4.card3.rank << player4.card3.suit << '\n' << '\n';
    
    Player_Hand player5;
    player5.card1 = Drawing(deck);
    player5.card2 = Drawing(deck);
    player5.card3 = Drawing(deck);
    
    std::cout << deck.size() << '\n';
    std::cout << player5.card1.rank << player5.card1.suit << '\n';
    std::cout << player5.card2.rank << player5.card2.suit << '\n';
    std::cout << player5.card3.rank << player5.card3.suit << '\n' << '\n';
    
    Player_Hand player6;
    player6.card1 = Drawing(deck);
    player6.card2 = Drawing(deck);
    player6.card3 = Drawing(deck);
    
    std::cout << deck.size() << '\n';
    std::cout << player6.card1.rank << player6.card1.suit << '\n';
    std::cout << player6.card2.rank << player6.card2.suit << '\n';
    std::cout << player6.card3.rank << player6.card3.suit << '\n' << '\n';
    
    
    
    
    
    
    
    
    
    

    
    
    std::cin.get();
}
