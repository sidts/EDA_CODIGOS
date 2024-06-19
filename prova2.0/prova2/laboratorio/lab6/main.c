//
// Universidade de Brasília - UnB
// Faculdade de Engenharias do Gama - FGA
// Estruturas de Dados e Algoritmos - EDA
// Exercício Prático de Listas Encadeadas
//
// PROBLEMA: Unificação das Listas de Cadastros da Secretaria da Fazenda do Distrito Federal
//
//  main.c
//
//  Created by Nilton Correia da Silva on 01/05/17.
//  Copyright © 2017 Nilton Correia da Silva. All rights reserved.
//
// Aluno:
// Matrícula:
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipos.h"

// Criar lista Industria a partir do arquivo Industria.txt
TNoI *CriaListaIndustria()
{
    FILE *parq;
    TCadastro pregaux;
    TNoI *plista, *pnovono;
    // Montando lista das Industrias:

    parq = fopen("/Users/niltonsilva/OneDrive/Sync/Nilton/UnB/2017_1/Disciplinas/EDA/Aulas/17_Atividade2/Industria.txt", "r");
    if (parq == NULL)
        return NULL;

    plista = NULL;
    while (fscanf(parq, "%s %s %s %s", pregaux.CNPJ, pregaux.RazaoSocial, pregaux.Cidade, pregaux.Fone) > 0)
    {
        pnovono = (TNoI *)malloc(sizeof(TNoI));
        pnovono->Dados = (TCadastro *)malloc(sizeof(TCadastro));
        strcpy(pnovono->Dados->CNPJ, pregaux.CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pregaux.RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pregaux.Cidade);
        strcpy(pnovono->Dados->Fone, pregaux.Fone);
        pnovono->Prox = plista;
        plista = pnovono;
    }

    return plista;
}

// Listar Conteúdo da lista Industria:
void ImprimeIndustria(TNoI *LInd)
{
    TNoI *plista = LInd;
    printf("                     LISTA DE INDUSTRIAS\n");
    printf("CNPJ            Razao Social                Cidade      Telefone\n");
    while (plista != NULL)
    {
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
    }
}

// Criar lista Comercio a partir do arquivo Comercio.txt
//  Função para criar a lista de Comércio a partir do arquivo Comercio.txt
TNoC *CriaListaComercio()
{
    FILE *parq;
    TCadastro pregaux;
    TNoC *plista, *pnovono;
    // Montando lista do Comércio

    parq = fopen("Comercio.txt", "r");
    if (parq == NULL)
        return NULL;

    plista = NULL;
    while (fscanf(parq, "%s %s %s %s", pregaux.CNPJ, pregaux.RazaoSocial, pregaux.Cidade, pregaux.Fone) > 0)
    {
        pnovono = (TNoC *)malloc(sizeof(TNoC));
        pnovono->Dados = (TCadastro *)malloc(sizeof(TCadastro));
        strcpy(pnovono->Dados->CNPJ, pregaux.CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pregaux.RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pregaux.Cidade);
        strcpy(pnovono->Dados->Fone, pregaux.Fone);
        pnovono->Ant = NULL;
        pnovono->Prox = plista;
        if (plista != NULL)
        {
            plista->Ant = pnovono;
        }
        plista = pnovono;
    }

    fclose(parq);
    return plista;
}

// Listar Conteúdo da lista Comercio:
//  Função para imprimir a lista de Comércio
void ImprimeComercio(TNoC *LCom)
{
    TNoC *plista = LCom;
    printf("                     LISTA DE COMÉRCIOS\n");
    printf("CNPJ            Razao Social                Cidade      Telefone\n");
    while (plista != NULL)
    {
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
    }
}

// Criar lista Servico (atualizando o parâmetro por referência pLSer) a partir do arquivo Servico.txt
// Deve retornar 1 caso tenha sucesso. 0 caso contrário
//  Função para criar a lista de Serviços a partir do arquivo Servico.txt
int CriaListaServico(TDescritorS *pLSer)
{
    FILE *parq;
    TCadastro pregaux;
    TNoS *pnovono;

    parq = fopen("Servico.txt", "r");
    if (parq == NULL)
        return 0;

    while (fscanf(parq, "%s %s %s %s", pregaux.CNPJ, pregaux.RazaoSocial, pregaux.Cidade, pregaux.Fone) > 0)
    {
        pnovono = (TNoS *)malloc(sizeof(TNoS));
        pnovono->Dados = (TCadastro *)malloc(sizeof(TCadastro));
        strcpy(pnovono->Dados->CNPJ, pregaux.CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pregaux.RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pregaux.Cidade);
        strcpy(pnovono->Dados->Fone, pregaux.Fone);
        pnovono->Ant = pLSer->Fim;
        pnovono->Prox = NULL;
        if (pLSer->Fim != NULL)
        {
            pLSer->Fim->Prox = pnovono;
            // apontando caso não seja vazia a lista, logo entra no final
        }
        else
        {
            pLSer->Inicio = pnovono;
            // se torna o primeiro caso esteja vazia
        }
        pLSer->Fim = pnovono;
        // novo final da lista
        pLSer->Tamanho++;
    }

    fclose(parq);
    return 1;
}

// Listar Conteúdo da lista Servico:
//  Função para imprimir a lista de Serviços
void ImprimeServico(TDescritorS *pdescritor)
{
    TNoS *plista = pdescritor->Inicio;
    printf("                     LISTA DE SERVIÇOS\n");
    printf("CNPJ            Razao Social                Cidade      Telefone\n");
    while (plista != NULL)
    {
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
    }
}

// Criar lista Unificada (atualizando o parâmetro por referência pUnica) a partir das listas Industria, Comercio e Servico
//  Função para criar a lista Unificada
void CriaListaUnificada(TNoI *pInd, TNoC *pCom, TDescritorS *pServ, TDescritorU *pUnica)
{
    TNoI *pI = pInd;
    TNoC *pC = pCom;
    TNoS *pS = pServ->Inicio;
    TNoU *pnovono;

    // Unificar lista de Indústrias
    while (pI != NULL)
    {
        pnovono = (TNoU *)malloc(sizeof(TNoU));
        pnovono->Dados = (TCadastroU *)malloc(sizeof(TCadastroU));
        strcpy(pnovono->Dados->CNPJ, pI->Dados->CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pI->Dados->RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pI->Dados->Cidade);
        strcpy(pnovono->Dados->Fone, pI->Dados->Fone);
        pnovono->Dados->Tipo = 'I';
        pnovono->Ant = pUnica->Fim;
        pnovono->Prox = NULL;
        if (pUnica->Fim != NULL)
        {
            pUnica->Fim->Prox = pnovono;
        }
        else
        {
            pUnica->Inicio = pnovono;
        }
        pUnica->Fim = pnovono;
        pUnica->Tamanho++;
        pI = pI->Prox;
    }

    // Unificar lista de Comércio
    while (pC != NULL)
    {
        pnovono = (TNoU *)malloc(sizeof(TNoU));
        pnovono->Dados = (TCadastroU *)malloc(sizeof(TCadastroU));
        strcpy(pnovono->Dados->CNPJ, pC->Dados->CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pC->Dados->RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pC->Dados->Cidade);
        strcpy(pnovono->Dados->Fone, pC->Dados->Fone);
        pnovono->Dados->Tipo = 'C';
        pnovono->Ant = pUnica->Fim;
        pnovono->Prox = NULL;
        if (pUnica->Fim != NULL)
        {
            pUnica->Fim->Prox = pnovono;
        }
        else
        {
            pUnica->Inicio = pnovono;
        }
        pUnica->Fim = pnovono;
        pUnica->Tamanho++;
        pC = pC->Prox;
    }

    // Unificar lista de Serviços
    while (pS != NULL)
    {
        pnovono = (TNoU *)malloc(sizeof(TNoU));
        pnovono->Dados = (TCadastroU *)malloc(sizeof(TCadastroU));
        strcpy(pnovono->Dados->CNPJ, pS->Dados->CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pS->Dados->RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pS->Dados->Cidade);
        strcpy(pnovono->Dados->Fone, pS->Dados->Fone);
        pnovono->Dados->Tipo = 'S';
        pnovono->Ant = pUnica->Fim;
        pnovono->Prox = NULL;
        if (pUnica->Fim != NULL)
        {
            pUnica->Fim->Prox = pnovono;
        }
        else
        {
            pUnica->Inicio = pnovono;
        }
        pUnica->Fim = pnovono;
        pUnica->Tamanho++;
        pS = pS->Prox;
    }
}

// Listar Conteúdo da lista Unificada:
void ImprimeUnificada(TDescritorU *pListaUnica)
{
    TNoU *plista = pListaUnica->Inicio;
    printf("                     LISTA UNIFICADA\n");
    printf("Tipo    CNPJ            Razao Social                Cidade      Telefone\n");
    while (plista != NULL)
    {
        printf("%c:\t\t%s\t%s\t%s\t%s\n", plista->Dados->Tipo, plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
    }
}

// Listar Conteúdo da lista Unificada da calda para a cabeça:
void ImprimeUnificadaInvertida(TDescritorU *pListaUnica)
{
    TNoU *plista = pListaUnica->Fim;
    printf("                     LISTA UNIFICADA INVERTIDA\n");
    printf("Tipo    CNPJ            Razao Social                Cidade      Telefone\n");
    while (plista != NULL)
    {
        printf("%c:\t\t%s\t%s\t%s\t%s\n", plista->Dados->Tipo, plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Ant;
    }
}

// Listar Conteúdo da lista Unificada:
void ImprimeUnificada(TDescritorU *pdescritor)
{
    // Complete o código...

    // ######################
}

// Desalocar todas as listas:
// Função para desalocar todas as listas
void DesalocaListas(TNoI *pInd, TNoC *pCom, TDescritorS *pServ, TDescritorU *pUnica)
{
    TNoI *auxI;
    TNoC *auxC;
    TNoS *auxS;
    TNoU *auxU;

    // Desalocar lista de Indústrias
    while (pInd != NULL)
    {
        auxI = pInd;
        pInd = pInd->Prox;
        free(auxI->Dados);
        free(auxI);
    }

    // Desalocar lista de Comércio
    while (pCom != NULL)
    {
        auxC = pCom;
        pCom = pCom->Prox;
        free(auxC->Dados);
        free(auxC);
    }

    // Desalocar lista de Serviços
    while (pServ->Inicio != NULL)
    {
        auxS = pServ->Inicio;
        pServ->Inicio = pServ->Inicio->Prox;
        free(auxS->Dados);
        free(auxS);
    }

    // Desalocar lista Unificada
    while (pUnica->Inicio != NULL)
    {
        auxU = pUnica->Inicio;
        pUnica->Inicio = pUnica->Inicio->Prox;
        free(auxU->Dados);
        free(auxU);
    }
}

int main() {
    int continuar = 1;
    // Listas de entrada
    TNoI *LIndustria = NULL;
    TNoC *LComercio = NULL;
    TDescritorS LServico = {NULL, 0, NULL};
    // Lista Unificada
    TDescritorU LUnica = {NULL, 0, NULL};

    do {
        printf("\n\tSecretaria da Fazenda do Distrito Federal");
        printf("\n\tSistema de Unificacao de Cadastro de Contribuintes\n\n");
        printf("1. Carregar Dados de Entrada\n");
        printf("2. Gerar Lista Unificada\n");
        printf("3. Relatorio: Industrias\n");
        printf("4. Relatorio: Comercios\n");
        printf("5. Relatorio: Servicos\n");
        printf("6. Relatorio: Lista Unificada\n");
        printf("7. Relatorio: Lista Unificada Invertida\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        // system("cls || clear");

        switch (continuar) {
            case 1:
                if ((LIndustria = CriaListaIndustria()))
                    printf("Lista de Industria montada!\n");
                else {
                    printf("Erro na criacao da Lista de Industria!\n");
                    break;
                }
                if ((LComercio = CriaListaComercio()))
                    printf("Lista de Comercio montada!\n");
                else {
                    printf("Erro na criacao da Lista de Comercio!\n");
                    break;
                }
                if (CriaListaServico(&LServico))
                    printf("Lista de Servico montada!\n");
                else {
                    printf("Erro na criacao da Lista de Servico!\n");
                }
                break;

            case 2:
                CriaListaUnificada(LIndustria, LComercio, &LServico, &LUnica);
                printf("Lista Unificada montada!\n");
                break;

            case 3:
                ImprimeIndustria(LIndustria);
                break;

            case 4:
                ImprimeComercio(LComercio);
                break;

            case 5:
                ImprimeServico(&LServico);
                break;

            case 6:
                ImprimeUnificada(&LUnica);
                break;

            case 7:
                ImprimeUnificadaInvertida(&LUnica);
                break;

            case 0:
                DesalocaListas(LIndustria, LComercio, &LServico, &LUnica);
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while (continuar);

    return 0;
}
