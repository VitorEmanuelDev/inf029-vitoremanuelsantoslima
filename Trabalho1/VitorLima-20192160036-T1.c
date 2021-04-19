// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int valida_numeros(int dia, int mes, int ano);

int q1(char *data)
{
	//isolar dia
	char sDia[3];
	int i;
	int len_dia = 0;

    for(i = 0; data[i] != '/'; i++){

    	sDia[i] = data[i];

    	if (i >= 2) return 0;

    	if (sDia[i] < 48 || sDia[i] > 57)
    		return 0;

    }

	sDia[i] = '\0';
	i++;

	for(int k = 0; sDia[k] != '\0'; k++)
	   len_dia++;

	if(len_dia == 0)
	   return 0;

	int iDia = atoi(sDia);

	//isolar o mês
	char sMes[3];
	int j;
	int len_mes = 0;

	for (j = i; data[j] != '/'; j++, len_mes++){

	sMes[len_mes] = data[j];

	if (len_mes > 1) return 0;

	if (sMes[i] < 48 || sMes[i] > 57)
			return 0;


	}

	sMes[j] = '\0';
	j++;

	for(int y = 0; sMes[y] != '\0'; y++)
		   len_mes++;

	if(len_mes == 0)
		return 0;

    int iMes = atoi(sMes);


   	char sAno[5];
    int len_ano = 0;

    for(int z = 0; sAno[z] != '\0'; z++)
    		   len_ano++;

    for (i = j; i < len_ano; i++, len_ano++){

         sAno[len_ano] = data[i];

         	if (sAno[i] < 48 || sAno[i] > 57)
         			return 0;
     }

      if (len_ano != 2 && len_ano != 4) return 0;

      sAno[len_ano] = '\0';

      int iAno = atoi(sAno);

	 int retorno = valida_numeros(iDia, iMes, iAno);

	 return retorno;



    //printf("%s\n", data) 28/12/1999;

}

int valida_numeros(int dia, int mes, int ano){

	if(ano >= 1900 && ano <= 2100){

		if (mes >= 1 && mes <= 12){

			if ((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
				return 1;

			else if ((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
				return 1;

			else if ((dia >= 1 && dia <= 28) && (mes == 2))
				return 1;

			else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)))
				return 1;

			else
				return 0;

		}else{

			return 0;

		}

	}else{

		return 0;

	}

}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    char sDia[3], sMes[3], sAno[5];

    int iDiaInicial, iMesInicial, iAnoInicial;
    int iDiaFinal, iMesFinal, iAnoFinal;

    int i, j, cont_Mes = 0, cont_Ano = 0;


    int nDias, nMeses, nAnos;



    if (q1(datainicial) == 0)
        return 2;
    if (q1(datafinal) == 0)
        return 3;


    for (i = 0; datainicial[i] != '/'; i++)
        sDia[i] = datainicial[i];

    sDia[i] = '\0';
    i++;

    for (j = i, cont_Mes = 0; datainicial[j] != '/'; j++, cont_Mes++)
        sMes[cont_Mes] = datainicial[j];

    sMes[j] = '\0';
    j++;

    int len_data_inicial = 0;

    for(int k = 0; datainicial[k] != '\0'; k++)
    	   len_data_inicial++;

    for (i = j, cont_Ano = 0; i < len_data_inicial; i++, cont_Ano++)
       sAno[cont_Ano] = datainicial[i];

    sAno[cont_Ano] = '\0';


    iDiaInicial = atoi(sDia);
    iMesInicial = atoi(sMes);
    iAnoInicial = atoi(sAno);


   for (i = 0; datafinal[i] != '/'; i++)
        sDia[i] = datafinal[i];

    sDia[i] = '\0';
    i++;

    for (j = i, cont_Mes = 0; datafinal[j] != '/'; j++, cont_Mes++)
        sMes[cont_Mes] = datafinal[j];

    sMes[j] = '\0';
    j++;

    int len_data_final = 0;

	for(int k = 0; datafinal[k] != '\0'; k++)
		len_data_final++;

    for (i = j, cont_Ano = 0; i < len_data_final; i++, cont_Ano++)
       sAno[cont_Ano] = datafinal[i];

    sAno[cont_Ano] = '\0';

    iDiaFinal = atoi(sDia);
    iMesFinal = atoi(sMes);
    iAnoFinal = atoi(sAno);

    if (iAnoFinal < iAnoInicial || (iAnoFinal == iAnoInicial && iMesFinal < iMesInicial) || (iAnoFinal == iAnoInicial && iMesFinal == iMesInicial && iDiaFinal < iDiaInicial))
        return 4;

    int mesFinalAnterior = iMesFinal - 1;

    if (iDiaFinal < iDiaInicial){

        if (mesFinalAnterior == 2){

            if (mesFinalAnterior % 4 == 0 || mesFinalAnterior % 400 == 0 && (mesFinalAnterior % 100 != 0) )
                iDiaFinal += 29;
            else
                iDiaFinal += 28;
        }

        if (mesFinalAnterior == 4 || mesFinalAnterior == 6 || mesFinalAnterior == 9 || mesFinalAnterior == 11)
            iDiaFinal += 30;
        else
            iDiaFinal += 31;

        iMesFinal--;
    }

    if (iMesFinal < iMesInicial){

        iMesFinal += 12;
        iAnoFinal--;
    }

    nDias = iDiaFinal - iDiaInicial;
    nMeses = iMesFinal - iMesInicial;
    nAnos = iAnoFinal - iAnoInicial;

    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;

}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int len = 0;

    for(int k = 0; texto[k] != '\0'; k++)
    	len++;

    if (isCaseSensitive == 1)
        for (int i = 0; i < len; i++)
            if (texto[i] == c)
                qtdOcorrencias++;

    if (isCaseSensitive != 1)
        for(int i = 0; i < len; i++)
            if (texto[i] == c || texto[i] == toupper(c) || texto[i] == tolower(c))
                qtdOcorrencias++;


    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}
