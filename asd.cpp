#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
vector<int> merge(vector<int> left, vector<int> right)
{
   vector<int> result;
   while ((int)left.size() > 0 || (int)right.size() > 0) {
      if ((int)left.size() > 0 && (int)right.size() > 0) {
         if ((int)left.front() <= (int)right.front()) {
            result.push_back((int)left.front());
            left.erase(left.begin());
         } 
   else {
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}

vector<int> mergeSort(vector<int> m)
{
   if (m.size() <= 1)
      return m;
 
   vector<int> left, right, result;
   int middle = ((int)m.size()+ 1) / 2;
 
   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {
      right.push_back(m[i]);
   }
 
   left = mergeSort(left);
   right = mergeSort(right);
   result = merge(left, right);
 
   return result;
}

int main(int nargs, char *args[]){
if(nargs<2){
	cout<<"Ingresa la direccion del archivo"<<endl;
}
else{
	ifstream fichero;
	string frase;
	int numero;
	float mediana;
	vector <int> numeros;
 	fichero.open(args[1]);
	while(!fichero.eof())
	{
		getline(fichero,frase);
		istringstream (frase)>> numero;
		numeros.push_back(numero);
	}
	numeros.erase(numeros.begin()+numeros.size()-1);
	numero=numeros.size();
	numeros = mergeSort(numeros);
	cout<<"cantidad numeros: "<<numero<<endl;
	if(numero%2==0)
	{
		numero=(numero/2)-1;
		mediana=(float(numeros[numero])+numeros[numero+1])/2;
		cout<<"Mediana: "<<mediana<<endl;
	}
	else
	{
		numero=(numero/2);
		cout<<"Mediana: "<<numeros[numero]<<endl;
	}

	fichero.close();
}
}

