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
  char output[LENGTH];
  int c = 0;
   
  for(int a = 0; a < LENGTH; a++) {
    input[a] = ' ';
    output[a] = ' ';
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
  cout << endl;
  cout << endl;

  //turn binary back to char
  for (int a = 0; a < (6 * LENGTH) / 8; a++) {
    if (otherBinay[8 * a] != 0 || otherBinay[8 * a + 1] != 1) {
      //cry
      //cout << "An error has occured" << endl;
      //exit(1);
      //nvr mind this just means we hit end of string
      a = 6 * LENGTH;
    }

    //print what we should have
    
    cout << endl;
    for (int b = 0; b < 8; b++) {
      cout << otherBinay[8 * a + b];
    }
    cout << endl;
    //*/
    
    int tmp = 0;
    //ignoreing 0 and 1 due to lenght of int restrictions
    //0
    //1
    tmp += otherBinay[8*a+2] * 100000;
    tmp += otherBinay[8*a+3] * 10000;
    tmp += otherBinay[8*a+4] * 1000;
    tmp += otherBinay[8*a+5] * 100;
    tmp += otherBinay[8*a+6] * 10;
    tmp += otherBinay[8*a+7] * 1;

    cout << tmp << ", ";

    if (tmp == 000001) {
      output[c] = 'A';
      c++;
    }
    else if (tmp == 10) {
      output[c] = 'B';
      c++;
    }
    else if (tmp == 11) {
      output[c] = 'C';
      c++;
    }
    else if (tmp == 100) {
      output[c] = 'D';
      c++;
    }
    else if (tmp == 101) {
      output[c] = 'E';
      c++;
    }
    else if (tmp == 110) {
      output[c] = 'F';
      c++;
    }
    else if (tmp == 111) {
      output[c] = 'G';
      c++;
    }
    else if (tmp == 1000) {
      output[c] = 'H';
      c++;
    }
    else if (tmp == 1001) {
      output[c] = 'I';
      c++;
    }
    else if (tmp == 1010) {
      output[c] = 'J';
      c++;
    }
    else if (tmp == 1011) {
      output[c] = 'K';
      c++;
    }
    else if (tmp == 1100) {
      output[c] = 'L';
      c++;
    }
    else if (tmp == 1101) {
      output[c] = 'M';
      c++;
    }
    else if (tmp == 1110) {
      output[c] = 'N';
      c++;
    }
    else if (tmp == 1111) {
      output[c] = 'O';
      c++;
    }
    else if (tmp == 10000) {
      output[c] = 'P';
      c++;
    }
    else if (tmp == 10001) {
      output[c] = 'Q';
      c++;
    }
    else if (tmp == 10010) {
      output[c] = 'R';
      c++;
    }
    else if (tmp == 10011) {
      output[c] = 'S';
      c++;
    }
    else if (tmp == 10100) {
      output[c] = 'T';
      c++;
    }
    else if (tmp == 10101) {
      output[c] = 'U';
      c++;
    }
    else if (tmp == 10110) {
      output[c] = 'V';
      c++;
    }
    else if (tmp == 10111) {
      output[c] = 'W';
      c++;
    }
    else if (tmp == 11000) {
      output[c] = 'X';
      c++;
    }
    else if (tmp == 11001) {
      output[c] = 'Y';
      c++;
    }
    else if (tmp == 11010) {
      output[c] = 'Z';
      c++;
    }
    else {
      //should be end character aka drop it
      //cout << "..." << endl;
    }


    //
    //cout << c << endl;
    cout << output[c - 1];
    cout << endl;
  }

  //cout output
  cout << endl;
  for (int a = 0; a < LENGTH; a++) {
    cout << output[a];
  }
  cout << endl;
}
