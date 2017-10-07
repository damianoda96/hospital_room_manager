/*
Deven Damiano
dad152
Project4
Program gives the layout of a hospital and allows user to add patients
*/

#include <iostream>
#include <fstream>
#include <string>
#include "readFile.hpp"

void readFile(char[][8]);
void displayGrid(char[][8]);
void checkOuts(char[][8]);
void transfers(char[][8]);
void userInput(char[][8], int&, int&);
void newPatients(char[][8], int);
void gridSearch(char[][8]);

using namespace std;

int main()
{
    char roomArray[5][8];
    int newPatientNum;
    int newPatientCounter = 0;

    readFile(roomArray);
    displayGrid(roomArray);
    checkOuts(roomArray);
    transfers(roomArray);
    displayGrid(roomArray);
    userInput(roomArray, newPatientNum, newPatientCounter);
    newPatients(roomArray, newPatientNum);
    displayGrid(roomArray);

    gridSearch(roomArray);

    return 0;
}

void displayGrid(char roomArray[5][8])
{
    int counter = 0;
    bool hasCheckouts = false;

    cout << "---------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            counter++;

            if (roomArray[i][j] == '0')
            {
                cout << "V ";
            }
            else if (roomArray[i][j] == '1')
            {
                cout << "C ";
                hasCheckouts = true;
            }
            else if (roomArray[i][j] == '2')
            {
                cout << "O ";
            }
            else if (roomArray[i][j] == '3')
            {
                cout << "W ";
            }
            else if (roomArray[i][j] == '4')
            {
                cout << "T ";
            }
            else
            {
                cout << "X ";
            }

            if (counter == 8)
            {
                counter = 0;
                cout << endl;
            }
        }
    }

    cout << "---------------" << endl;

    if(hasCheckouts)
    {
        cout << "Grid Loaded" << endl;
    }
    else if(!hasCheckouts)
    {
        cout << "Checkouts and Transfers Completed" << endl << endl;
    }
}

void checkOuts(char roomArray[5][8])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (roomArray[i][j] == '1')
            {
                roomArray[i][j] = '0';

            }
        }
    }

}

void transfers(char roomArray[5][8])
{
    char ** dynamicArray;
    char * vacancyArray;

    bool roomsToFill;

    int vacancyAmount = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (roomArray[i][j] == '0')
            {
                vacancyAmount++;
            }
        }
    }

    dynamicArray = new char *[vacancyAmount];

    if (vacancyAmount > 0)
    {
        vacancyAmount = 0;
        roomsToFill = true;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (roomArray[i][j] == '0')
                {
                    dynamicArray[vacancyAmount] = &roomArray[i][j];
                    vacancyAmount += 1;
                }
            }
        }
    }

    vacancyAmount = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (roomArray[i][j] == '4')
            {
                *dynamicArray[vacancyAmount] = '2';
                vacancyAmount += 1;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (roomArray[i][j] == '4')
            {
                roomArray[i][j] = '0';
            }
        }
    }



}


void userInput(char roomArray[5][8], int &newPatientNum, int &newPatientCounter)
{
    bool isValid = true;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (roomArray[i][j] == '0')
            {
                newPatientCounter++;
            }
        }
    }

    cout << "Please enter the number of new patients, from 0 up to " << newPatientCounter << ": ";
    cin >> newPatientNum;

    while(cin.fail() || newPatientNum < 0 || newPatientNum > newPatientCounter)
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter the number of new patients, from 0 up to " << newPatientCounter << ": ";
        cin >> newPatientNum;


    }


}

void newPatients(char roomArray[5][8], int newPatientNum)
{
    int fillCounter = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (roomArray[i][j] == '0' && fillCounter < newPatientNum)
            {
                roomArray[i][j] = '2';
                fillCounter++;
            }
        }
    }
}

void gridSearch(char roomArray[5][8])
{
    cout << "The nurse stations are located on floor and room: ";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(roomArray[j][i] == '3')
            {
                cout << j+1 << "," << i+1 << " ";
            }
        }
    }

    cout << endl;

    cout << "The utility rooms are located on floor and room: ";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(roomArray[i][j] == '5')
            {
                cout << i+1 << "," << j+1 << " ";
            }
        }
    }
}





