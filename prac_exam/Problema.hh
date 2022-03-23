/** @file Problema.hh
    @brief Especificación de la clase Problema

    Un problema forma parte de una sesion. Este está formado por el número de envios
    totales que se han realizado y el número de envios correctos.
*/

#ifndef PROBLEMA_HH
#define PROBLEMA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

using namespace std;

/** @class Problema
    @brief Especifiación de clase Problema

    Un problema forma parte de una sesion. Este está formado por el número de envios
    totales que se han realizado y el número de envios correctos.
*/

class Problema
{

private:

    int t; //envios totales
    int e; //envios con éxito

public:
    //Constructoras

    /** @brief Creadora por defecto.
        \pre cierto
        \post El resultado es un problema con el nº de envíos totales y el nº de
        envíos correctos que se han realizado igual a 0
    */
    Problema();

    //Modificadoras

    /** @brief Actualiza el número de envios totales y correctos de un problema dada una respuesta r.
        \pre cierto
        \post El nº de envios totales del problema augmentan en una unidad. Si
        r es cierto, también augmenta en una unidad el nº de envíos correctos del
        problema
    */
    void act_envios(bool r);

    //Consultoras

    /** @brief Devuelve el ratio de un problema.
        \pre cierto
        \post Devuelve el ratio (t+1)/(e+1) del parámetro implícito
    */
    double ratio() const;

    // Lectura i escritura

    /** @brief Imprime un problema.
        \pre cierto
        \post De un problema, imprime el nº de envíos totales y el nº de envíos con
        éxito, en ambos casos de usuarios presentes o pasados
    */
    void escribir_problema() const;
};
#endif
