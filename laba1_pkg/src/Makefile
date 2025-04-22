CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

all: install

check-env:
	@command -v $(CXX) > /dev/null || (echo "Error: $(CXX) not found. Install with 'sudo apt install build-essential'"; exit 1)
	@dpkg -l libc6-dev > /dev/null || (echo "Error: libc6-dev not found. Install with 'sudo apt install libc6-dev'"; exit 1)

build: check-env
	@$(CXX) $(CXXFLAGS) -o laba1 ./factorial.cpp
	@echo "Build complete"

install: build
	@install -Dm755 laba1 $(DESTDIR)/usr/bin/laba1
	@echo "Successfully installed"
uninstall:
	@rm -f $(DESTDIR)/usr/bin/laba1
	@echo "Successfully uninstalled"

.PHONY: check-env build install uninstall
