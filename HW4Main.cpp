#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "Pair.h"
#include "Map.h"
#include "Map_Set.h"
#include "Random.h"
#include "Random.cpp"
using namespace std;

int evaluate(int num);
float Haversine(float long1, float lat1, float long2, float lat2);
bool restart();

int main()
{
    string City;
    float Longitude;
    float Latitude;
    Map<string, Pair<float, float>> Capital;

    ifstream inp;
    inp.open("hw4_input.txt");
    inp >> City;
    while (!inp.fail())
    {
        inp >> Longitude;
        inp >> Latitude;
        Capital[City] = Pair(Longitude, Latitude);
        inp >> City;
    }
    inp.close();

    Set<string> Key = Capital.keys();
    Set<string>::iterator itr = Key.begin();

    bool loop = true;
    while(loop)
    {
        string cap = *itr;
        cout << "Select two capitals from the list below: " << endl;
        for (int i = 1; itr != Key.end(); i++)
        {
            cout << "(" << i << ")\t" << *itr << endl;
            itr++;
        }

        int choice1;
        itr = Key.begin();
        cout << endl << "First capital (1-10): ";
        cin >> choice1;
        choice1 = evaluate(choice1);
        for (int inc = 0; inc < choice1; inc++)
            itr++;
        string cap1 = *itr;

        int choice2;
        itr = Key.begin();
        cout << endl << "Second capital (1-10): ";
        cin >> choice2;
        choice2 = evaluate(choice2);
        for (int inc = 0; inc < choice2; inc++)
            itr++;
        string cap2 = *itr;

        float distance = Haversine(Capital[cap1].first, Capital[cap1].second, Capital[cap2].first, Capital[cap2].second);
        cout << endl << fixed << setprecision(4) << "The distance between " << cap1 << " and " << cap2 << " is " << distance << "KM" << endl;
        itr = Key.begin();

        loop = restart();
    }
    return 0;
}

int evaluate(int num)
{
    if (num > 10)
    {
        num = 10;
        cout << "Invalid entry, defaulting to 10";
    }
    else if (num < 1)
    {
        num = 1;
        cout << "Invalid entry, defaulting to 1";
    }
    else {}

    return num - 1;
}

float Haversine(float long1, float lat1, float long2, float lat2)
{
    float lat1_rad = lat1 * (M_PI / 180);
    float lat2_rad = lat2 * (M_PI / 180);
    float delta_lat_rad = (lat2 - lat1) * (M_PI / 180);
    float delta_long_rad = (long2 - long1) * (M_PI / 180);
    float a = pow(sin(delta_lat_rad/2), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(delta_long_rad/2), 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float haversine = 6371.0 * c;
    return haversine;
}

bool restart()
{
    bool result;
    string answer;
    cout << "Would you like to know more? (y/n) ";
    cin >> answer;
    if (answer == "n")
        result = false;
    else if (answer == "y")
        result = true;
    else
    {
        cout << "Invalid response (y/n) ";
        cin >> answer;
    }

    cout << endl;
    return result;
}