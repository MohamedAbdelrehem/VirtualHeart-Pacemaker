# matlab script MAT -> CSV (with complex data)

# CSV read universal function (with complex data) (ARRAY comma separated)

# complex function passing

#SDL

# terminal based UI

![VHeart](./0-Assets/VHeart.gif)

# File tree

```
.
│   readme.md
|
├───0-Assets
│       VHeart.gif
│
├───1-MatlabToCSV
│   │   ConvertMATtoCSVstrings.m
│   │   ConvertMATtoCSVstrings.mlx
│   │
│   └───cases
│           AFlutter.mat
│           EP_AVNRT.mat
│           Wenckbach.mat
│
├───2-MatlabToCSVOutput
│   ├───AFlutter
│   │       egm_table.csv
│   │       node_pos.csv
│   │       node_table.csv
│   │       pace_para.csv
│   │       path_table.csv
│   │       probe_pos.csv
│   │       probe_table.csv
│   │
│   ├───EP_AVNRT
│   │       egm_table.csv
│   │       node_pos.csv
│   │       node_table.csv
│   │       pace_para.csv
│   │       path_table.csv
│   │       probe_pos.csv
│   │       probe_table.csv
│   │
│   └───Wenckbach
│           egm_table.csv
│           node_pos.csv
│           node_table.csv
│           pace_para.csv
│           path_table.csv
│           probe_pos.csv
│           probe_table.csv
│
└───3-Heart&Pacemaker(C_CODE)
    │   HeartNoUI.exe
    │   HeartUI.exe
    │   main.c
    │   Makefile
    │   Settings.h
    │
    ├───assets
    │   ├───fonts
    │   │       Arial.ttf
    │   │       Atop-R99O3.ttf
    │   │       LoveDays-2v7Oe.ttf
    │   │
    │   └───images
    │           EP.JPG
    │
    ├───HeartCSVRead
    │   │   constants.h
    │   │   dataStructure.h
    │   │
    │   ├───matlabRead
    │   │       matlabRead.c
    │   │       MatlabRead.h
    │   │
    │   ├───nodes
    │   │       nodePath.c
    │   │       nodePath.h
    │   │       nodePathLoaction.h
    │   │       nodePathLocatin.c
    │   │       nodePosition.c
    │   │       nodePosition.h
    │   │       nodeTable.c
    │   │       nodeTable.h
    │   │
    │   └───probe
    │           pacemakerParameters.c
    │           pacemakerParameters.h
    │           probePosition.c
    │           probePosition.h
    │           probeTable.c
    │           probeTable.h
    │
    ├───HeartModel
    │       heartModel.c
    │       heartModel.h
    │       nodeAutomaton.c
    │       nodeAutomaton.h
    │       pathAutomaton.c
    │       pathAutomaton.h
    │
    └───UI
        ├───SDL
        │       MYsdlWindow.c
        │       MYsdlWindow.h
        │
        └───Terminal
                TerminalUI.c
                TerminalUI.h
```
