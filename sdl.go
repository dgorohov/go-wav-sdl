package sdl

// #include "sdl2.h"
import "C"

type SDLMode uint32

const (
	SDL_AUDIO SDLMode = C.SDL_INIT_AUDIO
)

func Init(mode SDLMode) {
	C.sdl_init(C.uint32_t(mode))
}

func Quit() {
	C.sdl_quit()
}
