
#include <iostream>
using namespace std;

int main()
{
    int stack[100], top = -1;
    int choice, value, i;

    do
    {
        cout << "\n\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (top == 99)
                {
                    cout << "Stack Overflow";
                }
                else
                {
                    cout << "Enter element: ";
                    cin >> value;

                    top++;
                    stack[top] = value;

                    cout << "Element pushed successfully";
                }
                break;

            case 2:
                if (top == -1)
                {
                    cout << "Stack Underflow";
                }
                else
                {
                    cout << "Popped element: " << stack[top];
                    top--;
                }
                break;

            case 3:
                if (top == -1)
                {
                    cout << "Stack is empty";
                }
                else
                {
                    cout << "Stack elements: ";

                    for (i = top; i >= 0; i--)
                    {
                        cout << stack[i] << " ";
                    }
                }
                break;

            case 4:
                cout << "Program terminated";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}
