SudokuValidator: SudokuValidator SudokuValidator.c
	@gcc -std=c99 -o SudokuValidator SudokuValidator.c -lpthread
	@echo "Finished compiling script.\nExiting Makefile[1].\nRun './SudokuValidator'"
