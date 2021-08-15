include $(RTEMS_ROOT)/make/custom/default.cfg

RTEMS_CPU = arm

CPU_CFLAGS = -march=armv7-r -mthumb -mfpu=vfpv3-d16 -mfloat-abi=hard -mtune=cortex-r5 -mcpu=cortex-r5

CFLAGS_OPTIMIZE_V ?= -O2 -g
CFLAGS_OPTIMIZE_V += -ffunction-sections -fdata-sections

LDFLAGS = -Wl,--gc-sections
