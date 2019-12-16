#ifndef LECTURE_CAM_H_INCLUDED
#define LECTURE_CAM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sz 20

struct camera1
 {
    char id[sz];
    char info[sz];
    char emplacement[sz];

 };
typedef struct camera1 came;

struct bracelet1
 {
    char id[sz];
    char info[sz];
    char emplacement[sz];

 };
typedef struct bracelet1 brac;

void lecture_camera(FILE *f,came T[]);
void lecture_bracelet(FILE *f,brac T[]);

#endif
