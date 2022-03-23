/** @file Curso.hh
    @brief Especificación de la clase Curso

    Un curso está formado por el número de inscritos, el número de usuarios que
    lo han completado (graduados), los identificadores de las sesiones y todos sus
    problemas con la sesion en la que pertenece cada uno.
*/

#ifndef CURSO_HH
#define CURSO_HH

#include "Cjt_sesiones.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#endif

using namespace std;

/** @class Curso
    @brief Representa un curso de la plataforma

    Un curso está formado por el número de inscritos, el número de usuarios que
    lo han completado (graduados), los identificadores de las sesiones y todos sus
    problemas con la sesion en la que pertenece cada uno.
*/

class Curso
{

private:
    int inscritos; //numero de usuarios inscritos actualmente
    int graduados; //numero de usuarios que han completado el curso
    vector<string> sesiones;
    map<string,string> problemas;

public:
    //Constructoras

    /** @brief Creadora por defecto.
        \pre cierto
        \post El resultado es un curso sin ningun usuario inscrito, sin ningun
        usuario que lo haya completado y sin sesiones
    */
    Curso();

    //Modificadoras

    /** @brief Augmenta en una unidad el nº de inscritos en un curso y lo imprime.
        \pre cierto
        \post El nº de inscritos en el curso augmenta una unidad y lo imprime
    */
    void alta();

    /** @brief Disminuye en una unidad el nº de inscritos en un curso.
        \pre cierto
        \post El nº de inscritos en el curso disminuye una unidad
    */
    void baja();

    /** @brief Disminuye en una unidad el nº de inscritos y augmenta en una unidad el nº de usuarios que han completado un curso.
        \pre cierto
        \post El nº de usuarios que han completado el curso augmenta en una unidad
        y el nº de usuarios inscritos disminuye en una unidad
    */
    void completado();

    //Consultoras

    /** @brief Devuelve el identificador de la sesion en la posicion i en el que se leyó.
        \pre i es un valor entre 0 y el nº de sesiones-1 del parámetro implícito
        \post Devuelve el identificador de la sesion en la posicion i en la que
        se leyó cuando se creó el parámetro implícito
    */
    string id_sesion(int i) const;

    /** @brief Devuelve el nº de sesiones que tiene un curso.
        \pre cierto
        \post Devuelve el nº de sesiones que tiene el parámetro implícito
    */
    int num_sesiones() const;

    /** @brief Consula el nº de usuarios inscritos en un curso.
        \pre cierto
        \post Devuelve el nº de usuarios inscritos al parámetro implícito
    */
    int num_usuarios() const;

    /** @brief Consula si existe un problema con identificador p en un curso.
        \pre cierto
        \post Devuelve cierto si existe un problema con identificador p en el parámetro
        implícito; falso en caso contrario
    */
    bool existe_problema(const string& p) const;

    /** @brief Devuelve el identificador de la sesion que contiene un problema p en el curso con identificador c.
        \pre Existe un problema p en el parámetro implícito
        \post Devuelve el identificador de la sesion donde se realiza el problema p
        en el curso c
    */
    string sesion_problema(const string& p) const;

    // Lectura i escritura

    /** @brief Lee un curso.
        \pre En la entrada hay un entero n y n strings identicadores de las sesiones
        \post El parámetro implícito es el mismo con los identificadores de las
        sesiones leídas; también se guarda los identificadores de los problemas de
        cada sesion y la sesión en la que petenecen. Si se detecta que la interseccion
        de problemas entre sesiones no es vacía, se aborta el guardado de identificadores
        de los problemas y la sesión donde pertenecen, como también se imprime un error
    */
    void leer_curso(Cjt_sesiones& cjtsesiones, bool& interseccion_vacia);

    /** @brief Imprime un curso.
        \pre cierto
        \post Imprime el nº de usuarios que lo han completado, el nº de usuarios
        inscritos actualmente, el nº de sesiones que lo forman y los identificadores
        de dichas sesiones, en el mismo orden que se leyeron cuando se creó el curso
    */
    void escribir_curso() const;
};
#endif
