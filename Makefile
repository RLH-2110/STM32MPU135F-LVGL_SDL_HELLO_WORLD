include lvgl/lvgl.mk

TARGET := lvgltst 
LVGL_SRCFILES := $(ASRCS) $(CSRCS)

SDL	:= $(shell pkg-config --cflags sdl2) $(shell pkg-config --libs sdl2)

$(info    SDL is $(SDL))

all: $(TARGET)

$(TARGET): $(LVGL_SRCFILES) main.c 
	$(CC) $(CFLAGS) $(AFLAGS) $(LDFLAGS) -lSDL2 $^ -o $@ $(SDL)

clean:
	rm $(TARGET)

.PHONY: all clean 

