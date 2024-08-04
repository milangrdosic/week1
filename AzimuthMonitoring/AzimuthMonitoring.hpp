    #include <iostream>
    #include <stdlib.h>
    #include <cctype>


    using namespace std;

    class AzimuthMonitoring {
        public:
            int getAzimuth(const vector<string> instructions) {
                int azimuth = 0;

                for (const string& instruction : instructions) {
                    if (instruction == "LEFT") {
                        azimuth = (azimuth - 90 + 360) % 360;
                    } else if (instruction == "RIGHT") {
                        azimuth = (azimuth + 90) % 360;
                    } else if (instruction == "TURN AROUND") {
                        azimuth = (azimuth + 180) % 360;
                    }
                }

                return azimuth;
            }

    };