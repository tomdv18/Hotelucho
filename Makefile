extension = cpp
verbose = si
CFLAGS += -Wall -Werror -pedantic -pedantic-errors -O0 -D _POSIX_C_SOURCE=200809L

# Para valgrind o debug
CFLAGS += -ggdb -DDEBUG -fno-inline

# Estandar de C a usar
CSTD = c17

# Estandar de C++ a usar
CXXSTD = c++17

# Linkea con libm de ser necesario.
ifdef math
LDFLAGS += -lm
endif

# Linkea con threads de ser necesario. Permite el uso de pthread en C y C++. Permite el uso de built-in threads en C++.
ifdef threads
LDFLAGS += -pthread
endif

ifdef static
LDFLAGS += -static
endif

# Agrega simulación de pérdidas de bytes en las funciones de sockets
ifdef wrapsocks
CFLAGS += -Dwrapsocks=1
LDFLAGS += -Wl,--wrap=send -Wl,--wrap=recv
endif

# Se reutilizan los flags de C para C++ también
CXXFLAGS += $(CFLAGS)

# Se usa enlazador de C++ si es código no C.
ifeq ($(extension), c)
CFLAGS += -std=$(CSTD)
LD = $(CC)
COMPILER = $(CC)
COMPILERFLAGS = $(CFLAGS)
else
CXXFLAGS += -std=$(CXXSTD)
LD = $(CXX)
COMPILER = $(CXX)
COMPILERFLAGS = $(CXXFLAGS)
endif

directorios = $(shell find . -type d -regex '.*\w+')

occ := $(CC)
ocxx := $(CXX)
orm := $(RM)
old := $(LD)
ifdef verbose
RM := $(RM) -v
else
CC =  @echo "  CC  $@"; $(occ)
CXX = @echo "  CXX $@"; $(ocxx)
RM =  @echo "  CLEAN"; $(orm)
LD =  @echo "  LD  $@"; $(old)
endif

LDFLAGS-TSAN = $(LDFLAGS) -fsanitize=thread
COMPILERFLAGS-TSAN = $(COMPILERFLAGS) -fsanitize=thread


# REGLAS
#########

.PHONY: all clean

all: hotel

o_hotel_files = $(patsubst %.$(extension),%.o,$(hotel_files))

client: $(o_hotel_files)
	@if [ -z "$(o_hotel_files)" ]; \
	then \
		echo "No hay archivos de entrada en el directorio"; \
		if [ -n "$(directorios)" ]; then echo "Directorios encontrados: $(directorios)"; fi; \
		false; \
	fi >&2
	$(LD) $(o_hotel_files) -o hotel $(LDFLAGS)

clean:
	$(RM) -f $(o_hotel_files) hotel

