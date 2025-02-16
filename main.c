#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <stdbool.h>

int main(int argc, char* argv)
{
	const int WINDOW_WIDTH = 600;
	const int WINDOW_HEIGHT = 600;

	SDL_Window* win = SDL_CreateWindow("Line Drawer", 
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED, 
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			0);

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
	
	bool running = true;
	
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	
	srand(time(NULL));

	const int FPS = 30;
	Uint64 nextFrame = SDL_GetTicks64() + 1000 / FPS;
	Uint64 nextLine = 0;

	SDL_RenderPresent(ren);

	while (running)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
			
		if(event.type == SDL_QUIT) running = false;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
		{
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 0); 
			SDL_RenderClear(ren); 
			SDL_RenderPresent(ren);
		}	
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_j)
		{
			SDL_SetRenderDrawColor(ren, 0, 0, 0, 0); 
			SDL_RenderClear(ren); 

			int iterations = rand() % 9 + 3;

			for (int i = 0; i < iterations; i++)
			{

				int r = rand() % 255;
				int g = rand() % 255;
				int b = rand() % 255;

				int x1 = rand() % WINDOW_WIDTH;
				int x2 = rand() % WINDOW_WIDTH;
				int y1 = rand() % WINDOW_HEIGHT;
				int y2 = rand() % WINDOW_HEIGHT;
			
				SDL_SetRenderDrawColor(ren, r, g, b, 255);
				SDL_RenderDrawLine(ren, x1, y1, x2, y2);
			}


			SDL_RenderPresent(ren);
		}	
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) 
		{
			int iterations = rand() % 9 + 3;

			for (int i = 0; i < iterations; i++)
			{

				int r = rand() % 255;
				int g = rand() % 255;
				int b = rand() % 255;

				int x1 = rand() % WINDOW_WIDTH;
				int x2 = rand() % WINDOW_WIDTH;
				int y1 = rand() % WINDOW_HEIGHT;
				int y2 = rand() % WINDOW_HEIGHT;
			
				SDL_SetRenderDrawColor(ren, r, g, b, 255);
				SDL_RenderDrawLine(ren, x1, y1, x2, y2);
			}

			SDL_RenderPresent(ren);

		}	
	

	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	return 0;
}
