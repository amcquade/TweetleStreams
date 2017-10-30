all: mapper.cc reducer.cc
	g++ -c mapper.cc
	g++ -o mapper mapper.o
	g++ -c reducer.cc
	g++ -o reducer reducer.o
	rm *.o

i_test: all
	cat 58.json | ./mapper -I 'love follow android'| sort| ./reducer

test: all
	cat 58.json | ./mapper 'love follow android'| sort| ./reducer

i_run: 	./mapper ./reducer
	cat 58.json | ./mapper -I '${ARGS}'| sort| ./reducer

run: 	./mapper ./reducer
	cat 58.json  | ./mapper '${ARGS}'| sort| ./reducer
