#include "BinTree.hh"
#include <iostream>
#include <string>

using namespace std;

void leer_arbol_preorden(BinTree<string>& a) {
  string x;
  cin >> x;
  if (x != "0") {
    BinTree<string> a1;
    BinTree<string> a2;

    leer_arbol_preorden(a1);
    leer_arbol_preorden(a2);
    a = BinTree<string> (x, a1, a2);
  }
}

void escribir_bintree_postorden(const BinTree<string>& a) {
  BinTree<string> a1 = a.left();
  BinTree<string> a2 = a.right();

  if (not a1.empty()) {
    cout << "(";
    escribir_bintree_postorden(a1);
    cout << ")";
  }
  if (not a2.empty()) {
    cout << "(";
    escribir_bintree_postorden(a2);
    cout << ")";
  }
  cout << a.value();
}

void escribir(const BinTree<string>& a) {
  if (not a.empty()) {
    BinTree<string> a1 = a.left();
    BinTree<string> a2 = a.right();

    cout << "(";

    escribir(a.left());
    escribir(a.right());

    if (not a2.empty()) cout << ")";
    cout << a.value();
  }
}

/*
pair<string,string> hijos(const BinTree<string>& a, string p) {
  string p1 = "0";
  string p2 = "0";
  if (not a.empty()) {
    if (a.value() == p) {
      if (not a.left().empty()) p1 = a.left().value();
      if (not a.right().empty()) p2 = a.right().value();
      return make_pair(p1,p2);
    }
  }
  return hijos(a.left(), p);
  return hijos(a.right(), p);
}
*/
void hijos(const BinTree<string>& a, string p, pair<string,string>& pair) {
  if (not a.empty() and a.value() == p) {
      if (not a.left().empty()) pair.first = a.left().value();
      if (not a.right().empty()) pair.second = a.right().value();
  }
  else {
    if (not a.right().empty()) hijos(a.right(), p, pair);
    if (not a.left().empty()) hijos(a.left(), p, pair);
  }
}

int main() {
  BinTree<string> a;
  leer_arbol_preorden(a);
  string p;
  cin >> p;
  pair<string,string> pair;
  pair.first = "0";
  pair.second = "0";
  hijos(a, p, pair);
  cout << pair.first << " " << pair.second << endl;
  //escribir(a);

}
