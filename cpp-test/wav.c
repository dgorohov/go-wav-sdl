#include "sdl2.h"
#include "audio/wav/sdl2-wav.h"

int main(int argc, char** argv) {
    sdl_init(SDL_INIT_AUDIO);
    int res = play_wav_file("audio/wav/maybe-next-time-huh.wav");
    sdl_quit();
    return res;
}