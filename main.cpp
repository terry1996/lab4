#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
//#include <string> 

using namespace std;

void numbersToText( unsigned long long);
unsigned long long findK(unsigned long long);
bool checkBin(long double, unsigned long long);


int main(int argc, char *argv[])
{

	unsigned long long  n=atoi(argv[1]);

	unsigned long long  k=findK(n);
	//cout<<"K wynosi: ["<<k<<"]"<<endl;
	numbersToText(k);
	
}
bool checkBin( long double k,unsigned long long n)
{
	long double a;
	int b;
	a=k*n;
	b=int(a);
	if(a!=(long double)b) return 0;
	else {			//warunek czy n*k skłąda sie z zer i jedynek

		string text=to_string(b);					//b=a, bo jestesmy w else-[a] trzebaby
		for(int i=0;i<text.length();i++){				// zrzutowac na u l lint
			if(text[i]=='1' or text[i]=='0'){;}
			else return 0;
		}
		for(int i=0;i<text.length();i++)cout<<text[i];cout<<"!";

		return 1;
	}


}
unsigned long long findK(unsigned long long  n)
{
	long double k=1;//(long double)n;
	//Liczba k musi byc postaci 101011010/n i musi byc całkowita
	do{
		//k*=n;
		k+=1;
		if(checkBin(k,n)) break;

	}while(k<1000000);

	if(k<1000000){
		cout<<"Zwrocono k!: ["<<k<<"]"<<endl;
		return (unsigned long long)k;
	}
	cout<<"k>1m i nadal nie znaleziono wlasciwego. Obecne k= ["<<k<<"]"<<endl; 
	return 0;
}
void numbersToText(unsigned long long n)
{

	string 	ones[]={"jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec"};
	string 	teens[]={"jedenascie","dwanascie","trzynascie","czternascie","pietnascie","szesnascie","siedemnascie","osiemnascie","dziewietnascie"};
	string 	tens[]={"dziesiec","dwadziescia","trzydziesci","czterdziesci","piecdziesiat","szescdziesiat","siedemdziesiat","osiemdziesiat","dziewiecdziesiat"};
	string	hundreds[]={"sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset","dziewiecset"};
	string	thousands[]={"tysiac","tysiace","tysiecy"};


	int length=(to_string(n)).size();
	int digit[6];
	unsigned long long p=n;	//byc moze wartosc poczatkowa n sie przyda, wiec kopiuje
	
	/*digit[0]=( p%10 );
	p-=digit[0];
	int i;
	for(i=1;i<length;i++)
	{
		digit[i]=(  ( p% (unsigned long long int)(pow(10,i+1))  ) / pow(10,i));
		p-=pow(10,i)*digit[i];
	}
	for (int j=i;j<6;j++) digit[j]=0;
	for (int i=6-1;i>=0;i--) cout<<digit[i];
	cout<<endl;*/

	for(int i=0;i<6;i++){					//rzeczywiscie mniej roboty :D
		digit[i]=p%10;
		p/=10;
	}
	//for(int i=0;i<6;i++){cout<<"["<<digit[i]<<"] ";}

	
	for(int i=1;i<10;i++)	if(digit[5]==i) cout<<hundreds[i-1]<<" "; //cyfra setek tysiecy

	if(digit[4]==1){													//cyfra dziesiątek tys
		for(int i=1;i<10;i++) if(digit[3]==i)cout<<teens[i-1] <<" ";		//cyfra
		if(digit[3]==0) cout<<tens[0]<<" ";								//jednosci tys
		cout<< thousands[2]<<" ";
	}
	else {
		for(int i=2;i<10;i++) if(digit[4]==i) cout<<tens[i-1]<<" ";
		for(int i=1;i<10;i++) if(digit[3]==i) cout<<ones[i-1]<<" ";

			if(digit[5]==0 and digit[4]==0 and digit[3]==1 ) cout<<thousands[0]<<" ";
			else if(digit[5]!=0 or digit[4]!=0 or digit[3]!=0){
				if(digit[3]>1 and digit[3]<5) cout<<thousands[1]<<" ";
				else  cout<<thousands[2]<<" "; 
			}
	}
	for(int i=1;i<10;i++)	if(digit[2]==i) cout<<hundreds[i-1]<<" "; //cyfra setek 

	if(digit[1]==1){													//cyfra dziesiątek tys
		for(int i=1;i<10;i++) if(digit[0]==i)cout<<teens[i-1] <<" ";		//cyfra
		if(digit[0]==0) cout<<tens[0]<<" ";								//jednosci tys
		
	}
	else {
		for(int i=2;i<10;i++) if(digit[1]==i) cout<<tens[i-1]<<" ";
		for(int i=1;i<10;i++) if(digit[0]==i) cout<<ones[i-1]<<" ";
			
	}
cout<<endl;

}
