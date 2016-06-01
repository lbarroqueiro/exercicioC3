/************************************************************
* programa : exercicio3
*
* autor : Luciano H Barroqueiro  dt 31/05/2016
*
* objetivo : criar uma função para validar o cpf e o tamanho dele
*
*
*************************************************************/


#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>

using namespace std;


bool verQtde(long cpf){

    int digits = 0;
    while( cpf > 0 ) {
        ++digits;
        cpf /= 10;
    }
    if(digits == 11 )
       return 1;
    else
       return 0;

}

int digito1(char scpf[12]){
    int soma = 0, resto = 0;
    soma = (static_cast<int>(scpf[0]) - 48 ) * 10;
    soma += (static_cast<int>(scpf[1]) - 48 ) * 9;
    soma += (static_cast<int>(scpf[2]) - 48 )* 8;
    soma += (static_cast<int>(scpf[3]) - 48 )* 7;
    soma += (static_cast<int>(scpf[4]) - 48 )* 6;
    soma += (static_cast<int>(scpf[5]) - 48 )* 5;
    soma += (static_cast<int>(scpf[6]) - 48 )* 4;
    soma += (static_cast<int>(scpf[7]) - 48 )* 3;
    soma += (static_cast<int>(scpf[8]) - 48 )* 2;
    resto = soma %11;
    if (resto < 2)
       resto = 0;
    else
       resto = 11 - (resto);
    return resto;
}

int digito2(char scpf[12]){
    int soma = 0, resto = 0;
    soma =  (static_cast<int>(scpf[0]) - 48 ) * 11; // 11
    soma += (static_cast<int>(scpf[1]) - 48 ) * 10; // 0
    soma += (static_cast<int>(scpf[2]) - 48 )  * 9;  // 72
    soma += (static_cast<int>(scpf[3]) - 48 )  * 8;  // 32
    soma += (static_cast<int>(scpf[4]) - 48 ) * 7;   //
    soma += (static_cast<int>(scpf[5]) - 48 )  * 6;
    soma += (static_cast<int>(scpf[6]) - 48 ) * 5;
    soma += (static_cast<int>(scpf[7]) - 48 )  * 4;
    soma += (static_cast<int>(scpf[8]) - 48 )  * 3;
    soma += (static_cast<int>(scpf[9]) - 48 )  * 2;
    resto = soma %11;
    if (resto < 2)
       resto = 0;
    else
       resto = 11 - (resto);
    return resto;
}

bool verificaCpf(long lcpf){
   bool retorno ;
   char scpf[12];
   int ret  = snprintf(scpf, sizeof(scpf), "%ld", lcpf);

   retorno = verQtde(lcpf);
   if (retorno) {
        int dig1 = digito1(scpf);
        if (dig1 == (static_cast<int>(scpf[9])) - 48 )
        {
            int dig2 = digito2(scpf);
            if (dig2 == (static_cast<int>(scpf[10])) - 48 )
                retorno = true;
            else
                retorno = false ;
        }
        else
           retorno = false;

      }
    return retorno;
}

int main()
{
    long lcpf = 10849436893;
    lcpf = 12345678907;
    char scpf[12];
    printf("Tamanho do cpf é válido ? %s" ,(verQtde(lcpf)) ? ("verdadeiro") : ("falso"));
    int retorno  = snprintf(scpf, sizeof(scpf), "%ld", lcpf);    //std::stringstream ss;
    printf("\nFollow this command: %c\n", scpf[0]);
    int dig1 = digito1(scpf);
    printf("\n1 - Resto encontrado %d", dig1);
    int dig2 = digito2(scpf);
    printf("\n2 - Resto encontrado %d", dig2);
    bool tudo  =verificaCpf(lcpf);
    if (tudo)
       printf ("\n Cpf valido");
    else
       printf("\n cpf inválido");
    //byte = retornaArray(x);
    //printf("\nTransformado em matriz %s" , byte[2]);


}

