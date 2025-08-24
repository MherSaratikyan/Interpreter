# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -Wformat=2

# Sources
RLS_SRCS = src/main.c src/chunk.c src/value_array.c
DBG_SRCS = src/main.c src/chunk.c src/dbg_utils.c src/value_array.c

# Object files
DBG_OBJS = $(DBG_SRCS:src/%.c=build/dbg/%.o)
RLS_OBJS = $(RLS_SRCS:src/%.c=build/rls/%.o)

# Output binaries
DEBUG_BIN = build/dbg/clox_dbg
RELEASE_BIN = build/rls/clox_rls

# Debug flags
DBG_FLAGS = -g -O0

# Release flags
RLS_FLAGS = -O3 -flto -DNDEBUG

# Default target
all: release

# Debug build
debug: CFLAGS += $(DBG_FLAGS)
debug: $(DBG_OBJS)
	$(CC) $(CFLAGS) $^ -o $(DEBUG_BIN)

# Release build
release: CFLAGS += $(RLS_FLAGS)
release: $(RLS_OBJS)
	$(CC) $(CFLAGS) $^ -o $(RELEASE_BIN)

# Compile .c -> .o for debug
build/dbg/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .c -> .o for release
build/rls/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf build
