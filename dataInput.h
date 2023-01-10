#ifndef dataInput_H
#define dataInput_H

#include <iostream>
#include <stdio.h>

using namespace std;

void dataInput(string site_name, int min_length, int length)
{
    cout << "Enter site/app name: " << endl;
    cin >> site_name;
    do
    {
        cout << "Enter minimum password length: " << endl;
        cin >> min_length;
    } while (min_length < 0);
    do
    {
        cout << "Enter maximum password length: " << endl;
        cin >> length;
    } while (length <= (min_length + 5));
}

#endif