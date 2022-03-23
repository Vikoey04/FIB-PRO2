#include "Problema.hh"

using namespace std;

/** @class Problema
    @brief Representa un Problema de la plataforma.

    Un problema forma parte de una sesion. Este está formado por el número de envios
    totales que se han realizado y el número de envios correctos.
*/

  //private


  //public
      //Constructoras

      Problema::Problema() {
        t = 0;
        e = 0;
      }

      //Modificadoras

      /** @brief Actualiza el número de envios totales y correctos de un problema dada una respuesta r.
          \pre cierto
          \post El nº de envios totales del problema augmentan en una unidad. Si
          r es cierto, también augmenta en una unidad el nº de envíos correctos del
          problema
      */
      void Problema::act_envios(bool r) {
        ++t;
        if (r) ++e;
      }

      //Consultoras

      /** @brief Devuelve el ratio de un problema.
          \pre cierto
          \post Devuelve el ratio (t+1)/(e+1) del parámetro implícito
      */
      double Problema::ratio() const {
        double ratio = (t+1);
        ratio = ratio/(e+1);
        return ratio;
      }

      // Lectura i escritura

      /** @brief Imprime un problema.
          \pre cierto
          \post De un problema, imprime el nº de envíos totales y el nº de envíos con
          éxito, en ambos casos de usuarios presentes o pasados
      */
      void Problema::escribir_problema() const {
        cout << "(" << t << "," << e << ",";
      }
