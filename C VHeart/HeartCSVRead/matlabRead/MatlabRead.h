#ifndef MATLABREAD_H_
#define MATLABREAD_H_

#define MAX_LINE_LENGTH 1024

int readMatlabCSV(const char *fileName, int *const numberOfRows, void (*saveToStructFPointer)(char *, const int, const int));

#endif // MATLABREAD_H_