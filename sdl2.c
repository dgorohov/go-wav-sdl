#include "sdl2.h"

void sdl_init(uint32_t flags) { SDL_Init(flags); }

void sdl_quit() { SDL_Quit(); }
