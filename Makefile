include lvgl/lvgl.mk

TARGET := lvgltst 
LVGL_SRCFILES := $(ASRCS) $(CSRCS)

INCLUDE_HELL := -I/home/hartung/workdir/build-openstlinuxweston-stm32mp13-disco/tmp-glibc/sysroots-components/cortexa7t2hf-neon-vfpv4/wayland/usr/include 
INCLUDE_HELL += -I/home/hartung/workdir/build-openstlinuxweston-stm32mp13-disco/tmp-glibc/sysroots-components/cortexa7t2hf-neon-vfpv4/libxkbcommon/usr/include
INCLUDE_HELL += -I./generated
INCLUDE_HELL += -L/home/hartung/workdir/build-openstlinuxweston-stm32mp13-disco/tmp-glibc/sysroots-components/cortexa7t2hf-neon-vfpv4/wayland/usr/lib/
INCLUDE_HELL += -L/home/hartung/workdir/build-openstlinuxweston-stm32mp13-disco/tmp-glibc/sysroots-components/cortexa7t2hf-neon-vfpv4/libffi/usr/lib/
INCLUDE_HELL += -L/home/hartung/workdir/build-openstlinuxweston-stm32mp13-disco/tmp-glibc/sysroots-components/cortexa7t2hf-neon-vfpv4/libxkbcommon/usr/lib/
INCLUDE_HELL += -L/home/hartung/workdir/build-openstlinuxweston-stm32mp13-disco/tmp-glibc/sysroots-components/cortexa7t2hf-neon-vfpv4/wayland/usr/lib/

LIBS := -lwayland-client -lffi -lxkbcommon -lwayland-cursor
drivers := -Ilv_drivers/wayland/ -Ilv_drivers/ lv_drivers/wayland/wayland.c  lv_drivers/wayland/smm.c  

all: $(TARGET)

$(info >>> CC = $(CC))
$(info >>> CFLAGS = $(CFLAGS))
$(info >>> INCLUDE_HELL = $(INCLUDE_HELL))

#$(TARGET): main.c generated/wayland_xdg_shell.c 
$(TARGET): $(LVGL_SRCFILES) main.c generated/wayland_xdg_shell.c 
	$(CC) $(INCLUDE_HELL) $(CFLAGS) $(AFLAGS) $(LDFLAGS) $(DRIVERS) $^ -o $@ $(LIBS)
	#$(CC) -E $(INCLUDE_HELL) $(CFLAGS) $(AFLAGS) $(LDFLAGS) $(DRIVERS) main.c -o $@ $(LIBS)

clean:
	rm $(TARGET)

.PHONY: all clean 

