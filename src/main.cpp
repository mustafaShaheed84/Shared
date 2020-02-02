// Created by Mustafa Shaheed
// Elct350 
// This program is created to find the output of a system based on the input and
// voltage gain.
// Created on 1/27/10
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
double Sinusodial(double time, double amp, double freq, double phase, double offset){
double val;
val = amp * sin( time * freq * 2.0 * 3.14 + phase ) + offset;
return val;
}

double VoltDiv(double r1, double r2){
double val;
val = r2/(r1+r2);
}

int main(){
 ifstream input( "input.txt");
 ofstream out( "output.csv");
 double time, timestep, amp, freq, phase, offset, R1, R2;
 input >> time >> timestep >> amp >> freq >> phase >> offset >> R1 >> R2;
 double i = 0.0;
 double vin = 0.0;
 double vout = 0.0;
 out << "Vin"<<',' <<"Vout"<<endl;
 while(i < time){
  vin = Sinusodial(i, amp, freq, phase, offset);
  vout =vin * VoltDiv(R1, R2);
  out << vin << ',' << vout << endl;
  i += timestep;
 }
}
