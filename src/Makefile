CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
PAC_DIR = ./deb_pac2


all: install

check-env:
	@command -v $(CXX) > /dev/null || (echo "Error: $(CXX) not found. Install with 'sudo apt install build-essential.'"; exit 1)
	@dpkg -l libc6-dev > /dev/null || (echo "Error: libc6-dev not found. Install with 'sudo apt install libc6-dev.'"; exit 1)

build: check-env
	@$(CXX) $(CXXFLAGS) -o laba2 ./factorial.cpp
	@echo "Build complete"
test: build
	@bash ../cicd/test.sh ./laba2
	@echo "Successfully tested"
install: test
	@install -Dm755 laba2 $(PAC_DIR)/usr/bin/laba2
	@echo "Successfully installed"
uninstall:
	@rm -f $(PAC_DIR)/usr/bin/laba2
	@echo "Successfully uninstalled"

.PHONY: check-env build test install uninstall
