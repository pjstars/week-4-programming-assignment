// week 4 programming assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
//#include "windows.h

//using namespace
using namespace std;
int main(int argc, char* argv[])
{

    // The executable name for one argument?
    if (argc < 2)
    {
        std::cout << "Error with input agrs.." << std::endl;
        return 1;
    }
    // For debugging purposes only
    for (int i = 0; i < argc; i++)
    {
        std::cout << i << ":" << argv[i] << std::endl;
    }
    std::ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile)
    {
        std::cout << "Error with file name.." << std::endl;
        return 1;
    }
    //declare the constants 
    const int headerlen = 50;

    //the welcome message for the program 
    string sTitle = "Welcome to my Letter Count Program";
    int iTitleLen = static_cast<int>(sTitle.length()); //Quell compiler warning. 

    int iFillLen = headerlen - iTitleLen;
    int iFillLenHalf = iFillLen / 2;
    string strFill(iFillLenHalf, '*');

    cout << setfill('*');
    cout << setw(headerlen) << "*" << endl;
    cout << setw(static_cast<std::streamsize>(iTitleLen) + iFillLenHalf) << right << sTitle << strFill << endl;
    cout << setw(headerlen) << "*" << endl << endl;

    cout << setfill(' ');
    std::cout << "Analyzing file " << argv[1] << "..." << std::endl << std::endl;
    char ch;
    int v[8] = { 0 };
    while (inFile)
    {
        inFile.get(ch);
        if (ch == 'A' || ch == 'a')v[0]++;
        if (ch == 'E' || ch == 'e')v[1]++;
        if (ch == 'I' || ch == 'i')v[2]++;
        if (ch == 'O' || ch == 'o')v[3]++;
        if (ch == 'U' || ch == 'u')v[4]++;
        if (ch == 'Y' || ch == 'y')v[5]++;
        if (ch == 'W' || ch == 'w')v[6]++;
        if (ch == 'X' || ch == 'x')v[7]++;
    }
    //ouput 
    int sum = v[0] + v[1] + v[2] + v[3] + v[4]; // +v[5] + v[6] + v[7];
    cout << "The number of A's:" << setw(48) << setfill('.') << v[0] << endl;
    cout << "The number of E's:" << setw(48) << setfill('.') << v[1] << endl;
    cout << "The number of I's:" << setw(48) << setfill('.') << v[2] << endl;
    cout << "The number of O's:" << setw(48) << setfill('.') << v[3] << endl;
    cout << "The number of U's:" << setw(47) << setfill('.') << v[4] << endl;
    cout << "The number of Y's:" << setw(47) << setfill('.') << v[5] << endl;
    cout << "The number of W's:" << setw(47) << setfill('.') << v[6] << endl;
    cout << "The number of X's:" << setw(47) << setfill('.') << v[7] << endl;
    cout << "The vowel count is:" << setw(47) << setfill('.') << sum << endl;

   
        ///////////////////////
        // Work here with open file.....
        ///////////////////////
    inFile.close();
    system("pause");
    return 0;
}