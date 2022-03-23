#include "Cjt_sesiones.hh"

using namespace std;

/** @class Cjt_sesiones
    @brief Representa un Cjt_sesiones (conjunto de sesiones)
*/

//private:


//public:
    //Constructoras

    Cjt_sesiones::Cjt_sesiones() {}

    //Modificadoras

    /** @brief Añade una sesion con identificador s a un Cjt_sesiones.
        \pre cierto
        \post El resultado es el mismo Cjt_sesiones con una nueva sesion con el
        identificador s; si ya existe una sesion con este identificador se imprime
        un error
    */
    void Cjt_sesiones::nueva_sesion(const string& s) {
      map<string, Sesion>::const_iterator it = sesiones.find(s);
      if (it == sesiones.end()) {
        sesiones[s];
        cout << sesiones.size() << endl;
      }
      else cout << "error: la sesion ya existe" << endl;
    }

    /** @brief Actualiza los problemas enviables sucesores de un problema p (este incluido), que pertenecen a una sesion de un Cjt_sesiones, de un usuario.
        \pre Existe una sesion s en el parámetro implícito
        \post Actualiza los problemas enviables sucesores de un problema p
        (este incluido), que pertenecen a la sesion del parámetro implícito,
        del usuario
    */
    void Cjt_sesiones::act_problemas_enviables(const string& s, const string& p, Usuario& usuario) const {
      map<string, Sesion>::const_iterator it = sesiones.find(s);
      it->second.act_problemas_enviables(p,usuario);
    }

    /** @brief Actualiza los problemas enviables, que pertenecen a una sesion de un Cjt_sesiones, de un usuario.
        \pre Existe una sesion s en el parámetro implícito
        \post Actualiza los problemas enviables, que pertenecen a la sesion del
        parámetro implícito, del usuario
    */
    void Cjt_sesiones::problemas_enviables(const string& s, Usuario& usuario) const {
      map<string, Sesion>::const_iterator it = sesiones.find(s);
      it->second.problemas_enviables(usuario);
    }

    //Consultoras

    /** @brief Devuelve el identificador del primer problema de una sesion s de un Cjt_sesiones.
        \pre cierto
        \post Devuelve el identificador del primer problema de una sesion con
        identificador s del parámetro implícito.
    */
    string Cjt_sesiones::id_problema(const string& s, int i) {
      map<string, Sesion>::const_iterator it = sesiones.find(s);
      return it->second.id_problema(i);
    }

    /** @brief Devuelve el nº de sesiones de un Cjt_sesiones.
        \pre cierto
        \post Devuelve el nº de sesiones del parámetro implícito
    */
    int Cjt_sesiones::num_sesiones() const {
      return sesiones.size();
    }

    /** @brief Devuelve el nº de problemas de una sesion de un Cjt_sesiones.
        \pre Existe una sesion con identificador s en el parámetro implícito
        \post Devuelve el nº de problemas de una sesion del parámetro implícito
    */
    int Cjt_sesiones::num_problemas(const string& s) const {
      map<string, Sesion>::const_iterator it = sesiones.find(s);
      return it->second.num_problemas();
    }

    /** @brief Consulta si existe una sesion con identificador s en un Cjt_sesiones.
        \pre cierto
        \post Devuelve cierto si existe una sesion con identificador s en el
        parámetro implícito; falso en caso contrario
    */
    bool Cjt_sesiones::existe_sesion(const string& s) const {
      map<string, Sesion>::const_iterator it = sesiones.find(s);
      if (it != sesiones.end()) return true;
      else return false;
    }

    /** @brief Consulta si existe un problema con identificador p en una sesion con identificador s del Cjt_sesiones.
        \pre cierto
        \post Devuelve cierto si existe un problema con identificador p en la
        sesion con identificador s del Cjt_sesiones; falso en caso contrario
    */
    bool Cjt_sesiones::existe_problema(const string& p, const string& s) const {
      map<string, Sesion>::const_iterator it = sesiones.find(s);
      return it->second.existe_problema(p);
    }

    /** @brief Devuelve una sesion con identificador s de un Cjt_sesiones.
        \pre Existe una sesion con identificador s en el parámetro implícito
        \post Devuelve una sesion con identificador c del parámetro implícito
    */
    Sesion Cjt_sesiones::sesion(const string& s) {
      map<string, Sesion>::const_iterator it = sesiones.find(s);
      return it->second;
    }

    //Lectura y escritura

    /** @brief Lee las sesiones para un Cjt_sesiones dado un nº de sesiones a leer.
        \pre Hay en la entrada un entero Q > 0 y Q strings identificadores de las sesiones
        sin repeticiones
        \post El resultado es el parámetro implícito con Q sesiones cuyos strings son los
        leidos por la entrada
    */
    void Cjt_sesiones::leer_sesiones() {
      int q;
      string s;
      cin >> q;
      for (int i = 0; i < q; ++i) {
        cin >> s;
        sesiones.insert(make_pair(s, Sesion()));
      }
    }

    /** @brief Escribe una sesion con identificador s de un Cjt_sesiones.
        \pre cierto
        \post De la sesion imprime el nº de problemas que la forman y los
        identificadores de dichos problemas siguiendo su estructura de
        prerequisitos en postorden. Si la sesion no existe se imprime un error
    */
    void Cjt_sesiones::escribir_sesion(const string& s) const {
      map<string, Sesion>::const_iterator it = sesiones.find(s);
      if (it != sesiones.end()) {
        cout << it->first << " ";
        it->second.escribir_sesion();
      }
      else cout << "error: la sesion no existe" << endl;
    }

    /** @brief Lista las sesiones de un Cjt_sesiones.
        \pre cierto
        \post Lista las sesiones actuales de la plataforma; para cada una imprime
        el nº de problemas que la forman y los identificadores de dichos problemas
        siguiendo su estructura de prerequisitos en postorden
    */
    void Cjt_sesiones::listar_sesiones() const {
      for (map<string, Sesion>::const_iterator it = sesiones.begin(); it != sesiones.end(); ++it) {
        cout << it->first << " ";
        it->second.escribir_sesion();
      }
    }
