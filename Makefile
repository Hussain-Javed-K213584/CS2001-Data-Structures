CC = clang++

speller:
	$(CC) speller.cpp dictionary.cpp hashmap.cpp -o speller