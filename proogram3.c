
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    return stack[top--];
}

void evaluatePostfix(char exp[])
{
    int i, a, b, result;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

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
                        printf("Division by zero is not allowed");
                        return;
                    }
                    result = a / b;
                    break;

                default:
                    printf("Invalid operator");
                    return;
            }

            push(result);
        }
    }

    printf("Result = %d", pop());
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    evaluatePostfix(exp);

    return 0;
}
