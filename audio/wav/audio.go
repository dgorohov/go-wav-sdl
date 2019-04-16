package wav

// #include "sdl2-wav.h"
import "C"
import (
	"github.com/pkg/errors"
	"unsafe"
)

func PlayWAV(source string) error {
	cs := C.CString(source)
	defer C.free(unsafe.Pointer(cs))

	if r := C.play_wav_file(cs); r != 0 {
		return errors.New("SDL2 failed with code")
	}
	return nil
}
