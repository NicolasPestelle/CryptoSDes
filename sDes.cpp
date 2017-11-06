#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <iostream>

using namespace std;

bitset<8> permutIP (bitset<8> lettre){
  bitset<8> tempo;

  for(int i = 0; i < lettre.size(); i++)
  cout << lettre[i] << endl;

  
  tempo[0] = lettre[1];
  tempo[1] = lettre[5];
  tempo[2] = lettre[2];
  tempo[3] = lettre[0];
  tempo[4] = lettre[3];
  tempo[5] = lettre[7];
  tempo[6] = lettre[4];
  tempo[7] = lettre[6];

  
  return tempo;
}

int main(int argc, char **argv){

  //on vas lire le texte et appliqué le td pour chaque caractere
  bitset<8> b { 'A' };

  // cout << b << endl;
  cout << permutIP(b) << endl;
  
  //cout << b << endl;
  
}
