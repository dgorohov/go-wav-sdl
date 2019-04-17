package sdl

// #include "sdl2.h"
import "C"

type Mode uint32

const (
	Audio Mode = C.SDL_INIT_AUDIO
)

func Init(mode Mode) {
	C.sdl_init(C.uint32_t(mode))
}

func Quit() {
	C.sdl_quit()
}
