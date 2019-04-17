#include "sdl2-wav.h"

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

    SDL_AudioDeviceID audioDevice;
    int res = stream_audio_data(&audioDevice, wavSpec, audio);
    if (res != 0) {
        SDL_FreeWAV(wavStart);
        return res;
    }

    SDL_CloseAudioDevice(audioDevice);
    SDL_FreeWAV(wavStart);
    return 0;
}
