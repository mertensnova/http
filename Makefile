output: main.o
	g++ main.o -o output -lssl -lcrypto

main.o: main.cxx  block.h transaction.h hash.h
	g++ -c main.cxx -lssl -lcrypto
clean:
	rm *.o 
