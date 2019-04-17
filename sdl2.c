#include "sdl2.h"

void sdl_init(uint32_t flags) { SDL_Init(flags); }

void sdl_quit() { SDL_Quit(); }

int stream_audio_data(SDL_AudioDeviceID *device_id, SDL_AudioSpec audio_spec, audio_data data) {
    audio_spec.callback = audio_callback;
    audio_spec.userdata = &data;

    *device_id = SDL_OpenAudioDevice(0, 0, &audio_spec, 0, SDL_AUDIO_ALLOW_ANY_CHANGE);
    if (device_id == 0) {
        fprintf(stderr, "Error: %s.", SDL_GetError());
        return -1;
    }
    SDL_PauseAudioDevice(*device_id, 0);

    while (data.length > 0) {
        SDL_Delay(100);
    }
    return 0;
}

void audio_callback(void* data, unsigned char * stream, int len) {
    audio_data* _audio = (audio_data*)data;

    if (_audio->length == 0) {
        return;
    }

    len = len > _audio->length ? _audio->length : len;
    SDL_memcpy(stream, _audio->position, len);

    _audio->position += len;
    _audio->length -= len;
}
