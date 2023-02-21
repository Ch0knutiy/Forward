#include <iostream>
#include "Stand.h"

using namespace std;


int main() {
   
   double temp_ambient;
   cout << "Enter the ambient temperature: ";
   cin >> temp_ambient;
   Combustion_engine engine;
   Stand<Combustion_engine> stand(&engine, temp_ambient);
   stand.start_overheat_test();
   if (stand.get_overheat())
      cout << "Time to overheat: " << stand.get_time_to_overheat() << "s";
   else
      cout << "Engine did not overheat in 10 hours";
   return 0;
}