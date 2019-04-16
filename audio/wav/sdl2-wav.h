#ifndef __SDL2_WAV_HEADER__
#define __SDL2_WAV_HEADER__

#include <SDL2/SDL.h>

typedef struct _audio_data {
    uint8_t* position;
    uint32_t length;
} audio_data;

void _wav_audio_callback(void* data, unsigned char * stream, int len);
int play_wav_file(const char* source);

#endif // __SDL2_WAV_HEADER__
