#include "Usuario.hh"

/** @class Usuario
    @brief Representa un Usuario registrado en la plataforma.

    Está formado por diferentes estadísticas como el número de problemas intentados,
    el número de problemas correcots, el número de envíos totales, el curso al que está
    inscrito (si vale 0, no está inscrito en ninguno), los problemas resueltos y los
    intentos que ha realizado y los problemas que tiene disponibles para intentar y
    los intentos de cada uno.
*/

using namespace std;

//private:
 

//public:
      //Constructoras

      Usuario::Usuario() {
        pint = 0;
        correctos = 0;
        envios = 0;
        curso = 0;
      }

      //Modificadoras

      /** @brief Inscribe un usuario a un curso.
          \pre c no vacío, el parámetro implícito no está inscrito en ningún curso
          \post El parámetro implícito pasa a estar inscrito a un curso c y se guarda
          su identificador
      */
      void Usuario::inscribir_curso(int c) {
        curso = c;
      }

      /** @brief Se toma nota del resultado r de un nuevo envío de un usuario al problema p.
          \pre Existe un problema con identificador p que pertenece al curso al que
          el parámetro implícito está inscrito, el cual puede enviar una solución
          por cumplir los prerequisitos. r puede ser falso o cierto
          \post El nº de envios totales, el nº de problemas intentados y el nº de
          intentos del problema por parte del parámetro implícito se actualizan.
          Si r es cierto, se añade el problema p a los problemas resueltos, se
          suprime de los problemas disponibles/enviables y se actualiza el nº de
          envios correctos del parámetro implícito
      */
      void Usuario::envio(const string& p, bool r) {
        map<string,int>::iterator i1 = disp.find(p);
        if (i1->second == 0) ++pint; //act nº prob. intentados
        ++envios; //act envios totales
        ++i1->second; //act envios del problema disp

        if (r) {
          map<string, int>::const_iterator i2 = presueltos.find(p);
          if (i2 == presueltos.end()) {
            ++correctos; //act envios correctos
            presueltos.insert(make_pair(p, disp[p]));
          }
          else presueltos[p]++;
          //disp.erase(p);
        }
      }

      /** @brief Agrega un problema con identificador p como enviable a un usuario.
          \pre cierto
          \post El parámetro implícito pasa a tener el problema p como enviable
      */
      void Usuario::agregar_problema_disp(const string& p) {
        disp.insert(make_pair(p,0));
      }

      /** @brief Desinscribe un usuario del curso al que está inscrito.
          \pre El parámetro implícito está inscrito a un curso actualmente
          \post El parámetro implícito deja de estar inscrito al curso
      */
      void Usuario::fin_curso() {
        curso = 0;
        disp.clear();
      }

      //Consultoras

      /** @brief Consulta si un usuario está inscrito en algun curso.
          \pre cierto
          \post Devuelve cierto si el parámetro implícito está inscrito a un curso;
          falso en caso contrario
      */
      bool Usuario::esta_inscrito() const {
        if (curso != 0) return true;
        else return false;
      }

      /** @brief Devuelve el identificador del curso al que está inscrito un usuario.
          \pre cierto
          \post Devuelve el identificador del curso al que está inscrito el parámetro
          implícito; si no está inscrito devuelve zero
      */
      int Usuario::curso_usuario() const {
        return curso;
      }

      /** @brief Comprueba si un usuario ha resuelto un problema con identificador p.
          \pre cierto
          \post Devuelve cierto si el parámetro implícito ha resuelto el problema p;
          falso en caso contrario
      */
      bool Usuario::ha_resuelto_problema(const string& p) const {
        map<string,int>::const_iterator it = presueltos.find(p);
        if (it != presueltos.end()) return true;
        else return false;
      }

      /** @brief Comprueba si un usuario ha terminado el curso al que está inscrito.
          \pre El parámetro implícito está inscrito a un curso
          \post Devuelve cierto si el parámetro implícito ha completado el curso al
          que está inscrito; falso en caso contrario
      */
      bool Usuario::ha_terminado() const {
        return disp.empty();
      }

      bool Usuario::es_problema_enviable(const string& p) const {
        map<string, int>::const_iterator it = disp.find(p);
        if (it != disp.end()) return true;
        else return false;
      }

      // Lectura i escritura

      /** @brief Imprime los identificadores de los problemas solucionados correctamente por el usuario y el nº de envios realizado por cada problema.
          \pre cierto
          \post Imprime en orden creciente los identificadores de los problemas
          solucionados correctamente por el parámetro implícito y el nº de envios
          realizado por cada problema
      */
      void Usuario::problemas_resueltos() const {
        for (map<string,int>::const_iterator it = presueltos.begin(); it != presueltos.end(); ++it) {
          cout << it->first << endl;
        }
      }

      /** @brief Imprime los identificadores de los problemas enviables por el usuario y el nº de envios que ha hecho de cada uno.
          \pre cierto
          \post Imprime en orden creciente los identificadores de los problemas
          enviables por el parámetro implícito y el nº de envios >= 0 que ha
          realizado por cada uno. Si el usuario no está inscrito en ningun curso
          se imprime un error
      */
      void Usuario::problemas_enviables() const {
        if (curso != 0) {
          for (map<string,int>::const_iterator it = disp.begin(); it != disp.end(); ++it) {
            cout << it->first << endl;
          }
        }
        else cout << "error: usuario no inscrito en ningun curso" << endl;
      }

      /** @brief Imprime un usuario.
          \pre cierto
          \post Imprime el nº de envios totales, el nº de problemas que ha resuelto
          satisfactoriamente, el nº de problemas que ha intentado y el identificador
          del curso al que está inscrito o un cero si no está inscrito en ninguno
      */
      void Usuario::escribir_usuario() const {
        cout << "(" << envios << "," << correctos << "," << curso << ")" << endl;
      }
