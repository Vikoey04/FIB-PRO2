#include "Cjt_cursos.hh"

/** @class Cjt_cursos
    @brief Representa un Cjt_cursos (conjunto de cursos)
*/

using namespace std;

//private:


//public:
    //Constructoras

    Cjt_cursos::Cjt_cursos() {}

    //Modificadoras

    /** @brief Añade un curso en un Cjt_cursos.
        \pre cierto
        \post El conjunto de cursos es el mismo con un nuevo curso más con el
        identificador N+1; si tiene problemas repetidos se imprime un mensaje de
        error y no se añade. En caso contrario, se imprime su identificador
    */
    void Cjt_cursos::nuevo_curso(Cjt_sesiones& sesiones) {
      Curso cursillo;
      bool interseccion_vacia = true;
      cursillo.leer_curso(sesiones, interseccion_vacia);
      if (interseccion_vacia) {
        cursos.push_back(cursillo);
        cout << cursos.size()-1 << endl;
      }
    }

    /** @brief Augmenta en una unidad el nº de inscritos en un curso c de un Cjt_cursos.
        \pre Existe un curso con identificador c en el parámetro implícito
        \post El nº de inscritos en el curso con identificador c augmenta una unidad
    */
    void Cjt_cursos::alta(int c) {
      cursos[c].alta();
    }

    /** @brief Disminuye en una unidad el nº de inscritos en un curso c de un Cjt_cursos.
        \pre Existe un curso con identificador c en el parámetro implícito
        \post El nº de inscritos en el curso con identificador c disminuye una unidad
    */
    void Cjt_cursos::baja(int c) {
      cursos[c].baja();
    }

    /** @brief Augmenta en una unidad el nº de usuarios que han completado un curso.
        \pre Existe un curso con identificador c en el parámetro implícito
        \post El nº de usuarios que han completado el curso con identificador c
        augmenta en una unidad
    */
    void Cjt_cursos::completado(int c) {
      cursos[c].completado();
    }
    
    //Consultoras

    /** @brief Comprueba si existe un curso con identificador c en un Cjt_cursos.
        \pre cierto
        \post Devuelve cierto si existe un curso con identificador c en el
        parámetro implícito; falso en caso contrario
    */
    bool Cjt_cursos::existe_curso(int c) const {
      if (c > 0 and c < cursos.size()) return true;
      else return false;
    }

    /** @brief Comprueba si existe un problema con identificador p en un curso c de un Cjt_cursos.
        \pre Existe un curso c en el parámetro implícito
        \post Devuelve cierto si existe un problema p en un curso con identificador
        c en el parámetro implícito; falso en caso contrario
    */
    bool Cjt_cursos::existe_problema(const string& p, int c) const {
      return cursos[c].existe_problema(p);
    }

    /** @brief Devuelve el identificador de una sesion en la posición i en la que se leyó en un curso c de un Cjt_cursos.
        \pre Existe un curso c en el parámetro implícito y i es un valor entre 0 y el
        nº de sesiones-1 de este curso
        \post Devuelve el identificador de una sesion en la posición i en la que se
        leyó en un curso c del parámetro implícito
    */
    string Cjt_cursos::id_sesion(int c, int i) const {
      return cursos[c].id_sesion(i);
    }

    /** @brief Devuelve el nº de sesiones de un curso c de un Cjt_cursos
        \pre Existe un curso c en el parámetro implícito
        \post Devuelve nº de sesiones de un curso con identificador c del parámetro
        implícito
    */
    int Cjt_cursos::num_sesiones(int c) const {
      return cursos[c].num_sesiones();
    }

    int Cjt_cursos::num_usuarios(int c) const {
      return cursos[c].num_usuarios();
    }

    //Lectura y escritura

    /** @brief Lee los cursos para un Cjt_cursos dado un nº de cursos a leer.
        \pre Hay en la entrada un entero N > 0 y para cada uno de los N cursos un
        entero Sc > 0 de sesiones y una secuencia de Sc strings identificadores válidos
        y sin repeticiones. La intersección de problemas entre sesiones de un mismo
        curso es siempre vacía
        \post El resultado es un Cjt_sesiones con N cursos identificados según el orden
        de entrada, cada uno con su correspondiente secuencia de problemas leídos.
        El primer curso tiene identificador 1, y así sucesivamente.
    */
    void Cjt_cursos::leer_cursos(Cjt_sesiones& sesiones) {
      int nc;
      cin >> nc;
      cursos = vector<Curso> (nc+1);
      bool interseccion_vacia = true;
      for (int i = 1; i <= nc; ++i) {
        cursos[i].leer_curso(sesiones, interseccion_vacia);
      }
    }

    /** @brief Imprime el identificador de la sesion donde se realiza un problema p en un curso c de un Cjt_cursos.
        \pre Existe un curso c en el parámetro implícito y un problema p en este
        curso
        \post Imprime el identificador de la sesion donde se realiza el problema p
        en el curso c; si el problema no pertence al curso o el curso no existe se
        imprime un mensaje de error
    */
    string Cjt_cursos::sesion_problema(int c, const string& p) const {
      return cursos[c].sesion_problema(p);
    }

    /** @brief Imprime el nº de usuarios inscritos en un curso c de un Cjt_cursos.
        \pre Existe un curso con identificador c en el parámetro implícito
        \post Imprime el nº de usuarios inscritos en el curso con identificador c
        del parámetro implícito
    */
    void Cjt_cursos::imprimir_num_usuarios(int c) const {
      cout << cursos[c].num_usuarios() << endl;
    }

    /** @brief Imprime un usuario con identificador c de un Cjt_usuarios.
        \pre cierto
        \post Imprime su identificador, el nº de envios totales, el nº de
        problemas que ha resuelto satisfactoriamente, el nº de problemas que ha
        intentado y el identificador del curso al que está inscrito o un cero si
        no está inscrito en ninguno. Si el usuario no existe se imprime un error
    */
    void Cjt_cursos::escribir_curso(int c) const {
      if (c > 0 and c < cursos.size()) {
        cout << c << " ";
        cursos[c].escribir_curso();
      }
      else cout << "error: el curso no existe" << endl;
    }

    /** @brief Lista los cursos actuales de la plataforma.
        \pre cierto
        \post Lista los cursos ordenados crecientemente por su identificador;
        para cada curso imprime le nº de usuarios que lo han completado, el nº
        de usuarios inscritos actualmente, el nº de sesiones que lo forman y los
        identificadores de dichas sesiones, en el mismo orden que se leyeron
        cuando se creó el curso
    */
    void Cjt_cursos::listar_cursos() const {
      int n = cursos.size();
      for (int i = 1; i < n; ++i) {
        cout << i << " ";
        cursos[i].escribir_curso();
      }
    }
