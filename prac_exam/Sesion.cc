#include "Sesion.hh"

using namespace std;
/** @class Sesion
    @brief Representa una Sesion de la plataforma.

    Está formada por un BinTree de los identificadores de los problemas y 
    un vector con los identificadores de estos problemas.
*/



  //private:

      /** @brief Comprueba si existe un nodo p en un BinTree.
          \pre cierto
          \post Devuelve cierto si encuenta p en el BinTree a; falso en caso
          contrario
      */
      bool Sesion::cerca(const BinTree<string>& a, const string& p) {
        if (a.empty()) return false;
        else return (a.value() == p)
                    or cerca(a.left(), p)
                    or cerca(a.right(), p);
      }

      /** @brief Realiza la lectura de un BinTree en preorden.
          \pre cierto
          \post Se ha realizado la lectura del BinTree en preorden
      */
      void Sesion::leer_arbol_preorden(BinTree<string>& a) {
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

      /** @brief Imprime un BinTree en postorden con los hijos entre paréntesis.
          \pre El BinTree a no es vacío
          \post Imprime el BinTree a en postorden con los hijos entre paréntesis
      */
      void Sesion::escribir_bintree_postorden(const BinTree<string>& a) {
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

      /** @brief Deja en un vector con todos los nodos de un BinTree.
          \pre cierto
          \post Deja en el vector v todos los nodos del BinTree a
      */
      void Sesion::vect_problemas(vector<string>& v, const BinTree<string>& a) {
        if (not a.empty()) {
          v.push_back(a.value());
          vect_problemas(v, a.left());
          vect_problemas(v, a.right());
        }
      }

      /** @brief Actualiza todos los problemas enviables, que pertenecen a un BinTree, de un usuario.
          \pre cierto
          \post Se actualizan los problemas enviables de un usuario a partir del
          BinTree
      */
      void Sesion::act_enviables_i(const BinTree<string>& a, Usuario& usuario) {
        if (not a.empty()) {
          usuario.agregar_problema_disp(a.value());
          if (usuario.ha_resuelto_problema(a.value())) {
            act_enviables_i(a.left(), usuario);
            act_enviables_i(a.right(), usuario);
          }
        }
      }

      /*
      void Sesion::act_enviables_i(const BinTree<string>& a, Usuario& usuario) {
        if (not a.empty()) {
          if (not usuario.ha_resuelto_problema(a.value())) {
            usuario.agregar_problema_disp(a.value());
          }
          else {
            act_enviables_i(a.left(), usuario);
            act_enviables_i(a.right(), usuario);
          }
        }
      }
      */

      /** @brief Actualiza los problemas enviables sucesores de un problema p (este incluido), que pertenecen a un BinTree, de un usuario.
          \pre cierto
          \post Se actualizan los problemas enviables de un usuario a partir del
          BinTree
      */
      void Sesion::act_enviables(const BinTree<string>& a, const string& p, Usuario& usuario) {
        if (not a.empty()) {
          if (a.value() == p) {
            usuario.agregar_problema_disp(p);
            if (usuario.ha_resuelto_problema(p)) {
              act_enviables_i(a.left(), usuario);
              act_enviables_i(a.right(), usuario);
            }
          }
          else {
            act_enviables(a.left(), p, usuario);
            act_enviables(a.right(), p, usuario);
          }
        }
      }

      /*
      void Sesion::act_enviables(const BinTree<string>& a, const string& p, Usuario& usuario) {
        if (not a.empty()) {
          if (a.value() == p) {
            if (not usuario.ha_resuelto_problema(p)) {
              usuario.agregar_problema_disp(p);
            }
            else {
              act_enviables_i(a.left(), usuario);
              act_enviables_i(a.right(), usuario);
            }
          }
          else {
            act_enviables(a.left(), p, usuario);
            act_enviables(a.right(), p, usuario);
          }
        }
      }
      */


  //public:
      //Constructoras

      Sesion::Sesion() {
        leer_arbol_preorden(problemas);
        vect_problemas(vect_p, problemas);
      }

      //Modificadoras

      /** @brief Actualiza los problemas enviables sucesores de un problema p (este incluido), que pertenecen a una sesion, de un usuario.
          \pre cierto
          \post Actualiza los problemas enviables sucesores de un problema p
          (este incluido), que pertenecen al parámetro implícito, del usuario
      */
      void Sesion::act_problemas_enviables(const string& p, Usuario& usuario) const {
        act_enviables(problemas, p, usuario);
      }

      /** @brief Actualiza los problemas enviables, que pertenecen a una sesion, de un usuario.
          \pre cierto
          \post Actualiza los problemas enviables, que pertenecen al parámetro
          implícito, del usuario
      */
      void Sesion::problemas_enviables(Usuario& usuario) const {
        act_enviables_i(problemas, usuario);
      }

      //Consultoras

      /** @brief Devuelve el identificador del problema con índice i del vector de problemas de una sesion.
          \pre El índice i (entero) es > 0 y < numero de problemas del parámetro implícito
          \post Devuelve el identificador del problema con índice i del vector de
          problemas del parámetro implícito
      */
      string Sesion::id_problema(int i) const {
        return vect_p[i];
      }

      /** @brief Devuelve el nº de problemas de una sesion.
          \pre cierto
          \post Devuelve el nº de problemas del parámetro implícito
      */
      int Sesion::num_problemas() const {
        return vect_p.size();
      }

      /** @brief Consulta si existe un problema con el identificador p en una sesion.
          \pre cierto
          \post Devuelve cierto si existe un problema con identificador p en el
          parámetro implícito; falso en caso contrario
      */
      bool Sesion::existe_problema(const string& p) const {
        return cerca(problemas, p);
      }

      // Lectura i escritura

      /** @brief Imprime una sesion.
          \pre cierto
          \post Imprime el nº de problemas que la forman y los identificadores de
          dichos problemas, siguiendo su estructura de prerequisitos en postorden
      */
      void Sesion::escribir_sesion() const {
        cout << vect_p.size() << " (";
        escribir_bintree_postorden(problemas);
        cout << ")" << endl;
      }
