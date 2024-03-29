SRC_DIR = ./src
OUT_DIR = ./build
OBJ_DIR = $(OUT_DIR)/obj
BIN_DIR = $(OUT_DIR)/bin
DOC_DIR = $(OUT_DIR)/doc

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

.DEFAULT_GOAL := all

$(OUT_DIR): 
	mkdir -p $(OUT_DIR)

$(OBJ_DIR): $(OUT_DIR)
	mkdir -p $(OBJ_DIR)

$(BIN_DIR): $(OUT_DIR)
	mkdir -p $(BIN_DIR)

$(DOC_DIR): $(OUT_DIR)
	mkdir -p $(DOC_DIR)	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	gcc -c $< -o $@ $(TIPO)

all: $(OBJ_FILES) $(BIN_DIR)
	gcc -o $(BIN_DIR)/app.elf $(OBJ_FILES)

clean: $(OUT_DIR)
	rm -r $(OUT_DIR)

doc: $(DOC_DIR)
	doxygen doxyfile