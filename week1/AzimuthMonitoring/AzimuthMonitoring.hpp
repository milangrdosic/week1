#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class AzimuthMonitoring {
public:
    int getAzimuth(vector<string> instructions) {
        int azimuth = 0;

        for (const string& instruction : instructions) {
            stringstream ss(instruction);
            string direction;
            int degrees;

            ss >> direction;

            if (direction == "LEFT") {
                if (ss >> degrees) {
                    if (degrees < 1 || degrees > 179) {
                        cerr << "Error: Degrees must be between 1 and 179." << endl;
                        continue;
                    }
                    azimuth = (azimuth - degrees + 360) % 360;
                } else {
                    azimuth = (azimuth - 90 + 360) % 360;
                }
            } else if (direction == "RIGHT") {
                if (ss >> degrees) {
                    if (degrees < 1 || degrees > 179) {
                        cerr << "Error: Degrees must be between 1 and 179." << endl;
                        continue;
                    }
                    azimuth = (azimuth + degrees) % 360;
                } else {
                    azimuth = (azimuth + 90) % 360;
                }
            } else if (direction == "TURN") {
                string turnAround;
                ss >> turnAround;
                if (turnAround == "AROUND") {
                    azimuth = (azimuth + 180) % 360;
                }
            } else if (direction == "HALT") {
                return azimuth;
            } else {
                cerr << "Unknown instruction: " << direction << endl;
            }
        }

        return azimuth;
    }
};

