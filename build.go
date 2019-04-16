// +build cgo

package sdl

/*
#cgo CFLAGS: -I/usr/local/include -I${SRCDIR} -Wall
#cgo LDFLAGS: -L/usr/local/lib -lSDL2

#include "sdl2.h"
*/
import "C"
