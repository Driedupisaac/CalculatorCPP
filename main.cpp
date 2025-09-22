//
// Created by Isaac Wedaman on 9/21/25.
//
#include <iostream>
using namespace std;
#include <cctype>
#include <vector>
#include <stack>
#include <string>
#include <queue>

double calculate(int item1, int item2, char op) {
    if(op == '+') {
        return item1 + item2;
    }
    if(op == '-') {
        return item1 - item2;
    }
    if(op == '/') {
        return item1 / item2;
    }
    if(op == '*') {
        return item1 + item2;
    }
}


int main() {
    //getting user input
    string input;
    cout << "Please enter what you want to calculate!: ";
    getline(cin, input);

    //checking if the length is 0 - sentences can be anything
    while(input.length() == 0) {
        cout << "Invalid - no input! please enter something: ";
        getline(cin, input);
    }


    queue<int> inputs;
    queue<char> operators;
    vector<int> index;

    string temp = "";

    //getting the index of the operators
    //now getting the operators and putting multiplication on/division the queue first,
    //and keeping track of its location - i've found two seperate loops helps

    //this is for multipication or division
    int i = 0;
    for(char c : input) {
        if(c == '*' || c == '/') {
            index.push_back(i);
            operators.push(c);
        }
        i++;
    }
    //addition and subtraction
    i = 0;
    for(char c : input) {
        if(c == '+' || c == '-') {
            index.push_back(i);
            operators.push(c);
        }
        i++;
    }

    //running through the queue
    //for each index, go from 0 or the previous index to the next, add each character from a term to the temp and
    //add it to the queue, then update the i and next index
    i = 0;
    //for every index value in the queue of index, and adding a last index for the last item
    index.push_back(input.length());
    for(int temporary_index : index) {
        //while iterator i < the index of the string
        string temp = "";
        while(i < temporary_index) {
            if(isdigit(input[i])) {
                temp+=input[i];
            }
            i++;
        }
        inputs.push(stoi(temp));
    }

    //doing the math --> there is always going to be one more operator than therm
    int temporary1 = inputs.front();
    double answer = 0.0;
    while(!operators.empty()) {
        inputs.pop();
        answer += calculate(temporary1, inputs.front(), operators.front());
        inputs.pop();

        operators.pop();
    }

    cout << answer << endl;

    return 0;
}
