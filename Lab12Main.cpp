#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Pair.h"
#include "Map.h"
#include "Map_Set.h"
#include "Random-2.h"
#include "Random-2.cpp"
using namespace std;

int main()
{
    Map<string, Pair<float, float>> Capital;
    string City;
    float Longitude;
    float Latitude;
    
    for (int i = 1; i <= 5; i++)
    {
        cout << endl << "Enter the capital: ";
        cin >> City;
        cout << "Enter the longitude: ";
        cin >> Longitude;
        cout << "Enter the latitide: ";
        cin >> Latitude;

        Capital[City] = Pair(Longitude, Latitude);
    }

    cout << endl << "Latitude and longitude were entered for these capitals: " << endl;
    Set<string> Key = Capital.keys();
    Set<string>::iterator itr = Key.begin();

    for (; itr != Key.end(); itr++)
    {
        string cap = *itr;
        float Long = Capital[cap].first;
        float Lat = Capital[cap].second;

        cout << fixed << setprecision(2) << left << setw(20) << *itr << setw(10) << Capital[*itr].first << setw(10) << Capital[*itr].second << endl;
    }
    return 0;
}