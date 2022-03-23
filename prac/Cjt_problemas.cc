#include "Cjt_problemas.hh"

using namespace std;

/** @class Cjt_problemas
    @brief Representa un Cjt_problemas (conjunto de problemas)
*/

//private:

    /** @brief Funcion de comparación de dos elementos segun el ratio y si hay empate segun identificador creciente.
        \pre cierto
        \post Funcion de comparación de dos elementos segun el ratio y si hay empate
        segun identificador creciente
    */
    bool Cjt_problemas::comp(prat p1, prat p2) {
      if (p1.ratio == p2.ratio) return p1.id < p2.id;
      else return p1.ratio < p2.ratio;
    }

//public:
    //Constructoras

    Cjt_problemas::Cjt_problemas() {}

    //Modificadoras

    /** @brief Añade un nuevo problema con identificador p a un Cjt_problemas.
        \pre cierto
        \post Se añade un nuevo problema con identificador p en el parámetro
        implícito; si ya existe un problema con el mismo identificador se imprime
        un error. En caso contrario imprime el nº de problemas del parámetro implícito
    */
    void Cjt_problemas::nuevo_problema(const string& p) {
      map<string, Problema>::const_iterator it = problemas.find(p);
      if (it == problemas.end()) {
        problemas[p] = Problema();
        cout << problemas.size() << endl;
      }
      else cout << "error: el problema ya existe" << endl;
    }

    /** @brief Actualiza el número de envíos totales y correctos de un problema de un Cjt_problemas.
        \pre Existe un problema con identificador p. r vale 1 o 0
        \post El nº de envios totales del problema augmentan en una unidad. Si
        r = 1, también augmenta en una unidad el nº de envíos correctos del problema
    */
    void Cjt_problemas::act_envios(const string& p, bool r) {
      map<string, Problema>::iterator it = problemas.find(p);
      if (it != problemas.end()) it->second.act_envios(r);
    }

    //Consultoras

    /** @brief Devuelve el nº de problemas de un Cjt_problemas.
        \pre cierto
        \post Devuelve el nº de problemas del parámetro implícito
    */
    int Cjt_problemas::num_problemas() const {
      return problemas.size();
    }

    /** @brief Consulta si existe un problema con identificador p en un Cjt_problemas.
        \pre cierto
        \post Devuelve cierto si existe un problema con identificador p en el
        parámetro implícito
    */
    bool Cjt_problemas::existe_problema(const string& p) const {
      map<string, Problema>::const_iterator it = problemas.find(p);
      if (it != problemas.end()) return true;
      else return false;
    }

    //Lectura y escritura

    /** @brief Lee los problemas para un Cjt_problemas dado un nº de problemas a leer.
        \pre Hay en la entrada un entero P > 0 y P strings identificadores de los problemas
        \post El resultado es un Cjt_problemas con P problemas cuyos strings son los
        leidos por la entrada
    */
    void Cjt_problemas::leer_problemas() {
      int nump;
      string p;
      cin >> nump;
      for (int i = 0; i <nump; ++i) {
        cin >> p;
        problemas.insert(make_pair(p, Problema()));
      }
    }

    /** @brief Escribe un problema con identificador p de un Cjt_problemas.
        \pre cierto
        \post Del problema imprime el nº t de envíos totales y el nº e de envíos
        con éxito a dicho problema, en ambos casos de usuarios presentes o pasados.
        También imprime el ratio (t+1)/(e+1). Si el problema no existe se imprime
        un error
    */
    void Cjt_problemas::escribir_problema(const string& p) const {
      map<string, Problema>::const_iterator it = problemas.find(p);
      if (it != problemas.end()) {
        cout << it->first;
        it->second.escribir_problema();
        cout << it->second.ratio() << ")" << endl;
      }
      else cout << "error: el problema no existe" << endl;
    }

    /** @brief Lista los problemas de un Cjt_problemas.
        \pre cierto
        \post Lista los problemas de la colección; para cada problema imprime el
        nº t de envíos totales y el nº e de envíos con éxito a dicho problema, en
        ambos casos de usuarios presentes o pasados. También imprime el ratio
        (t+1)/(e+1) con el cúal se listan los problemas de forma creciente. En caso
        de empate, se listarán de forma creciente según el identificador
    */
    void Cjt_problemas::listar_problemas() const {
      vector<prat> v;
      prat prat;
      for (map<string,Problema>::const_iterator it = problemas.begin(); it != problemas.end(); ++it) {
        prat.id = it->first;
        prat.ratio = it->second.ratio();
        prat.problema = it->second;
        v.push_back(prat);
      }
      sort(v.begin(), v.end(), comp);
      int n = v.size();

      for (int i = 0; i < n; ++i) {
        prat = v[i];
        cout << prat.id;
        prat.problema.escribir_problema();
        cout << prat.ratio << ")" << endl;
      }
    }
