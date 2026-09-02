#include <iostream>
#include <vector>
#include <random>
#include <numeric>

struct Card
{
    int rank;
    char suit;
};

int drawCard(std::vector<int>& remaining, std::mt19937& gen)
{
    std::uniform_int_distribution<> dist(0, (int)remaining.size() - 1);
    int pick = dist(gen);
    int cardIndex = remaining[pick];

    remaining[pick] = remaining.back();
    remaining.pop_back();

    return cardIndex;
}

int main()
{
    std::vector<Card> deck = {
        {1,'H'},{2,'H'},{3,'H'},{4,'H'},{5,'H'},{6,'H'},{7,'H'},{8,'H'},{9,'H'},{10,'H'},{11,'H'},{12,'H'},{13,'H'},
        {1,'D'},{2,'D'},{3,'D'},{4,'D'},{5,'D'},{6,'D'},{7,'D'},{8,'D'},{9,'D'},{10,'D'},{11,'D'},{12,'D'},{13,'D'},
        {1,'C'},{2,'C'},{3,'C'},{4,'C'},{5,'C'},{6,'C'},{7,'C'},{8,'C'},{9,'C'},{10,'C'},{11,'C'},{12,'C'},{13,'C'},
        {1,'S'},{2,'S'},{3,'S'},{4,'S'},{5,'S'},{6,'S'},{7,'S'},{8,'S'},{9,'S'},{10,'S'},{11,'S'},{12,'S'},{13,'S'}
    };

    std::vector<int> remaining(52);
    std::iota(remaining.begin(), remaining.end(), 0);

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < 18; i++) // e.g. deal 3 cards to 6 players
    {
        Card drawn = deck[drawCard(remaining, gen)];
        std::cout << drawn.rank << drawn.suit << " ";
    }
    std::cout << std::endl;

    std::cin.get();
}
