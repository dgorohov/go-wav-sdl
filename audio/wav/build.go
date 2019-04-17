// +build cgo

package wav

/*
#cgo darwin LDFLAGS: -Wl,-undefined -Wl,dynamic_lookup
#cgo !darwin LDFLAGS: -Wl,-unresolved-symbols=ignore-all
#cgo CFLAGS: -I/usr/local/include -I. -I../../ -Wall
#cgo LDFLAGS: -L/usr/local/lib -lSDL2

#include "sdl2-wav.h"
*/
import "C"
