CC = gcc

CFLAGS = -IC:\SDL2\include -LC:\SDL2\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

FILESlistNoSDL = ./HeartCSVRead/main.c ./HeartCSVRead/matlabRead/matlabRead.c  ./HeartCSVRead/nodes/nodeTable.c ./HeartCSVRead/nodes/nodePath.c ./HeartCSVRead/nodes/nodePosition.c
FILESlist = ./HeartCSVRead/main.c ./HeartCSVRead/matlabRead/matlabRead.c ./HeartCSVRead/nodes/nodeTable.c ./HeartCSVRead/nodes/nodePath.c ./HeartCSVRead/nodes/nodePosition.c ./HeartCSVRead/MYsdlWindow.c

buildUI: 
	$(CC)  $(FILESlist) $(CFLAGS) -o Heart
	make run

buildNoUI: 
	$(CC) $(FILESlistNoSDL)  -o Heart
	make run
run: 
	./Heart

clean:
	rm -f Heart
	