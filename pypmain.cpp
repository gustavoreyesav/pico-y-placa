#include<iostream> //entrada y salida de datos cout y cin
#include<windows.h> //strlen 
#include<locale.h>// para los acentos y la ñ
#include<stdlib.h> // atoi y atof 
//#include<conio.h>
//#include<stdio.h>
#include<string>

using namespace std;

//Declaro las funciones a utilizar
bool IsNumber(char* szString);

//Creo mi clase fecha
class fecha{
	private:
		int d,m,a,res1,res2,res3,res4,res5,opc;
		string mtri;
	public:
		fecha(int,int,int); // constructor
		void impfecha(void);
		void fechaCorrecta(int,int,int);
		void picoyplaca(void);
};//Fin de clase fecha.

//Inicio mi constructor fecha
fecha::fecha(int _d, int _m, int aaaa){
	d=_d;
	m=_m;
	a=aaaa;
}//Fin de constructor fecha

//Valido que la fecha sea correcta, año bisiesto o año regular, los días
void fecha::fechaCorrecta(int dia, int mes, int anio){
	while (d > 31 || d < 1 || m < 1 || m > 12 || a <1600)
	{
		cout << "Fecha Incorrecta"<<endl<<endl;
	    cout << "Introduzca una fecha válida:" <<endl <<endl;
	    cout << "Día: "; cin >> d;
	    cout << "Mes: "; cin >> m;
	    cout << "Año: "; cin >> a;
	    cout << endl;
    }
    //calculo si es año bisiesto o año regular
    int regular[]={0,3,3,6,1,4,6,2,5,0,3,5};
	int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};
    if((a%4==0) && !(a%100==0)){m = bisiesto[m-1];}
	else if (a%400==0){m = bisiesto[m-1];}
	else{m = regular[m-1];}
	//Fórmula del los días
	res1 = (a-1)%7;
	res2 = (a-1)/4;
	res3 = (3*(((a-1)/100)+1))/4;
	res4 = (res2-res3)%7;
	res5 = d%7;
	opc = (res1+res4+m+res5)%7;
}//Fin de validar fecha, año y día.

//Metodo imprime fecha
void fecha::impfecha(void){
	switch(opc){
    case 0: cout << "La fecha ingresada es Domingo"<<endl; break; // arreglar textos
    case 1: cout << "La fecha ingresada es Lunes"<<endl; break;
    case 2: cout << "La fecha ingresada es Martes"<<endl; break;
    case 3: cout << "La fecha ingresada es Miércoles"<<endl; break;
    case 4: cout << "La fecha ingresada es Jueves"<<endl; break;
    case 5: cout << "La fecha ingresada es Viernes"<<endl; break;
    case 6: cout << "La fecha ingresada es Sábado"<<endl; break;
	}
}//Fin de imprime fecha.

void fecha::picoyplaca(void){
string sub;
int opcmtri, opc;

do{//matrícula
	cout<<"Matrícula: "; cin>>mtri;
}while(mtri.length() < 8);

sub = mtri.substr(7,1); //Obtengo el ultimo número de la matricula
opcmtri = atoi(sub.c_str()); //Lo convierto a entero

if(opcmtri == 1 || opcmtri == 2 && opc == 1){
	cout << "Lunes, Usted tiene pico y placa desde las 07H00am hasta 9H30am y 16H00pm hasta 19H30pm."<<endl;}
	else if(opcmtri == 3 || opcmtri == 4 && opc == 2){
	cout << "Martes, Usted tiene pico y placa desde las 07H00am hasta 9H30am y 16H00pm hasta 19H30pm."<<endl;}	
	else if(opcmtri == 5 || opcmtri == 6 && opc == 3){
	cout << "Miercoles, Usted tiene pico y placa desde las 07H00am hasta 9H30am y 16H00pm hasta 19H30pm."<<endl;}
	else if(opcmtri == 7 || opcmtri == 8 && opc == 4){
	cout << "Jueves, Usted tiene pico y placa desde las 07H00am hasta 9H30am y 16H00pm hasta 19H30pm."<<endl;}
	else if(opcmtri == 9 || opcmtri == 0 && opc == 5){
	cout << "Viernes, Usted tiene pico y placa desde las 07H00am hasta 9H30am y 16H00pm hasta 19H30pm."<<endl;}
else
{cout<<"Uste no tiene pico y placa.";}
}

int main(void){
	setlocale (LC_CTYPE, "spanish");// para los acentos y la ñ
	
	char di[3],me[3],an[3];
	bool salida = false;
	int dia, mes,anio;
	
	system ("cls");
	cout<<"INGRESA FECHA Y MATRICULA."<<endl<<endl;

do{//Principal

do{//Segundo

do{//día
	cout<<"Día: "; cin>>di;
}while(strlen(di) > 2);

do{//mes
	cout<<"Mes: "; cin>>me;	
} while(strlen(me) > 2);

do{//año
	cout<<"Año: "; cin>>an;
}while(strlen(an) >0 && strlen(an) <4);

//De cadena de caracteres a enteros	
dia=atoi(di); mes=atoi(me); anio=atoi(an);

}while(dia > 31 || dia < 1 || mes < 1 || mes > 12 || anio <1600);

	if(IsNumber(di)==1 && IsNumber(me)==1 && IsNumber(an)==1){
		//printf("\nIngresaste: %i, %i, %i",atoi(d),atoi(m),atoi(a));
		salida=true;
	}
	else{
		cout<<endl<<"Error, no has introducido números en el Día, Mes o Año."<<endl<<endl;
	}
}while(!salida);

//Combierto de cadena a int
dia=atoi(di); mes=atoi(me); anio=atoi(an);

//Creo y llamo mis objetos
fecha objetoFecha(dia,mes,anio);
objetoFecha.fechaCorrecta(dia,mes,anio);
objetoFecha.impfecha();
objetoFecha.picoyplaca();

return EXIT_SUCCESS;
}

//Funcion para determinar que se ingresen solo números.
bool IsNumber(char* szString)
{
 for(unsigned int i=0;i<strlen(szString);i++)
 {
  if(!(szString[i]>='0' && szString[i]<='9')) return false;
 }
 return true;
}//Fin de función.

