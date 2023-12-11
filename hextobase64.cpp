#include <iostream>
#include <cstring>

using namespace std;

//by Ryan Veith
//this is me trying to code a program to turn hex to base 64
//I am out of practice with c++ so we will see how this goes

int main() {
  const int LENGTH = 80;
  cout << "hello world" << endl;

  char input[LENGTH];
  int intermideate[LENGTH];
  int otherBinay[6*LENGTH];
    
  for(int a = 0; a < LENGTH; a++) {
    input[a] = ' ';
    intermideate[a] = 0;
  }
  for(int a =0; a < 6*LENGTH; a++) {
    otherBinay[a] = 0;
  }

  
  cin.getline(input, LENGTH);
  
  //letter to base64 number index
  for(int a = 0; a < LENGTH; a++) {
    if(input[a] > 64 && input[a] < 91) {
      intermideate[a] = input[a] -65;
    }
    else if (input[a] > 96 && input[a] < 123) {
      intermideate[a] = input[a] -71;
    }
    else if (input[a] > 47 && input[a] < 58) {
      intermideate[a] = input[a] +4;
    }
    else if (input[a] == '+' ) {
      intermideate[a] = 62;
    }
    else if (input[a] == '/' ) {
      intermideate[a] = 63;
    }
    else {
      intermideate[a] = 0;
    }

  }
  cout << endl;
  
  //index to binary
  for (int a = 0; a < LENGTH; a++) {
    if(intermideate[a] > 31) {
      otherBinay[a * 6] = 1;
      intermideate[a] -= 32;
    }   
    if(intermideate[a] > 15) {
      otherBinay[a * 6 + 1] = 1;
      intermideate[a] -= 16;
    }
    if(intermideate[a] > 7) {
      otherBinay[a * 6 + 2] = 1;
      intermideate[a] -= 8;
    }
    if(intermideate[a] > 3) {
      otherBinay[a * 6 + 3] = 1;
      intermideate[a] -= 4;
    }
    if(intermideate[a] > 1) {
      otherBinay[a * 6 + 4] = 1;
      intermideate[a] -= 2;
    }
    if(intermideate[a] > 0) {
      otherBinay[a * 6 + 5] = 1;
      intermideate[a] -= 1;
    }   
  }
  //if its stupid and it works its not stupid

  for(int a = 0; a < LENGTH; a++) {
    cout << otherBinay[a];
  }

  //turn binary back to char
  for (int a = 0; a < (6 * LENGTH) / 8; a++) {
    if (otherBinay[8 * a] != 0 || otherBinay[8 * a + 1] != 1) {
      //cry
      //cout << "An error has occured" << endl;
      //exit(1);
      //nvr mind this just means we hit end of string
      //a = 6 * LENGTH;
    }
    /*
    char tmp[6];
    //0
    //1
    tmp[0] = otherBinay[a+2];
    tmp[1] = otherBinay[a+3];
    tmp[2] = otherBinay[a+4];
    tmp[3] = otherBinay[a+5];
    tmp[4] = otherBinay[a+6];
    tmp[5] = otherBinay[a+7];

    for (int b = 0; b < 6; b++) {
      cout << tmp[b];
      cout << endl;
    }
    */
  }
}
