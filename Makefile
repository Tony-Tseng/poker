IDIR = include
CC=g++ -std=c++11
CFLAGS=-I$(IDIR)

ODIR=obj
SRCDIR=src

_DEPS = board.hpp card.hpp deck.hpp display.hpp hand.hpp handtype.hpp player.hpp poker.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o board.o card.o deck.o display.o hand.o handtype.o player.o poker.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -g

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -g

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
