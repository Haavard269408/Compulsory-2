#include "Calculations.h"
#include <iostream>

// GLOBAL VARIABLES: 
using namespace std;
int input1;

int poly01[4];
int poly02[4];
 
// used to check if user has created polynomials
bool polyIsCreated = false;


/// <summary>
/// This is a recursive function which calculates the factorial of a given number (x).
/// </summary>
/// <param name="x"></param>
/// <returns>factorial number of x or 1</returns>
int factorial(int x) {
    
    if (x == 1) {
      
        return 1;
    }
    else {
        return x * factorial(x - 1);
      
    }
    

   
}


// INPUT CHECK: 

/// <summary>
/// Checks if input form user is a valid integer
/// </summary>
/// <param name="input"></param>
/// <returns>String "Please enter valid number" is not a number, else returns true</returns>
bool validateInput(int &input) {
    cin >> input;
    while (!cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid number: ";
        cin >> input;
        
    }
    return true;
}

// MATH EQUATIONS: 


/// <summary>
/// Menu function which lets the user choose which mathematical operation the user wants.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns>returns the mathemacial operation based on user input.</returns>
int mathEquations(int x, int y) {
    cout << "\nHere you can perform simple math equations. " << endl;
    
    int input1;
    // make it so that the user can change x and y mid menu. (new case). 

    while (true) {
        cout << "\nEnter a value (0 to go back go main-menu): \nEnter 1 to add numbers: \nEnter 2 to subtract numbers: \nEnter 3 to multiply numbers:  \nEnter 4 to divide numbers: ";
        validateInput(input1);

        if (input1 == 0) {
            break;
        }

        switch (input1) {
        case 1:
           
            cout << "\nResult: " << add(x,y) << endl;
          
            break;

        case 2:
            cout << "\nResult: " << subtract(x,y) << endl;
            
            break;

        case 3:
            cout << "\nResult: " << multiply(x,y) << endl;
            
            break;

        case 4:
            cout << "\nResult: " << divide(x,y) << endl;
           
            break;


        default:
            cout << "\nUnknown input" << endl;
            break;
        }
      
    }
    return 0;

}


// POLYNOMIALS: 

/// <summary>
/// Function derivates user made polynomials. It takes two for loops for both user-made polynomial arrays.
/// </summary>
/// <param name="poly01"></param>
/// <param name="poly02"></param>
/// <returns>derivated poly 01 array and derivated poly 02 array</returns>
int* derivatePolys(int poly01[], int poly02[]) {

    const int lengthAfterDerivation = 4;
    int derivatedProd1[lengthAfterDerivation];
    int derivatedProd2[lengthAfterDerivation];
    int exponent = (lengthAfterDerivation);

    //POLY 01:
    cout << "\nDerivation of poly 01 is: " << endl;

    for (int i = 0; i < lengthAfterDerivation; i++)
    {
        exponent--;
        derivatedProd1[i] = poly01[i] * exponent;
        
        
        if (exponent >= 1) {
            
            cout << derivatedProd1[i] << "x^" << exponent << " + ";
        }
        else {
            cout << derivatedProd1[i] << endl;
        }
        

    }

    // POLY 02:

    exponent = lengthAfterDerivation;
    cout << "\nDerivation of poly 02 is: " << endl;
   

    for (int i = 0; i < lengthAfterDerivation; i++)
    {
        exponent--;
        derivatedProd2[i] = poly02[i] * exponent;

        if (exponent >= 1) {

            cout << derivatedProd2[i] << "x^" << exponent << " + ";
        }
        else {
            cout << derivatedProd2[i] << endl;
        }
    }

    return derivatedProd1; return derivatedProd2;

}

/// <summary>
/// takes both user created polynomials and subtracts them
/// </summary>
/// <param name="poly01"></param>
/// <param name="poly02"></param>
/// <returns>addProd, array containig value of both arrays subtracted</returns>
int* subtractPolys(int poly01[], int poly02[]) {

    int lenghtAfterAdding = 4;
    int exponent = (lenghtAfterAdding - 1);
    int addProd[4];

    for (int i = 0; i < lenghtAfterAdding; i++)
    {
        addProd[i] = poly01[i] - poly02[i];
    }

    cout << "\nSubtraction of both polynomials yields: ";

    for (int i = 0; i < lenghtAfterAdding; i++)
    {
        if (i < exponent) {

            cout << addProd[i] << "x^" << ((exponent)-i) << " + ";
        }
        else {
            cout << addProd[i] << endl;
        }


    }

    return addProd;
}



/// <summary>
/// takes both user created polynomials and adds them
/// </summary>
/// <param name="poly01"></param>
/// <param name="poly02"></param>
/// <returns>addProd, array containig value of both arrays added</returns>
int* addPolys(int poly01[], int poly02[]) {

    int lenghtAfterAdding = 4;
    int exponent = (lenghtAfterAdding - 1);
    int addProd[4];

    for (int i = 0; i < lenghtAfterAdding; i++)
    {
        addProd[i] = poly01[i] + poly02[i];
    }

    cout << "\nAddition of both polynomials yields: ";

    for (int i = 0; i < lenghtAfterAdding; i++)
    {       
        if (i < exponent) {
            
            cout << addProd[i] << "x^" << ((exponent)-i) << " + ";
        }
        else {
            cout << addProd[i] << endl;
        }
        
            
    }
     
    return addProd;
}


/// <summary>
/// takes both user created polynomials and multiplies them. New array prod[i] stores the value of both arrays multiplied.
/// </summary>
/// <param name="poly01"></param>
/// <param name="poly02"></param>
/// <returns>prod array which returns the value of poly01 and poly02 multiplied</returns>
int* multiplyPoly(int poly01[], int poly02[]) {
    //Using pointer here in order to use arrays as dynamic paramteres.


    // max length of prod. array (sum) since we are multiplying two poly`s we can set it to 7.
    int maxLength = 7;

    int prod[7];
    //initialize prod array to be 0 so that it resets each iteration when we call the function. Or else prod[] just gonna increase each time we multiply it.
    for (int i = 0; i < maxLength; i++)
    {
        prod[i] = 0;
    }

    //nested for-loop (two for-loops in one). 
    //we multilpy poly1[i] with poly2[j] and then store the result in prod.array. prod[i+j] = prod[i+j] + poly01[i] * poly02[j].
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            prod[i + j] += poly01[i] * poly02[j];
    }
    
    cout << "\nProduct of both polynomials is: ";

    //itereate trough the array to print out each element of prod.array. and then add x^ + exponent. If its the last index in prod. array we just print the number.
    for (int i = 0; i < maxLength; i++)
    {
        if (i < maxLength - 1) {
            cout << prod[i] << "x^" << ((maxLength - 1) - i) << " + ";

        }
        else {
            cout << prod[i] << endl;
        }

    }

    // returns the prod.array. This ends the function. 
    return prod;
}


/// <summary>
/// user menu system for creating a 3rd degree polynomial.
/// </summary>
/// <param name="poly01"></param>
/// <param name="poly02"></param>
/// <returns>two user-created 3rd degree polynomial array</returns>
int *createPolynomial() {
    
    int poly01value;

    cout << "\nPlease insert 4 numbers for polynomial: \n";

    for (int i = 0; i < 4; i++)
    {
        validateInput(poly01value);
        poly01[i] = poly01value;

    }

    cout << "\nYour first polynomial is: ";
    cout << poly01[0] << "x^3 " << "+ " << poly01[1] << "x^2 " << "+ " << poly01[2] << "x " << "+ " << poly01[3] << endl;

    int poly02value;

    cout << "\nPlease insert 4 numbers for second polynomial: \n";

    for (int i = 0; i < 4; i++)
    {
        validateInput(poly02value);
        poly02[i] = poly02value;

    }

    cout << "\nYour second polynomial is: ";
    cout << poly02[0] << "x^3 " << poly02[1] << "x^2 " << poly02[2] << "x " << poly02[3] << endl;
    
    polyIsCreated = true;
    return poly01;
    return poly02;
  
}

/// <summary>
/// Menu system for user to choose which mathematical operation user wants to perform with polynomials.
/// </summary>
void polyEquations() {

    cout << "\nHere you can perform polynomial equations. " << endl;

    int input1;
    // make it so that the user can change x and y mid menu. (new case). 

    while (true) {
        cout << "\nEnter a value (0 to go back go main-menu): \nEnter 1 to create polynomials: \nEnter 2 to multiply polynomials: \nEnter 3 to add polynomials:  \nEnter 4 to subtract polynomials: \nEnter 5 to derivate the polynomials: ";
        validateInput(input1);

        if (input1 == 0) {
            break;
        }

        switch (input1) {
        case 1:

            createPolynomial();
            
            break;


        case 2:
          
            if (!polyIsCreated) {
                cout << "\nYou need to create two polynomials first, please press 1 to create them. " << endl;
            }
            else {
                multiplyPoly(poly01, poly02);
            }
            break;


        case 3:

            if (!polyIsCreated) {
                cout << "\nYou need to create two polynomials first, please press 1 to create them. " << endl;
            }
            else {
                addPolys(poly01, poly02);
            }
            break;


        case 4:
            if (!polyIsCreated) {
                cout << "\nYou need to create two polynomials first, please press 1 to create them. " << endl;
            }
            else {
                subtractPolys(poly01, poly02);
            }
            break;

        case 5:
            if (!polyIsCreated) {
                cout << "\nYou need to create two polynomials first, please press 1 to create them. " <<endl;
            }
            else {
                derivatePolys(poly01, poly02);
            }
            break;

        default:
            cout << "\nUnknown input" << endl;
            break;
        }

    }

}


// MAIN:

/// <summary>
/// Main function, takes care of the main menu
/// </summary>
/// <returns></returns>
int main()
{
    int maxFactorialValue = 33;
    int input;
    cout << "Welcome to Håvard`s calculator! " << endl;

    while (true) {
       

        cout << "\nEnter a value (0 to exit program): \n\nEnter 1 to calculate factorial: \n\nEnter 2 to perform simple math equations: \n\nEnter 3 to do polynomial equations:  " << endl;
        validateInput(input);


        if (input == 0) {
            break; 
        }

        switch (input) {
        case 1:
            
            int userInputFactor;
            cout << "\nEnter number to calculate factorial: ";
            validateInput(userInputFactor);

            if (userInputFactor > maxFactorialValue) { cout << "\nNumber is too high, try again " << endl;  break; }
            else
            { cout << "\nFactorial to value " << userInputFactor << " is: " << factorial(userInputFactor) << endl; }
 
            break;


        case 2:
            int varX;
            int varY;
            cout << "\nEnter num 1: ";
            validateInput(varX);
            cout << "\nEnter num 2: ";
            validateInput(varY);

            mathEquations(varX, varY);

            break;


        case 3: 

            
            polyEquations();
            
            break;


        default:
            cout << "\nUnknown input" << endl;
            break;
        }
    }

}

