#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        stack<char> stck;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ')') {
                string result = "";
                bool braces = true;
                char frontPr = 0, insidePr = CHAR_MAX, back = 0, backPr = 0;
                if (i + 1 < str.size() && str[i + 1] >= '*' && str[i + 1] <= '/') // '*' < '+' < '-' < '/'
                    if (str[i + 1] == '+' || str[i + 1] == '-') frontPr = 1;
                    else frontPr = 2;
                int bracesToStay = 0;
                while (true) {
                    char top = stck.top();
                    if (top == ')') bracesToStay++;
                    if (top == '(')
                        if (bracesToStay) bracesToStay--;
                        else {
                            stck.pop();
                            if (stck.size()) {
                                back = stck.top();
                                if (back >= '*' && back <= '/')
                                    if (back == '+' || back == '-') backPr = 1;  
                                    else backPr = 2;  
                            }
                            if (frontPr <= insidePr)
                                if (backPr < insidePr) braces = false;
                                else if (backPr == insidePr && (back == '*' || back == '+'))
                                    braces = false;
                            if (braces) result = '(' + result + ')';
                            for (int i = 0; i < result.size(); i++) 
                                stck.push(result[i]);
                            break;
                        }
                    if (insidePr > 2 && (top == '*' || top == '/')) insidePr = 2;
                    if (!bracesToStay && (top == '+' || top == '-')) insidePr = 1;
                    result = top + result;
                    stck.pop();
                }
                continue;
            }
            stck.push(str[i]);
        }
        string result = "";
        while (stck.size()) {
            result = stck.top() + result;
            stck.pop();
        }
        cout << result << endl;
    }
}