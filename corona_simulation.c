#include "population.h"
int main(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Window * window;
        SDL_Renderer * renderer;
        SDL_Event event;
        SDL_bool done = SDL_FALSE;
        if(!SDL_CreateWindowAndRenderer(WindowWidth, WindowHeight, 0, &window, &renderer)){
            SDL_SetWindowTitle(window, "Corona Simulation");
            while(!done){
                SDL_PollEvent(&event);
                if(event.type == SDL_QUIT){
                    done = SDL_TRUE;
                }
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_TRANSPARENT);
                SDL_RenderClear(renderer);

                Population * p = create_population(100);
                draw_population(p, renderer);

                SDL_RenderPresent(renderer);
            }
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
            SDL_Quit();
        }else{
            fprintf(stderr, "Failed to create window or renderer\n");
            exit(EXIT_FAILURE);
        }
    }else{
        fprintf(stderr, "Failed to initialize SDL\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}