CC=g++
EXE_FILE=main
all: $(EXE_FILE)

deck.o: deck.hpp deck.cpp
	$(CC) -c deck.cpp

card.o: card.hpp card.cpp
	$(CC) -c card.cpp

hand.o: hand.hpp hand.cpp
	$(CC) -c hand.cpp

player.o: player.hpp player.cpp
	$(CC) -c player.cpp

game.o: game.hpp game.cpp
	$(CC) -c game.cpp


$(EXE_FILE): deck.o deck.hpp  card.o card.hpp hand.o hand.hpp player.o player.hpp game.o game.hpp main.cpp
	$(CC) deck.o card.o hand.o player.o game.o main.cpp -o $(EXE_FILE)

