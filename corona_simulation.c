#include "population.h"

int main(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Window * window;
        SDL_Renderer * renderer;
        SDL_Event event;
        SDL_bool done = SDL_FALSE;
        if(!SDL_CreateWindowAndRenderer(WindowWidth, WindowHeight, 0, &window, &renderer)){
            SDL_SetWindowTitle(window, "Corona Simulation");
            Population * p = create_population(250);
            while(!done){
                SDL_PollEvent(&event);
                if(event.type == SDL_QUIT){
                    done = SDL_TRUE;
                }
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
                SDL_RenderClear(renderer);
                draw_population(p, renderer);
                update_population(p);
                SDL_RenderPresent(renderer);
            }
            free_population(p);
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
            SDL_Quit();
        }else{
            fprintf(stderr, "Failed to create window or renderer : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }else{
        fprintf(stderr, "Failed to initialize SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return 0;
}
