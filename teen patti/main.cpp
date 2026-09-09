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
    int honesty;
    Player_Hand hand;
};

struct Player_Mood
{
    int currentConfidence;
    int streak; // wins/losses in a row
    int currentHonesty;
};

int maxValue(const Player &a)
{
    int max = a.hand.card1.rank;
    if (a.hand.card2.rank > max) max = a.hand.card2.rank;
    if (a.hand.card3.rank > max) max = a.hand.card3.rank;
    return max;
}

Player Check_for_max(const Player &p1 ,const Player &p2)
{
    Player max;
    int a = maxValue(p1);
    int b = maxValue(p2);
    
    std::vector<int> rank_1 = {p1.hand.card1.rank , p1.hand.card2.rank , p1.hand.card3.rank};
    std::sort(rank_1.begin() , rank_1.end());
    
    std::vector<int> rank_2 = {p2.hand.card1.rank , p2.hand.card2.rank , p2.hand.card3.rank};
    std::sort(rank_2.begin() , rank_2.end());
    
    if(a > b)
    {
        max = p1;
    }
    if(a < b)
    {
        max = p2;
    }
    if(a == b)
    {
        int x = rank_1[1];
        int y = rank_2[1];
        
        if(x > y)
        {
            max = p1;
        }
        if(x < y)
        {
            max = p2;
        }
        if(x == y)
        {
            int x = rank_1[0];
            int y = rank_2[0];
            if(x > y)
            {
                max = p1;
            }
            if(x < y)
            {
                max = p2;
            }
        }
    }
    
    return max;
}

Player Winner(Player p)
{
    std::cout << "the winner is : " << p.name << '\n';
    p.confidence += 50;
    p.honesty -= 10;
    return p;
}

bool IsSequence(std::vector<int> &ranks)
{
    std::sort(ranks.begin(), ranks.end());
    
    for (size_t i = 1; i < ranks.size(); ++i)
        {
            if (ranks[i] != ranks[i - 1] + 1)
            {
                return false;
            }
        }
        return true;
}

bool IsTrail(const Player &p)
{
    if(p.hand.card1.rank == p.hand.card2.rank && p.hand.card2.rank == p.hand.card3.rank && p.hand.card3.rank == p.hand.card1.rank)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsColour(const Player &p)
{
    if(p.hand.card1.suit == p.hand.card2.suit && p.hand.card2.suit == p.hand.card3.suit && p.hand.card3.suit == p.hand.card1.suit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsPair(const Player &p)
{
    int a = p.hand.card1.rank;
    int b = p.hand.card2.rank;
    int c = p.hand.card3.rank;
    
    return (a == b) || (b == c) || (a == c);
}

int FindPairValue(std::vector<int> nums) // returns -1 if no pair
{
    std::sort(nums.begin() , nums.end());
    for (size_t i = 1 ; i < nums.size() ; ++i)
    {
        if (nums[i] == nums[i - 1])
        {
            return nums[i];
        }
    }
    return -1;
}

Player Check_winner_for_trail(const Player &p1 ,const Player &p2)
{
    Player winner;
    
    if(IsTrail(p1))
    {
        if(IsTrail(p2))
        {
            winner = Winner(Check_for_max(p1 , p2));
        }
        else
        {
            winner = Winner(p1);
        }
    }
    else if(IsTrail(p2))
    {
        if(IsTrail(p1))
        {
            winner = Winner(Check_for_max(p1 , p2));
        }
        else
        {
            winner = Winner(p2);
        }
    }
    
    return winner;
}

Player Check_winner_for_colour(const Player &p1 ,const Player &p2)
{
    Player winner;
    
    if(IsColour(p1))
    {
        if(IsColour(p2))
        {
            winner = Winner(Check_for_max(p1 , p2));
        }
        else
        {
            winner = Winner(p1);
        }
    }
    else if(IsColour(p2))
    {
        if(IsColour(p1))
        {
            winner = Winner(Check_for_max(p1 , p2));
        }
        else
        {
            winner = Winner(p2);
        }
    }
    
    return winner;
}

Player Check_winner_for_run(const Player &p1 , const Player &p2)
{
    Player winner;
    
    std::vector<int> ranks_1 = {p1.hand.card1.rank , p1.hand.card2.rank , p1.hand.card3.rank};
    std::vector<int> ranks_2 = {p2.hand.card1.rank , p2.hand.card2.rank , p2.hand.card3.rank};
    
    if(IsSequence(ranks_1))
    {
        if(IsSequence(ranks_2))
        {
            winner = Winner(Check_for_max(p1 , p2));
        }
        else
        {
            winner = Winner(p1);
        }
    }
    if(IsSequence(ranks_2))
    {
        if(IsSequence(ranks_1))
        {
            winner = Winner(Check_for_max(p1 , p2));
        }
        else
        {
            winner = Winner(p2);
        }
    }
    
    return winner;
}

Player Check_winner_for_pair(const Player &p1 , const Player &p2)
{
    Player winner;
    
    std::vector<int> ranks_1 = {p1.hand.card1.rank , p1.hand.card2.rank , p1.hand.card3.rank};
    std::vector<int> ranks_2 = {p2.hand.card1.rank , p2.hand.card2.rank , p2.hand.card3.rank};
    
    if(IsPair(p1))
    {
        if(IsPair(p2))
        {
            int a = FindPairValue(ranks_1);
            int b = FindPairValue(ranks_2);
            
            if(a > b)
            {
                winner = Winner(p1);
            }
            else if(a == b)
            {
                winner = Winner(p1);
            }
            else
            {
                winner = Winner(p2);
            }
        }
        else
        {
            winner = Winner(p1);
        }
    }
    else if(IsPair(p2))
    {
        if(IsPair(p1))
        {
                int a = FindPairValue(ranks_1);
                int b = FindPairValue(ranks_2);
                
                if(a > b)
                {
                    winner = Winner(p1);
                }
                else if(a == b)
                {
                    winner = Winner(p1);
                }
                else
                {
                    winner = Winner(p2);
                }
        }
        else
        {
            winner = Winner(p2);
        }
    }
    
    return winner;
}

Player Check_winner_for_highCard(const Player &p1 , const Player &p2)
{
    Player winner;
    
    winner = Winner(Check_for_max(p1 , p2));
    
    return winner;
}

void DebugHand(const Player &p)
{
    std::cout << p.name << ": "
              << p.hand.card1.rank << p.hand.card1.suit << " "
              << p.hand.card2.rank << p.hand.card2.suit << " "
              << p.hand.card3.rank << p.hand.card3.suit
              << "  | Trail=" << std::boolalpha << IsTrail(p)
              << " Colour=" << IsColour(p)
              << " Pair="   << IsPair(p);

    std::vector<int> ranks = {p.hand.card1.rank, p.hand.card2.rank, p.hand.card3.rank};
    std::cout << " Sequence=" << IsSequence(ranks) << '\n';
}

Player Final(const Player &p1 ,const Player &p2)
{
    std::vector<int> rank_1 = {p1.hand.card1.rank , p1.hand.card2.rank , p1.hand.card3.rank};
    std::vector<int> rank_2 = {p2.hand.card1.rank , p2.hand.card2.rank , p2.hand.card3.rank};
    
    if(IsTrail(p1) || IsTrail(p2))
    {
        return Check_winner_for_trail(p1 , p2);
    }
    else if(IsSequence(rank_1) || IsSequence(rank_2))
    {
        return Check_winner_for_run(p1 , p2);
    }
    else if(IsColour(p1) || IsColour(p2))
    {
        return Check_winner_for_colour(p1 , p2);
    }
    else if(IsPair(p1) || IsPair(p2))
    {
        return Check_winner_for_pair(p1 , p2);
    }
    else
    {
        return Check_winner_for_highCard(p1 , p2);
    }
}

Player Player_Mood_In_Game(Player &p , Player_Mood &m)
{
    Player winner = p;
    
    std::vector<int> ranks = {p.hand.card1.rank , p.hand.card2.rank , p.hand.card3.rank};
    
    if(IsTrail(winner))
    {
        m.currentConfidence += 90;
        m.currentHonesty -= 15;
    }
    else if(IsSequence(ranks))
    {
        m.currentConfidence += 70;
        m.currentHonesty -= 10;
    }
    else if(IsColour(winner))
    {
        m.currentConfidence += 40;
        m.currentHonesty -= 5;
    }
    else if(IsPair(winner))
    {
        m.currentConfidence += 10;
        m.currentHonesty += 5;
    }
    else
    {
        m.currentConfidence += 0;
        m.currentHonesty += 15;
    }
    
    return winner;
}

int balance_checker(Player &p1 , Player &p2 , Player &p3 , Player &p4 , Player &p5 , Player &p6)
{
    int n = 0;
    
    if(p1.balance > 0 && p2.balance > 0 && p3.balance > 0 && p4.balance > 0 && p5.balance > 0 && p6.balance > 0)
    {
        n = 1;
    }
    
    return n;
}

Player Move(Player &p , double round)
{
    p.balance -= round;
    
    return p;
}

Player Blind(Player &p , double round)
{
    p.balance -= 2*round;
    
    return p;
}

Player Counter(Player &p , double round)
{
    p.balance -= 3*round;
    
    return p;
}

Player Fold(Player &p , double round)
{
    return p;
}


Player Funtion(Player &p , Player_Mood &m , double &round , int &number_of_player , int &move_made , int &blind_tracker ,  bool &card_seen , bool &p_fold)
{
    std::vector<int> ranks = {p.hand.card1.rank , p.hand.card2.rank , p.hand.card3.rank};
    
    if(card_seen)
    {
        if(m.currentHonesty > 50)
        {
            if(IsTrail(p))
            {
                Move(p , round);
                return p;
            }
            if(IsSequence(ranks))
            {
                Move(p , round);
                return p;
            }
            if(IsColour(p) && move_made < 4)
            {
                Move(p , round);
                return p;
            }
            if(IsPair(p) && move_made < 1)
            {
                Move(p , round);
                return p;
            }
            if(number_of_player > 2)
            {
                p_fold = true;
                number_of_player--;
            }
        }
        else
        {
            if(number_of_player > 5)
            {
                Move(p , round);
                return p;
            }
        }
    }
    else
    {
        if(m.currentConfidence >= 70)
        {
            if(blind_tracker > 0)
            {
                Blind(p , round);
                blind_tracker ++;
            }
            else
            {
                Counter(p , round);
            }
            
            m.currentConfidence -= 10;
            
            return p;
        }
        if(m.currentConfidence < 70)
        {
            card_seen = true;
            return p;
        }
    }
    return p;
}

void Game(Player &p1 , Player_Mood &m1 , Player &p2 , Player_Mood &m2 , Player &p3 , Player_Mood &m3 , Player &p4 , Player_Mood &m4 , Player &p5 , Player_Mood &m5 , Player &p6 , Player_Mood &m6)
{
    while(balance_checker(p1 , p2 , p3 , p4 , p5 , p6) > 0)
    {
        int blind_tracker = 0;
        int move_made = 0;
        std::vector<Player> players = {p1 , p2 , p3 , p4 , p5 , p6};
        int number_of_players = players.size();
        double round = 10;
        
        bool card_seen_p1 = false;
        bool p1_fold = false;
        bool card_seen_p2 = false;
        bool p2_fold = false;
        bool card_seen_p3 = false;
        bool p3_fold = false;
        bool card_seen_p4 = false;
        bool p4_fold = false;
        bool card_seen_p5 = false;
        bool p5_fold = false;
        bool card_seen_p6 = false;
        bool p6_fold = false;
        
        Funtion(p1 , m1 , round , number_of_players , move_made , blind_tracker , card_seen_p1 , p1_fold);
        if(p1_fold == false)
        {
            auto it = std::find(players.begin() , players.end(), p1);
            if (it != players.end())
                players.erase(it);
        }
        
    }
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

    std::vector<Player_Hand> player_hand(6);
    
    for (int i = 0; i < 6; ++i)
    {
        player_hand[i] = DealHand(deck);
    }
    
    Player p1;
    p1.name = "Pranjal";
    p1.balance = 10000;
    p1.confidence = 100;
    p1.honesty = 80;
    p1.hand = player_hand[0];
    Player_Mood p_1;
    p_1.currentConfidence = p1.confidence;
    p_1.currentHonesty = p1.honesty;
    p_1.streak = 0;
    
    Player p2;
    p2.name = "Paawani";
    p2.balance = 10000;
    p2.confidence = 90;
    p2.honesty = 50;
    p2.hand = player_hand[1];
    Player_Mood p_2;
    p_2.currentConfidence = p2.confidence;
    p_2.currentHonesty = p2.honesty;
    p_2.streak = 0;
    
    Player p3;
    p3.name = "candy";
    p3.balance = 10000;
    p3.confidence = 70;
    p3.honesty = 100;
    p3.hand = player_hand[2];
    Player_Mood p_3;
    p_3.currentConfidence = p3.confidence;
    p_3.currentHonesty = p3.honesty;
    p_3.streak = 0;
    
    Player p4;
    p4.name = "kishu";
    p4.balance = 10000;
    p4.confidence = 100;
    p4.honesty = 0;
    p4.hand = player_hand[3];
    Player_Mood p_4;
    p_4.currentConfidence = p4.confidence;
    p_4.currentHonesty = p4.honesty;
    p_4.streak = 0;
    
    Player p5;
    p5.name = "anita";
    p5.balance = 10000;
    p5.confidence = 100;
    p5.honesty = 100;
    p5.hand = player_hand[4];
    Player_Mood p_5;
    p_5.currentConfidence = p5.confidence;
    p_5.currentHonesty = p5.honesty;
    p_5.streak = 0;
    
    Player p6;
    p6.name = "popo";
    p6.balance = 10000;
    p6.confidence = 0;
    p6.honesty = 100;
    p6.hand = player_hand[5];
    Player_Mood p_6;
    p_6.currentConfidence = p6.confidence;
    p_6.currentHonesty = p6.honesty;
    p_6.streak = 0;
    
    
    DebugHand(p1);
    DebugHand(p2);
    DebugHand(p3);
    DebugHand(p4);
    DebugHand(p5);
    DebugHand(p6);
    
    Final(p1 , p2);
        
    Player_Mood_In_Game(p1 , p_1);
    
    Game(p1 , p_1 , p2 , p_2 , p3 , p_3 , p4 , p_4 , p5 , p_5 , p6 , p_6);
    
    
    
    std::cin.get();
}
