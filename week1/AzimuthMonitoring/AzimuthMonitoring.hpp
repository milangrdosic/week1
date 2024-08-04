#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class AzimuthMonitoring {
public:
    int getAzimuth(const vector<string>& instructions) {
        int azimuth = 0;

        for (const string& instruction : instructions) {
            stringstream ss(instruction);
            string direction;
            int degrees;

            ss >> direction;

            if (direction == "LEFT" || direction == "RIGHT") {
                ss >> degrees;

                // Ensure degrees is between 1 and 179
                if (degrees < 1 || degrees > 179) {
                    cerr << "Error: Degrees must be between 1 and 179." << endl;
                    continue;
                }

                if (direction == "LEFT") {
                    azimuth = (azimuth - degrees + 360) % 360;
                } else if (direction == "RIGHT") {
                    azimuth = (azimuth + degrees) % 360;
                }
            } else if (direction == "TURN") {
                string turnAround;
                ss >> turnAround; // Read "AROUND"
                if (turnAround == "AROUND") {
                    azimuth = (azimuth + 180) % 360;
                }
            }
        }

        return azimuth;
    }
};
