#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

void carrega_urss(SDL_Surface *screen){

    string lado1("servidor");
    string cor = "vermelho";

    for(int i=0, j=1;i<6;i++,j+=30){

        string caminho = "source/GameFeatures/Jogar/Fase3/images/soldado_vermelho.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/soldado_vermelho_ataque.png";
        SDL_Surface *ataque_soldado = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/soldado_vermelho_ataque_baixo.png";
        SDL_Surface *ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/soldado_vermelho_ataque_cima.png";
        SDL_Surface *ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/soldado_lateral_vermelho.png";
        SDL_Surface *soldado_lateral_a= load_Image(caminho, screen);
        Unidade *soldado = new Unidade();

        string unidadea1 = "soldado";
        setar_soldado(soldado, cor, unidadea1, soldado1, ataque_soldado, ataque_baixo, ataque_cima,soldado_lateral_a, id);
        id++;
        unidades_azul.push_back(soldado);
        //if(i+2<=hexagonos.size()){
        SDL_Rect dst;
        dst.x = hexagonos[i*2][3]->x;
        dst.y = hexagonos[i*2][3]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_azul[i]->nome, &cutBox,  screen, &dst);
        hexagonos[i*2][3]->unidade = unidades_azul[i];
        hexagonos[i*2][3]->contem_unidade = 1;


        caminho = "source/GameFeatures/Jogar/Fase3/images/bryjstudios_cabana_vermelha.png";
        SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
        Unidade *quartel_a = new Unidade();
        string quarte = "quartel";
        setar_quartel(quartel_a,cor,quarte,quartel_azul_cabana, quartel_azul_cabana, quartel_azul_cabana, id);
        id++;
        BlitImage(screen,quartel_azul_cabana,hexagonos[6][1]->x,hexagonos[6][1]->y);
        hexagonos[5][1]->unidade = quartel_a;
        hexagonos[5][1]->contem_unidade = 1;
        hexagonos[6][1]->unidade = quartel_a;
        hexagonos[6][1]->contem_unidade = 1;
        hexagonos[6][2]->contem_unidade = 1;
        hexagonos[6][2]->unidade = quartel_a;
        hexagonos[7][1]->contem_unidade = 1;
        hexagonos[7][1]->unidade = quartel_a;
        hexagonos[8][1]->contem_unidade = 1;
        hexagonos[8][1]->unidade = quartel_a;
        hexagonos[8][2]->contem_unidade = 1;
        hexagonos[8][2]->unidade = quartel_a;
        hexagonos[9][1]->contem_unidade = 1;
        hexagonos[9][1]->unidade = quartel_a;

    }

    for(int i=6, j=1;i<8;i++,j+=30){

        string caminho = "source/GameFeatures/Jogar/Fase3/images/tanque_vermelho.png";
        SDL_Surface *tanque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/tanque_ataqueVermelho.png";
        SDL_Surface *ataque_tanque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/tanque_ataqueParaBaixo(vermelho).png";
        SDL_Surface *ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/tanque_ataqueParaCima(vermelho).png";
        SDL_Surface *ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/tanque_lateral_vermelho.png";
        SDL_Surface *tanque_lateral= load_Image(caminho, screen);
        Unidade *tanque1 = new Unidade();

        string unidadea1 = "tanque";
        setar_tanque(tanque1, cor, unidadea1, tanque, ataque_tanque, ataque_baixo, ataque_cima,tanque_lateral, id);
        id++;
        unidades_azul.push_back(tanque1);
        //if(i+2<=hexagonos.size()){
        SDL_Rect dst;
        dst.x = hexagonos[i*2][3]->x;
        dst.y = hexagonos[i*2][3]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_azul[i]->nome, &cutBox,  screen, &dst);
        hexagonos[i*2][3]->unidade = unidades_azul[i];
        hexagonos[i*2][3]->contem_unidade = 1;
    }


for (int i=8;i<9;i++){
        string caminho = "source/GameFeatures/Jogar/Fase3/images/helicoptero_vermelho_movimento.png";
        SDL_Surface *helicoptero1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/helicoptero_vermelho_ataque.png";
        SDL_Surface *helicoptero_ataque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/helicoptero_ataque_vermelho_baixo.png";
        SDL_Surface *helicoptero_ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/helicoptero_ataque_vermelho_cima.png";
        SDL_Surface *helicoptero_ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase3/images/helicoptero_barraLateral.png";
        SDL_Surface *helicoptero_lateral = load_Image(caminho, screen);
        //caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_azul_ataque_baixo.png";
        //SDL_Surface *helicoptero_ataque_baixo = load_Image(caminho, screen);
        Unidade *helicoptero = new Unidade();
        string unidade1 = "helicoptero";
        setar_helicoptero(helicoptero, cor, unidade1, helicoptero1, helicoptero_ataque, helicoptero_ataque_baixo, helicoptero_ataque_cima,helicoptero_lateral, id);
        id++;
        unidades_azul.push_back(helicoptero);

        SDL_Rect dst;
        dst.x = hexagonos[i*2][3]->x;
        dst.y = hexagonos[i*2][3]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_azul[i]->nome, &cutBox,  screen, &dst);
        hexagonos[i*2][3]->unidade = unidades_azul[i];
        hexagonos[i*2][3]->contem_unidade = 1;
        unidades_azul[0]->x = hexagonos[i*2][3]->x;
        unidades_azul[0]->y = hexagonos[i*2][3]->y;
    }


    SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	//drawCircle(screen, 20, 44, 137, blue);
	//drawCircle(screen, 20, 78, 157, blue);
}






