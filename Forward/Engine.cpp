#include "Engine.h"


Combustion_engine::Combustion_engine() {
   I = 10;
   input_M = { 20, 75, 100, 105, 75, 0 };
   input_V = { 0, 75, 150, 200, 250, 300 };
   Temp_overheat = 110;
   Hm = 0.01;
   Hv = 0.0001;
   C = 0.1;
   M = input_M[0];
   V = input_V[0];
}

double Combustion_engine::Vh() { // Вычисление скорости нагрева (С/сек)
   return (M * Hm) + (V * V * Hv);  
}

double Combustion_engine::Vc(double temp_ambient, double temp_engine) { // Вычисление скорости охлождения (С/сек)
   return C * (temp_ambient - temp_engine);
}

double Combustion_engine::get_Temp_overheat() { return Temp_overheat; }

double Combustion_engine::get_I() { return I; }

double Combustion_engine::get_M() { return M; }
void Combustion_engine::set_M(double m) { M = m; }

double Combustion_engine::get_V() { return V; }
void Combustion_engine::set_V(double v) { V = v; }

vector<double> Combustion_engine::get_input_M() { return input_M; }

vector<double> Combustion_engine::get_input_V() { return input_V; }