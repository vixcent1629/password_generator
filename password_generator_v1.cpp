#include <time.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <filesystem>
#include <stdio.h>
//#include "dataInput.h"

using namespace std;
    //character library 
    const char charList[] = "0123456789!@#$%^&*_qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

// calculating password complexity
// E = L * log(R) / log(2)
// E = entropy; R = char library size; L = max password length
// source: https://www.omnicalculator.com/other/password-entropy
 double entropyCalc(int poolSize, int *length)
{
    float entropy = 0;
    entropy = *length * log(72) / log(2);

    return entropy;
}

//void dataInput(string , int , int ) {};

int main() {
    int length = 0;
    int min_length = 0;
    string site_name = "";

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

    srand(time(0));
    cout << "Generated password for " << site_name << " :" << endl; 
    for (int i=0; i<length;i++) {
        cout << charList[rand() % (length)];
    }
    cout << "\n Entropy bits: " << entropyCalc(sizeof(charList), &length);

    return 0;  
}

