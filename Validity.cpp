#include<bits/stdc++.h>
using namespace std;
bool OpeningParenthesis(char ch)
{
    return (ch == '(' || ch == '[' || ch == '{');
}

bool ClosingParenthesis(char ch)
{
    return (ch == ')' || ch == ']' || ch == '}');
}

bool MatchingPair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else
        return false;

}

bool ValidExpression(string expr)
{
    stack<char> s;
    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];
        if (OpeningParenthesis(ch))
        {
            s.push(ch);
        }
        else if (ClosingParenthesis(ch))
        {
            if (s.empty() || !MatchingPair(s.top(), ch))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty();
}
int main()
{
    string expr;
    cout << "Enter an arithmetic expression: ";

    cin >> expr;
    if (ValidExpression(expr))
    {
        cout << "The expression is valid." << endl;
    }
    else
    {
        cout << "The expression is invalid." << endl;
    }
    return 0;
}
