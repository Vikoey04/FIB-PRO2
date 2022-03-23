/** @file Cjt_sesiones.hh
    @brief Especificación de la clase conjunto de sesiones
*/

#ifndef CJT_SESIONES
#define CJT_SESIONES

#include "Sesion.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif

using namespace std;

/** @class Cjt_sesiones
    @brief Especificación de la clase Cjt_sesiones (conjunto de sesiones)
*/

class Cjt_sesiones
{
private:
    map<string, Sesion> sesiones;

public:
    //Constructoras

    /** @brief Creadora por defecto.
        \pre cierto
        \post El resultado es un Cjt_sesiones vacío
    */
    Cjt_sesiones();

    //Modificadoras

    /** @brief Añade una sesion con identificador s a un Cjt_sesiones.
        \pre cierto
        \post El resultado es el mismo Cjt_sesiones con una nueva sesion con el
        identificador s; si ya existe una sesion con este identificador se imprime
        un error
    */
    void nueva_sesion(const string& s);

    /** @brief Actualiza los problemas enviables sucesores de un problema p (este incluido), que pertenecen a una sesion de un Cjt_sesiones, de un usuario.
        \pre Existe una sesion s en el parámetro implícito
        \post Actualiza los problemas enviables sucesores de un problema p
        (este incluido), que pertenecen a la sesion del parámetro implícito,
        del usuario
    */
    void act_problemas_enviables(const string& s, const string& p, Usuario& usuario) const;

    /** @brief Actualiza los problemas enviables, que pertenecen a una sesion de un Cjt_sesiones, de un usuario.
        \pre Existe una sesion s en el parámetro implícito
        \post Actualiza los problemas enviables, que pertenecen a la sesion del
        parámetro implícito, del usuario
    */
    void problemas_enviables(const string& s, Usuario& usuario) const;

    //Consultoras

    /** @brief Devuelve el identificador del primer problema de una sesion s de un Cjt_sesiones.
        \pre cierto
        \post Devuelve el identificador del primer problema de una sesion con
        identificador s del parámetro implícito.
    */
    string id_problema(const string& s, int i);

    /** @brief Devuelve el nº de sesiones de un Cjt_sesiones.
        \pre cierto
        \post Devuelve el nº de sesiones del parámetro implícito
    */
    int num_sesiones() const;

    /** @brief Devuelve el nº de problemas de una sesion de un Cjt_sesiones.
        \pre Existe una sesion con identificador s en el parámetro implícito
        \post Devuelve el nº de problemas de una sesion del parámetro implícito
    */
    int num_problemas(const string& s) const;

    /** @brief Consulta si existe una sesion con identificador s en un Cjt_sesiones.
        \pre cierto
        \post Devuelve cierto si existe una sesion con identificador s en el
        parámetro implícito; falso en caso contrario
    */
    bool existe_sesion(const string& s) const;

    /** @brief Consulta si existe un problema con identificador p en una sesion con identificador s del Cjt_sesiones.
        \pre cierto
        \post Devuelve cierto si existe un problema con identificador p en la
        sesion con identificador s del Cjt_sesiones; falso en caso contrario
    */
    bool existe_problema(const string& p, const string& s) const;

    /** @brief Devuelve una sesion con identificador s de un Cjt_sesiones.
        \pre Existe una sesion con identificador s en el parámetro implícito
        \post Devuelve una sesion con identificador c del parámetro implícito
    */
    Sesion sesion(const string& s);

    //Lectura y escritura

    /** @brief Lee las sesiones para un Cjt_sesiones dado un nº de sesiones a leer.
        \pre Hay en la entrada un entero Q > 0 y Q strings identificadores de las sesiones
        sin repeticiones
        \post El resultado es el parámetro implícito con Q sesiones cuyos strings son los
        leidos por la entrada
    */
    void leer_sesiones();

    /** @brief Escribe una sesion con identificador s de un Cjt_sesiones.
        \pre cierto
        \post De la sesion imprime el nº de problemas que la forman y los
        identificadores de dichos problemas siguiendo su estructura de
        prerequisitos en postorden. Si la sesion no existe se imprime un error
    */
    void escribir_sesion(const string& s) const;

    /** @brief Lista las sesiones de un Cjt_sesiones.
        \pre cierto
        \post Lista las sesiones actuales de la plataforma; para cada una imprime
        el nº de problemas que la forman y los identificadores de dichos problemas
        siguiendo su estructura de prerequisitos en postorden
    */
    void listar_sesiones() const;

};
#endif
