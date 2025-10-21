/*Name: Azena Reid
 *Class: CSCI 240
 * Description:  Reads a string from the user (up to 25 characters)and
 checks whether parentheses, curly braces, and square brackets in a user-entered string are
 properly opened and closed in the correct order, reporting any missing or mismatched symbols.
 * Program: Midterm
 * Date: 15/10/2025
 */



#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    cout << "This program checks for syntax errors involving open-close pair symbols." << endl;

    string input;
    while (true) {
        cout << "Please enter a string (up to 25 characters), with \"quit\" allowing the user to exit the program:" << endl;
        getline(cin, input);

        if (input == "quit") break;

        // Enforce 25-character limit
        if (input.length() > 25) {
            cout << "Error: Input exceeds 25-character limit. Please try again." << endl;
            continue;
        }

        stack<char> symbols;
        bool errorFound = false;
        string errorMessage = "";

        for (int i = 0; i < input.length(); i++) {
            char ch = input[i];

            // Opening symbols are pushed onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                symbols.push(ch);
            }

            // Closing symbols are checked against the top of the stack
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (symbols.empty()) {
                    if (ch == ')')
                        errorMessage = "No opening parenthesis.";
                    else if (ch == '}')
                        errorMessage = "No opening curly-bracket.";
                    else
                        errorMessage = "No opening square-bracket.";
                    errorFound = true;
                    break;
                }

                char top = symbols.top();
                if (!isMatchingPair(top, ch)) {
                    if (ch == ')')
                        errorMessage = "No opening parenthesis.";
                    else if (ch == '}')
                        errorMessage = "No opening curly bracket.";
                    else
                        errorMessage = "No opening square bracket.";
                    errorFound = true;
                    break;
                }
                symbols.pop();
            }
        }

        // If no closing errors but still items in the stack, a closing symbol is missing
        if (!errorFound && !symbols.empty()) {
            char top = symbols.top();
            if (top == '(')
                errorMessage = "No closing parenthesis.";
            else if (top == '{')
                errorMessage = "No closing curly bracket.";
            else
                errorMessage = "No closing square bracket.";
            errorFound = true;
        }

        if (errorFound)
            cout << "There is an error in the above string. " << errorMessage << endl;
        else
            cout << "The above string is correct." << endl;
    }

    return 0;
}
