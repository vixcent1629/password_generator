//For rand() function to generate based on local machine time
#include <time.h>
//For implementing log() for password entropy formula
#include <cstdlib>
#include <math.h>
//For basic syntax & file operations
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ostream>

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

void dataInput(string*, int*, int*);
void dataOutput(string*, int*, char);

int main() {
    int length = 0;
    int min_length = 0;
    string site_name = "";
    int password_array_index;
    char passwordGenerated[password_array_index];

   
    dataInput(&site_name, &min_length, &length);
    password_array_index = length;

    srand(time(0));

    cout << "Generated password for " << site_name << " :" << endl; 
    for (int i=0; i<length;i++) {
        passwordGenerated[i] = charList[rand() % (length)];
        cout << passwordGenerated[i];
    }

    dataOutput(&site_name, &length, passwordGenerated);
    cout << "\n Entropy bits: " << entropyCalc(sizeof(charList), &length);

    return 0;  
}

void dataInput(string* name, int* min, int* ideal)
{
    cout << "Enter site/app name: " << endl;
    cin >> *name;
    do
    {
        cout << "Enter minimum password length: " << endl;
        cin >> *min;
    } while (*min < 0);
    do
    {
        cout << "Enter maximum password length: " << endl;
        cin >> *ideal;
    } while (*ideal <= (*min + 5));
}

void dataOutput(string* site_name, int* ideal, char passwordGenerated) {
    ofstream passwordDump("passwordDump.txt");

    passwordDump << "\n\n";
    passwordDump << *site_name << ": " << endl;
    for (int i=0;i<*ideal;i++) {
        passwordDump << passwordGenerated[i];
    }
    passwordDump << "\n\n";
}

