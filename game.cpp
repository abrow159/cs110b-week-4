#include <iostream>
using namespace std;

void printArrays(int arr[3][7]) {
  for(int i = 0; i < 3; i++) {
    cout << "Pile " << i + 1 << ":" << endl;
    for(int j = 0; j < 7; j++) {
      cout << arr[i][j] << " ";

      if(j == 6) {
        cout << endl;
      }
    }
  }
}

void rotateArrays(int pile, int (&arr)[3][7]) {
  switch(pile) {
    case(1):
      for(int i = 0; i < 7; i++) {
        arr[0][i] += arr[1][i];
        arr[1][i] = arr[0][i] - arr[1][i];
        arr[0][i] -= arr[1][i];
      }
    break;
    case(2):
    //don't need to do anything because number is already in the middle!
    return;
    break;
    case(3):
      for(int i = 0; i < 7; i++) {
        arr[1][i] += arr[2][i];
        arr[2][i] = arr[1][i] - arr[2][i];
        arr[1][i] -= arr[2][i];
      }
    break;
    default: 
      cout << "Invalid choice";

  }
}

void iterateArray(int flattenedArr[21], int (&arr)[3][7]) {
  for (int i = 0; i < 3; i++) {
    int count = i;
    for (int j = 0; j < 7; j++) {
      arr[i][j] = flattenedArr[count];
      count += 3;
    }
  }
}

void transformArrays(int pile, int (&arr)[3][7]) {
  int flattenedArr[21] = {};
  int count = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 7; j++) {
      flattenedArr[count++] = arr[i][j];
    }
  }

  iterateArray(flattenedArr, arr);
}

int main() {
  int chosen_num;
  int pile;

  int arr[3][7] = {{1, 2, 3, 4, 5, 6, 7}, {8, 9, 10, 11, 12, 13, 14}, {15, 16, 17, 18, 19, 20, 21}};

  cout << "Choose a number from 1 to 21" << endl;
  cin >> chosen_num;

  for (int i = 0; i < 3; i++) {
    cout << "Which pile is this number in? Choose 1, 2, or 3." << endl;

    printArrays(arr);
    cin >> pile;

    rotateArrays(pile, arr);
    transformArrays(pile, arr);
  }

  cout << "Your number is " << arr[1][3] << "!" << endl;
}
