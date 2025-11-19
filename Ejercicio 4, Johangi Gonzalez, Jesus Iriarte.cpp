#include <iostream>
using namespace std;
 
 int main (){
 	
 	float td = 237.75;
 	float te = 275.81;
 	int opcion;
 	float metaM, salary, gastosM, pesoD, pesoA, pesoP, bs, eu, verde, retorno, restant, meses; // meta monetaria, salario, gastos mensuales, peso deseado, peso actual, 
	 //peso a perder, bolivar, euro, dolar, :)
	 
	 do{
	 
	 cout<<"1. Convertir $ a bs."<<endl;
	 cout<<"2. Convertir bs a euros."<<endl;
	 cout<<"3. Calcular tiempo de meta monetaria"<<endl;
	 cout<<"4. Calcular tiempo para su peso deseado"<<endl;
	 cout<<endl;
	 cin>>opcion;
	 
	 switch(opcion){
	 		
	 		case 1:
	 			
	 			cout<<"¿Cuantos dolares tiene?"<<endl;
	 			cin>>verde;
	 			bs = verde * td;
	 			cout<<verde<<"$ son "<<bs<<"bs \a"<<endl;
	 			break;
	 			
	 		case 2:
	 			
	 			cout<<"¿Cuantos bolivares tiene?"<<endl;
	 			cin>>bs;
	 			eu = bs / te;
	 			cout<<bs<<"bs son "<<eu<<" euros \a"<<endl;
	 			break;
	 			
	 		case 3:
	 			
	 			cout<<"¿Cual es su meta monetaria?"<<endl;
	 			cin>>metaM;
	 			cout<<"¿De cuanto es su salario mensual?"<<endl;
	 			cin>>salary;
	 			cout<<"¿De cuanto son sus gastos fijos mensuales?"<<endl;
	 			cin>>gastosM;
	 			
	 			if (salary <= gastosM){
	 				
	 				cout<<"su meta es imposible de completar ya que su sueldo no alcanza para ahorar"<<endl;
				 }else{
				 	
				 	//cout<<(salary > gastosM ? "su meta es posible" : "su meta es imposible")<<endl;
				 	restant = salary - gastosM;
					meses = metaM / restant;
					cout<<"usted podra alcanzar su meta en un total de "<<meses<<" meses \a"<<endl;
					break;
					
			case 4:
				
				cout<<"si desea ganar peso presione 1 y si desea perder peso presione 2"<<endl;
				cin>>opcion;
				
				if (opcion == 2){
					
					cout<<"¿Cual peso desea alcanzar?"<<endl;
					cin>>pesoD;
	 			cout<<"¿De cuanto es su peso actual?"<<endl;
	 			cin>>pesoA;
	 			cout<<"¿Cuantos kg esta comprometido a perder mensualmente?"<<endl;
	 			cin>>pesoP;
	 			
	 			restant = pesoA - pesoD;
	 			meses = restant / pesoP;
	 			cout<<"usted podra alcanzar su meta en un total de "<<meses<<" meses \a"<<endl;
				
				} else if (opcion == 1){
					cout<<"¿Cual peso desea alcanzar?"<<endl;
	 			cin>>pesoD;
	 			cout<<"¿De cuanto es su peso actual?"<<endl;
	 			cin>>pesoA;
	 			cout<<"¿Cuantos kg esta comprometido a ganar mensualmente?"<<endl;
	 			cin>>pesoP;
	 			
	 			restant = pesoD - pesoA;
	 			meses = restant / pesoP;
	 			cout<<"usted podra alcanzar su meta en un total de "<<meses<<" meses \a"<<endl;
				}else{
					
					cout<<"opcion inexistente"<<endl;
				}
				break;
				 }
	 			
	 			
		 }
		 
		 
cout<<"Ingrese 1 si desea continuar o 0 si desea culminar"<<endl;
cin>>retorno;
}while (retorno != 0);

	 return 0;
 }
