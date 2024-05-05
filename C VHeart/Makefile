
# Compiler
CC = gcc

CFLAGS = -IC:\SDL2\include -LC:\SDL2\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx

# Files
HeartModelFiles = ./HeartModel/heartModel.c ./HeartModel/nodeAutomaton.c ./HeartModel/pathAutomaton.c

probeFiles = ./HeartCSVRead/probe/probeTable.c

MainFiles = ./main.c ./HeartCSVRead/matlabRead/matlabRead.c  ./HeartCSVRead/nodes/nodeTable.c ./HeartCSVRead/nodes/nodePathLocatin.c ./HeartCSVRead/nodes/nodePath.c ./HeartCSVRead/nodes/nodePosition.c

SDLFiles = ./UI/SDL/MYsdlWindow.c



TerminalFiles = ./UI/Terminal/TerminalUI.c

# Targets
buildUI: 
	$(CC)  $(MainFiles) $(SDLFiles) $(HeartModelFiles) $(probeFiles) $(CFLAGS) -o HeartUI
	make runUI

buildNoUI: 
	$(CC) $(MainFiles) $(TerminalFiles) $(HeartModelFiles) $(probeFiles) -o HeartNoUI
	make runNoUI

runUI:
	./HeartUI

runNoUI: 
	./HeartNoUI

clean:
	rm -f ./Heart.exe