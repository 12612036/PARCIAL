//examen de 1er.parcial de programacion
//clase pieza 
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
class pieza{
private:
	short denominador;
	short numerador;
public:
	numero ()
	{
	denominador = 1;
	numerador = 4;
	{
		short getnumerador();
	}
	return numerador;
	}
numero(short  f,short c){
		denominador = f;
		denominador = c;
	}
void verInfo()
{
	cout <<denominador;
	cout <<numerador
}
int main() {
	numerador p1;
	cout <<p1.numero<<" el resultado del numero es  " <<p1.denominador;
	denominador p2;
	cout<<p2.numerador<<" el resultado del numero es " <<p2.numerador;
	cout <<p1.getnumero() <<endl;
	p1.verInfo();
	numero p2(10,10);
	p2.verInfo();
	numero.numero(s,s);
	return 0;
};

