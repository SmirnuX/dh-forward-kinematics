libraries = dh_model.c matrix.c
all:
	gcc main.c $(libraries) -o robopro -lm

run:
	gcc main.c $(libraries) -o robopro-test -lm
	./robopro-test
	rm ./robopro-test

sanitized:
	gcc main.c $(libraries) -o robopro-test -lm -fsanitize=address
	./robopro-test
	rm ./robopro-test
