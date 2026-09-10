CC = gcc
CFLAGS = -Wall -Wextra -I./include/
LDFLAGS = -lncurses

TARGET = sudoku
VERSION = 1.0.1

PACKAGE_DIR = packaging/sudoku-solver
PACKAGE_BIN = $(PACKAGE_DIR)/usr/bin/sudoku
DEB = sudoku-solver_$(VERSION)_amd64.deb

.PHONY: all run package clean

all: $(TARGET)

$(TARGET):
	$(CC) ./src/*.c $(CFLAGS) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

package: $(TARGET)
	mkdir -p $(PACKAGE_DIR)/usr/bin
	cp $(TARGET) $(PACKAGE_BIN)
	dpkg-deb --build --root-owner-group $(PACKAGE_DIR)
	mv $(PACKAGE_DIR).deb $(DEB)
	@echo "Package created: $(DEB)"

clean:
	rm -f $(TARGET)
	rm -f $(DEB)
