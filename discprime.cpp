#include <iostream>
#include <vector>



void printPrimesLessThanN(unsigned long long n)
{
    vector<bool> table(n, true);

    for (unsigned long long p = 2; p * p < n; p++) {
        if (table[p] == true) {
            for (unsigned long long i = p * p; i < n; i += p)
                table[i] = false;
        }
    }

    for (unsigned long long p = 2; p < n; p++)
        if (table[p])
            cout << p << " ";
}

int main() {
    unsigned long long integer;

    while (true) {
        cout << "Enter integer: ";
        if (cin >> integer) {
            break;
        } else {
            cout << "Enter a valid integer value!\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    cout << "Following prime numbers are smaller than given integer: \n";

    printPrimesLessThanN(integer);

    return EXIT_SUCCESS;
}