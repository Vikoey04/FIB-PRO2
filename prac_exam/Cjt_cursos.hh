/** @file Cjt_cursos.hh
    @brief Especificación de la clase Cjt_cursos (conjunto de cursos)
*/

#ifndef CJT_CURSOS
#define CJT_CURSOS

#include "Curso.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#endif

/** @class Cjt_cursos
    @brief Representa un conjunto de cursos
*/

using namespace std;

class Cjt_cursos
{

private:
    vector<Curso> cursos;

public:
    //Constructoras

    /** @brief Creadora por defecto.
        \pre cierto
        \post El resultado es un Cjt_cursos vacío
    */
    Cjt_cursos();

    //Modificadoras

    /** @brief Añade un curso en un Cjt_cursos.
        \pre cierto
        \post El conjunto de cursos es el mismo con un nuevo curso más con el
        identificador N+1; si tiene problemas repetidos se imprime un mensaje de
        error y no se añade. En caso contrario, se imprime su identificador
    */
    void nuevo_curso(Cjt_sesiones& sesiones);


    /** @brief Augmenta en una unidad el nº de inscritos en un curso c de un Cjt_cursos.
        \pre Existe un curso con identificador c en el parámetro implícito
        \post El nº de inscritos en el curso con identificador c augmenta una unidad
    */
    void alta(int c);

    /** @brief Disminuye en una unidad el nº de inscritos en un curso c de un Cjt_cursos.
        \pre Existe un curso con identificador c en el parámetro implícito
        \post El nº de inscritos en el curso con identificador c disminuye una unidad
    */
    void baja(int c);

    /** @brief Augmenta en una unidad el nº de usuarios que han completado un curso.
        \pre Existe un curso con identificador c en el parámetro implícito
        \post El nº de usuarios que han completado el curso con identificador c
        augmenta en una unidad
    */
    void completado(int c);

    //Consultoras

    /** @brief Comprueba si existe un curso con identificador c en un Cjt_cursos.
        \pre cierto
        \post Devuelve cierto si existe un curso con identificador c en el
        parámetro implícito; falso en caso contrario
    */
    bool existe_curso(int c) const;

    /** @brief Comprueba si existe un problema con identificador p en un curso c de un Cjt_cursos.
        \pre Existe un curso c en el parámetro implícito
        \post Devuelve cierto si existe un problema p en un curso con identificador
        c en el parámetro implícito; falso en caso contrario
    */
    bool existe_problema(const string& p, int c) const;

    /** @brief Devuelve el identificador de una sesion en la posición i en la que se leyó en un curso c de un Cjt_cursos.
        \pre Existe un curso c en el parámetro implícito y i es un valor entre 0 y el
        nº de sesiones-1 de este curso
        \post Devuelve el identificador de una sesion en la posición i en la que se
        leyó en un curso c del parámetro implícito
    */
    string id_sesion(int c, int i) const;

    /** @brief Devuelve el nº de sesiones de un curso c de un Cjt_cursos
        \pre Existe un curso c en el parámetro implícito
        \post Devuelve nº de sesiones de un curso con identificador c del parámetro
        implícito
    */
    int num_sesiones(int c) const;

    int num_usuarios(int c) const;

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
    void leer_cursos(Cjt_sesiones& sesiones);

    /** @brief Imprime el identificador de la sesion donde se realiza un problema p en un curso c de un Cjt_cursos.
        \pre Existe un curso c en el parámetro implícito y un problema p en este
        curso
        \post Imprime el identificador de la sesion donde se realiza el problema p
        en el curso c; si el problema no pertence al curso o el curso no existe se
        imprime un mensaje de error
    */
    string sesion_problema(int c, const string& p) const;

    /** @brief Imprime el nº de usuarios inscritos en un curso c de un Cjt_cursos.
        \pre Existe un curso con identificador c en el parámetro implícito
        \post Imprime el nº de usuarios inscritos en el curso con identificador c
        del parámetro implícito
    */
    void imprimir_num_usuarios(int c) const;

    /** @brief Imprime un usuario con identificador c de un Cjt_usuarios.
        \pre cierto
        \post Imprime su identificador, el nº de envios totales, el nº de
        problemas que ha resuelto satisfactoriamente, el nº de problemas que ha
        intentado y el identificador del curso al que está inscrito o un cero si
        no está inscrito en ninguno. Si el usuario no existe se imprime un error
    */
    void escribir_curso(int c) const;

    /** @brief Lista los cursos actuales de la plataforma.
        \pre cierto
        \post Lista los cursos ordenados crecientemente por su identificador;
        para cada curso imprime le nº de usuarios que lo han completado, el nº
        de usuarios inscritos actualmente, el nº de sesiones que lo forman y los
        identificadores de dichas sesiones, en el mismo orden que se leyeron
        cuando se creó el curso
    */
    void listar_cursos() const;

};
#endif
