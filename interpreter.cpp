// Roberto Caamano
// Recitation Assignment 2

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    ifstream inFile;
    string fileName;

    // VARS
    string data;
    int numLines = 0;
    int numComments = 0;
    string maxLength = "";
    string maxWord;
    int wordCount = 0;
    int realLines = 0;

    cout << "Enter the name of a file to read from: \n" << endl;
    cin >> fileName;

    // Open file in read mode
    inFile.open(fileName.c_str(), ios::in);

    // See if file can be opened
    if(inFile.fail()){
        cerr << "File cannot be opened " << fileName << endl;
        exit(EXIT_FAILURE);
    }
    
    string line;
    // Go thru lines in file
    while(getline (inFile, line)){
        ++numLines;
        // Check for comments
        if(line.empty()){   
            continue;
        }
        if(line.find("//") == 0 || line.find("#") == 0){
            // Increment num of commented lines
            numComments++;
            continue;
        }
        else{
            // Compare data length to current max line length, adjust maxLength
            if(line.length() > maxLength.length()){
                maxLength = line;
            }

            // Get number of words on current line, increase wordCount, look for maxWord
            stringstream s(line);
            string word;
            
            int count = 0;
            while (s >> word){
                count++;
                if(word.length() > maxWord.length()){
                    maxWord = word;
                }
            }

            wordCount+=count;    
        }
    }

    // Close file
    inFile.close();

    // Calculate final number of "real lines"
    realLines = numLines - numComments;

    // Show results
    cout << "Total Number of Lines: "<< numLines << endl;
    cout << "Number of non-commented lines: "<< realLines << endl;
    cout << "Line of Maximum Length: \""<< maxLength << "\"" << endl;
    cout << "Number of Words: "<< wordCount << endl;
    cout << "Word of Maximum Length: \""<< maxWord << "\"" << endl;

    return 0;
}
