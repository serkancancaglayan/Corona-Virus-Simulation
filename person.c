#include "person.h"
Person * create_person(int age, float x_pos, float y_pos){
    Person * p = malloc(sizeof(Person));
    p->age = age;
    p->x_pos = x_pos;
    p->y_pos = y_pos;
    p->is_infected = 0;
    p->isAlive = 1;
    p->is_checked = 0;
    return p;
}

void move_person(Person * p, float dt, float direction_x, float direction_y){
    if(p->x_pos < -default_width){
        p->x_pos = WindowWidth + default_width;
    }
    else if(p->x_pos > WindowWidth + default_width){
        p->x_pos = - default_width;
    }

    if(p->y_pos < -default_height){
        p->y_pos = WindowHeight + default_height;
    }
    else if(p->y_pos > WindowHeight + default_height){
        p->y_pos = - default_height;
    }
    p->x_pos += default_vel_x * dt * direction_x;
    p->y_pos += default_vel_y *dt * direction_y;
}

void draw_person(Person *p, SDL_Renderer * renderer){
    if(p->isAlive){
        SDL_Rect rect = {(int)p->x_pos, (int)p->y_pos, 20, 20};
        //draw red if person is infected, otherwise white
        if(p->is_infected){
            SDL_SetRenderDrawColor(renderer, 255, 10, 10, SDL_ALPHA_OPAQUE);
        }else{
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        }
        SDL_RenderDrawRect(renderer, &rect);
    }else{
        return;
    }
}


void check_infected(Person *p){
    p->is_checked = 1;
    /* 0 - 9 years old --> no fatalities
        10 - 39 years old --> %0.2
        40 - 49 years old --> %0.4
        50 - 59 years old --> %1.3
        60 - 69 years old --> %3.6
        70 - 79 years old --> %8.0
        80+ years old --> %14.8
    */
    float death_rate = 100 *((float) rand() / (float)RAND_MAX);
    if(p->age >= 10 && p->age <= 39){
        if(death_rate <= 0.2){
            p->isAlive = 0;
        }
    }
    else if(p->age >= 40 && p->age <= 49){
        if(death_rate <= 0.4){
            p->isAlive = 0;
        }
    }
    else if(p->age >= 50 && p->age <= 59){
        if(death_rate <= 1.3){
            p->isAlive = 0;
        }
    }
    else if(p->age >= 60 && p->age <= 69){
        if(death_rate <= 3.6){
            p->isAlive = 0;
        }
    }
    else if(p->age >= 70 && p->age <= 79){
        if(death_rate <= 8.0){
            p->isAlive = 0;
        }
    }
    else{
        if(death_rate <= 14.8){
            p->isAlive = 0;
        }
    }
    if(p->isAlive){
        p->is_infected = 0;
    }
}
float distance(int x1, int y1, int x2, int y2){
    float dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrt(dist);
}
void infection(Person *p, Person *other){
    float dist = distance(p->x_pos, p->y_pos, other->x_pos, other->y_pos);
    if(dist <= 10 && other->is_infected){
        p->is_infected = 1;
    }

}