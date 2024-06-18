#include <queue>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    void assignScores(priority_queue<int> &high_scores, map<int, int> &score_map, vector<string> &output){
        for(int i=0; i<score_map.size(); i++) {
            int index = score_map[high_scores.top()];
            if(i == 0) {
                output[index] = "Gold Medal";
            } else if(i == 1) {
                output[index] = "Silver Medal";
            } else if(i == 2) {
                output[index] = "Bronze Medal";
            } else {
                output[index] = to_string(i+1);
            }
            high_scores.pop();
        }
        return;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> high_scores;
        map<int, int> score_map;
        vector<string> output(score.size(), "");
        
        for(int i=0; i<score.size(); i++) {
            score_map[score[i]] = i;
            high_scores.push(score[i]);
        }
        assignScores(high_scores, score_map, output);
        
        return output;
    }
};
