#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include "utils.h"

/* Tasks:
2.1
Declare a 10-element Y array of integer type. Read data from the keyboard into the table.
a. Calculate the sum of elements greater than zero.
b. Calculate the arithmetic mean of elements less than zero

2.2
Given is an array A with 10 elements of integer type.
a. read the elements of this array from the keyboard,
b. calculate the minimum element and specify how many times it occurred in the array (the function should return two values),
c. print the result in the main() function.

2.3
Declare an X 15-to element array of integers.
Fill the table with random numbers from <5, 30> range. Read a number into the main() function.
Write a function that checks whether a given number appears in an array, and if so, how many times. Write the result in a function
main().

2.4
Write a function that calculates the standard deviation of the arithmetic mean of the data stored in an array.
The standard deviation is the mean square of the deviations from the arithmetic mean. where sr - arithmetic mean
Call for table X (from point 2.1.3).

2.5
Declare two arrays XX and YY n - elements of integer type and array C 4 - elements. Draw
elements of the XX and YY arrays from the range <-10, 10>, the pair (XXi, YYi) means the coordinates of a point on the plane
1. calculate how many points there were in each quadrant of the coordinate system (results stored in table C)
2. write out the drawn tables as follows (XXi, YYi) and below the result table C.

Comments:
1. All tasks should be written in one program, with the possibility to choose the point that we want
realize.
2. The program should run in a loop.
3. All arrays declared in the main() function and passed to the appropriate functions.
4. We print the calculated value in the main() function, except for arrays, which should be printed after
using the appropriate functions.
5. Please do not use the vector class in this program
*/
using namespace std;

const int n = 10;
const int m = 15;

void wstaw( int tab[] )
{
    cout << "\nEnter numbers into array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> tab[i];
    }
}

void wstaw1( int tab[] )
{
    for(int i=0; i<m; i++)
    {
        tab[i] = 5 + rand()%26;
    }
}

int suma_elementow( int tab[] )
{
    int suma = 0;
    for(int i=0; i<n; i++)
    {
        if(tab[i] > 0)
        suma += tab[i];
    }
    return suma;
}

double srednia( int tab[] )
{
    int suma = 0;
    int ilosc = 0;

    for(int i=0; i<n ; i++)
{
        if(tab[i] < 0)
        {
            suma += tab[i];
            ilosc++;
        }
}
    if( ilosc == 0 )
    return 0;
    return suma/(double)ilosc;
}

int *element_minimalny(int tab[])
{
    int min_ = tab[0];
    int ilosc = 1;

    for (int i = 1; i < n; i++)
    {
        if( tab[i] < min_ )
        {
            min_ = tab[i];
            ilosc = 1;
        }
        else if( tab[i] == min_ )
        {
            ilosc++;
        }
    }

    int *pom = new int[2];
    pom[0] = min_;
    pom[1] = ilosc;
    return pom;
}

int szukaj(int tab[], int liczba)
{
    int ilosc = 0;
    for(int i=0; i<m; i++)
    {
        if( tab[i] == liczba )
        ilosc++;
    }
    return ilosc;
}

float calculate(float data[])
{
	float sum = 0.0, odchylenie = 0.0, srednia;

	for(int i = 0; i < m; i++)
    {
        sum += data[i];
    }
    srednia = sum/m;

    for(int i = 0; i < m; i++)
    {
    	odchylenie += pow(data[i] - srednia, 2);
	}

	return sqrt(odchylenie/m);
}

void cwiartki(int XX[], int YY[], int C[], int n)
{
	int a=0, b=0, c=0, d=0;

	for(int i = 0; i < n; i++)
    {
		if(XX[i]>0 && YY[i]>0)
			a++;

		else if(XX[i]<0 && YY[i]>0)
			b++;

		else if(XX[i]<0 && YY[i]<0)
			c++;

		else if(XX[i]>0 && YY[i]<0)
			d++;
	}

	C[0]=a; C[1]=b; C[2]=c; C[3]=d;

	for(int i = 0; i < n; i++)
    {
		cout << "\n" << XX[i] << " " << YY[i] << endl;
	}

	cout << "\nNumber of elements in quarters: ";

	for(int i = 0; i < 4; i++)
    {
		cout << C[i] << " ";
	}
}

void displayHeader() {
    clearScreen();
    setColor(Colors::LIGHT_BLUE);
    drawLine('*');
    setColor(Colors::YELLOW);
    cout << "\t\tMathematical Array Operations Program" << endl;
    cout << "\t\tCreated by Adrian Lesniak" << endl;
    setColor(Colors::LIGHT_BLUE);
    drawLine('*');
    setColor(Colors::LIGHT_GREEN);
    cout << "\nProgram Functions Description:" << endl;
    cout << "1. Calculate sum of positive numbers and average of negative numbers in array" << endl;
    cout << "2. Find minimum value in array and count its occurrences" << endl;
    cout << "3. Generate random numbers and search for specific value" << endl;
    cout << "4. Calculate standard deviation for array of numbers" << endl;
    cout << "5. Analyze points distribution in coordinate system" << endl;
    cout << "6. Exit program" << endl;
    setColor(Colors::LIGHT_BLUE);
    drawLine('-');
    setColor(Colors::WHITE);
    cout << "\nPress any key to continue...";
    _getch();
}

void showMenu() {
    setColor(Colors::LIGHT_BLUE);
    drawLine();
    setColor(Colors::YELLOW);
    cout << "\nSelect operation (1-5, 6 to exit): ";
    setColor(Colors::WHITE);
}

int main() {
    int choice;
    displayHeader();

    do {
        clearScreen();
        displayHeader();
        showMenu();
        cin >> choice;

        switch(choice) {
            case 1: {
                setColor(Colors::LIGHT_GREEN);
                cout << "\n=== Array Operations with Positive/Negative Numbers ===" << endl;
                int Y[n];
                wstaw(Y);
                cout << "\nThe sum of elements greater than 0 is: " << suma_elementow(Y) << endl;
                cout << "The arithmetic average of elements less than zero is: " << srednia(Y) << endl;
                break;
            }
            case 2: {
                setColor(Colors::LIGHT_GREEN);
                cout << "\n=== Find Minimum Element and Its Occurrences ===" << endl;
                int A[n];
                wstaw(A);
                cout << "\nThe minimum element of the array is: " << element_minimalny(A)[0] << endl;
                cout << "The number of occurrences of the minimum element in the array is: " << element_minimalny(A)[1] << endl;
                break;
            }
            case 3: {
                setColor(Colors::LIGHT_GREEN);
                cout << "\n=== Random Number Search in Array ===" << endl;
                srand(time(NULL));
                int X[m], liczba;
                wstaw1(X);
                cout << "\nPlease enter a number: ";
                cin >> liczba;
                cout << "The given number has occurred: " << szukaj(X, liczba) << " times" << endl;
                break;
            }
            case 4: {
                setColor(Colors::LIGHT_GREEN);
                cout << "\n=== Calculate Standard Deviation ===" << endl;
                srand(time(NULL));
                float X[m];
                for(int i = 0; i < m; i++)
                    X[i] = 5 + rand()%26;
                cout << "\nThe deviation is: " << calculate(X) << endl;
                break;
            }
            case 5: {
                setColor(Colors::LIGHT_GREEN);
                cout << "\n=== Coordinate System Point Distribution ===" << endl;
                srand(time(NULL));
                int n;
                cout << "\nEnter the data: " << endl;
                cin >> n;
                int XX[n], YY[n], C[4];
                for(int i = 0; i < n; i++) {
                    XX[i] = -10 + rand()%21;
                    YY[i] = -10 + rand()%21;
                }
                cwiartki(XX, YY, C, n);
                break;
            }
            case 6:
                setColor(Colors::YELLOW);
                cout << "\nThank you for using the program!" << endl;
                break;
            default:
                setColor(Colors::LIGHT_RED);
                cout << "\nInvalid choice! Please try again." << endl;
        }

        if (choice != 6) {
            setColor(Colors::WHITE);
            cout << "\nPress any key to return to menu...";
            _getch();
        }
    } while (choice != 6);

    return 0;
}






