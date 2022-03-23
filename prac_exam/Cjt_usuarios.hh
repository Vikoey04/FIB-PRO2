/** @file Cjt_usuarios.hh
    @brief Especificación de la clase Cjt_usuarios (conjunto de usuarios)
*/

#ifndef CJT_USUARIOS
#define CJT_USUARIOS

#include "Usuario.hh"
#include "Cjt_cursos.hh"
#include "Cjt_sesiones.hh"
#include "Cjt_problemas.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif

using namespace std;

/** @class Cjt_usuarios
    @brief Representa un conjunto de usuarios
*/

class Cjt_usuarios
{

private:
    map<string, Usuario> users;

public:
    //Constructoras

    /** @brief Creadora por defecto
        \pre cierto
        \post El resultado es un Cjt_usuarios vacío
    */
    Cjt_usuarios();

    //Modificadoras

    /** @brief Añade una usuario con identificador u a un Cjt_usuarios.
        \pre cierto
        \post El resultado es el mismo Cjt_usuarios con un nuevo usuario con el
        identificador u; si ya existe un usuario con el mismo identificador se
        imprime un error
    */
    void alta_usuario(const string& u);

    /** @brief Elimina una usuario con identificador u de un Cjt_usuarios.
        \pre cierto
        \post El resultado es el mismo Cjt_usuarios sin el usuario con
        identificador u; si no existe un usuario con este identificador se
        imprime un error
    */
    void baja_usuario(const string& u, Cjt_cursos& cursos);

    /** @brief Inscribe un usuario con identificador u de un Cjt_usuarios a un curso con identificador c.
        \pre cierto
        \post Si el usuario no existe, si el curso no existe o si el usuario está
        inscrito en otro curso se imprime un error. Si existen y no está inscrito
        a ningun curso pasa a estar inscrito al curso con identificador c y el nº
        de usuarios inscritos del curso augmenta en una unidad. También se
        actualizan los problemas enviables del usuario. Si el usuario ha hecho todos
        los problemas del curso al que se ha inscrito, se desincribe como si lo hubiera
        autocompletado y se actualizan las estadísticas
    */
    void inscribir_curso(const string& u, int c, Cjt_cursos& cursos, Cjt_sesiones& sesiones);

    /** @brief Desinscribe de un curso a un usuario u de un Cjt_usuarios.
        \pre Existe un curso con identificador c y un usuario con identificador u
        \post El usuario deja de estar inscrito a un curso
    */
    void fin_curso(const string& u);

    /** @brief Se toma nota del resultado r de un nuevo envío de un usuario u al problema p.
        \pre Existe un usuario con identificador u y un problema con identificador
        p que pertenece al curso al que el usuario está inscrito, el cual puede enviar
        una solución por cumplir los prerequisitos. r puede ser falso o cierto
        \post El nº de envios totales, el nº de problemas intentados y el nº de
        intentos del problema por parte del parámetro implícito se actualizan.
        El nº de envios totales del problema augmenta en una unidad. Si r es cierto,
        se añade el problema p a los problemas resueltos, se suprime de los problemas
        disponibles/enviables y se actualiza el nº de envios correctos del parámetro
        implícito. También se actualizan los problemas enviables del parámetro implícito
        y se comprueba si ha terminado el curso; si es así, se desinscribe del curso y
        el nº de usuarios que han completado el curso augmenta en una unidad y el nº de
        usuarios inscritos disminuye en una unidad
    */
    void envio(const string& u, const string& p, bool r, Cjt_problemas& problemas, Cjt_sesiones& sesiones, Cjt_cursos& cursos);

    void acabar_curso(const string& u, Cjt_cursos& cursos);

    //Consultoras

    /** @brief Devuelve el nº de usuarios de un Cjt_usuarios.
        \pre cierto
        \post Devuelve el nº de usuarios del parámetro implícito
    */
    int num_usuarios() const;

    /** @brief Comprueba si existe un usuario con identificador u en un Cjt_usuarios.
        \pre cierto
        \post Devuelve cierto si existe un usuario con el identificador u en el
        parámetro implícito; falso en caso contrario
    */
    bool existe_usuario(const string& u) const;

    /** @brief Comprueba si un usuario de un Cjt_usuarios actualmente está inscrito en algun curso.
        \pre Existe un usuario con identificador u en el parámetro implícito
        \post Devuelve cierto si el usuario con identificador u está actualmente
        inscrito en algun curso; falso en caso contrario
    */
    bool esta_inscrito(const string& u) const;

    /** @brief Imprime el curso en el que está inscrito el usuario u de un Cjt_usuarios.
        \pre cierto
        \post Imprime el identificador del curso o un cero si no esta inscrito
         en ningun curso; si el usuario no existe se imprime un error
    */
    void curso_usuario(const string& u) const;

    /** @brief Imprime los identificadores de los problemas solucionados correctamente por el usuario con identificador u y el nº de envios realizado por cada problema.
        \pre cierto
        \post Imprime en orden creciente los identificadores de los problemas
        solucionados correctamente por el usuario con identificador u y el nº de
        envios realizado por cada problema; si el usuario no existe se imprime
        un error
    */
    void problemas_resueltos(const string& u) const;

    /** @brief Imprime los identificadores de los problemas enviables por el usuario con identificador u y el nº de envios que ha hecho de cada uno.
        \pre cierto
        \post Imprime en orden creciente los identificadores de los problemas
        enviables por el usuario con identificador u y el nº de envios >= 0 que ha
        realizado por cada uno. Si el usuario no existe o si el usuario no está
        inscrito en ningun curso se imprime un error
    */
    void problemas_enviables(const string& u) const;

    //Lectura y escritura

    /** @brief Lee los usuarios para un Cjt_usuarios dado un nº de usuarios a leer.
        \pre Hay en la entrada un entero M > 0 y M strings identificadores de los
        usuarios no repetidos
        \post El resultado es un Cjt_usuarios con M usuarios cuyos identificadores
        son los leidos por la entrada
    */
    void leer_usuarios();

    /** @brief Imprime un usuario con identificador u de un Cjt_usuarios.
        \pre cierto
        \post Imprime su identificador, el nº de envios totales, el nº de
        problemas que ha resuelto satisfactoriamente, el nº de problemas que ha
        intentado y el identificador del curso al que está inscrito o un cero si
        no está inscrito en ninguno. Si el usuario no existe se imprime un error
    */
    void escribir_usuario(const string& u) const;

    /** @brief Lista los usuarios registrados actualmente por la plataforma.
        \pre cierto
        \post Lista los usuarios registrados actualmente por la plataforma; para
        cada usuario imprime su identificador, el nº de envios totales, el nº de
        problemas que ha resuelto satisfactoriamente, el nº de problemas que ha
        intentado y el identificador del curso al que está inscrito o un cero si
        no está inscrito en ninguno
    */
    void listar_usuarios() const;

};
#endif
