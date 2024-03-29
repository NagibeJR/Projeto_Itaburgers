#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include <string.h>

int limite_colunas, limite_linhas, cor_letra, linha, coluna, escolha_da_categoria, escolha = 0, Guardar_Itens[100] = {0};
float somaTotal = 0;
float valorRecebido = 0;
float troco = 0;
float taxa = 5;
int i, ItensCarrinho = 0, right = 0, down = 0, Contar_Hamburguer = 0, Contar_Acompanhamento = 0,Carrinho[1]={0};
float ItensGeral[10][5];

struct cliente
{
    char nome[100];
    char bairro[100];
    char rua[100];
    int numeroCasa;
};

void Ordenar_Itens_Em_Ordem_Crescente(int Repeticao, int Itens[])
{ //ordenar os itens por ordem de preço e nao por ordem de escolha
    int i, j, aux = 0;
    for (i = 0; i < Repeticao; i++)
    {
        for (j = i + 1; j < Repeticao; j++)
        {
            if (Itens[j] < Itens[i])
            {
                aux = Itens[j];
                Itens[j] = Itens[i];
                Itens[i] = aux;
            }
        }
    }
}

float Apagar_Itens(float Total, int Repeticao, int esco, int Itens[], int hamb, int Apagar,int Carrinho[])
{ // para eliminar algum item que nao queira mais
    int i, j;

    for (i = 0; i < Repeticao; i++)
        if (Itens[i] == Apagar)
        {
            Total -= ItensGeral[esco][hamb];
            Itens[i] = 50;
            i = Repeticao;
            Carrinho[0]--;
        }
    return Total;
}

void Limpar_Texto(int i) //após remover o item o nome dele ser removido da lista
{
    for (int j = 0; j < i; j++)
        printf(" ");
}

void Desenho_Do_Carrinho(float soma) //carrinho de compras se movendo, local onde pode ver os itens selecionados e tbm remover algo que nao queira masi comprar
{
    int i, j;
    gotoxy(2, 15);
    printf("______________________________________________________________________________________________________________");
    for (i = 2; i < 90; i++)
    {
        gotoxy(i, 10);
        printf("  _");
        gotoxy(i, 11);
        printf("    \\________");
        gotoxy(i, 12);
        printf(" ~   \\######/       ");
        gotoxy(i, 13);
        printf("  ~   |####/");
        gotoxy(i, 14);
        printf(" ~    |____.");
        gotoxy(i, 15);
        printf("______o____o__________ ");

        Sleep(2);
        if (i < 90)
            ;
        gotoxy(i, 10);
        printf("   ");
        gotoxy(i, 11);
        printf("             ");
        gotoxy(i, 12);
        printf("                    ");
        gotoxy(i, 13);
        printf("            ");
        gotoxy(i, 14);
        printf("            ");
        gotoxy(2, 15);
        printf("______________________________________________________________________________________________________________");
    }
    gotoxy(90, 10);
    printf("  _");
    gotoxy(90, 11);
    printf("    \\________");
    gotoxy(90, 12);
    printf(" ~   \\######/       ");
    gotoxy(90, 13);
    printf("  ~   |####/");
    gotoxy(90, 14);
    printf(" ~    |____.");
    gotoxy(90, 15);
    printf("______o____o__________ ");

    Sleep(500);

    gotoxy(2, 9);
    textcolor(GREEN);
    printf("Valor Total (%.2f)", soma);
    textcolor(YELLOW);

    Sleep(500);
    //gotoxy(2,11);printf("%s, SELECIONE UMA DAS OPCOES ABAIXO: ",nome);
    gotoxy(2, 13);
    printf("(1) DESEJA REMOVER ALGUMA OPCAO DO CARRINHO?");
    Sleep(500);
    gotoxy(2, 14);
    textcolor(LIGHTRED);
    printf("(0) VOLTAR PARA CARDAPIO");
    textcolor(YELLOW);
    Sleep(500);
}

void Nome_Carrinho_De_Compra() //nome carrinho de compras na tela
{
    gotoxy(20, 2);
    textcolor(RED);
    printf(" _____ _______          _____ ____  __  __ _____  _____             _____ ");
    gotoxy(20, 3);
    printf("|_   _|__   __|/\\      / ____/ __ \\|  \\/  |  __ \\|  __ \\     /\\    / ____|");
    gotoxy(20, 4);
    printf("  | |    | |  /  \\    | |   | |  | | \\  / | |__) | |__) |   /  \\  | (___  ");
    gotoxy(20, 5);
    printf("  | |    | | / /\\ \\   | |   | |  | | |\\/| |  ___/|  _  /   / /\\ \\  \\___ \\ ");
    gotoxy(20, 6);
    printf(" _| |_   | |/ ____ \\  | |___| |__| | |  | | |    | | \\ \\  / ____ \\ ____) |");
    gotoxy(20, 7);
    printf("|_____|  |_/_/    \\_\\  \\_____\\____/|_|  |_|_|    |_|  \\_\\\/_/    \\_\\_____/ ");
    textcolor(YELLOW);
}

void Mostrar_Itens_Carrinho_Hambuger(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 2, Controle_Coluna = 18, j = 0;
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0, h7 = 0, h8 = 0, h9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(CYAN);
    printf("HAMBURGUERS ESCOLHIDOS");
    textcolor(YELLOW);
    Controle_Coluna += 2;
    gotoxy(24, 18);
    printf("(%c)", 25);

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 1)
            h1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 2)
            h2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 3)
            h3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 4)
            h4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 5)
            h5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 6)
            h6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 7)
            h7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 8)
            h8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 9)
            h9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 1 && h1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITRADICIONAL R$ 5,00", h1);
            h1 = 0;
        }
        else if (Itens[i] == 2 && h2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA CHEDDAR R$ 6,50", h2);
            h2 = 0;
        }
        else if (Itens[i] == 3 && h3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA BACON R$ 8,50", h3);
            h3 = 0;
        }
        else if (Itens[i] == 4 && h4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA CHICKEN R$ 10,00", h4);
            h4 = 0;
        }
        else if (Itens[i] == 5 && h5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA HOUSE R$ 15,00", h5);
            h5 = 0;
        }
        else if (Itens[i] == 6 && h6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA VEGETARIANO R$ 20,00", h6);
            h6 = 0;
        }
        else if (Itens[i] == 7 && h7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA KONG R$ 25,00", h7);
            h7 = 0;
        }
        else if (Itens[i] == 8 && h8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA GODZILLA R$ 25,00", h8);
            h8 = 0;
        }
        else if (Itens[i] == 9 && h9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA PICANHA R$ 30,00", h9);
            h9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Hambuger_3(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 2, Controle_Coluna = 18, j = 0;
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0, h7 = 0, h8 = 0, h9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(CYAN);
    printf("CATEGORIA HAMBURGUERS(1)");
    textcolor(YELLOW);
    Controle_Coluna += 2;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 1)
            h1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 2)
            h2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 3)
            h3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 4)
            h4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 5)
            h5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 6)
            h6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 7)
            h7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 8)
            h8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 9)
            h9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 1 && h1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITRADICIONAL R$ 5,00", h1);
            h1 = 0;
        }
        else if (Itens[i] == 2 && h2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA CHEDDAR R$ 6,50", h2);
            h2 = 0;
        }
        else if (Itens[i] == 3 && h3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA BACON R$ 8,50", h3);
            h3 = 0;
        }
        else if (Itens[i] == 4 && h4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA CHICKEN R$ 10,00", h4);
            h4 = 0;
        }
        else if (Itens[i] == 5 && h5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA HOUSE R$ 15,00", h5);
            h5 = 0;
        }
        else if (Itens[i] == 6 && h6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA VEGETARIANO R$ 20,00", h6);
            h6 = 0;
        }
        else if (Itens[i] == 7 && h7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA KONG R$ 25,00", h7);
            h7 = 0;
        }
        else if (Itens[i] == 8 && h8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA GODZILLA R$ 25,00", h8);
            h8 = 0;
        }
        else if (Itens[i] == 9 && h9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITA PICANHA R$ 30,00", h9);
            h9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Hambuger_2(int Repeticao, int Itens[])
{

    int i = 0, Controle_Linha = 2, Controle_Coluna = 18, j = 0;
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0, h7 = 0, h8 = 0, h9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(CYAN);
    printf("HAMBURGUERS ESCOLHIDOS(%c)", 25);
    Controle_Coluna += 2;
    textcolor(YELLOW);

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 1)
            h1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 2)
            h2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 3)
            h3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 4)
            h4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 5)
            h5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 6)
            h6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 7)
            h7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 8)
            h8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 9)
            h9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 1 && h1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(1) ITRADICIONAL R$ 5,00 (%dx)", h1);
            h1 = 0;
        }
        else if (Itens[i] == 2 && h2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(2) ITA CHEDDAR R$ 6,50 (%dx)", h2);
            h2 = 0;
        }
        else if (Itens[i] == 3 && h3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(3) ITA BACON R$ 8,50 (%dx)", h3);
            h3 = 0;
        }
        else if (Itens[i] == 4 && h4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(4) ITA CHICKEN R$ 10,00 (%dx)", h4);
            h4 = 0;
        }
        else if (Itens[i] == 5 && h5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(5) ITA HOUSE R$ 15,00 (%dx)", h5);
            h5 = 0;
        }
        else if (Itens[i] == 6 && h6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(6) ITA VEGETARIANO R$ 20,00 (%dx)", h6);
            h6 = 0;
        }
        else if (Itens[i] == 7 && h7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(7) ITA KONG R$ 25,00 (%dx)", h7);
            h7 = 0;
        }
        else if (Itens[i] == 8 && h8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(8) ITA GODZILLA R$ 25,00 (%dx)", h8);
            h8 = 0;
        }
        else if (Itens[i] == 9 && h9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(9) ITA PICANHA R$ 30,00 (%dx)", h9);
            h9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Acompanhamento(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 32, Controle_Coluna = 18, j = 0;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(MAGENTA);
    printf("ACOMPANHAMENTOS ESCOLHIDOS");
    Controle_Coluna += 2;
    textcolor(YELLOW);
    gotoxy(58, 18);
    printf("(%c)", 25);

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 11)
            a1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 12)
            a2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 13)
            a3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 14)
            a4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 15)
            a5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 16)
            a6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 17)
            a7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 18)
            a8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 19)
            a9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 11 && a1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITABATATINHA (P) R$ 6,00", a1);
            a1 = 0;
        }
        else if (Itens[i] == 12 && a2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITABATATINHA (M) R$ 12,00", a2);
            a2 = 0;
        }
        else if (Itens[i] == 13 && a3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITABATATINHA (G) R$ 18,00", a3);
            a3 = 0;
        }
        else if (Itens[i] == 14 && a4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITANUGGETS (P) 6,00", a4);
            a4 = 0;
        }
        else if (Itens[i] == 15 && a5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITANUGGETS (M) 12,00", a5);
            a5 = 0;
        }
        else if (Itens[i] == 16 && a6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITANUGGETS (G) 18,00", a6);
            a6 = 0;
        }
        else if (Itens[i] == 17 && a7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITACEBOLIAS (P) R$ 6.00", a7);
            a7 = 0;
        }
        else if (Itens[i] == 18 && a8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITACEBOLIAS (M) R$ 12.00", a8);
            a8 = 0;
        }
        else if (Itens[i] == 19 && a9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITACEBOLIAS (G) R$ 18.00", a9);
            a9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Acompanhamento_3(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 32, Controle_Coluna = 18, j = 0;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(MAGENTA);
    printf("CATEGORIA ACOMPANHAMENTOS(2)");
    Controle_Coluna += 2;
    textcolor(YELLOW);

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 11)
            a1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 12)
            a2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 13)
            a3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 14)
            a4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 15)
            a5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 16)
            a6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 17)
            a7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 18)
            a8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 19)
            a9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 11 && a1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITABATATINHA (P) R$ 6,00", a1);
            a1 = 0;
        }
        else if (Itens[i] == 12 && a2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITABATATINHA (M) R$ 12,00", a2);
            a2 = 0;
        }
        else if (Itens[i] == 13 && a3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITABATATINHA (G) R$ 18,00", a3);
            a3 = 0;
        }
        else if (Itens[i] == 14 && a4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITANUGGETS (P) 6,00", a4);
            a4 = 0;
        }
        else if (Itens[i] == 15 && a5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITANUGGETS (M) 12,00", a5);
            a5 = 0;
        }
        else if (Itens[i] == 16 && a6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITANUGGETS (G) 18,00", a6);
            a6 = 0;
        }
        else if (Itens[i] == 17 && a7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITACEBOLIAS (P) R$ 6.00", a7);
            a7 = 0;
        }
        else if (Itens[i] == 18 && a8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITACEBOLIAS (M) R$ 12.00", a8);
            a8 = 0;
        }
        else if (Itens[i] == 19 && a9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ITACEBOLIAS (G) R$ 18.00", a9);
            a9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Acompanhamento_2(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 32, Controle_Coluna = 18, j = 0;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(MAGENTA);
    printf("ACOMPANHAMENTOS ESCOLHIDOS(%c)", 25);
    textcolor(YELLOW);
    Controle_Coluna += 2;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 11)
            a1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 12)
            a2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 13)
            a3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 14)
            a4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 15)
            a5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 16)
            a6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 17)
            a7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 18)
            a8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 19)
            a9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 11 && a1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(1) ITABATATINHA (P) R$ 6,00 (%dx)", a1);
            a1 = 0;
        }
        else if (Itens[i] == 12 && a2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(2) ITABATATINHA (M) R$ 12,00 (%dx)", a2);
            a2 = 0;
        }
        else if (Itens[i] == 13 && a3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(3) ITABATATINHA (G) R$ 18,00 (%dx)", a3);
            a3 = 0;
        }
        else if (Itens[i] == 14 && a4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(4) ITANUGGETS (P) 6,00 (%dx)", a4);
            a4 = 0;
        }
        else if (Itens[i] == 15 && a5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(5) ITANUGGETS (M) 12,00 (%dx)", a5);
            a5 = 0;
        }
        else if (Itens[i] == 16 && a6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(6) ITANUGGETS (G) 18,00 (%dx)", a6);
            a6 = 0;
        }
        else if (Itens[i] == 17 && a7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(7) ITACEBOLIAS (P) R$ 6.00 (%dx)", a7);
            a7 = 0;
        }
        else if (Itens[i] == 18 && a8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(8) ITACEBOLIAS (M) R$ 12.00 (%dx)", a8);
            a8 = 0;
        }
        else if (Itens[i] == 19 && a9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(9) ITACEBOLIAS (G) R$ 18.00 (%dx)", a9);
            a9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Bebidas(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 63, Controle_Coluna = 18, j = 0;
    int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0, b9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(BLUE);
    printf("BEBIDAS ESCOLHIDAS");
    textcolor(YELLOW);
    Controle_Coluna += 2;
    gotoxy(81, 18);
    printf("(%c)", 25);

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 21)
            b1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 22)
            b2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 23)
            b3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 24)
            b4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 25)
            b5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 26)
            b6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 27)
            b7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 28)
            b8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 29)
            b9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 21 && b1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ita-cola R$ 4,50", b1);
            b1 = 0;
        }
        else if (Itens[i] == 22 && b2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) itaguarana R$ 4,50", b2);
            b2 = 0;
        }
        else if (Itens[i] == 23 && b3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) italaranja R$ 4,50", b3);
            b3 = 0;
        }
        else if (Itens[i] == 24 && b4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ita-limao 4,00", b4);
            b4 = 0;
        }
        else if (Itens[i] == 25 && b5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ita-acerola 4,00", b5);
            b5 = 0;
        }
        else if (Itens[i] == 26 && b6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ita-maracuja 4,00", b6);
            b6 = 0;
        }
        else if (Itens[i] == 27 && b7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) sem gas R$ 2,00", b7);
            b7 = 0;
        }
        else if (Itens[i] == 28 && b8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) com gas R$ 2,50", b8);
            b8 = 0;
        }
        else if (Itens[i] == 29 && b9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) tonica R$ 3,00", b9);
            b9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Bebidas_3(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 63, Controle_Coluna = 18, j = 0;
    int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0, b9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(BLUE);
    printf("CATEGORIA BEBIDAS(3)");
    textcolor(YELLOW);
    Controle_Coluna += 2;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 21)
            b1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 22)
            b2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 23)
            b3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 24)
            b4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 25)
            b5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 26)
            b6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 27)
            b7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 28)
            b8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 29)
            b9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 21 && b1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ita-cola R$ 4,50", b1);
            b1 = 0;
        }
        else if (Itens[i] == 22 && b2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) itaguarana R$ 4,50", b2);
            b2 = 0;
        }
        else if (Itens[i] == 23 && b3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) italaranja R$ 4,50", b3);
            b3 = 0;
        }
        else if (Itens[i] == 24 && b4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ita-limao 4,00", b4);
            b4 = 0;
        }
        else if (Itens[i] == 25 && b5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ita-acerola 4,00", b5);
            b5 = 0;
        }
        else if (Itens[i] == 26 && b6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) ita-maracuja 4,00", b6);
            b6 = 0;
        }
        else if (Itens[i] == 27 && b7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) sem gas R$ 2,00", b7);
            b7 = 0;
        }
        else if (Itens[i] == 28 && b8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) com gas R$ 2,50", b8);
            b8 = 0;
        }
        else if (Itens[i] == 29 && b9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) tonica R$ 3,00", b9);
            b9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Bebidas_2(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 63, Controle_Coluna = 18, j = 0;
    int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0, b9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(BLUE);
    printf("BEBIDAS ESCOLHIDAS(%c)", 25);
    textcolor(YELLOW);
    Controle_Coluna += 2;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 21)
            b1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 22)
            b2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 23)
            b3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 24)
            b4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 25)
            b5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 26)
            b6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 27)
            b7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 28)
            b8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 29)
            b9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 21 && b1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(1) ita-cola R$ 4,50 (%dx)", b1);
            b1 = 0;
        }
        else if (Itens[i] == 22 && b2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(2) itaguarana R$ 4,50 (%dx)", b2);
            b2 = 0;
        }
        else if (Itens[i] == 23 && b3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(3) italaranja R$ 4,50 (%dx)", b3);
            b3 = 0;
        }
        else if (Itens[i] == 24 && b4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(4) ita-limao 4,00 (%dx)", b4);
            b4 = 0;
        }
        else if (Itens[i] == 25 && b5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(5) ita-acerola 4,00 (%dx)", b5);
            b5 = 0;
        }
        else if (Itens[i] == 26 && b6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(6) ita-maracuja 4,00 (%dx)", b6);
            b6 = 0;
        }
        else if (Itens[i] == 27 && b7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(7) sem gas R$ 2,00 (%dx)", b7);
            b7 = 0;
        }
        else if (Itens[i] == 28 && b8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(8) com gas R$ 2,50 (%dx)", b8);
            b8 = 0;
        }
        else if (Itens[i] == 29 && b9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(9) tonica R$ 3,00 (%dx)", b9);
            b9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Sobremesas(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 87, Controle_Coluna = 18, j = 0;
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0, s9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(DARKGRAY);
    printf("SOBREMESAS ESCOLHIDAS");
    textcolor(YELLOW);
    Controle_Coluna += 2;
    gotoxy(108, 18);
    printf("(%c)", 25);

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 31)
            s1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 32)
            s2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 33)
            s3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 34)
            s4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 35)
            s5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 36)
            s6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 37)
            s7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 38)
            s8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 39)
            s9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 31 && s1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SOR. Chocolate R$ 10,00", s1);
            s1 = 0;
        }
        else if (Itens[i] == 32 && s2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SOR. Baunilha R$ 10,00", s2);
            s2 = 0;
        }
        else if (Itens[i] == 33 && s3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SOR. Morango R$ 10,00", s3);
            s3 = 0;
        }
        else if (Itens[i] == 34 && s4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SH. Chocolate 10,00", s4);
            s4 = 0;
        }
        else if (Itens[i] == 35 && s5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SH. Baunilha 10,00", s5);
            s5 = 0;
        }
        else if (Itens[i] == 36 && s6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SH. Morango 10,00", s6);
            s6 = 0;
        }
        else if (Itens[i] == 37 && s7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) CAS. Chocolate R$ 2,00", s7);
            s7 = 0;
        }
        else if (Itens[i] == 38 && s8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) CAS. Baunilha R$ 2,00", s8);
            s8 = 0;
        }
        else if (Itens[i] == 39 && s9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) CAS. Misto R$ 2,00", s9);
            s9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Sobremesas_3(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 87, Controle_Coluna = 18, j = 0;
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0, s9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(DARKGRAY);
    printf("CATEGORIA SOBREMESAS(4)");
    textcolor(YELLOW);
    Controle_Coluna += 2;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 31)
            s1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 32)
            s2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 33)
            s3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 34)
            s4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 35)
            s5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 36)
            s6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 37)
            s7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 38)
            s8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 39)
            s9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 31 && s1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SOR. Chocolate R$ 10,00", s1);
            s1 = 0;
        }
        else if (Itens[i] == 32 && s2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SOR. Baunilha R$ 10,00", s2);
            s2 = 0;
        }
        else if (Itens[i] == 33 && s3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SOR. Morango R$ 10,00", s3);
            s3 = 0;
        }
        else if (Itens[i] == 34 && s4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SH. Chocolate 10,00", s4);
            s4 = 0;
        }
        else if (Itens[i] == 35 && s5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SH. Baunilha 10,00", s5);
            s5 = 0;
        }
        else if (Itens[i] == 36 && s6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) SH. Morango 10,00", s6);
            s6 = 0;
        }
        else if (Itens[i] == 37 && s7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) CAS. Chocolate R$ 2,00", s7);
            s7 = 0;
        }
        else if (Itens[i] == 38 && s8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) CAS. Baunilha R$ 2,00", s8);
            s8 = 0;
        }
        else if (Itens[i] == 39 && s9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(%dx) CAS. Misto R$ 2,00", s9);
            s9 = 0;
        }
    }
}

void Mostrar_Itens_Carrinho_Sobremesas_2(int Repeticao, int Itens[])
{
    int i = 0, Controle_Linha = 87, Controle_Coluna = 18, j = 0;
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0, s9 = 0;

    gotoxy(Controle_Linha, Controle_Coluna);
    textcolor(DARKGRAY);
    printf("SOBREMESAS ESCOLHIDAS(%c)", 25);
    textcolor(YELLOW);
    Controle_Coluna += 2;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 31)
            s1++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 32)
            s2++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 33)
            s3++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 34)
            s4++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 35)
            s5++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 36)
            s6++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 37)
            s7++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 38)
            s8++;

    for (j = 0; j < Repeticao; j++)
        if (Itens[j] == 39)
            s9++;

    for (i = 0; i < Repeticao; i++)
    {
        if (Itens[i] == 31 && s1 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(1) SOR. Chocolate R$ 10,00 (%dx)", s1);
            s1 = 0;
        }
        else if (Itens[i] == 32 && s2 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(2) SOR. Baunilha R$ 10,00 (%dx)", s2);
            s2 = 0;
        }
        else if (Itens[i] == 33 && s3 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(3) SOR. Morango R$ 10,00 (%dx)", s3);
            s3 = 0;
        }
        else if (Itens[i] == 34 && s4 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(4) SH. Chocolate 10,00 (%dx)", s4);
            s4 = 0;
        }
        else if (Itens[i] == 35 && s5 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(5) SH. Baunilha 10,00 (%dx)", s5);
            s5 = 0;
        }
        else if (Itens[i] == 36 && s6 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(6) SH. Morango 10,00 (%dx)", s6);
            s6 = 0;
        }
        else if (Itens[i] == 37 && s7 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(7) CAS. Chocolate R$ 2,00 (%dx)", s7);
            s7 = 0;
        }
        else if (Itens[i] == 38 && s8 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(8) CAS. Baunilha R$ 2,00 (%dx)", s8);
            s8 = 0;
        }
        else if (Itens[i] == 39 && s9 != 0)
        {
            gotoxy(Controle_Linha, Controle_Coluna);
            Controle_Coluna++;
            printf("(9) CAS. Misto R$ 2,00 (%dx)", s9);
            s9 = 0;
        }
    }
}

void Itens_Geral(float ItensGeral[10][5]) //matriz com o valor de cada item
{
    ItensGeral[1][1] = 5;
    ItensGeral[2][1] = 6.5;
    ItensGeral[3][1] = 8.5;
    ItensGeral[4][1] = 10;
    ItensGeral[5][1] = 15;
    ItensGeral[6][1] = 20;
    ItensGeral[7][1] = 25;
    ItensGeral[8][1] = 25;
    ItensGeral[9][1] = 30;

    ItensGeral[1][2] = 6;
    ItensGeral[2][2] = 12;
    ItensGeral[3][2] = 18;
    ItensGeral[4][2] = 6;
    ItensGeral[5][2] = 12;
    ItensGeral[6][2] = 18;
    ItensGeral[7][2] = 6;
    ItensGeral[8][2] = 12;
    ItensGeral[9][2] = 18;

    ItensGeral[1][3] = 4.5;
    ItensGeral[2][3] = 4.5;
    ItensGeral[3][3] = 4.5;
    ItensGeral[4][3] = 4;
    ItensGeral[5][3] = 4;
    ItensGeral[6][3] = 4;
    ItensGeral[7][3] = 2;
    ItensGeral[8][3] = 2.5;
    ItensGeral[9][3] = 3;

    ItensGeral[1][4] = 10;
    ItensGeral[2][4] = 10;
    ItensGeral[3][4] = 10;
    ItensGeral[4][4] = 10;
    ItensGeral[5][4] = 10;
    ItensGeral[6][4] = 10;
    ItensGeral[7][4] = 2;
    ItensGeral[8][4] = 2;
    ItensGeral[9][4] = 2;
}

void EntregaMotoboy() //imagem do motoboy indo entregar o lanche na casa do cliente
{

    printf("       ,_o");
    printf("    .-/c-/,:: ");
    printf("    (_)'==(_)");
    printf("");
    printf("... ..... ... ..");
    printf(" .. .... ..... ..");
    printf(" ... ..... ... ..");
}

void borda() // borda do programa
{

    limite_colunas = 119, limite_linhas = 29, cor_letra = YELLOW;
    textcolor(cor_letra);
    for (linha = 1; linha <= limite_linhas; linha++)
    {
        for (coluna = 1; coluna <= limite_colunas; coluna++)
            printf(" ");
        printf("\n");
    }
    gotoxy(1, 1);

    printf("%c", 201);
    for (coluna = 2; coluna < limite_colunas; coluna++)
        printf("%c", 205);
    printf("%c\n", 187);
    for (linha = 2; linha < limite_linhas; linha++)
    {
        gotoxy(1, linha);
        printf("%c", 186);
        gotoxy(limite_colunas, linha);
        printf("%c", 186);
    }
    printf("\n%c", 200);
    for (coluna = 2; coluna < limite_colunas; coluna++)
        printf("%c", 205);
    printf("%c", 188);
}

void bemVindo() //escrita da frase: Bem Vindo
{
    borda();
    textcolor(RED);
    gotoxy(15, 3);
    printf("  _____ ______     _           ____  ______ __  __     __      _______ _   _ _____   ____  ");
    gotoxy(15, 4);
    printf(" / ____|  ____|   | |  /\\     |  _ \\|  ____|  \\/  |    \\ \\    / /_   _| \\ | |  __ \\ / __ \\  ");
    gotoxy(15, 5);
    printf("| (___ | |__      | | /  \\    | |_) | |__  | \\  / |_____\\ \\  / /  | | |  \\| | |  | | |  | |");
    gotoxy(15, 6);
    printf(" \\___ \\|  __| _   | |/ /\\ \\   |  _ <|  __| | |\\/| |______\\ \\/ /   | | | . ` | |  | | |  | |");
    gotoxy(15, 7);
    printf(" ____) | |___| |__| / ____ \\  | |_) | |____| |  | |       \\  /   _| |_| |\\  | |__| | |__| |");
    gotoxy(15, 8);
    printf("|_____/|______\\____/_/    \\_\\ |____/|______|_|  |_|        \\/   |_____|_| \\_|_____/ \\____/ ");
}

void ITA() //escrita do Ita Burguer
{

    borda();
    textcolor(BROWN);
    gotoxy(23, 10);
    printf(" _____ _______       ____  _    _ _____   _____ _    _ ______ _____   _____ ");
    gotoxy(23, 11);
    printf("|_   _|__   __|/\\   |  _ \\| |  | |  __ \\ / ____| |  | |  ____|  __ \\ / ____|");
    gotoxy(23, 12);
    printf("  | |    | |  /  \\  | |_) | |  | | |__) | |  __| |  | | |__  | |__) | (___  ");
    gotoxy(23, 13);
    printf("  | |    | | / /\\ \\ |  _ <| |  | |  _  /| | |_ | |  | |  __| |  _  / \\___ \\ ");
    gotoxy(23, 14);
    printf(" _| |_   | |/ ____ \\| |_) | |__| | | \\ \\| |__| | |__| | |____| | \\ \\ ____) |");
    gotoxy(23, 15);
    printf("|_____|  |_/_/    \\_\\____/ \\____/|_|  \\_\\\\_____|\\____/|______|_|  \\_\\_____/");
}

void informe(struct cliente usuario) //receber os dados do usuario
{
    textcolor(YELLOW);
    gotoxy(15, 20);
    printf("Por favor, informe o seu nome:  ");
    textcolor(WHITE);
    gets(usuario.nome);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 22);
    printf("(%c) Por favor, informe o seu endereco", 25);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 23);
    printf("Bairro : ");
    textcolor(WHITE);
    gets(usuario.bairro);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 24);
    printf("Rua : ");
    textcolor(WHITE);
    gets(usuario.rua);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 25);
    printf("Numero : ");
    textcolor(WHITE);
    scanf("%d", &usuario.numeroCasa);
    getchar();
}

void cardapioInicial() //escrita da palavra cardapio
{
    borda();
    textcolor(RED);
    gotoxy(30, 5);
    printf("  _____          _____  _____          _____ _____ ____  ");
    gotoxy(30, 6);
    printf(" / ____|   /\\   |  __ \\|  __ \\   /\\   |  __ \\_   _/ __ \\ ");
    gotoxy(30, 7);
    printf("| |       /  \\  | |__) | |  | | /  \\  | |__) || || |  | |");
    gotoxy(30, 8);
    printf("| |      / /\\ \\ |  _  /| |  | |/ /\\ \\ |  ___/ | || |  | |");
    gotoxy(30, 9);
    printf("| |____ / ____ \\| | \\ \\| |__| / ____ \\| |    _| || |__| |");
    gotoxy(30, 10);
    printf(" \\_____/_/    \\_\\_|  \\_\\_____/_/    \\_\\_|   |_____\\____/");
}

void cardapioLateral() //escrita da palavra cardapio no canto para poder colocar desenho do lado
{

    textcolor(RED);
    gotoxy(3, 3);
    printf("  _____          _____  _____          _____ _____ ____  ");
    gotoxy(3, 4);
    printf(" / ____|   /\\   |  __ \\|  __ \\   /\\   |  __ \\_   _/ __ \\ ");
    gotoxy(3, 5);
    printf("| |       /  \\  | |__) | |  | | /  \\  | |__) || || |  | |");
    gotoxy(3, 6);
    printf("| |      / /\\ \\ |  _  /| |  | |/ /\\ \\ |  ___/ | || |  | |");
    gotoxy(3, 7);
    printf("| |____ / ____ \\| | \\ \\| |__| / ____ \\| |    _| || |__| |");
    gotoxy(3, 8);
    printf(" \\_____/_/    \\_\\_|  \\_\\_____/_/    \\_\\_|   |_____\\____/");
}

void burgLateral() //desenho do hamburgues
{
    textcolor(BROWN);
    gotoxy(60, 2);
    printf("      _..----.._  ");
    gotoxy(60, 3);
    printf("    .'     o    '.  ");
    gotoxy(60, 4);
    printf("   /   o       o  \\  ");
    gotoxy(60, 5);
    printf("  |o        o     o|  ");
    gotoxy(60, 6);
    printf("  /'-.._o     __.-'\\ ");
    gotoxy(60, 7);
    printf("  \\      `````     /  ");
    gotoxy(60, 8);
    printf("  |``--........--'`|  ");
    gotoxy(60, 9);
    printf("   \\              /");
    gotoxy(60, 10);
    printf("   `'----------'`");
}

void acompLateral() //desenho do acompanhamento
{
    textcolor(BROWN);
    gotoxy(60, 2);
    printf("     |\\ /| /|_/|");
    gotoxy(60, 3);
    printf("   |\\||-|\\||-/|/|");
    gotoxy(60, 4);
    printf("    \\\\|\\|//||///");
    gotoxy(60, 5);
    printf("    |\\/\\||//||||");
    gotoxy(60, 6);
    printf("    |||\\\\|/\\\\ ||");
    gotoxy(60, 7);
    printf("    | './\\_/.' |");
    gotoxy(60, 8);
    printf("    |          |");
    gotoxy(60, 9);
    printf("    |          |");
    gotoxy(60, 10);
    printf("     '.______.'");
}

void bebidaLateral() //desenho da bebida
{
    textcolor(BROWN);
    gotoxy(60, 2);
    printf("                        \ ");
    gotoxy(60, 3);
    printf("   .\\\""
           ""
           ""
           ""
           "-.");
    gotoxy(60, 4);
    printf("   \\`\\-------'`/");
    gotoxy(60, 5);
    printf("    \\ \\__ o . /");
    gotoxy(60, 6);
    printf("     \\/  \  o /");
    gotoxy(60, 7);
    printf("      \\__/. /");
    gotoxy(60, 8);
    printf("       \\_ _/");
    gotoxy(60, 9);
    printf("         Y");
    gotoxy(60, 10);
    printf("         |");
    gotoxy(60, 11);
    printf("         |");
    gotoxy(60, 12);
    printf("     .-' '-.");
    gotoxy(60, 13);
    printf("    `---------`");
}

void sobLateral() //desenho da sobremesa
{
    textcolor(BROWN);
    gotoxy(60, 2);
    printf("        .-''`''-.");
    gotoxy(60, 3);
    printf("       /        \\");
    gotoxy(60, 4);
    printf("       |        |");
    gotoxy(60, 5);
    printf("       /'---'--`\\");
    gotoxy(60, 6);
    printf("      |          |");
    gotoxy(60, 7);
    printf("      \\.--.---.-./");
    gotoxy(60, 8);
    printf("      (_.--._.-._)");
    gotoxy(60, 9);
    printf("        \\=-=-=-/");
    gotoxy(60, 10);
    printf("         \\=-=-/   ");
    gotoxy(60, 11);
    printf("          \\=-/  ");
    gotoxy(60, 12);
    printf("           \\/");
}

void categorias(char nome[]) //interface que redireciona o usuário para os locais onde pode-se escolher seu pedido, finalizar a compra,cancelar a compra e verificar o carrinho de compras
{
    textcolor(YELLOW);

    gotoxy(15, 16);
    printf("HAMBURGUERS (1)");
    Sleep(500);

    gotoxy(15, 18);
    printf("ACOMPANHAMENTOS (2)");
    Sleep(500);

    gotoxy(15, 20);
    printf("BEBIDAS (3)");
    Sleep(500);

    gotoxy(15, 22);
    printf("SOBREMESAS (4)");
    Sleep(500);
    gotoxy(15, 24);
    textcolor(LIGHTGREEN);
    printf("EFETUAR COMPRA (5)");
    Sleep(500);
    gotoxy(15, 26);
    textcolor(LIGHTRED);
    printf("CANCELAR COMPRA (0)");
    Sleep(500);
    gotoxy(70, 16);
    textcolor(BROWN);
    printf("CARRINHO DE COMPRA (6)");
    Sleep(500);
    gotoxy(70, 19);
    textcolor(BROWN);
    printf("(%d) ITENS NO CARRINHO", Carrinho[0]);
    textcolor(WHITE);
    gotoxy(70, 20);

    textcolor(LIGHTCYAN);
    for (linha = 0; linha < 23; linha++)
        printf("%c", 205);

    gotoxy(70, 18);
    for (linha = 0; linha < 23; linha++)
        printf("%c", 205);

    gotoxy(69, 18);
    printf("%c", 201);
    gotoxy(69, 20);
    printf("%c", 200);
    gotoxy(69, 19);
    printf("%c", 186);
    gotoxy(93, 18);
    printf("%c", 187);
    gotoxy(93, 20);
    printf("%c", 188);
    gotoxy(93, 19);
    printf("%c", 186);
    textcolor(YELLOW);

    gotoxy(15, 14);
    printf("%s, SELECIONE UMAS DAS OPCOES ABAIXO: ", nome);
    scanf("%d", &escolha_da_categoria);
}

void itensBurg() //lista de hamburguers do estabelecimento
{

    textcolor(YELLOW);
    gotoxy(2, 12);
    printf("(1) ITRADICIONAL R$ 5,00");
    textcolor(LIGHTGRAY);
    gotoxy(2, 13);
    printf("pao, carne, mussarela, tomate, alface, cebola.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(2, 15);
    printf("(2) ITA CHEDDAR  R$ 6,50");
    textcolor(LIGHTGRAY);
    gotoxy(2, 16);
    printf("pao, carne, cheddar, cebola caramelizada.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(2, 18);
    printf("(3) ITA BACON R$ 8,50");
    textcolor(LIGHTGRAY);
    gotoxy(2, 19);
    printf("pao, carne, bacon, mussarela, tomate, alface, cebola.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(2, 21);
    printf("(4) ITA CHICKEN  R$ 10,00");
    textcolor(LIGHTGRAY);
    gotoxy(2, 22);
    printf("pao, frango, mussarela, alface, tomate, cebola.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(2, 24);
    printf("(5) ITA HOUSE R$ 15,00");
    textcolor(LIGHTGRAY);
    gotoxy(2, 25);
    printf("pao, picanha, alface, tomate, cebola, mussarela, barbecue.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(59, 12);
    printf("(6) ITA VEGETARIANO R$ 20,00");
    textcolor(LIGHTGRAY);
    gotoxy(59, 13);
    printf("pao, carne de soja, tomate, alface, cebola, champignon.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(59, 15);
    printf("(7) ITA KONG R$ 25,00");
    textcolor(LIGHTGRAY);
    gotoxy(59, 16);
    printf("pao, carne 3x, bacon, cheddar 3x, tomate, banana frita.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(59, 18);
    printf("(8) ITA GODZILLA R$ 25,00 ");
    textcolor(LIGHTGRAY);
    gotoxy(59, 19);
    printf("pao, carne 3x, ovo frito, bacon, cheddar 3x, tomate, cebola.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(59, 21);
    printf("(9) ITA PICANHA R$ 30,00");
    textcolor(LIGHTGRAY);
    gotoxy(59, 22);
    printf("pao, picanha, alface, tomate, cebola, mucarela, barbecue.");

    textcolor(LIGHTRED);
    gotoxy(2, 27);
    printf("VOLTAR PARA CARDAPIO (0)");
    textcolor(WHITE);
    gotoxy(2, 28);
    printf("DIGITE UMA DAS OPCOES ACIMA : ");
}

void itensAcomp() //lista de acompanhamentos do estabelecimento
{

    textcolor(YELLOW);
    gotoxy(3, 12);
    printf("ITABATATINHA");
    textcolor(LIGHTGRAY);
    gotoxy(3, 13);
    printf("(1) P R$ 6,00");
    gotoxy(3, 14);
    printf("(2) M R$ 12,00");
    gotoxy(3, 15);
    printf("(3) G R$ 18,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 17);
    printf("ITANUGGETS");
    textcolor(LIGHTGRAY);
    gotoxy(3, 18);
    printf("(4) P R$ 6,00");
    gotoxy(3, 19);
    printf("(5) M R$ 12,00");
    gotoxy(3, 20);
    printf("(6) G R$ 18,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 22);
    printf("ITACEBOLITAS");
    textcolor(LIGHTGRAY);
    gotoxy(3, 23);
    printf("(7) P R$ 6,00");
    gotoxy(3, 24);
    printf("(8) M R$ 12,00");
    gotoxy(3, 25);
    printf("(9) G R$ 18,00");

    Sleep(250);

    textcolor(LIGHTRED);
    gotoxy(2, 27);
    printf("VOLTAR PARA CARDAPIO (0)");
    textcolor(WHITE);
    gotoxy(2, 28);
    printf("DIGITE UMA DAS OPCOES ACIMA : ");
}

void itensBeb() //lista de bebidas do estabelecimento
{

    textcolor(YELLOW);
    gotoxy(3, 12);
    printf("ITAREFRI");
    textcolor(LIGHTGRAY);
    gotoxy(3, 13);
    printf("(1) ita-cola        R$ 4,50");
    gotoxy(3, 14);
    printf("(2) itaguarana      R$ 4,50");
    gotoxy(3, 15);
    printf("(3) italaranjinha   R$ 4,50");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 17);
    printf("ITASUCAO");
    textcolor(LIGHTGRAY);
    gotoxy(3, 18);
    printf("(4) ita-limao    R$ 4,00");
    gotoxy(3, 19);
    printf("(5) ita-acerola  R$ 4,00");
    gotoxy(3, 20);
    printf("(6) ita-maracuja R$ 4,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 22);
    printf("ITAGUA");
    textcolor(LIGHTGRAY);
    gotoxy(3, 23);
    printf("(7) sem gas R$ 2,00");
    gotoxy(3, 24);
    printf("(8) com gas R$ 2,50");
    gotoxy(3, 25);
    printf("(9) tonica  R$ 3,00");

    Sleep(250);

    textcolor(LIGHTRED);
    gotoxy(2, 27);
    printf("VOLTAR PARA CARDAPIO (0)");
    textcolor(WHITE);
    gotoxy(2, 28);
    printf("DIGITE UMA DAS OPCOES ACIMA : ");
}

void itensSob() //lista de sobremesas do estabelecimento
{

    textcolor(YELLOW);
    gotoxy(3, 12);
    printf("ITASORVETE");
    textcolor(LIGHTGRAY);
    gotoxy(3, 13);
    printf("(1) chocolate R$ 10,00");
    gotoxy(3, 14);
    printf("(2) baunilha  R$ 10,00");
    gotoxy(3, 15);
    printf("(3) morango   R$ 10,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 17);
    printf("ITASHAKE");
    textcolor(LIGHTGRAY);
    gotoxy(3, 18);
    printf("(4) chocolate R$ 10,00");
    gotoxy(3, 19);
    printf("(5) baunilha  R$ 10,00");
    gotoxy(3, 20);
    printf("(6) morango   R$ 10,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 22);
    printf("ITACASQUINHA");
    textcolor(LIGHTGRAY);
    gotoxy(3, 23);
    printf("(7) chocolate R$ 2,00");
    gotoxy(3, 24);
    printf("(8) baunilha  R$ 2,00");
    gotoxy(3, 25);
    printf("(9) misto     R$ 2,00");

    Sleep(250);

    textcolor(LIGHTRED);
    gotoxy(2, 27);
    printf("VOLTAR PARA CARDAPIO (0)");
    textcolor(WHITE);
    gotoxy(2, 28);
    printf("DIGITE UMA DAS OPCOES ACIMA : ");
}

void volteSmp() //escrita da frase Volte Sempre
{

    textcolor(RED);
    gotoxy(20, 3);
    printf("__      ______  _   _______ ______      _____ ______ __  __ _____  _____  ______ ");
    gotoxy(20, 4);
    printf("\\ \\    / / __ \\| | |__   __|  ____|    / ____|  ____|  \\/  |  __ \\|  __ \\|  ____|");
    gotoxy(20, 5);
    printf(" \\ \\  / / |  | | |    | |  | |__      | (___ | |__  | \\  / | |__) | |__) | |__   ");
    gotoxy(20, 6);
    printf("  \\ \\/ /| |  | | |    | |  |  __|      \\___ \\|  __| | |\\/| |  ___/|  _  /|  __|  ");
    gotoxy(20, 7);
    printf("   \\  / | |__| | |____| |  | |____     ____) | |____| |  | | |    | | \\ \\| |____ ");
    gotoxy(20, 8);
    printf("    \\/   \\____/|______|_|  |______|   |_____/|______|_|  |_|_|    |_|  \\_\\______|");
}

void pagamento() //escrita da palavra Pagamento
{

    textcolor(RED);
    gotoxy(30, 5);
    printf(" _____        _____          __  __ ______ _   _ _______ ____  ");
    gotoxy(30, 6);
    printf("|  __ \\ /\\   / ____|   /\\   |  \\/  |  ____| \\ | |__   __/ __ \\ ");
    gotoxy(30, 7);
    printf("| |__) /  \\ | |  __   /  \\  | \\  / | |__  |  \\| |  | | | |  | |");
    gotoxy(30, 8);
    printf("|  ___/ /\\ \\| | |_ | / /\\ \\ | |\\/| |  __| | . ` |  | | | |  | |");
    gotoxy(30, 9);
    printf("| |  / ____ \\ |__| |/ ____ \\| |  | | |____| |\\  |  | | | |__| |");
    gotoxy(30, 10);
    printf("|_| /_/    \\_\\_____/_/    \\_\\_|  |_|______|_| \\_|  |_|  \\____/ ");
}

void modosPagamento(struct cliente usuario) //tela onde o usuário irá escolher o melhor metodo de pagamento para ele
{

    textcolor(LIGHTGREEN);
    gotoxy(15, 17);
    printf("Valor a ser pago pelo pedido, R$ %.2f", somaTotal);
    gotoxy(15, 19);
    printf("Valor a ser pago pela entrega, R$ %.2f", taxa);
    textcolor(YELLOW);
    gotoxy(15, 21);
    printf("(1) DINHEIRO");
    gotoxy(15, 22);
    printf("(%c) CARTAO", 25);
    gotoxy(15, 23);
    textcolor(LIGHTGRAY);
    printf("(2) credito");
    gotoxy(15, 24);
    printf("(3) debito");

    Sleep(250);

    textcolor(WHITE);
    gotoxy(15, 15);
    printf("%s, como deseja efetuar o pagamento? ", usuario.nome);
}

void notaFiscal() //escrita da frase Nota Fiscal
{

    textcolor(RED);
    gotoxy(25, 3);
    printf(" _   _  ____ _______         ______ _____  _____  _____          _      ");
    gotoxy(25, 4);
    printf("| \\ | |/ __ \\__   __|/\\     |  ____|_   _|/ ____|/ ____|   /\\   | |     ");
    gotoxy(25, 5);
    printf("|  \\| | |  | | | |  /  \\    | |__    | | | (___ | |       /  \\  | |     ");
    gotoxy(25, 6);
    printf("| . ` | |  | | | | / /\\ \\   |  __|   | |  \\___ \\| |      / /\\ \\ | |     ");
    gotoxy(25, 7);
    printf("| |\\  | |__| | | |/ ____ \\  | |     _| |_ ____) | |____ / ____ \\| |____ ");
    gotoxy(25, 8);
    printf("|_| \\_|\\____/  |_/_/    \\_\\ |_|    |_____|_____/ \\_____/_/    \\_\\______|");
}

void notaFiscalDesc(struct cliente usuario) //informações finais da compra
{

    textcolor(BROWN);

    Sleep(250);

    gotoxy(15, 19);
    printf("SUBTOTAL : R$ %.2f", somaTotal);

    somaTotal = (somaTotal + taxa);

    troco = (valorRecebido - somaTotal);

    Sleep(250);

    gotoxy(15, 21);
    printf("TAXA DE ENTREGA : R$ %.2f ", taxa);

    Sleep(250);

    gotoxy(15, 23);

    printf("VALOR FINAL : R$ %.2f", somaTotal);

    Sleep(250);

    gotoxy(15, 25);
    printf("PAGAMENTO : R$ %.2f", valorRecebido);

    Sleep(250);

    gotoxy(15, 27);
    printf("TROCO : R$ %.2f", troco);

    Sleep(250);

    gotoxy(40, 27);
    printf("ENDERECO PARA ENTREGA : %s, %s, %d. ", usuario.rua, usuario.bairro, usuario.numeroCasa);
}

void doWhile(struct cliente usuario, char nome[]) //corpo principal do programa
{

    do
    {
        int h = 1, a = 2, b = 3, s = 4;

        clrscr();

        cardapioInicial();

        categorias(usuario.nome); // RESULTA NA ESCOLHA DA CATEGORIA

        if (escolha_da_categoria == 1) // hamburguers
        {

            clrscr();

            borda();

            cardapioLateral();

            burgLateral();

            itensBurg();

            scanf("%d", &escolha);

            while (escolha != 0)
            {

                if (escolha == 1)
                {
                    somaTotal += ItensGeral[escolha][h];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 1;
                    right++;
                }
                else if (escolha == 2)
                {
                    somaTotal += ItensGeral[escolha][h];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 2;
                    right++;
                }
                else if (escolha == 3)
                {
                    somaTotal += ItensGeral[escolha][h];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 3;
                    right++;
                }
                else if (escolha == 4)
                {
                    somaTotal += ItensGeral[escolha][h];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 4;
                    right++;
                }
                else if (escolha == 5)
                {
                    somaTotal += ItensGeral[escolha][h];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 5;
                    right++;
                }
                else if (escolha == 6)
                {
                    somaTotal += ItensGeral[escolha][h];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 6;
                    right++;
                }
                else if (escolha == 7)
                {
                    somaTotal += ItensGeral[escolha][h];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 7;
                    right++;
                }
                else if (escolha == 8)
                {
                    somaTotal += ItensGeral[escolha][h];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 8;
                    right++;
                }
                else if (escolha == 9)
                {
                    somaTotal += ItensGeral[escolha][h];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 9;
                    right++;
                }
                else if ((escolha < 0) || (escolha > 9))
                {
                    gotoxy(88, 26);
                    textcolor(LIGHTRED);
                    printf("Essa escolha nao existe !!!");
                    textcolor(WHITE);

                    getch();
                    gotoxy(88, 26);
                    printf("                            ");
                }
                gotoxy(32, 28);
                Limpar_Texto(50);

                gotoxy(32, 28);
                scanf("%d", &escolha);
            }
        }
        else if (escolha_da_categoria == 2) // acompanhamentos
        {

            clrscr();

            borda();

            cardapioLateral();

            acompLateral();

            itensAcomp();

            scanf("%d", &escolha);

            while (escolha != 0)
            {

                if (escolha == 1)
                {
                    somaTotal += ItensGeral[escolha][a];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 11;
                    right++;
                }
                else if (escolha == 2)
                {
                    somaTotal += ItensGeral[escolha][a];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 12;
                    right++;
                }
                else if (escolha == 3)
                {
                    somaTotal += ItensGeral[escolha][a];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 13;
                    right++;
                }
                else if (escolha == 4)
                {
                    somaTotal += ItensGeral[escolha][a];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 14;
                    right++;
                }
                else if (escolha == 5)
                {
                    somaTotal += ItensGeral[escolha][a];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 15;
                    right++;
                }
                else if (escolha == 6)
                {
                    somaTotal += ItensGeral[escolha][a];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 16;
                    right++;
                }
                else if (escolha == 7)
                {
                    somaTotal += ItensGeral[escolha][a];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 17;
                    right++;
                }
                else if (escolha == 8)
                {
                    somaTotal += ItensGeral[escolha][a];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 18;
                    right++;
                }
                else if (escolha == 9)
                {
                    somaTotal += ItensGeral[escolha][a];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 19;
                    right++;
                }
                else if ((escolha < 0) || (escolha > 9))
                {
                    gotoxy(88, 26);
                    textcolor(LIGHTRED);
                    printf("Essa escolha nao existe !!!");
                    textcolor(WHITE);

                    getch();
                    gotoxy(88, 26);
                    printf("                            ");
                }
                gotoxy(32, 28);
                Limpar_Texto(50);

                gotoxy(32, 28);
                scanf("%d", &escolha);
            }
        }
        else if (escolha_da_categoria == 3) // bebidas
        {

            clrscr();

            borda();

            cardapioLateral();

            bebidaLateral();

            itensBeb();

            scanf("%d", &escolha);

            while (escolha != 0)
            {

                if (escolha == 1)
                {
                    somaTotal += ItensGeral[escolha][b];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 21;
                    right++;
                }
                else if (escolha == 2)
                {
                    somaTotal += ItensGeral[escolha][b];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 22;
                    right++;
                }
                else if (escolha == 3)
                {
                    somaTotal += ItensGeral[escolha][b];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 23;
                    right++;
                }
                else if (escolha == 4)
                {
                    somaTotal += ItensGeral[escolha][b];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 24;
                    right++;
                }
                else if (escolha == 5)
                {
                    somaTotal += ItensGeral[escolha][b];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 25;
                    right++;
                }
                else if (escolha == 6)
                {
                    somaTotal += ItensGeral[escolha][b];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 26;
                    right++;
                }
                else if (escolha == 7)
                {
                    somaTotal += ItensGeral[escolha][b];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 27;
                    right++;
                }
                else if (escolha == 8)
                {
                    somaTotal += ItensGeral[escolha][b];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 28;
                    right++;
                }
                else if (escolha == 9)
                {
                    somaTotal += ItensGeral[escolha][b];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 29;
                    right++;
                }
                else if ((escolha < 0) || (escolha > 9))
                {
                    gotoxy(88, 26);
                    textcolor(LIGHTRED);
                    printf("Essa escolha nao existe !!!");
                    textcolor(WHITE);

                    getch();
                    gotoxy(88, 26);
                    printf("                            ");
                }
                gotoxy(32, 28);
                Limpar_Texto(50);

                gotoxy(32, 28);
                scanf("%d", &escolha);
            }
        }
        else if (escolha_da_categoria == 4) // sobremesas
        {

            clrscr();

            borda();

            cardapioLateral();

            sobLateral();

            itensSob();

            scanf("%d", &escolha);

            while (escolha != 0)
            {

                if (escolha == 1)
                {
                    somaTotal += ItensGeral[escolha][s];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 31;
                    right++;
                }
                else if (escolha == 2)
                {
                    somaTotal += ItensGeral[escolha][s];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 32;
                    right++;
                }
                else if (escolha == 3)
                {
                    somaTotal += ItensGeral[escolha][s];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 33;
                    right++;
                }
                else if (escolha == 4)
                {
                    somaTotal += ItensGeral[escolha][s];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 34;
                    right++;
                }
                else if (escolha == 5)
                {
                    somaTotal += ItensGeral[escolha][s];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 35;
                    right++;
                }
                else if (escolha == 6)
                {
                    somaTotal += ItensGeral[escolha][s];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 36;
                    right++;
                }
                else if (escolha == 7)
                {
                    somaTotal += ItensGeral[escolha][s];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 37;
                    right++;
                }
                else if (escolha == 8)
                {
                    somaTotal += ItensGeral[escolha][s];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 38;
                    right++;
                }
                else if (escolha == 9)
                {
                    somaTotal += ItensGeral[escolha][s];
                    ItensCarrinho++;
                    Carrinho[0]++;
                    Guardar_Itens[right] = 39;
                    right++;
                }
                else if ((escolha < 0) || (escolha > 9))
                {
                    gotoxy(88, 26);
                    textcolor(LIGHTRED);
                    printf("Essa escolha nao existe !!!");
                    textcolor(WHITE);

                    getch();
                    gotoxy(88, 26);
                    printf("                            ");
                }
                gotoxy(32, 28);
                Limpar_Texto(50);

                gotoxy(32, 28);
                scanf("%d", &escolha);
            }
        }
        else if ((escolha_da_categoria == 5) && (somaTotal == 0))
        {

            clrscr();

            borda();

            ITA();

            textcolor(LIGHTRED);
            gotoxy(27, 20);
            printf("%s, sua compra nao foi efetuada, nenhum item selecionado !!!", usuario.nome);

            Sleep(5000);

            clrscr();

            borda();

            volteSmp();

            ITA();

            Sleep(5000);

            break;
        }
        else if ((escolha_da_categoria == 5) && (somaTotal != 0))
        {

            clrscr();

            borda();

            pagamento();

            modosPagamento(usuario);

            scanf("%d", &escolha);

            if (escolha == 1 || escolha == 2 || escolha == 3)
            {
                if (escolha == 1)
                {

                    clrscr();

                    borda();

                    pagamento();

                    textcolor(WHITE);
                    gotoxy(15, 17);
                    printf("Insira o valor do pagamento:  ");
                    textcolor(GREEN);
                    scanf("%f", &valorRecebido);

                    if (valorRecebido >= somaTotal + taxa)
                    {

                        clrscr();

                        borda();

                        notaFiscal();

                        ITA();

                        notaFiscalDesc(usuario);

                        Sleep(10000);

                        clrscr();

                        borda();

                        volteSmp();

                        ITA();

                        Sleep(5000);
                        break;
                    }

                    else if (valorRecebido < somaTotal + taxa)
                    {

                        clrscr();

                        borda();

                        ITA();

                        textcolor(LIGHTRED);
                        gotoxy(27, 20);
                        printf("%s, sua compra nao foi efetuada, fundos insuficientes !!!", usuario.nome);

                        Sleep(5000);

                        clrscr();

                        borda();

                        volteSmp();

                        ITA();

                        Sleep(5000);

                        break;
                    }
                }

                if ((escolha == 2) || (escolha == 3))
                {

                    valorRecebido = somaTotal + 5;

                    clrscr();

                    borda();

                    notaFiscal();

                    ITA();

                    notaFiscalDesc(usuario);

                    Sleep(10000);

                    clrscr();

                    borda();

                    volteSmp();

                    ITA();

                    Sleep(5000);
                    break;
                }

                else if (somaTotal == 0)
                {

                    clrscr();

                    borda();

                    volteSmp();

                    ITA();

                    textcolor(WHITE);
                    gotoxy(27, 20);
                    printf("%s, a sua compra nao foi aprovada pois nenhum item do cardapio foi selecionado.", usuario.nome);

                    Sleep(5000);
                    break;
                }
            }
            else{
                    clrscr();

                    borda();

                    volteSmp();

                    ITA();

                    textcolor(WHITE);
                    gotoxy(27, 20);
                    printf("%s sua compra nao foi efetuada, use um modo de pagamento valido", usuario.nome);

                    Sleep(5000);
                    break;

            }
            if (escolha == 1)
            {

                clrscr();

                borda();

                pagamento();

                textcolor(WHITE);
                gotoxy(15, 17);
                printf("Insira o valor do pagamento:  ");
                textcolor(GREEN);
                scanf("%f", &valorRecebido);

                if (valorRecebido >= somaTotal + taxa)
                {

                    clrscr();

                    borda();

                    notaFiscal();

                    ITA();

                    notaFiscalDesc(usuario);

                    Sleep(10000);

                    clrscr();

                    borda();

                    volteSmp();

                    ITA();

                    Sleep(5000);
                    break;
                }

                else if (valorRecebido < somaTotal + taxa)
                {

                    clrscr();

                    borda();

                    ITA();

                    textcolor(LIGHTRED);
                    gotoxy(27, 20);
                    printf("%s, sua compra nao foi efetuada, fundos insuficientes !!!", usuario.nome);

                    Sleep(5000);

                    clrscr();

                    borda();

                    volteSmp();

                    ITA();

                    Sleep(5000);

                    break;
                }
            }

            if ((escolha == 2) || (escolha == 3))
            {

                valorRecebido = somaTotal + 5;

                clrscr();

                borda();

                notaFiscal();

                ITA();

                notaFiscalDesc(usuario);

                Sleep(10000);

                clrscr();

                borda();

                volteSmp();

                ITA();

                Sleep(5000);
                break;
            }

            else if (somaTotal == 0)
            {

                clrscr();

                borda();

                volteSmp();

                ITA();

                textcolor(WHITE);
                gotoxy(27, 20);
                printf("%s, a sua compra nao foi aprovada pois nenhum item do cardapio foi selecionado.", usuario.nome);

                Sleep(5000);
                break;
            }
        }
        else if (escolha_da_categoria == 0)
        {

            clrscr();

            borda();

            volteSmp();

            ITA();

            textcolor(GREEN);
            gotoxy(27, 20);
            printf("%s, sua compra de R$ %.2f foi cancelada com sucesso !!!", usuario.nome, somaTotal);

            Sleep(5000);
            break;
        }
        else if (escolha_da_categoria == 6)
        {
            escolha = 1;
            while (escolha != 0)
            {
                Ordenar_Itens_Em_Ordem_Crescente(ItensCarrinho, Guardar_Itens);

                clrscr();

                borda();

                Nome_Carrinho_De_Compra();

                Desenho_Do_Carrinho(somaTotal);

                Mostrar_Itens_Carrinho_Hambuger(ItensCarrinho, Guardar_Itens);

                Mostrar_Itens_Carrinho_Acompanhamento(ItensCarrinho, Guardar_Itens);

                Mostrar_Itens_Carrinho_Bebidas(ItensCarrinho, Guardar_Itens);

                Mostrar_Itens_Carrinho_Sobremesas(ItensCarrinho, Guardar_Itens);

                Sleep(1000);

                gotoxy(2, 11);
                textcolor(WHITE);
                printf("%s, SELECIONE UMA DAS OPCOES ABAIXO: ", usuario.nome);
                textcolor(YELLOW);
                scanf("%d", &escolha);

                if (escolha == 1)
                {
                    clrscr();

                    borda();

                    Nome_Carrinho_De_Compra();

                    Mostrar_Itens_Carrinho_Hambuger_3(ItensCarrinho, Guardar_Itens);

                    Mostrar_Itens_Carrinho_Acompanhamento_3(ItensCarrinho, Guardar_Itens);

                    Mostrar_Itens_Carrinho_Bebidas_3(ItensCarrinho, Guardar_Itens);

                    Mostrar_Itens_Carrinho_Sobremesas_3(ItensCarrinho, Guardar_Itens);

                    gotoxy(2, 9);
                    textcolor(GREEN);
                    printf("VALOR TOTAL: %.2f", somaTotal);

                    gotoxy(2, 12);
                    textcolor(LIGHTRED);
                    printf("(0)VOLTAR PARA O CARRINHO");
                    textcolor(YELLOW);

                    gotoxy(2, 10);
                    textcolor(WHITE);
                    printf("DE QUAL CATEGORIA DESEJA EXCLUIR UM ITEM? ");
                    textcolor(YELLOW);

                    scanf("%d", &escolha);

                    if (escolha == 0)
                        escolha = 10;

                    if (escolha == 1)
                    {
                        while (escolha != 0)
                        {
                            clrscr();
                            borda();
                            Nome_Carrinho_De_Compra();
                            Mostrar_Itens_Carrinho_Hambuger_2(ItensCarrinho, Guardar_Itens);
                            gotoxy(2, 9);
                            textcolor(GREEN);
                            printf("VALOR TOTAL: %.2f", somaTotal);
                            textcolor(YELLOW);
                            gotoxy(2, 10);
                            printf("DIGITE O NUMERO DO HAMBURGER QUE DESEJA EXCLUIR: ");
                            scanf("%d", &escolha);
                            if (escolha >= 1 && escolha <= 9){
                                somaTotal = Apagar_Itens(somaTotal, ItensCarrinho, escolha, Guardar_Itens, h, escolha,Carrinho);

                            }
                            else if (escolha != 0)
                            {
                                gotoxy(2, 11);
                                printf("ESSA ESCOLHA NAO EXISTE!!!");
                                getch();
                                gotoxy(2, 11);
                                Limpar_Texto(26);
                            }
                        }
                    }
                    else if (escolha == 2)
                    {
                        while (escolha != 0)
                        {
                            clrscr();
                            borda();
                            Nome_Carrinho_De_Compra();
                            Mostrar_Itens_Carrinho_Acompanhamento_2(ItensCarrinho, Guardar_Itens);
                            gotoxy(2, 9);
                            textcolor(GREEN);
                            printf("VALOR TOTAL: %.2f", somaTotal);
                            textcolor(YELLOW);
                            gotoxy(2, 10);
                            printf("DIGITE O NUMERO DO ACOMPANHAMENTO QUE DESEJA EXCLUIR:");
                            scanf("%d", &escolha);
                            if (escolha >= 1 && escolha <= 9)
                            {
                                int Acomp;
                                Acomp = escolha + 10;
                                somaTotal = Apagar_Itens(somaTotal, ItensCarrinho, escolha, Guardar_Itens, a, Acomp, Carrinho);
                            }
                            else if (escolha != 0)
                            {
                                gotoxy(2, 11);
                                printf("ESSA ESCOLHA NAO EXISTE!!!");
                                getch();
                                gotoxy(2, 11);
                                Limpar_Texto(26);
                            }
                        }
                    }
                    else if (escolha == 3)
                    {
                        while (escolha != 0)
                        {
                            clrscr();
                            borda();
                            Nome_Carrinho_De_Compra();
                            Mostrar_Itens_Carrinho_Bebidas_2(ItensCarrinho, Guardar_Itens);
                            gotoxy(2, 9);
                            textcolor(GREEN);
                            printf("VALOR TOTAL: %.2f", somaTotal);
                            textcolor(YELLOW);
                            gotoxy(2, 10);
                            printf("DIGITE O NUMERO DA BEBIDA QUE DESEJA EXCLUIR:");
                            scanf("%d", &escolha);
                            if (escolha >= 1 && escolha <= 9)
                            {
                                int Acomp;
                                Acomp = escolha + 20;
                                somaTotal = Apagar_Itens(somaTotal, ItensCarrinho, escolha, Guardar_Itens, b, Acomp, Carrinho);
                            }
                            else if (escolha != 0)
                            {
                                gotoxy(2, 11);
                                printf("ESSA ESCOLHA NAO EXISTE!!!");
                                getch();
                                gotoxy(2, 11);
                                Limpar_Texto(26);
                            }
                        }
                    }
                    else if (escolha == 4)
                    {
                        while (escolha != 0)
                        {
                            clrscr();
                            borda();
                            Nome_Carrinho_De_Compra();
                            Mostrar_Itens_Carrinho_Sobremesas_2(ItensCarrinho, Guardar_Itens);
                            gotoxy(2, 9);
                            textcolor(GREEN);
                            printf("VALOR TOTAL: %.2f", somaTotal);
                            textcolor(YELLOW);
                            gotoxy(2, 10);
                            printf("DIGITE O NUMERO DO SOBREMESAS QUE DESEJA EXCLUIR:");
                            scanf("%d", &escolha);
                            if (escolha >= 1 && escolha <= 9)
                            {
                                int Acomp;
                                Acomp = escolha + 30;
                                somaTotal = Apagar_Itens(somaTotal, ItensCarrinho, escolha, Guardar_Itens, s, Acomp, Carrinho);
                            }
                            else if (escolha != 0)
                            {
                                gotoxy(2, 11);
                                printf("ESSA ESCOLHA NAO EXISTE!!!");
                                getch();
                                gotoxy(2, 11);
                                Limpar_Texto(26);
                            }
                        }
                    }
                    escolha = 10;
                }
            }
        }
    } while (escolha_da_categoria != 0 || escolha_da_categoria != 5);
}

int main()
{
    Itens_Geral(ItensGeral);

    struct cliente usuario;

    bemVindo();

    Sleep(1000);

    ITA();

    Sleep(1000);

    //informe(usuario);

    textcolor(YELLOW);
    gotoxy(15, 20);
    printf("Por favor, informe o seu nome:  ");
    textcolor(WHITE);
    gets(usuario.nome);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 22);
    printf("(%c) Por favor, informe o seu endereco", 25);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 23);
    printf("Bairro : ");
    textcolor(WHITE);
    gets(usuario.bairro);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 24);
    printf("Rua : ");
    textcolor(WHITE);
    gets(usuario.rua);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 25);
    printf("Numero : ");
    textcolor(WHITE);
    scanf("%d", &usuario.numeroCasa);
    getchar();

    doWhile(usuario, usuario.nome);

    Sleep(10000);

    gotoxy(3, 29);

    return 0;
}
