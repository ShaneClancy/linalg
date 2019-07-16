#!/bin/bash
#
build:
	@g++ linalg.cpp -o linalg
	@echo -e "Build Complete"
run:
	@echo -e "Running Test Program"
	@./linalg

clean:
	@rm -rf linalg
	@echo -e "All executable files removed"