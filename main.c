#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
  char bit,valor[31];
  int tamanho,i, posicao, digito, decimal=0;

  scanf("%s",valor);
  while(strcmp(valor,"-1")!=0){
    tamanho = strlen(valor);
    if(valor[1]=='x'||valor[1]=='X'){
      for(i=2;i<tamanho;i++){
        bit=valor[i];
        if(bit=='A'||bit=='a'){
          digito=10; 
        }
        if(bit=='B'||bit=='b'){
        digito=11; 
        }
        if(bit=='C'||bit=='c'){
        digito=12; 
        }
        if(bit=='D'||bit=='d'){
        digito=13; 
        }
        if(bit=='E'||bit=='e'){
        digito=14; 
        }
        if(bit=='F'||bit=='f'){
        digito=15; 
        }
        if(bit=='0' || bit=='1' || bit=='2' || bit=='3' || bit=='4' || bit=='5' || bit=='6' || bit=='7' || bit=='8' || bit=='9'){
          digito = (int)(bit) - 48;
        }
        posicao=tamanho-(i+1);
        decimal = decimal + digito*pow(16,posicao);  
      } 
      printf("%d\n",decimal);     
    }else{
      int dividendo,resto,numero=0,i;
      int tamanho = strlen(valor);
      char hexadecimal[32]="",hexadecimalInvert[32],d[1];
      for (i=0;i<tamanho;i++){
        numero=numero+((int)(valor[i])-48)*pow(10,tamanho-(i+1));
      }
      resto = numero;
      dividendo= numero;
      if(dividendo<16){
        if(resto<10){
          sprintf(d,"%d",resto);
          strcat(hexadecimal, d);
        }
        if(resto==10){
          strcat(hexadecimal, "A");
        }
        if(resto==11){
          strcat(hexadecimal, "B");
        }
        if(resto==12){
          strcat(hexadecimal, "C");
        }
        if(resto==13){
          strcat(hexadecimal, "D");
        }
        if(resto==14){
          strcat(hexadecimal, "E");
        }
        if(resto==15){
          strcat(hexadecimal, "F");
        }
      }else{
        while(dividendo>=16){
          resto = dividendo%16;
          dividendo=dividendo/16;
          if(resto<10){
            sprintf(d,"%d",resto);
            strcat(hexadecimal, d);
          }
          if(resto==10){
            strcat(hexadecimal, "A");
          }
          if(resto==11){
            strcat(hexadecimal, "B");
          }
          if(resto==12){
            strcat(hexadecimal, "C");
          }
          if(resto==13){
            strcat(hexadecimal, "D");
          }
          if(resto==14){
            strcat(hexadecimal, "E");
          }
          if(resto==15){
            strcat(hexadecimal, "F");
          }
        }
        sprintf(d,"%d",dividendo);
        strcat(hexadecimal, d);
      }
      strcat(hexadecimal, "x0");
      tamanho = strlen(hexadecimal);
      for(i=0;i<tamanho;i++){
        hexadecimalInvert[i]=hexadecimal[tamanho-(i+1)];
      }
      hexadecimalInvert[tamanho]='\0';
      printf("%s\n",hexadecimalInvert);
    }    
    scanf("%s",valor);
  }
  return 0;
}