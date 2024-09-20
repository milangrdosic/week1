#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;


class VeryInterestingMovie {
    public:
        int maximumPupils(vector<string> seats) {
            int totalStudents = 0;

            for (const std::string& row : seats) {
                totalStudents += getMaxStudentsInRow(row);
            }
            return totalStudents;
        }

    private:
        int getMaxStudentsInRow(string row) {
            int n = row.size();
            vector<int> notOccupied(n,0);
            vector<int> Occupied(n, INT_MAX);

            if(row[0] == 'Y') {
                notOccupied[0] = 0;
                Occupied[0] = 1;
            } else {
                notOccupied[0] = 0;
                Occupied[0] = INT_MIN;
            }

            for (int i = 1; i < n; i++) {
                if (row[i] == 'Y') {
                    notOccupied[i] = max(notOccupied[i - 1], Occupied[i - 1]);
                    Occupied[i] = notOccupied[i - 1] + 1;
                } else {
                    notOccupied[i] = max(notOccupied[i -1], Occupied[i - 1]);
                    Occupied[i] = INT_MIN;
                }
            }
            return max(notOccupied[n - 1], Occupied[n - 1]);

        }
};