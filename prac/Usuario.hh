/** @file Usuario.hh
    @brief Especificación de la clase usuario
*/

#ifndef USUARIO_HH
#define USUARIO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <string>
#endif

using namespace std;

/** @class Usuario
    @brief Especificación de la clase Usuario

    Está formado por diferentes estadísticas como el número de problemas intentados,
    el número de problemas correcots, el número de envíos totales, el curso al que está
    inscrito (si vale 0, no está inscrito en ninguno), los problemas resueltos y los
    intentos que ha realizado y los problemas que tiene disponibles para intentar y
    los intentos de cada uno.
*/

class Usuario
{

private:
    int pint; //problemas intentados
    int correctos; //problemas correctos
    int envios; //envios totales
    int curso; //curso al que está inscrito, si vale zero no está inscrito en ninguno
    map<string, int> presueltos;
    map<string, int> disp;

public:
    //Constructoras

    /** @brief Creadora por defecto.
        \pre cierto
        \post El resultado es un Usuario sin estadísticas o iguales a 0
    */
    Usuario();

    //Modificadoras

    /** @brief Inscribe un usuario a un curso.
        \pre c no vacío, el parámetro implícito no está inscrito en ningún curso
        \post El parámetro implícito pasa a estar inscrito a un curso c y se guarda
        su identificador
    */
    void inscribir_curso(int c);

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
    void envio(const string& p, bool r);

    /** @brief Agrega un problema con identificador p como enviable a un usuario.
        \pre cierto
        \post El parámetro implícito pasa a tener el problema p como enviable
    */
    void agregar_problema_disp(const string& p);

    /** @brief Desinscribe un usuario del curso al que está inscrito.
        \pre El parámetro implícito está inscrito a un curso actualmente
        \post El parámetro implícito deja de estar inscrito al curso
    */
    void fin_curso();

    //Consultoras

    /** @brief Consulta si un usuario está inscrito en algun curso.
        \pre cierto
        \post Devuelve cierto si el parámetro implícito está inscrito a un curso;
        falso en caso contrario
    */
    bool esta_inscrito() const;

    /** @brief Devuelve el identificador del curso al que está inscrito un usuario.
        \pre cierto
        \post Devuelve el identificador del curso al que está inscrito el parámetro
        implícito; si no está inscrito devuelve zero
    */
    int curso_usuario() const;
    
    /** @brief Comprueba si un usuario ha resuelto un problema con identificador p.
        \pre cierto
        \post Devuelve cierto si el parámetro implícito ha resuelto el problema p;
        falso en caso contrario
    */
    bool ha_resuelto_problema(const string& p) const;

    /** @brief Comprueba si un usuario ha terminado el curso al que está inscrito.
        \pre El parámetro implícito está inscrito a un curso
        \post Devuelve cierto si el parámetro implícito ha completado el curso al
        que está inscrito; falso en caso contrario
    */
    bool ha_terminado() const;

    // Lectura i escritura

    /** @brief Imprime los identificadores de los problemas solucionados correctamente por el usuario y el nº de envios realizado por cada problema.
        \pre cierto
        \post Imprime en orden creciente los identificadores de los problemas
        solucionados correctamente por el parámetro implícito y el nº de envios
        realizado por cada problema
    */
    void problemas_resueltos() const;

    /** @brief Imprime los identificadores de los problemas enviables por el usuario y el nº de envios que ha hecho de cada uno.
        \pre cierto
        \post Imprime en orden creciente los identificadores de los problemas
        enviables por el parámetro implícito y el nº de envios >= 0 que ha
        realizado por cada uno. Si el usuario no está inscrito en ningun curso
        se imprime un error
    */
    void problemas_enviables() const;

    /** @brief Imprime un usuario.
        \pre cierto
        \post Imprime el nº de envios totales, el nº de problemas que ha resuelto
        satisfactoriamente, el nº de problemas que ha intentado y el identificador
        del curso al que está inscrito o un cero si no está inscrito en ninguno
    */
    void escribir_usuario() const;
};
#endif
