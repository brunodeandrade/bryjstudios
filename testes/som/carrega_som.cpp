#include <SDL/SDL.h>
#include <iostream>
#include "sound.h"
#include "callback.cpp"
//#include "loop.h"
//#include "input.cpp"

using namespace std;

int carrega_som(){

	// Inicia o Dispositivo de Audio
	int rc = SDL_Init(SDL_INIT_AUDIO);

	if (rc != 0) {
		cerr << "Erro na inicializacao do modulo de audio: " <<
			SDL_GetError() << endl;
		return -1;
	}

	Sound sound;
	sound.position = -1;
	sound.size = 0;
	sound.buffer = 0;

	SDL_AudioSpec desired, obtained;
	desired.freq = 44100;
	desired.format = AUDIO_S16;
	desired.channels = 2;
	desired.samples = 4096;
	desired.callback = callback;
	desired.userdata = (void *) &sound;
	// Fim da inicialização

	// Abre o dispositivo de audio
	rc = SDL_OpenAudio(&desired, &obtained);

	if (rc != 0) {
		cerr << "Erro na abertura do dispositivo de audio: " <<
			SDL_GetError() << endl;
		SDL_Quit();
		return -2;
	}

	cout << "Dispositivo de audio inicializado com sucesso!" << endl;
	// Fim da abertura
	
	// Carrega o arquivo de audio
	cout << "Carregando o arquivo com o audio desejado... ";

	SDL_AudioSpec wavSpec;
	Uint32 wavLen;
	Uint8 *wavBuffer;

	if (SDL_LoadWAV("tela_de_abertura.wav", &wavSpec, &wavBuffer, &wavLen) == NULL) {
		cout << "Falha! " << SDL_GetError() << endl;
		SDL_CloseAudio();
		SDL_Quit();
		return -3;
	}

	cout << "Ok!" << endl;
	// Fim do carregamento


	// Converte o som para o formato da placa
	cout << "Convertendo o som para o formato atual da placa... ";

	SDL_AudioCVT cvt;

    	rc = SDL_BuildAudioCVT(&cvt, wavSpec.format, wavSpec.channels, wavSpec.freq,
			obtained.format, obtained.channels, obtained.freq);

	if (rc != 0) {
		cout << "Falha! " << SDL_GetError() << endl;
		SDL_FreeWAV(wavBuffer);
		SDL_CloseAudio();
		SDL_Quit();

		return -5;
    	}

	cvt.len = wavLen;
    	Uint8 *wavNewBuf = (Uint8 *) malloc(cvt.len * cvt.len_mult);

    	if (wavNewBuf == NULL) {
		cerr << "Sem memoria para um novo buffer!" << endl;
		SDL_FreeWAV(wavBuffer);
		SDL_CloseAudio();
		SDL_Quit();

		return -6;
    	}

    	memcpy(wavNewBuf, wavBuffer, wavLen);
    	cvt.buf = wavNewBuf;

    	rc = SDL_ConvertAudio(&cvt);

   	 if (rc != 0) {
		cerr << "Erro na conversao do audio!" << endl;
		SDL_FreeWAV(wavBuffer);
		free(wavNewBuf);
		SDL_CloseAudio();
		SDL_Quit();

		return -6;
	}

    	SDL_FreeWAV(wavBuffer);

	cout << "Ok!" << endl;

	SDL_LockAudio();
	sound.position = 0;
	sound.buffer = wavNewBuf;
	sound.size = cvt.len * cvt.len_mult;
	SDL_UnlockAudio();
	// Fim da conversão


	// Inicia a reprodução do audio
	//Vetor_mouse *vetor = new Vetor_mouse;
	
	cout << "Inicializando o playback... " << endl;
	SDL_PauseAudio(0);

	while (true)
	{		
		//vetor = get_Input();
		if (sound.position >= sound.size /*|| vetor->click==1*/)
			break;	
		
		SDL_LockAudio();
		SDL_UnlockAudio();		

		SDL_Delay(10);			
	}

	cout << "Playback finalizado" << endl;
	SDL_PauseAudio(1);	
	// Termina a reprodução


	SDL_Delay(100);

	free(wavNewBuf); //Libera o buffer de audio
	SDL_CloseAudio(); // Encerra o dispositivo de audio
	SDL_Quit(); // Encerra SDL

	return 0;
}

