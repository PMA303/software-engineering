// Week 3 Portfolio - OO Analysis & Design Introduction C++
// Simple IoT node to keep track of temperature and humidity
// Data queue with a maximum of 10 readings of type integer

#include <iostream>
#include "iotDataQueue.h"

using namespace std;

int main()
{
    iotDataQueue temperature, humidity; //create two queue objects

    temperature.init();
    humidity.init();

    temperature.qput(21);
    humidity.qput(19);

    temperature.qput(20);
    humidity.qput(18);

    temperature.qput(22);
    humidity.qput(17);

    temperature.qput(16);
    humidity.qput(16);

    temperature.qput(23);
    humidity.qput(20);

    temperature.qput(24);
    humidity.qput(22);

    temperature.qput(21);
    humidity.qput(19);

    temperature.qput(20);
    humidity.qput(18);

    temperature.qput(22);
    humidity.qput(17);

    temperature.qput(19);
    humidity.qput(16);

    cout << "Contents of Temperature queue: ";
    for (int i=0; i<9; i++){
    cout << temperature.qget() << " ";
    }
    cout << temperature.qget() << "\n";

    cout << "Contents of Humidity queue: ";
    for (int i=0; i<9; i++){
    cout << humidity.qget() << " ";
    }
    cout << humidity.qget() << "\n ";
    return 0;
}
