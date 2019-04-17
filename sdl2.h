#ifndef __SDL2_HEADER__
#define __SDL2_HEADER__

#include <SDL2/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _audio_data {
    uint8_t* position;
    uint32_t length;
} audio_data;

void sdl_init(uint32_t flags);
void sdl_quit();
void audio_callback(void* data, unsigned char * stream, int len);
int stream_audio_data(SDL_AudioDeviceID *device_id, SDL_AudioSpec audio_spec, audio_data data);

#ifdef __cplusplus
}
#endif

#endif
