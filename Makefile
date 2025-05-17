GXX = gcc

GXX_FLAGS = -g

SRC = src
BUILD = build
OBJ = $(BUILD)/obj


SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(subst $(SRC)/, $(OBJ)/, $(addsuffix .o, $(basename $(SRCS))))

EXEC = yatp

all: clean compile

compile: $(BUILD)/$(EXEC)

$(BUILD)/$(EXEC): $(OBJS)
	$(GXX) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(GXX) $(GXX_FLAGS) -c $< -o $@

ifeq ($(OS), Windows_NT)
.SILENT: clean
endif

.PHONY: clean
clean: mkbuild
ifeq ($(OS), Windows_NT)
	del /Q /S $(BUILD)\*
else ifeq ($(shell uname), Linux)
	find $(BUILD) -maxdepth 1 -type f -exec rm {} \;
	rm -rf $(OBJ)/*
endif

mkbuild:
ifeq ($(OS), Windows_NT)
	if not exist "$(BUILD)" mkdir "$(BUILD)"
	if not exist "$(OBJ)" mkdir "$(OBJ)"
else ifeq ($(shell uname), Linux)
	mkdir -p $(BUILD)
	mkdir -p $(OBJ)
endif