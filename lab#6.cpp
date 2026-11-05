/////////////////////////////////////////////////////////////////////
// Name: Ashley Villela
// Date: 11/4/26
// Class: CSCI 1470.0X
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: Spell checker (Phase 1)
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

bool getData(ifstream &iFile, string a[], int max);
void initArr(string a[], int max);
int sumOfWords(string a[], int max);
void printArr(string a[], int max);

const bool DEBUG = false;

int main()
{
    const int MAX = 1000;
    ifstream inFile;
    string arr[MAX];
    string words;
    int count;
    
    inFile.open("dictionary.txt");
    
    cout << setfill('*') << setw(22) << "*" << endl;
    cout << "    SpElL cHeCk :) " << endl;
    cout << setfill('*') << setw(22) << "*" << endl;
    
    auto start = high_resolution_clock::now();
    
    initArr(arr, MAX);
    
    if(DEBUG)
    {
           // record time before execution
        auto end = high_resolution_clock::now();
        duration<double> elapsed = (end - start) * 1000000000;
        cout << endl << "DEBUG: Initialization took " << elapsed.count() << " microseconds." << endl;
        auto start = high_resolution_clock::now();
    }
    
    getData(inFile, arr, MAX);
    
    if(DEBUG)
    {
        auto end = high_resolution_clock::now();
        duration<double> elapsed = (end - start) * 1000000000;        
        cout << "DEBUG: Loading took " << elapsed.count() << " microseconds." << endl;
        auto start = high_resolution_clock::now();
    }
    
    if(DEBUG)
    {
        cout << endl;
        printArr(arr, MAX);
        auto end = high_resolution_clock::now();
        duration<double> elapsed = (end - start) * 1000000000;
        cout << endl << "DEBUGGING: Printing took " << elapsed.count() << " microseconds." << endl;
        auto start = high_resolution_clock::now();
    }
    count = sumOfWords(arr, MAX);
    
    
    cout << endl << "Loaded " << count << " words from the dictionary!" << endl;
    
    if(DEBUG)
    {
        auto end = high_resolution_clock::now();
        duration<double> elapsed = (end - start) * 1000000000;
        cout << endl << "DEBUGGING: Word count took " << elapsed.count() << " microseconds." << endl;
    }
    
    return 0;
}

void initArr(string a[], int max)
{
    for(int i = 0; i < max; i++)
    {
        a[i] = "";
    }
}

bool getData(ifstream &iFile, string a[], int max)
{
    int counter = 0;
    
    if(!iFile)
    {
        return false;
    }
    while(counter < max && iFile >> a[counter])
    {
        counter++;
    }
    iFile.close();
    
    return true;
}


int sumOfWords(string a[], int max)
{
    int counter = 0;

    for(int i = 0; i < max; i++)
    {
        if(a[i] != "")
        {
            counter++;
        }
    }
    return counter;
}

void printArr(string a[], int max)
{
    for(int i = 0; i < max; i++)
    {
        cout << a[i] << endl;
    }
}


