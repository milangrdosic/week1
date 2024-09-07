#include <iostream>
#include <string>

using namespace std;

class GoodHours {
public:
    int howMany(string beforeTime, string afterTime) {
        string HHb = beforeTime.substr(0, 2);
        string MMb = beforeTime.substr(3, 2);
        string HHa = afterTime.substr(0, 2);
        string MMa = afterTime.substr(3, 2);

        int howMany = 0;
        int startHH = stoi(HHb);
        int startMM = stoi(MMb);
        int finishHH = stoi(HHa);
        int finishMM = stoi(MMa);

        if (startHH > finishHH || (startHH == finishHH && startMM > finishMM)) {
            finishHH += 24; 
        }

        for (int i = startHH; i <= finishHH; i++) {
            int currentHour = i % 24;
            for (int j = (i == startHH ? startMM : 0); j <= (currentHour == finishHH % 24 ? finishMM : 59); j++) {
                string I = (currentHour < 10 ? "0" : "") + to_string(currentHour);
                string J = (j < 10 ? "0" : "") + to_string(j);

                int H1 = I[0] - '0';
                int H2 = I[1] - '0';
                int M1 = J[0] - '0';
                int M2 = J[1] - '0';

                if (H1 == H2 * M1 * M2) {
                    howMany++;
                } else if (H1 * H2 == M1 * M2) {
                    howMany++;
                } else if (H1 * H2 * M1 == M2) {
                    howMany++;
                }
            }
        }

        return howMany;
    }
};