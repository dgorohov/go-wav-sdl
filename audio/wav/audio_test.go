package wav_test

import (
	"github.com/dgorohov/sdl-bindings"
	"github.com/dgorohov/sdl-bindings/audio/wav"
	"testing"
)

func TestPlayWav(t *testing.T) {
	sdl.Init(sdl.SDL_AUDIO)
	defer sdl.Quit()

	if err := wav.PlayWAV("maybe-next-time-huh.wav"); err != nil {
		panic(err)
	}
}
