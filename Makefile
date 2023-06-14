TARGET=ArrIndexTest
OBJ_DIR=objs
SRC := $(wildcard *.c)
OBJS := $(SRC:%.c$(OBJ_DIR)/%.o)

all: $(TARGET)
dir:
	@mkdir objs

$(TARGET): dir $(OBJS)
	@echo "Linking [\n\t$^\n\t]""
	@$(CC)  $^ -o $@

$(OBJS): $(OBJ_DIR)/%.o:  %.c 
	@printf "Compiling  [%-45s -> %s]\n" $< $@
	@$(CC) -c $< -o $@

clean:
	@rm -rf objs