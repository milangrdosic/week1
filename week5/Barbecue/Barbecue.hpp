#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Barbecue {
public:
    int eliminate(int n, vector<int> voter, vector<int> excluded) {
        map<int, int> votesReceived; 
        map<int, int> votesCast;     

        for (int i = 0; i < n; i++) {
            votesReceived[i] = 0;
            votesCast[i] = 0;
        }

        for (size_t i = 0; i < voter.size(); i++) {
            votesReceived[excluded[i]]++;
            votesCast[voter[i]]++;
        }

        int maxVotes = -1, maxVoted = -1, maxIdx = -1;
        for (int i = 0; i < n; i++) {
            if (votesReceived[i] > maxVotes ||
                (votesReceived[i] == maxVotes && votesCast[i] > maxVoted) ||
                (votesReceived[i] == maxVotes && votesCast[i] == maxVoted && (maxIdx == -1 || i < maxIdx))) {
                maxVotes = votesReceived[i];
                maxVoted = votesCast[i];
                maxIdx = i;
            }
        }

        return maxIdx;
    }
};
