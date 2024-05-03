CC = gcc

CFLAGS = -IC:\SDL2\include -LC:\SDL2\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx

FILESlistNoSDL = ./HeartCSVRead/main.c ./HeartCSVRead/matlabRead/matlabRead.c  ./HeartCSVRead/nodes/nodeTable.c ./HeartCSVRead/nodes/nodePathLocatin.c ./HeartCSVRead/nodes/nodePath.c ./HeartCSVRead/nodes/nodePosition.c

SDLFiles = ./HeartCSVRead/MYsdlWindow.c


buildUI: 
	$(CC)  $(FILESlistNoSDL) $(SDLFiles) $(CFLAGS) -o HeartUI
	make runUI

buildNoUI: 
	$(CC) $(FILESlistNoSDL)  -o HeartNoUI
	make runNoUI

runUI:
	./HeartUI

runNoUI: 
	./HeartNoUI

clean:
	rm -f ./Heart.exe