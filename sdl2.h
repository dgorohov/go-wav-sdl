#ifndef __SDL2_HEADER__
#define __SDL2_HEADER__

#include <SDL2/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

void sdl_init(uint32_t flags);
void sdl_quit();

#ifdef __cplusplus
}
#endif

#endif
