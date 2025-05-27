#include "Leaderboard.h"
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

void Leaderboard::addOrUpdatePlayer(const std::string &username, int score) {
    leaderbrd[username] = score;
}

void Leaderboard::removePlayer(const std::string &username) {
    std::pair<std::string, int> entry = {username, leaderbrd[username]};
    leaderbrd.erase(username);
}

std::vector<std::pair<std::string, int>> Leaderboard::getTopN(int N) const {
    std::vector<std::pair<std::string, int>> topn;
    std::map<std::string, int>::const_iterator i;
    for (i=leaderbrd.begin(); i!=leaderbrd.end(); i++) {
        std::pair<std::string, int> entry = *i;
        std::vector<std::pair<std::string, int>>::iterator j = topn.begin();
        while (j!=topn.end() && j->second<=entry.second) j++;
        topn.insert(j,entry);
        if (topn.size()>N) topn.pop_back();
    }
    return topn;
}