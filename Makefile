all: asciidencoder

WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
OPTS = -lm

asciidencoder: Makefile asciidencoder.c
	$(CC) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) $(OPTS) asciidencoder.c

clean:
	rm -f asciidencoder

install:
	echo "Installing is not supported"

run:
	./asciidencoder

