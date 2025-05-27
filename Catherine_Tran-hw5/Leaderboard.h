#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

class Leaderboard {
public:
    void addOrUpdatePlayer(const std::string &username, int score);
    void removePlayer(const std::string &username);
    std::vector<std::pair<std::string, int>> getTopN(int N) const;

private:
    std::map<std::string, int> leaderbrd;
};
#endif