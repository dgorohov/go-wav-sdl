// +build cgo

package wav

/*
#cgo CFLAGS: -I/usr/local/include -I${SRCDIR} -I${SRCDIR}/../.. -Wall
#cgo LDFLAGS: -L/usr/local/lib -lSDL2

#include "sdl2-wav.h"
*/
import "C"
