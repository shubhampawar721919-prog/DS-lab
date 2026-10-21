
#include <iostream>
using namespace std;

int main()
{
    int a[100], b[100], c[200];
    int n, m, pos, value, choice, i;

    cout << "Enter number of elements in first array: ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid array size";
        return 0;
    }

    cout << "Enter array elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    do
    {
        cout << "\n\n1. Display array";
        cout << "\n2. Insert element";
        cout << "\n3. Delete element";
        cout << "\n4. Merge two arrays";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Array elements: ";
                for (i = 0; i < n; i++)
                {
                    cout << a[i] << " ";
                }
                break;

            case 2:
                cout << "Enter position (1 to " << n + 1 << "): ";
                cin >> pos;

                if (n == 100 || pos < 1 || pos > n + 1)
                {
                    cout << "Invalid position or array is full";
                }
                else
                {
                    cout << "Enter element to insert: ";
                    cin >> value;

                    for (i = n; i >= pos; i--)
                    {
                        a[i] = a[i - 1];
                    }

                    a[pos - 1] = value;
                    n++;

                    cout << "Element inserted successfully";
                }
                break;

            case 3:
                cout << "Enter position to delete (1 to " << n << "): ";
                cin >> pos;

                if (pos < 1 || pos > n)
                {
                    cout << "Invalid position";
                }
                else
                {
                    for (i = pos - 1; i < n - 1; i++)
                    {
                        a[i] = a[i + 1];
                    }

                    n--;

                    cout << "Element deleted successfully";
                }
                break;

            case 4:
                cout << "Enter number of elements in second array: ";
                cin >> m;

                if (m < 1 || m > 100 || n + m > 200)
                {
                    cout << "Invalid second array size";
                }
                else
                {
                    cout << "Enter second array elements: ";
                    for (i = 0; i < m; i++)
                    {
                        cin >> b[i];
                    }

                    for (i = 0; i < n; i++)
                    {
                        c[i] = a[i];
                    }

                    for (i = 0; i < m; i++)
                    {
                        c[n + i] = b[i];
                    }

                    cout << "Merged array: ";
                    for (i = 0; i < n + m; i++)
                    {
                        cout << c[i] << " ";
                    }
                }
                break;

            case 5:
                cout << "Program terminated";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 5);

    return 0;
}
