/** @file Sesion.hh
    @brief Especificación de la clase sesion
*/

#ifndef SESION_HH
#define SESION_HH

#include "Cjt_problemas.hh"
#include "Usuario.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include "BinTree.hh"
#include <set>
#include <algorithm>
#endif

using namespace std;

/** @class Sesion
    @brief Especificación de la clase Sesion

    Está formada por un BinTree de los identificadores de los problemas y 
    un vector con los identificadores de estos problemas.
*/

class Sesion
{

private:
    BinTree<string> problemas;
    vector<string> vect_p;

    /** @brief Comprueba si existe un nodo p en un BinTree.
        \pre cierto
        \post Devuelve cierto si encuenta p en el BinTree a; falso en caso
        contrario
    */
    static bool cerca(const BinTree<string>& a, const string& p);

    /** @brief Realiza la lectura de un BinTree en preorden.
        \pre cierto
        \post Se ha realizado la lectura del BinTree en preorden
    */
    static void leer_arbol_preorden(BinTree<string>& a);

    /** @brief Imprime un BinTree en postorden con los hijos entre paréntesis.
        \pre El BinTree a no es vacío
        \post Imprime el BinTree a en postorden con los hijos entre paréntesis
    */
    static void escribir_bintree_postorden(const BinTree<string>& a);

    /** @brief Deja en un vector con todos los nodos de un BinTree.
        \pre cierto
        \post Deja en el vector v todos los nodos del BinTree a
    */
    static void vect_problemas(vector<string>& v, const BinTree<string>& a);

    /** @brief Actualiza todos los problemas enviables, que pertenecen a un BinTree, de un usuario.
        \pre cierto
        \post Se actualizan los problemas enviables de un usuario a partir del
        BinTree
    */
    static void act_enviables_i(const BinTree<string>& a, Usuario& usuario);

    /** @brief Actualiza los problemas enviables sucesores de un problema p (este incluido), que pertenecen a un BinTree, de un usuario.
        \pre cierto
        \post Se actualizan los problemas enviables de un usuario a partir del
        BinTree
    */
    static void act_enviables(const BinTree<string>& a, const string& p, Usuario& usuario);

public:
    //Constructoras

    /** @brief Creadora por defecto con la lectura de los problemas.
        \pre cierto
        \post El resultado es una sesion con sus problemas leídos
    */
    Sesion();

    //Modificadoras

    /** @brief Actualiza los problemas enviables sucesores de un problema p (este incluido), que pertenecen a una sesion, de un usuario.
          \pre cierto
          \post Actualiza los problemas enviables sucesores de un problema p
          (este incluido), que pertenecen al parámetro implícito, del usuario
      */
      void act_problemas_enviables(const string& p, Usuario& usuario) const;

    /** @brief Actualiza los problemas enviables, que pertenecen a una sesion, de un usuario.
        \pre cierto
        \post Actualiza los problemas enviables, que pertenecen al parámetro
        implícito, del usuario
    */
    void problemas_enviables(Usuario& usuario) const;

    //Consultoras

    /** @brief Devuelve el identificador del primer problema de una sesion.
        \pre El parámetro implícito contiene 1 o más problemas
        \post Devuelve el identificador del primer problema del parámetro
        implícito
    */
    string primera() const;

    /** @brief Devuelve el identificador del problema con índice i del vector de problemas de una sesion.
        \pre El índice i (entero) es > 0 y < numero de problemas del parámetro implícito
        \post Devuelve el identificador del problema con índice i del vector de
        problemas del parámetro implícito
    */
    string id_problema(int i) const;

    /** @brief Devuelve el nº de problemas de una sesion.
        \pre cierto
        \post Devuelve el nº de problemas del parámetro implícito
    */
    int num_problemas() const;

    /** @brief Consulta si existe un problema con el identificador p en una sesion.
        \pre cierto
        \post Devuelve cierto si existe un problema con identificador p en el
        parámetro implícito; falso en caso contrario
    */
    bool existe_problema(const string& p) const;

    // Lectura i escritura

    /** @brief Imprime una sesion.
        \pre cierto
        \post Imprime el nº de problemas que la forman y los identificadores de
        dichos problemas, siguiendo su estructura de prerequisitos en postorden
    */
    void escribir_sesion() const;
};
#endif
