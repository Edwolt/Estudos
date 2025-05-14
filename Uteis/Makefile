# Compilation
CC        := gcc

# Flags
LIBS      := -lm
RFLAGS    := $(LIBS) -O3 -w #-march=native
DFLAGS    := $(LIBS) -Wall -g3 -Werror=implicit-function-declaration -fsanitize=address,undefined -pedantic
RM_FLAGS  := -fv

# Output
EXEC      := program
ZIP       := Trabalho.zip

# Folders
F_SRC     := ./src
F_BIN     := ./bin
F_HEADER := ./headers

# List of all expected $(BIN)/*.o
SRCS      := $(wildcard $(F_SRC)/*.c)
HEADERS   := $(wildcard $(F_HEADERS)/*.h)

OBJS      := $(SRCS:$(F_SRC)/%.c=$(F_BIN)/%.o)

# Comandos
.PHONY: all run release debug zip clean_zip clean

# All & Run
all: $(EXEC)

run: all
	./$(EXEC)

# Compile
release: FLAGS := $(RFLAGS)
release: clean $(EXEC)

debug: FLAGS := $(DFLAGS)
debug: clean $(EXEC)

zip:
	rm $(ZIP) $(RM_FLAGS)
	zip $(ZIP) Makefile $(F_HEADER)/*.h $(F_SRC)/*.c assets/*

# Clean
clean_zip:
	rm $(ZIP) $(RM_FLAGS)

clean:
	rm $(EXEC) $(RM_FLAGS)
	rm $(OBJS) $(RM_FLAGS)

# Exec
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(F_BIN)/*.o $(FLAGS)

$(F_BIN)/%.o: $(F_SRC)/%.c $(HEADERS) | $(F_BIN)
	$(CC) -o $@ -c $< -I $(F_HEADER) $(FLAGS)

$(F_BIN):
	mkdir -p $(F_BIN)
