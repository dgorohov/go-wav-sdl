#include "sdl2-wav.h"

void _wav_audio_callback(void* data, unsigned char * stream, int len) {
    audio_data* _audio = (audio_data*)data;

    if (_audio->length == 0) {
        return;
    }

    len = len > _audio->length ? _audio->length : len;
    SDL_memcpy(stream, _audio->position, len);

    _audio->position += len;
    _audio->length -= len;
}

int play_wav_file(const char* source) {
    SDL_AudioSpec wavSpec;
    uint8_t* wavStart;
    uint32_t wavLength;

    if(SDL_LoadWAV(source, &wavSpec, &wavStart, &wavLength) == 0) {
        fprintf(stderr, "Error: file could not be loaded as an audio file.");
        return -2;
    }

    audio_data audio = {
        .position = wavStart,
        .length = wavLength
    };

    wavSpec.callback = _wav_audio_callback;
    wavSpec.userdata = &audio;

    SDL_AudioDeviceID audioDevice = SDL_OpenAudioDevice(0, 0, &wavSpec, 0, SDL_AUDIO_ALLOW_ANY_CHANGE);

    if (audioDevice == 0) {
        fprintf(stderr, "Error: %s.", SDL_GetError());
        return -1;
    }
    SDL_PauseAudioDevice(audioDevice, 0);

    while (audio.length > 0) {
        SDL_Delay(100);
    }
    SDL_CloseAudioDevice(audioDevice);
    SDL_FreeWAV(wavStart);
    return 0;
}
