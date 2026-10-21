
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char exp[100];
    int stack[100], top = -1;
    int i, a, b, result;

    cout << "Enter postfix expression: ";
    cin >> exp;

    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            stack[++top] = exp[i] - '0';
        }
        else
        {
            if (top < 1)
            {
                cout << "Invalid expression";
                return 0;
            }

            b = stack[top--];
            a = stack[top--];

            switch (exp[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0)
                    {
                        cout << "Division by zero";
                        return 0;
                    }
                    result = a / b;
                    break;

                default:
                    cout << "Invalid operator";
                    return 0;
            }

            stack[++top] = result;
        }
    }

    if (top == 0)
        cout << "Result = " << stack[top];
    else
        cout << "Invalid expression";

    return 0;
}
