# Project Name
TARGET = HeavyDaisy_breathPrint

# Library Locations
LIBDAISY_DIR = ../../libdaisy



LDFLAGS += -u _printf_float

# Project Source
C_SOURCES = $(wildcard *.c)
CPP_SOURCES = $(wildcard *.cpp)

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

CFLAGS += -DHV_BARE_METAL