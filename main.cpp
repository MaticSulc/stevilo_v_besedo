
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <windows.h>
using namespace std;

string pretvoriEnice(int stevilo){ //ce imamo samo 1mestno
	switch(stevilo){
		case 0: return "nic "; break;
		case 1: return "ena "; break;
		case 2: return "dva "; break;
		case 3: return "tri "; break;
		case 4: return "stiri "; break;
		case 5: return "pet "; break;
		case 6: return "sest "; break;
		case 7: return "sedem "; break;
		case 8: return "osem "; break;
		case 9: return "devet ";	break;
	}
}
string pretvoriDesetice(int stevilo){
	switch(stevilo){
		case 1: return "deset "; break; //izjema
		case 2: return "dvajset "; break;	//izjema
		case 3 ... 9: return pretvoriEnice(stevilo) + "deset "; break; //tri-deset, stiri-deset so enaki do devet-deset
	}
}

string pretvoriStotice(int stevilo){
		switch(stevilo){
		case 1: return "sto "; break; //enaka logika kot pri deseticah
		case 2: return "dvesto "; break;
		case 3 ... 9: return pretvoriEnice(stevilo) + "sto "; break;
	}
}

string prevtoriTisocice(int stevilo, string beseda){
	int temp;
	if(stevilo > 99){ //ce je vecje od 100
		beseda = pretvoriStotice(round(stevilo/100)); //dodamo stotice v string
		stevilo = stevilo%100; //odstranimo stotice(modulo)
		if(stevilo == 0){
            return beseda; //konec, ce pridemo do 0
		}
	}
	if(stevilo > 19){ //nad 19 ni izjem
		temp = stevilo%10; //ko gremo skozi odstranimo desetice
		switch(temp){
			case 0: beseda+= pretvoriDesetice(round(stevilo/10)); break; //pri nic nimamo predpone "nicindvajset"
			case 1: beseda+= "ena in " + pretvoriDesetice(round(stevilo / 10)); break; //ce je 1
			default: beseda+= pretvoriEnice(temp) + "in " + pretvoriDesetice(round(stevilo / 10)); break; //ce je drugo stevilo
		}
	}
	else{
		switch(stevilo){
			case 12 ... 19: beseda+= pretvoriEnice(stevilo%10) + "najst "; break; //ostale izjeme(enice)
			case 11: beseda+= "enajst "; break;	//izjema 11
			case 10: beseda+= "deset "; break;	//izjema 10
			case 0 ... 9: beseda+= pretvoriEnice(stevilo%10); break; //enice od 1 do 9
		}
	}
	return beseda;
}


int main(){
    int st;
    cout<<"Vnesi stevilo med 0 in 999: ";
    cin>>st;
	string beseda = "";
	string beseda_kot_stevilo = prevtoriTisocice(st, beseda);
	cout<<beseda_kot_stevilo<<endl<<endl;

	stringstream stream(beseda_kot_stevilo);
	string s;

	while(getline(stream,s,' ')){
	    string filename =  "audio/" + s + ".wav";
        PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(1000);

	}


}
