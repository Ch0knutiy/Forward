#pragma once
 
#include "Engine.h"

#define STOP_EPS 10e-4 // точность приближения температуры двигателя к температуре перегрева
#define MAX_TIME 36000 // максимальное время работы двигателя

template <typename T> class Stand {
private:
   T* engine;
   double temp_engine;
   double temp_ambient;
   bool overheat = false;
   int time_to_overheat = 0;
   
   double get_m_by_v(double v) {// линейная интерполяция
      double m;
      vector<double> V = engine->get_input_V();
      vector<double> M = engine->get_input_M();
      for (size_t i = 1; i < V.size(); i++) {
         if (v < V[i]) {
            m = M[i - 1] + (M[i] - M[i - 1]) * (v - V[i - 1]) / (V[i] - V[i - 1]);
            return m;
         }
      }
      return 0;
   }

public:
   
   template <typename T> Stand(T* engine, double temp_ambient) {
      this->engine = engine;
      this->temp_engine = this->temp_ambient = temp_ambient;
   }

   void start_overheat_test() {
      int time = 0;
      double eps = engine->get_Temp_overheat() - temp_engine;
      while (eps > STOP_EPS && time < MAX_TIME) {
         double a = engine->get_M() / engine->get_I();// вычисляем ускорение вала
         engine->set_V(engine->get_V() + a);// вычисляем новое значение скорости вращения
         engine->set_M(get_m_by_v(engine->get_V()));// вычисляем новое значение крутящего момента

         temp_engine += engine->Vh() + engine->Vc(temp_ambient, temp_engine);// вычисляем новое значение температуры двигателя

         eps = engine->get_Temp_overheat() - temp_engine;// вычисляем приближение к температуре перегрева

         time++;
      }
      if (time == MAX_TIME)
         return;
      else {
         time_to_overheat = time;
         overheat = true;
      }
   }
   bool get_overheat() { return overheat; }
   int get_time_to_overheat() { return time_to_overheat; }
};