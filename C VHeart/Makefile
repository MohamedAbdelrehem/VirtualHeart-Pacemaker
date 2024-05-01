CC = gcc

CFLAGS = -IC:\SDL2\include -LC:\SDL2\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

FILESlistNoSDL = ./HeartCSVRead/main.c ./HeartCSVRead/matlabRead.c  ./HeartCSVRead/nodeTable.c ./HeartCSVRead/nodePath.c
FILESlist = ./HeartCSVRead/main.c ./HeartCSVRead/matlabRead.c ./HeartCSVRead/nodeTable.c ./HeartCSVRead/nodePath.c ./HeartCSVRead/MYsdlWindow.c

buildUI: 
	$(CC)  $(FILESlist) $(CFLAGS) -o Heart

buildNoUI: 
	$(CC) $(FILESlistNoSDL)  -o Heart
runHeart: 
	./Heart

clean:
	rm -f Heart
	