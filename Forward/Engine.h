#pragma once

#include <vector>

using namespace std;

class Combustion_engine {
private:
   double I;
   vector<double> input_M;
   vector<double> input_V;
   double Temp_overheat;
   double Hm;
   double Hv;
   double C;
   double M;
   double V;

public:
   Combustion_engine();
   double Vh();
   double Vc(double temp_ambient, double temp_engine);
   double get_Temp_overheat();
   double get_I();
   double get_M();
   void set_M(double m);
   double get_V();
   void set_V(double v);
   vector<double> get_input_M();
   vector<double> get_input_V();
};