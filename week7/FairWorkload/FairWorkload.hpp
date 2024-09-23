#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class FairWorkload {
public:
    int getMostWork(vector<int> folders, int workers) {
        int low = *max_element(folders.begin(), folders.end());
        int high = accumulate(folders.begin(), folders.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isFeasible(folders, workers, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

private:
    bool isFeasible(const vector<int>& folders, int workers, int maxWorkload) {
        int requiredWorkers = 1;
        int currentLoad = 0;

        for (int foldersInCabinet : folders) {
            if (currentLoad + foldersInCabinet <= maxWorkload) {
                currentLoad += foldersInCabinet;
            } else {
                requiredWorkers++;
                currentLoad = foldersInCabinet;
                if (requiredWorkers > workers) {
                    return false;
                }
            }
        }

        return true;
    }
};