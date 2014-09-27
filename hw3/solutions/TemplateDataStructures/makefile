# Setting compiler
CC = g++

# compiler flags for debug
CPPFLAGS=-std=c++11 -Wall -g -DDEBUG

# compiler flags for release. treat warnings as errors and also optimize code.
# CPPFLAGS=-std=c++11 -Werror=all -O2 

# folder for source code
SRC_DIR=src
# folder for header files
HEADER_DIR=header
# folder for generated object files
OBJ_DIR=obj

# name of the binary
all: maptest settest

# First we map every source code to its object file.
# We do this separately for each source file to better identify the header dependency.

$(OBJ_DIR)/MapTest.o: $(SRC_DIR)/MapTest.cpp $(SRC_DIR)/MapImpl.cxx $(HEADER_DIR)/Map.h $(OBJ_DIR)/.dirstamp
	$(CC) -c $< -o $@ $(CPPFLAGS) -I${HEADER_DIR}/
	
$(OBJ_DIR)/SetTest.o: $(SRC_DIR)/SetTest.cpp $(SRC_DIR)/SetImpl.cxx $(HEADER_DIR)/Set.h $(OBJ_DIR)/.dirstamp
	$(CC) -c $< -o $@ $(CPPFLAGS) -I${HEADER_DIR}/

#$(OBJ_DIR)/Map.o: $(SRC_DIR)/MapImpl.cxx $(HEADER_DIR)/Map.h $(OBJ_DIR)/.dirstamp
#	$(CC) -c $< -o $@ $(CPPFLAGS) -I${HEADER_DIR}/

# Now it's time to link both objects. No need for -I argument anymore.
#maptest: $(OBJ_DIR)/MapTest.o $(OBJ_DIR)/Map.o
maptest: $(OBJ_DIR)/MapTest.o
	${CC} $^ -o $@ ${CPPFLAGS}
	
settest: $(OBJ_DIR)/SetTest.o
	${CC} $^ -o $@ ${CPPFLAGS}

# this rule insures the obj directory exist or it'll create it.
$(OBJ_DIR)/.dirstamp:
	-@mkdir -p $(OBJ_DIR) && touch $@

# Memory check rule. Depends on a fresh binary.
.PHONY: memcheck
memcheck: maptest
	valgrind --tool=memcheck ./$<

# The clean rule
.PHONY: clean
clean:
	-@rm ${OBJ_DIR}/*.o maptest settest *.stackdump *~ $(SRC_DIR)/*~ $(HEADER_DIR)/*~ 2>/dev/null || true
