#include "Curso.hh"

using namespace std;

/** @class Curso
    @brief Representa un Curso de la plataforma

    Un curso está formado por el número de inscritos, el número de usuarios que
    lo han completado (graduados), los identificadores de las sesiones y todos sus
    problemas con la sesion en la que pertenece cada uno.
*/

  //private:


  //public:
      //Constructoras

      Curso::Curso() {
        inscritos = 0;
        graduados = 0;
      }

      //Modificadoras

      /** @brief Augmenta en una unidad el nº de inscritos en un curso y lo imprime.
          \pre cierto
          \post El nº de inscritos en el curso augmenta una unidad y lo imprime
      */
      void Curso::alta() {
        ++inscritos;
        cout << inscritos << endl;
      }

      /** @brief Disminuye en una unidad el nº de inscritos en un curso.
          \pre cierto
          \post El nº de inscritos en el curso disminuye una unidad
      */
      void Curso::baja() {
        --inscritos;
      }

      /** @brief Disminuye en una unidad el nº de inscritos y augmenta en una unidad el nº de usuarios que han completado un curso.
          \pre cierto
          \post El nº de usuarios que han completado el curso augmenta en una unidad
          y el nº de usuarios inscritos disminuye en una unidad
      */
      void Curso::completado() {
        --inscritos;
        ++graduados;
      }

      //Consultoras

      /** @brief Devuelve el identificador de la sesion en la posicion i en el que se leyó.
          \pre i es un valor entre 0 y el nº de sesiones-1 del parámetro implícito
          \post Devuelve el identificador de la sesion en la posicion i en la que
          se leyó cuando se creó el parámetro implícito
      */
      string Curso::id_sesion(int i) const {
        return sesiones[i];
      }

      /** @brief Devuelve el nº de sesiones que tiene un curso.
          \pre cierto
          \post Devuelve el nº de sesiones que tiene el parámetro implícito
      */
      int Curso::num_sesiones() const {
        return sesiones.size();
      }

      /** @brief Consula el nº de usuarios inscritos en un curso.
          \pre cierto
          \post Devuelve el nº de usuarios inscritos al parámetro implícito
      */
      int Curso::num_usuarios() const {
        return inscritos;
      }

      /** @brief Consula si existe un problema con identificador p en un curso.
          \pre cierto
          \post Devuelve cierto si existe un problema con identificador p en el parámetro
          implícito; falso en caso contrario
      */
      bool Curso::existe_problema(const string& p) const {
        map<string,string>::const_iterator it = problemas.find(p);
        if (it != problemas.end()) return true;
        else return false;
      }

      /** @brief Devuelve el identificador de la sesion que contiene un problema p en el curso con identificador c.
          \pre Existe un problema p en el parámetro implícito
          \post Devuelve el identificador de la sesion donde se realiza el problema p
          en el curso c
      */
      string Curso::sesion_problema(const string& p) const {
        map<string,string>::const_iterator it = problemas.find(p);
        return it->second;
      } 

      // Lectura i escritura

      /** @brief Lee un curso.
          \pre En la entrada hay un entero n y n strings identicadores de las sesiones
          \post El parámetro implícito es el mismo con los identificadores de las
          sesiones leídas; también se guarda los identificadores de los problemas de
          cada sesion y la sesión en la que petenecen. Si se detecta que la interseccion
          de problemas entre sesiones no es vacía, se aborta el guardado de identificadores
          de los problemas y la sesión donde pertenecen, como también se imprime un error
      */
      void Curso::leer_curso(Cjt_sesiones& cjtsesiones, bool& interseccion_vacia) {
        int ns, np;
        cin >> ns;
        string s;
        pair<map<string,string>::const_iterator,bool> res;
        int i = 0;
        int j;
        while (i < ns) {
          cin >> s;
          sesiones.push_back(s);
          j = 0;
          np = cjtsesiones.num_problemas(s);
          while (j < np and interseccion_vacia) {
            res = problemas.insert(make_pair(cjtsesiones.id_problema(s,j),s));
            if (not res.second) {
              interseccion_vacia = false;
              cout << "error: curso mal formado" << endl;
            }
            ++j;
          }
          ++i;
        }
      }

      /** @brief Imprime un curso.
          \pre cierto
          \post Imprime el nº de usuarios que lo han completado, el nº de usuarios
          inscritos actualmente, el nº de sesiones que lo forman y los identificadores
          de dichas sesiones, en el mismo orden que se leyeron cuando se creó el curso
      */
      void Curso::escribir_curso() const {
        int ns = sesiones.size();
        cout << graduados << " " << inscritos << " " << ns << " (" << sesiones[0];
        for (int i = 1; i < ns; ++i) {
          cout << " " << sesiones[i];
        }
        cout << ")" << endl;
      }
