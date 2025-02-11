//edits to be made
//1)blank tiles
//2)point distribution in the map
//3)first to place in the middle
//https://www.google.com/search?q=how+to+start+scrabble+game&sca_esv=ba58619d07deea40&sxsrf=ADLYWIJgAnnHVIEWkpdR13CiWtVI-gSlsQ%3A1734129168732&ei=ELZcZ7WsLOuPxc8P8ZG8uAU&ved=0ahUKEwi19OLI5qWKAxXrR_EDHfEID1cQ4dUDCA8&uact=5&oq=how+to+start+scrabble+game&gs_lp=Egxnd3Mtd2l6LXNlcnAiGmhvdyB0byBzdGFydCBzY3JhYmJsZSBnYW1lMgUQABiABDIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHkjUYVCOFVjLYHACeACQAQCYAb8BoAGEFaoBBDAuMjC4AQPIAQD4AQGYAhGgAokQwgIHECMYsAMYJ8ICChAAGLADGNYEGEfCAgYQABgHGB7CAgcQABiABBgKwgIHEAAYgAQYDcICCRAAGIAEGAoYDcICCBAAGAcYCBgewgIIEAAYCBgNGB7CAgQQABgewgIGEAAYCBgewgILEAAYgAQYkQIYigXCAgsQABiABBiGAxiKBcICCBAAGIAEGKIEwgIFEAAY7wWYAwCIBgGQBgqSBwQyLjE1oAeYjwE&sclient=gws-wiz-serp#fpstate=ive&vld=cid:a6f7e61b,vid:swlg3vQXboE,st:0
#include<bits/stdc++.h>
using namespace std;

class board;
class Player;
vector<int> winner(deque<Player> deque1);
int numOfPlayers = 0;

vector<pair<char, int>> letters()
{
    vector<pair<char, int>> scrabbleTiles;

    // Add tiles to the vector
    //scrabbleTiles.emplace_back(' ', 0); // Blank tile x2
    //scrabbleTiles.emplace_back(' ', 0);
    // Add 1-point tiles
    scrabbleTiles.insert(scrabbleTiles.end(), 12, {'E', 1});
    scrabbleTiles.insert(scrabbleTiles.end(), 9, {'A', 1});
    scrabbleTiles.insert(scrabbleTiles.end(), 9, {'I', 1});
    scrabbleTiles.insert(scrabbleTiles.end(), 8, {'O', 1});
    scrabbleTiles.insert(scrabbleTiles.end(), 6, {'N', 1});
    scrabbleTiles.insert(scrabbleTiles.end(), 6, {'R', 1});
    scrabbleTiles.insert(scrabbleTiles.end(), 6, {'T', 1});
    scrabbleTiles.insert(scrabbleTiles.end(), 4, {'L', 1});
    scrabbleTiles.insert(scrabbleTiles.end(), 4, {'S', 1});
    scrabbleTiles.insert(scrabbleTiles.end(), 4, {'U', 1});
    // Add 2-point tiles
    scrabbleTiles.insert(scrabbleTiles.end(), 4, {'D', 2});
    scrabbleTiles.insert(scrabbleTiles.end(), 3, {'G', 2});
    // Add 3-point tiles
    scrabbleTiles.insert(scrabbleTiles.end(), 2, {'B', 3});
    scrabbleTiles.insert(scrabbleTiles.end(), 2, {'C', 3});
    scrabbleTiles.insert(scrabbleTiles.end(), 2, {'M', 3});
    scrabbleTiles.insert(scrabbleTiles.end(), 2, {'P', 3});
    // Add 4-point tiles
    scrabbleTiles.insert(scrabbleTiles.end(), 2, {'F', 4});
    scrabbleTiles.insert(scrabbleTiles.end(), 2, {'H', 4});
    scrabbleTiles.insert(scrabbleTiles.end(), 2, {'V', 4});
    scrabbleTiles.insert(scrabbleTiles.end(), 2, {'W', 4});
    scrabbleTiles.insert(scrabbleTiles.end(), 2, {'Y', 4});
    // Add 5-point tiles
    scrabbleTiles.emplace_back('K', 5);
    // Add 8-point tiles
    scrabbleTiles.emplace_back('J', 8);
    scrabbleTiles.emplace_back('X', 8);
    // Add 10-point tiles
    scrabbleTiles.emplace_back('Q', 10);
    scrabbleTiles.emplace_back('Z', 10);
    //Shuffle not yet studied
    random_device rd;
    mt19937 gen(rd());
    shuffle(scrabbleTiles.begin(), scrabbleTiles.end(), gen);
    //Print to test
    //for(auto& tile:scrabbleTiles) cout << "(" << tile.first << ", " << tile.second << ") ";
    cout<<endl;
    return scrabbleTiles;
}

unordered_set<string> loadDictionary(const string& filename) {
    unordered_set<std::string> wordSet;
    ifstream file(filename);
    string word;

    if (!file.is_open()) {
        throw runtime_error("Could not open the file: " + filename);
    }

    while (file >> word) {
        wordSet.insert(word);
    }
    return wordSet;
}

bool isValidWord(string word, const unordered_set<string>& dictionary)
{
    for(int i = 0 ; i < word.size() ; i++)
    {
        word[i] = toupper(word[i]);
    }
    return dictionary.find(word) != dictionary.end();
}
unordered_set<string> dictionary = loadDictionary("wordlist.txt");

char LetterToCapital(char x)
{
    if(x >= 'a') x -= 32;
    return x;
}
char LetterToSmall(char x)
{
    if(x < 'a') x += 32;
    return x;
}

class Player {
private:
    struct data {
        string name;
        int score;
        char alignment;
        int turn;
        vector<pair<char, int>> letters;
    }
    data;
public:
    void add_player(string x) {
        data.name = x;
        data.score = 0;
        data.alignment = (numOfPlayers % 2 == 0) ? 'V' : 'H';
        numOfPlayers++;
        data.turn = numOfPlayers;
    }

    void print_score() {
        cout << data.name << "score is: " << data.score << endl;
    }

    void add_score(int x) {
        data.score += x;
    }

    int scores() {
        return data.score;
    }

    char alignments()
    {
        return data.alignment;
    }
    string names()
    {
        return data.name;
    }
    void fill_letters(vector<pair<char, int>> &scrabbleTile)
    {
        while(!scrabbleTile.empty() && data.letters.size() < 7)
        {
            data.letters.push_back(scrabbleTile.back());
            scrabbleTile.pop_back();
        }
    }
    void printLetters()
    {
        cout<<"Your letters || scores:"<<endl;
        for(int i = 0 ; i < 7 ; i++)
        {
            if(i <  data.letters.size())
                cout<<"     "<<data.letters[i].first<<"       ||    "<<data.letters[i].second<<endl;
            else cout<<"             ||    "<<endl;
        }
    }
    bool lettersUsed(string k)//makes sure that used letters are in player's options
    {
        long long sze = k.size();
        vector<int> v1(26,0),v2(26,0);
        vector<char> remove;
        for(int i = 0 ; i < sze ; i++)
        {
            v1[k[i]-'a']++;
            remove.push_back(k[i]);
        }
        for(int i = 0 ; i < 7 ; i++)
        {
            v2[data.letters[i].first-'A']++;
        }
        for(int i = 0 ; i < 26 ; i++)
        {
            if(v1[i] <= v2[i])
            {
                continue;
            }
            else
            {
                cout<<"Error : used non owned Letters '"<<char('A'+i)<<"'"<<endl;
                return false ;
            }
        }
        removeFromPlayerLetters(remove,sze);
        return true;
    }
    void removeFromPlayerLetters(vector<char> remove , int sze)
    {
        for (int i = 0; i < sze; i++) {
                int k = 0;
                while(char(remove[i]-'a'+'A') != data.letters[k].first)
                   k++;
                data.score+=data.letters[k].second;
                data.letters.erase( data.letters.begin()+k); // Erase the element
        }
    }
};

const int grid_size = 15;//max 26

class board
{
private:
    char cell[grid_size][grid_size];
    vector<int> scores = {
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // E, A, I, O, N, R, T, L, S, U
            2, 2,                          // D, G
            3, 3, 3, 3,                    // B, C, M, P
            4, 4, 4, 4, 4,                 // F, H, V, W, Y
            5,                             // K
            8, 8,                          // J, X
            10, 10                         // Q, Z
    };
public:
    void Set_board()
    {
        for(int i = 0 ; i < grid_size;i++)
        {
            for(int j = 0 ; j < grid_size;j++)
            {
                cell[i][j] = '.';
            }
        }
    }
    void display()
    {
        cout<<"   ";
        for(int i = 0 ; i < grid_size ;i++)
        {
            cout<<char('A'+ i)<<" ";
        }
        cout<<endl;
        for(int i = 0 ;i < 9 && i < grid_size;i++)
        {
            cout<<1+i<<"  ";
            for(int j = 0 ; j < grid_size;j++)
            {
                cout<<cell[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i = 9 ; i < grid_size;i++)
        {
            cout<<1+i<<" ";
            for(int j = 0 ; j < grid_size;j++)
            {
                cout<<cell[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int add_h(string k, int starth,char startv )
    {
        int sze = k.size();
        int score = 0;
        int row = starth;
        int col = startv - 'A';
        if (row < 0 || row >= grid_size || col < 0 || col >= grid_size || col + sze > grid_size) {
            cout << "Error: Word does not fit within the grid horizontally." << endl;
            return -1;
        }
        for (int i = 0; i < sze; i++) {
            if (cell[row-1][col + i] == '.') {
                cell[row-1][col + i] = k[i];
                score+=scores[k[i] - 'a'];
            }
            else if (cell[row - 1][col + i] == LetterToCapital(k[i])) {
                continue;
            }
            else {
                cout << "Error: Conflicting character at position (" << row << ", " <<char(col+i+'A')<< ")." << endl;
                return -1;
            }
        }
        return score;
    }
    int add_v(string k, int starth,char startv )
    {
        int sze = k.size();
        int score = 0;
        int row = starth;
        int col = startv - 'A';
        if (row < 0 || row >= grid_size || col < 0 || col >= grid_size || row + sze > grid_size) {
            cout << "Error: Word does not fit within the grid Vertically." << endl;
            return -1;
        }
        for (int i = 0; i < sze; i++) {
            if (cell[row + i - 1][col] == '.') {
                cell[row + i - 1][col] = k[i];
                score+=scores[k[i] - 'a'];
            }
            else if (cell[row + i - 1][col] == LetterToCapital(k[i])) {
                continue;
            }
            else {
                cout << "Error: Conflicting character at position (" << row+i << ", " <<char(col+'A')<< ")." << endl;
                return -1;
            }
        }
        return score;
    }
    void toCapital()
    {
        for(int i = 0 ; i < grid_size ; i++)
        {
            for(int j = 0 ; j < grid_size ; j++)
            {
                if(cell[i][j] >= 'a' && cell[i][j] <= 'z') cell[i][j] = LetterToCapital(cell[i][j]);
            }
        }
    }
    string colectSmall()
    {
        string k;
        for(int i = 0 ; i < grid_size ; i++)
        {
            for(int j = 0 ; j < grid_size ; j++)
            {
                if(cell[i][j] >= 'a' && cell[i][j] <= 'z') k += cell[i][j];
            }
        }
        return k;
    }
    void deleteSmall()
    {
        for(int i = 0 ; i < grid_size ; i++)
        {
            for(int j = 0 ; j < grid_size ; j++)
            {
                if(cell[i][j] >= 'a' && cell[i][j] <= 'z') cell[i][j] = '.';
            }
        }
    }
    bool check()
    {
        string k;
        for(int i = 0 ; i < grid_size ; i++)
        {
            for(int j = 0 ; j < grid_size ; j++)
            {
                if(cell[i][j] != '.')
                {
                    k.push_back(LetterToSmall(cell[i][j]));
                }
                else
                {
                    if( k.size() > 1  && !isValidWord( k, dictionary))
                    {
                        cout<<"Invalid word "<<k<<endl;
                        return false;
                    }
                        k.clear();
                }
            }
            if(k.size() > 1 && !isValidWord( k, dictionary))
            {
                cout<<"Invalid word "<<k<<endl;
                return false;
            }
        }
        k.clear();
        for(int i = 0 ; i < grid_size ; i++)
        {
            for(int j = 0 ; j < grid_size ; j++)
            {
                if(cell[j][i] != '.')
                {
                    k.push_back(LetterToSmall(cell[j][i]));
                }
                else
                {
                    if(k.size() > 1 && !isValidWord( k, dictionary))
                    {
                        cout<<"Invalid word "<<k<<endl;
                        return false;
                    }
                        k.clear();
                }
            }
            if(k.size() > 1 && !isValidWord( k, dictionary) )
            {
                cout<<"Invalid word "<<k<<endl;
                return false;
            }
        }
        return true;
    }
    bool ruleCon()//checks if its concentrated right
    {
        for(int i = 0 ; i < grid_size; i++)
        {
            for(int j = 0 ; j < grid_size ; j++)
            {
                if(cell[i][j]<=122 && cell[i][j]>=97)//if small
                {
                    if(i > 0)
                    {
                        for (int k = j - 1; k < 3+j-1; k++)
                        {
                           if(k >= 0 && cell[i-1][k]<=90 && cell[i-1][k]>=65)
                           {
                                return true;
                           }
                        }
                    }
                    if(i+1 < grid_size)
                    {
                        for (int k = j - 1; k < 3+j-1; k++)
                        {
                            if(k >= 0 && cell[i+1][k]<=90 && cell[i+1][k]>=65)
                            {
                                return true;
                            }
                        }
                    }
                    if(cell[i][j+1]<=90 && cell[i][j+1]>=65)
                    {
                        return true;
                    }
                    if(cell[i][j-1]<=90 && cell[i][j-1]>=65)
                    {
                        return true;
                    }
                }
            }
        }
        cout<<"Error your new word should touch old words"<<endl;
        return false;
    }
};

vector<int> winner(deque<Player> deque1)//returns index of winners
{
    int max = 0;
    int r = 0;
    int sze = deque1.size();
    for(int i = 0 ; i < sze ; i++)
    {
        if(deque1[max].scores() < deque1[i].scores()) {
            max = i;
            r = 1;
        }
        else if(deque1[max].scores() == deque1[i].scores())
        {
            r++;
        }
    }
    vector<int> ans;
    for(int i = 0 ; r > 0 && i < sze ; i++)
    {
        if(deque1[max].scores() == deque1[i].scores()) {
            ans.push_back(i);
            r--;
        }
    }
    return ans;
}

int main(){
    vector<pair<char, int>> scrabbleTiles = letters();
    cout<<"Enter number of Players: ";
    int numOfPlayers;
    cin>>numOfPlayers;
    cout<<endl;
    while(numOfPlayers < 2 || numOfPlayers > 4)
    {
        cout<<"Invalid entry, number of players must be more than 1 & less than 5"<<endl<<"Enter num of Players: ";
        cin>>numOfPlayers;
        cout<<endl;
    }
    deque<Player> deque1;
    for(int i = 1 ; i <= numOfPlayers ; i++)
    {
        string name;
        cout<<"Enter player "<<i<<" name: ";
        cin>>name;
        cout<<endl;
        Player player;
        player.add_player(name);
        player.fill_letters(scrabbleTiles);
        deque1.push_back(player);
    }
    int turn = 0;
    board game;
    game.Set_board();
    bool gameEnd = false;
    bool first = true;
    while(!gameEnd)
    {
        cout<<"If you need to end game now press 1 else press 2: ";
        int l;cin>>l;
        bool retry = false;
        cout<<endl;
        if(l == 1)
        {
            gameEnd = true;
        }
        else if (l == 2)
        {
            game.display();
            if(numOfPlayers == turn) turn = 0;
            int starth;char startv;string word;
            deque1[turn].fill_letters(scrabbleTiles);
            if(deque1[turn].alignments() == 'H')
            {
                do {
                    deque1[turn].printLetters();
                    cout << "Please Your word " << deque1[turn].names() << " :";
                    cin >> word;
                    for(int i = 0 ; i < word.size() ; i++)
                    {
                        word[i] = LetterToSmall(word[i]);
                    }
                    while(!isValidWord( word, dictionary))
                    {
                        cout<<"invalid word"<<endl;
                        cout << "Please Your word " << deque1[turn].names() << " :";
                        cin >> word;
                    }
                    cout << endl;
                    cout << "Please Your start horizontally " << deque1[turn].names() << " :";
                    cin >> starth;
                    while(starth <= 0 || starth > grid_size)
                    {
                        cout<<"invalid index"<<endl;
                        cout << "Please Your start horizontally " << deque1[turn].names() << " :";
                        cin >> starth;
                    }
                    cout << endl;
                    cout << "Please Your start vertically " << deque1[turn].names() << " :";
                    cin >> startv;
                    startv = LetterToCapital(startv);
                    while(startv > 90 || startv < 65 || startv- 65 >= grid_size)//later function
                    {
                        cout<<"invalid index"<<endl;
                        cout << "Please Your start horizontally " << deque1[turn].names() << " :";
                        cin >> startv;
                        startv = LetterToCapital(startv);
                    }
                    cout << endl;
                    for(int i = 0 ; i < word.size() ; i++)
                    {
                        word[i] = LetterToSmall(word[i]);
                    }
                    int newScore = game.add_h(word, starth, startv);
                    newScore = (game.check())? newScore:-2;
                    bool noc;
                    if(!first) noc = game.ruleCon();
                    else noc = true;
                    string k = game.colectSmall();
                    if (newScore == -1) {
                        retry = true;
                    }
                    else if(!noc && !first)
                    {
                        retry = true;
                        game.deleteSmall();
                    }
                    else if(!deque1[turn].lettersUsed(k))
                    {
                        retry = true;
                        game.deleteSmall();
                    }
                    else if(newScore == 0)
                    {
                        cout<<"you didn't add any new letter"<<endl;
                        retry = true;
                    }
                    else if(newScore == -2)
                    {
                        retry = true;
                        game.deleteSmall();
                    }
                    else
                    {
                        retry = false;
                        cout<<"New score for "<<deque1[turn].names()<<" is "<<deque1[turn].scores()<<endl;
                        game.toCapital();
                    }
                }while(retry);
            }
            else
            {
                do {
                    deque1[turn].printLetters();
                    cout << "Please Your word " << deque1[turn].names() << " :";
                    cin >> word;
                    for(int i = 0 ; i < word.size() ; i++)
                    {
                        word[i] = LetterToSmall(word[i]);
                    }
                    while(!isValidWord( word, dictionary))//later function
                    {
                        cout<<"invalid word"<<endl;
                        cout << "Please Your word " << deque1[turn].names() << " :";
                        cin >> word;
                    }
                    cout << endl;
                    cout << "Please Your start horizontally " << deque1[turn].names() << " :";
                    cin >> starth;
                    starth = LetterToCapital(starth);
                    while(starth <= 0 || starth > grid_size)
                    {
                        cout<<"invalid index"<<endl;
                        cout << "Please Your start horizontally " << deque1[turn].names() << " :";
                        cin >> starth;
                    }
                    cout << endl;
                    cout << "Please Your start vertically " << deque1[turn].names() << " :";
                    cin >> startv;
                    startv = LetterToCapital(startv);
                    while(startv > 90 || startv < 65 || startv- 65 >= grid_size)
                    {
                        cout<<"invalid index"<<endl;
                        cout << "Please Your start horizontally " << deque1[turn].names() << " :";
                        cin >> startv;
                        startv = LetterToCapital(startv);

                    }
                    cout << endl;
                    for(int i = 0 ; i < word.size() ; i++)
                    {
                        word[i] = LetterToSmall(word[i]);
                    }
                    int newScore = game.add_v(word, starth, startv);
                    newScore = (game.check())? newScore:-2;
                    bool noc;
                    if(!first) noc = game.ruleCon();
                    else noc = true;
                    string k = game.colectSmall();
                    if (newScore == -1) {
                        retry = true;
                    }
                    else if(!noc && !first)
                    {
                        retry = true;
                        game.deleteSmall();
                    }

                    else if(newScore == 0)
                    {
                        cout<<"you didn't add any new letter"<<endl;
                        retry = true;
                    }
                    else if(newScore == -2)
                    {
                        retry = true;
                        game.deleteSmall();
                    }
                    else if(!deque1[turn].lettersUsed(k))
                    {
                        retry = true;
                        game.deleteSmall();
                    }
                    else
                    {
                        retry = false;
                        cout << "New score for " << deque1[turn].names() << " is " << deque1[turn].scores() << endl;
                        game.toCapital();
                    }
                }while(retry);
            }
            first = false;
            cout<<"New board "<<endl;
            game.display();
            turn++;
        }
        else
        {
            cout<<"Invalid entry "<<endl;
        }
    }
    vector<int> winners = winner(deque1);
    if(winners.size() == 1)
    {
        cout<<"And the winner is....."<<endl<<deque1[winners[0]].names()<<" with a total score of "<<deque1[winners[0]].scores();
    }
    else
    {
        cout<<"And it is a tie between....."<<endl;
        for(int i = 0 ; i < winners.size() ; i++)
        {
            cout<<deque1[winners[i]].names()<<" with a total score of "<<deque1[winners[i]].scores()<<endl;
        }
    }
    return 0;
}