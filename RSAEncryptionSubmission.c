#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void RSAEncryption(int p1, int p2, char text[]);
void RSADecryption(int p1, int p2, char text[]);
int isCommonFactor(int x, int y);
int isExponential(int num, int power);

int main(){
	char text[] = "ENCRYPTION";
	char word[] = "lNYECaHS(N";
	long prime1 = 5, prime2 = 7;
	
	RSAEncryption(prime1, prime2, text);
	printf("\n");
	RSADecryption(prime1, prime2, word);
	
	return 0;
}

void RSAEncryption(int p1, int p2, char text[]){
	int n, z, e, d, i, cipher[strlen(text)];
	
	n = p1 * p2;	
	z = (p1-1) * (p2-1);	
	for(e=2; e<n && isCommonFactor(e, z)!=1; e++){}		
	for(d=z+1; ((e*d)-1)%z!=0; d++){}		
	
	for(i=0; i<strlen(text); i++){
		cipher[i] = isExponential(text[i],e)%n;
	}
	
	for(i=0; i<strlen(text); i++){
		printf("%c ", cipher[i]);
	}
}

void RSADecryption(int p1, int p2, char text[]){
	int n, z, e, d, i, cipher[strlen(text)];
	
	n = p1 * p2;	
	z = (p1-1) * (p2-1);	
	for(e=2; e<n && isCommonFactor(e, z)!=1; e++){}		
	for(d=z+1; ((e*d)-1)%z!=0; d++){}		
	
	//transfer the string text[] into the cypher as ascii values before encrypting them
	for(i=0; i<strlen(text); i++){
		cipher[i] = isExponential(text[i],d)%n;
	}
	
	for(i=0; i<strlen(text); i++){
		printf("%c ", cipher[i]);
	}
}

int isCommonFactor(int x, int y){
	//to make the int positive
	x = (x > 0) ? x : -x;
    y = (y > 0) ? y : -y;
	
	while (x * y != 0) {
        if (x >= y){
        	x = x % y;
		} 
        else {
        	y = y % x;
		}
    }
    return (x + y);
}

int isExponential(int num, int power){
	int val=1, i;
	for(i=power; i>0; i--){
		val *= num;
	}
	return val = (val > 0) ? val : -val;
}