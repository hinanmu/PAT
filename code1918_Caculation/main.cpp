#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priority(char op) {
    switch(op){
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    }
}

int main()
{
    string cal;
    stack<double> num;
    stack<char> op;

    cin>>cal;
    for(int i = 0; i < cal.length();) {
        double numm = 0;
        if(cal[i] >= '0' && cal[i] <= '9') {
            numm = cal[i++] - '0';
            while(i < cal.length() && cal[i] >= '0' && cal[i] <= '9') {
                numm = numm * 10 + cal[i++] - '0';
                i++;
            }
            num.push(numm);

        } else if (cal[i] != ' '){

            while(!op.empty() && priority(cal[i]) <= priority(op.top())) {
                double num1 = num.top();
                num.pop();
                double num2 = num.top();
                num.pop();

                switch(op.top()) {
                case '+':
                    num.push(num1 + num2);
                    break;
                case '-':
                    num.push(num1 - num2);
                    break;
                case '*':
                    num.push(num1 * num2);
                    break;
                case '/':
                    num.push(num1 / num2);
                    break;
                }
                op.pop();
            }
            op.push(cal[i]);
            i++;
        }else if(cal[i] == ' '){
            i++;
        }

    }
    while(!op.empty()) {
        double num1 = num.top();
        num.pop();
        double num2 = num.top();
        num.pop();

        switch(op.top()) {
        case '+':
            num.push(num1 + num2);
            break;
        case '-':
            num.push(num1 - num2);
            break;
        case '*':
            num.push(num1 * num2);
            break;
        case '/':
            num.push(num1 / num2);
            break;
        }
        op.pop();
    }

    printf("%.2f",num.top());
    return 0;
}
