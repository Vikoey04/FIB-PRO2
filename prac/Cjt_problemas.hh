/** @file Cjt_problemas.hh
    @brief Especificación de la clase Cjt_problemas (conjunto de problemas)
*/

#ifndef CJT_PROBLEMAS
#define CJT_PROBLEMAS

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#endif

using namespace std;

/** @class Cjt_problemas
    @brief Representa un conjunto de problemas
*/

class Cjt_problemas
{

private:
    map<string, Problema> problemas;

    struct prat {
      string id;
      Problema problema;
      double ratio;
    };

    /** @brief Funcion de comparación de dos elementos segun el ratio y si hay empate segun identificador creciente.
        \pre cierto
        \post Funcion de comparación de dos elementos segun el ratio y si hay empate
        segun identificador creciente
    */
    static bool comp(prat p1, prat p2);
public:
    //Constructoras

    /** @brief Creadora por defecto.
        \pre cierto
        \post El resultado es un Cjt_problemas vacío
    */
    Cjt_problemas();

    //Modificadoras

    /** @brief Añade un nuevo problema con identificador p a un Cjt_problemas.
        \pre cierto
        \post Se añade un nuevo problema con identificador p en el parámetro
        implícito; si ya existe un problema con el mismo identificador se imprime
        un error. En caso contrario imprime el nº de problemas del parámetro implícito
    */
    void nuevo_problema(const string& p);

    /** @brief Actualiza el número de envíos totales y correctos de un problema de un Cjt_problemas.
        \pre Existe un problema con identificador p. r vale 1 o 0
        \post El nº de envios totales del problema augmentan en una unidad. Si
        r = 1, también augmenta en una unidad el nº de envíos correctos del problema
    */
    void act_envios(const string& p, bool r);

    //Consultoras

    /** @brief Devuelve el nº de problemas de un Cjt_problemas.
        \pre cierto
        \post Devuelve el nº de problemas del parámetro implícito
    */
    int num_problemas() const;

    /** @brief Consulta si existe un problema con identificador p en un Cjt_problemas.
        \pre cierto
        \post Devuelve cierto si existe un problema con identificador p en el
        parámetro implícito
    */
    bool existe_problema(const string& p) const;

    //Lectura y escritura

    /** @brief Lee los problemas para un Cjt_problemas dado un nº de problemas a leer.
        \pre Hay en la entrada un entero P > 0 y P strings identificadores de los problemas
        \post El resultado es un Cjt_problemas con P problemas cuyos strings son los
        leidos por la entrada
    */
    void leer_problemas();

    /** @brief Escribe un problema con identificador p de un Cjt_problemas.
        \pre cierto
        \post Del problema imprime el nº t de envíos totales y el nº e de envíos
        con éxito a dicho problema, en ambos casos de usuarios presentes o pasados.
        También imprime el ratio (t+1)/(e+1). Si el problema no existe se imprime
        un error
    */
    void escribir_problema(const string& p) const;

    /** @brief Lista los problemas de un Cjt_problemas.
        \pre cierto
        \post Lista los problemas de la colección; para cada problema imprime el
        nº t de envíos totales y el nº e de envíos con éxito a dicho problema, en
        ambos casos de usuarios presentes o pasados. También imprime el ratio
        (t+1)/(e+1) con el cúal se listan los problemas de forma creciente. En caso
        de empate, se listarán de forma creciente según el identificador
    */
    void listar_problemas() const;

};
#endif
