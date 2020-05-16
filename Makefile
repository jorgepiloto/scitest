all : clean test_example

clean:
	@rm -f test_example

test_example: test_example.c
	@gcc -o test_example -Wall test_example.c
