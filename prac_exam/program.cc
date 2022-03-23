/** @mainpage

    EVALUATOR: plataforma de gestión de problemas y cursos de programación.

    Programa modular para la gestion de la plataforma EVALUATOR, una plataforma de gestión de problemas y cursos de programación. Está formado por las clases <em>Cjt_cursos</em>, <em>Cjt_problemas</em>, <em>Cjt_sesiones</em>, <em>Cjt_usuarios</em>, <em>Curso</em>, <em>Problema</em>, <em>Sesion</em> y <em>Usuario</em>.

    El programa principal se encuentra en el módulo <em>main.cc</em>
*/

/** @file main.cc

    @brief Programa principal para la práctica <em>Plataforma EVALUATOR</em>

    EVALUATOR es una plataforma de gestión de problemas y cursos de programación.
    El programa consiste en una lectura inicial de unos cursos, de unos problemas,
    de unas sesiones y de unos usuarios.

    Una vez leídos los datos iniciales se leeran codigos de operación varios para
    tratar los datos leídos inicialmente e incluso suprimir datos o agregar nuevos.
*/

#include "Cjt_cursos.hh"
#include "Cjt_problemas.hh"
#include "Cjt_sesiones.hh"
#include "Cjt_usuarios.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

using namespace std;

int main() {
  Cjt_problemas problems;
  problems.leer_problemas(); //lectuda inicial de problemas
  Cjt_sesiones sesiones;
  sesiones.leer_sesiones(); //lectura inicial de sesiones
  Cjt_cursos cursos;
  cursos.leer_cursos(sesiones); //lectura inicial de cursos
  Cjt_usuarios users;
  users.leer_usuarios(); //lectura inicial de usuarios

  int c; //IDENTIFICADOR Curso
  string p, s, u; //IDENTIFICADORES Problema, Sesion y Usuario respectivamente

  string op; //CODIGO DE OPERACIÓN
  while (cin >> op and op != "fin") {

    //1- nuevo_problema
    if (op == "np" or op == "nuevo_problema"){
      cin >> p;
      cout << "#" << op << " " << p << endl;
      problems.nuevo_problema(p);
    }

    //2- nueva_sesion
    else if (op == "ns" or op == "nueva_sesion"){
      cin >> s;
      cout << "#" << op << " " << s << endl;
      sesiones.nueva_sesion(s);
    }

    //3- nuevo_curso
    else if (op == "nc" or op == "nuevo_curso"){
      cout << "#" << op << endl;
      cursos.nuevo_curso(sesiones);
    }

    //4- alta_usuario
    else if (op == "a" or op == "alta_usuario"){
      cin >> u;
      cout << "#" << op << " " << u << endl;
      users.alta_usuario(u);
    }

    //5- baja_usuario
    else if (op == "b" or op == "baja_usuario"){
      cin >> u;
      cout << "#" << op << " " << u << endl;
      users.baja_usuario(u, cursos);
    }

    //6- inscribir_curso
    else if (op == "i" or op == "inscribir_curso"){
      cin >> u >> c;
      cout << "#" << op << " " << u << " " << c << endl;
      users.inscribir_curso(u, c, cursos, sesiones);
    }

    // 7- curso_usuario
    else if (op == "cu" or op == "curso_usuario"){
      cin >> u;
      cout << "#" << op << " " << u << endl;
      users.curso_usuario(u);
    }

    //8- sesion_problema
    else if (op == "sp" or op == "sesion_problema"){
      cin >> c >> p;
      cout << "#" << op << " " << c << " " << p << endl;
      if (problems.existe_problema(p)) {
        if (cursos.existe_curso(c)) {
          if (cursos.existe_problema(p, c)) {
            cout << cursos.sesion_problema(c, p) << endl;
          }
          else cout << "error: el problema no pertenece al curso" << endl;
        }
        else cout << "error: el curso no existe" << endl;
      }
      else cout << "error: el problema no existe" << endl;
    }

    //9- problemas_resueltos
    else if (op == "pr" or op == "problemas_resueltos"){
      cin >> u;
      cout << "#" << op << " " << u << endl;
      users.problemas_resueltos(u);
    }

    //10- problemas_enviables
    else if (op == "pe" or op == "problemas_enviables"){
      cin >> u;
      cout << "#" << op << " " << u << endl;
      users.problemas_enviables(u);
    }
    
    //11- envio
    else if (op == "e" or op == "envio"){
      int nota;
      cin >> u >> p >> nota;
      bool r = true;
      if (nota == 0) r = false;
      cout << "#" << op << " " << u << " " << p << " " << nota << endl;
      users.envio(u, p, r, problems, sesiones, cursos);
    }
    
    //12- listar_problemas
    else if (op == "lp" or op == "listar_problemas"){
      cout << "#" << op << endl;
      problems.listar_problemas();
    }

    //escribir_problema
    else if (op == "ep" or op == "escribir_problema"){
      cin >> p;
      cout << "#" << op << " " << p << endl;
      problems.escribir_problema(p);
    }

    //13- listar_sesiones
    else if (op == "ls" or op == "listar_sesiones"){
      cout << "#" << op << endl;
      sesiones.listar_sesiones();
    }

    //escribir_sesion
    else if (op == "es" or op == "escribir_sesion"){
      cin >> s;
      cout << "#" << op << " " << s << endl;
      sesiones.escribir_sesion(s);
    }

    //14- listar_cursos
    else if (op == "lc" or op == "listar_cursos"){
      cout << "#" << op << endl;
      cursos.listar_cursos();
    }

    //escribir_curso
    else if (op == "ec" or op == "escribir_curso"){
      cin >> c;
      cout << "#" << op << " " << c << endl;
      cursos.escribir_curso(c);
    }

    //15- listar_usuarios
    else if (op == "lu" or op == "listar_usuarios"){
      cout << "#" << op << endl;
      users.listar_usuarios();
    }

    //escribir_usuario
    else if (op == "eu" or op == "escribir_usuario"){
      cin >> u;
      cout << "#" << op << " " << u << endl;
      users.escribir_usuario(u);
    }

    //acabar_curso
    else if (op == "ac" or op == "acabar_curso") {
      cin >> u;
      cout << "#" << op << " " << u << endl;
      users.acabar_curso(u, cursos);
    }
  }
}
