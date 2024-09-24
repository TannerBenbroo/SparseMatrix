#include <iostream>
using namespace std;

class matrix {

public:

    void SetEntry(int i, int j, int v);

    int GetEntry(int i, int j); 

    int CountNonZero();

    void GetSparseRep();

    int* SparseRow, * SparseCol, * SparseVal;

private:

    int m[3][5];

};

void matrix::SetEntry(int i, int j, int v) {

    // ------------------------------------------------------
    // assign value v to the row i and column j of matrix "m" 
    // ------------------------------------------------------

    m[i][j] = v;
}

int matrix::GetEntry(int i, int j) {

    // this function returns matrix entry at row i and column j 

    return m[i][j];

}

int matrix::CountNonZero() {

    // ------------------------------------------------------
    // return the number of non-zero elements in matrix "m" 
    // ------------------------------------------------------

    //This code searches for non-zero elements and 
    //increments count when a non-zero is found.
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j)
            if (m[i][j] != 0) {
                ++count;
            }
    }

    return count;

}

void matrix::GetSparseRep() {

    // ------------------------------------------------------
    // generate a sparse representation of matrix "m"
    // ------------------------------------------------------
    // assign results to (SparseRow, SparseCol, SparseVal)
    // use SparseRow to hold row indcies
    // use SparseCol to hold column indcies
    // use SparseVal to hold entry values
    // 
    // For example, if the first non-zero element we find is m[a][b], 
    // then SparseRow[0]=a, SparseCol[0]=b, SparseVale[0]=m[a][b]. 
    // If the second non-zero element we find is m[c][d], then 
    // SparseRow[1]=a, SparseCol[1]=b, SparseVale[1]=m[a][b]
    // --------------------------------------------------------
    
    //initialize the pointers to new arrays
    //for the sparse array.
    SparseRow = new int[3];
    SparseCol = new int[3];
    SparseVal = new int[3];

    //loop throughout the entire array to find the 
    //non-zero elements. When they are found, add them to the first
    //element of the sparse array and increment count to 1. etc. 
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] != 0) {
                SparseRow[count] = i;
                SparseCol[count] = j;
                SparseVal[count] = m[i][j];
                ++count;
                // ............. 

            }
        }
    }
}


int main()
{
    // The main function is given to you. 
    // It first declares a matrix object "x", 
    // then inputs the matrix values, 
    // then generates the sparse representation 
    // of the matrix and finally outputs it. 

    // You do not need to modify this function. 
    // And please do not modify it or Gradescope 
    // may not recognize the format of your intput/output.

    matrix x;

    int temp, mode;

    cin >> mode; // this controls what to test 

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> temp;
            x.SetEntry(i, j, temp);
        }
    }

    switch (mode) {

    case 1: // test if inputs are correctly assigned 

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                cout << x.GetEntry(i, j) << endl;
            }
        }
        break;

    case 2: // test if CountNonZero() is correct 

        cout << x.CountNonZero() << endl;
        break;

    case 3: // test if GetSparseRep() is correct 

        x.GetSparseRep();

        for (int i = 0; i < x.CountNonZero(); i++) {

            cout << x.SparseRow[i] << ' ' << x.SparseCol[i] << ' ' << x.SparseVal[i] << endl;
        }
        break;

    }

    return 0;
}