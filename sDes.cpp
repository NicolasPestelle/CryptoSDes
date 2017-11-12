#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
#include <fstream>

void init();

using namespace std;


vector<int> permutIP(vector<int> lettre) {
    vector<int> tempo = lettre;
  
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


vector<int> p10(vector<int> key) {
    vector<int> tempo = key;

    tempo[0] = key[2];
    tempo[1] = key[4];
    tempo[2] = key[1];
    tempo[3] = key[6];
    tempo[4] = key[3];
    tempo[5] = key[9];
    tempo[6] = key[0];
    tempo[7] = key[8];
    tempo[8] = key[7];
    tempo[9] = key[5];

    return tempo;
}

vector<int> char2bin(char a) {
    std::bitset<7> octet = a;

    vector<int> b;

    for (int j = octet.size(); j >= 0; j--) {
        b.push_back((int) octet[j]);
    }

    return b;
}

vector<int> decal5(vector<int> cle) {
    vector<int> tmp(9);

    tmp[0] = cle[1];
    tmp[1] = cle[2];
    tmp[2] = cle[3];
    tmp[3] = cle[4];
    tmp[4] = cle[0];

    tmp[5] = cle[6];
    tmp[6] = cle[7];
    tmp[7] = cle[8];
    tmp[8] = cle[9];
    tmp[9] = cle[5];

    return tmp;
}

vector<int> p8(vector<int> cle) {
    vector<int> tmp(7);

    tmp[0] = cle[5];
    tmp[1] = cle[2];
    tmp[2] = cle[6];
    tmp[3] = cle[3];
    tmp[4] = cle[7];
    tmp[5] = cle[4];
    tmp[6] = cle[9];
    tmp[7] = cle[8];

    return tmp;
}

vector<int> QuatrePremierBits(vector<int> vec) {

    vector<int> tmp(4);

    for (int i = 0; i <= 4; i++) {
        tmp[i] = vec[i];
    }

    return tmp;
}

vector<int> QuatreDernierBits(vector<int> vec) {

    vector<int> tmp(4);

    tmp[0] = vec[4];
    tmp[1] = vec[5];
    tmp[2] = vec[6];
    tmp[3] = vec[7];

    return tmp;
}

vector<int> ep(vector<int> vec) {

    vector<int> tmp(7);

    tmp[0] = vec[3];
    tmp[1] = vec[0];
    tmp[2] = vec[1];
    tmp[3] = vec[2];
    tmp[4] = vec[1];
    tmp[5] = vec[2];
    tmp[6] = vec[3];
    tmp[7] = vec[0];

    return tmp;
}

vector<int> xorBis(vector<int> vec, vector<int> vec2) {

    vector<int> tmp(7);

    for (int j = 0; j <= vec.size(); j++) {
        tmp[j] = vec[j] ^ vec2[j];
    }

    return tmp;

}

string chiffrement(char line) {
    vector<int> k = {1, 1, 1, 1, 0, 1, 1, 0, 0, 1};

    vector<int> p10k = p10(k);

    vector<int> p10Decal = decal5(p10k);

    vector<int> k1 = p8(p10Decal);

    vector<int> decal1k2 = decal5(p10Decal);

    vector<int> decal2k2 = decal5(decal1k2);

    vector<int> k2 = p8(decal2k2); //clé fausse


    vector<int> lettre = char2bin(line);

    vector<int> IP = permutIP(lettre);

    vector<int> Quatrepremierbits = QuatrePremierBits(IP);

    vector<int> Quatredernierbits = QuatreDernierBits(IP);

    vector<int> ep1 = ep(Quatredernierbits);

    vector<int> xorep1 = xorBis(ep1, k1); //pb xor !


    cout << "code pas finis, mais avancé jusq'au xor + les 2 clés de faites" << endl;


    /*for (int j=0 ;j<= xorep1.size();j++) {
        cout << xorep1[j]<< endl;
    }*/
}

int main(int argc, char **argv){

    //on vas lire le texte et appliqué le td pour chaque caractere :
    //test uniquement avec la clé du tp pour l'instant

    /* string texte = argv[1];
     string cle = argv[2];

     std::ifstream ifs(argv[1]);
     std::string line;
     std::ofstream ofs("texteChiffre.txt");

     while (std::getline(ifs, line)) {

             ofs << init(line,(char*)cle);

     }*/

    chiffrement('A');

}

