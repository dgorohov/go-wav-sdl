package main

import (
	"github.com/dgorohov/sdl-bindings"
	"github.com/dgorohov/sdl-bindings/audio/wav"
	"log"
	"os"
	"path/filepath"
)

func main() {
	sdl.Init(sdl.Audio)
	defer sdl.Quit()

	path, err := filepath.Abs(os.Args[1])
	if err != nil {
		panic(err)
	}

	log.Printf("Playing WAV: %s\n", path)
	if err := wav.PlayWAV(path); err != nil {
		panic(err)
	}
}
