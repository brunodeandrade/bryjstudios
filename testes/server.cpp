#include<iostream> 
#include<SDL/SDL.h>
#include<SDL/SDL_net.h>
#include<cstring>

using namespace std;

int main(int argc,char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	IPaddress ip;
	SDLNet_ResolveHost(&ip,NULL,1234);

	TCPsocket server = SDLNet_TCP_Open(&ip);
	TCPsocket client;
	
	char text[100];

	while(1){
		client = SDLNet_TCP_Accept(server);
		if(client){
			cout<<"Digite a zuera"<<endl;
			while(1){
				//aqui você pode comunicar com o cliente
				//SDLNet_TCP_Send (client,text,strlen(text)+1);
				cin>>text;
				SDLNet_TCP_Send(client,&text,100);
					if(strcmp(text,"sair") ==0){
						SDLNet_TCP_Close(client);
						SDLNet_TCP_Close(server); 
						SDLNet_Quit();
						SDL_Quit();
						return 0;
					}			
			
			}
		}
	}
	SDLNet_TCP_Close(server); // precisa fechar porque senão,
				 // não dá pra usar a mesma porta denovo

	SDLNet_Quit();
	SDL_Quit();
}