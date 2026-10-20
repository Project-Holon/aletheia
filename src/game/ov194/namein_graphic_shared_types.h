#ifndef GAME_OV194_NAMEIN_GRAPHIC_SHARED_TYPES_H
#define GAME_OV194_NAMEIN_GRAPHIC_SHARED_TYPES_H

/* A cell position and a cell box of the name entry picker, shared by namein_graphic.c and namein_graphic_field.c. */
typedef struct { int x, y; } NameinGraphicPair;

typedef struct { int x, y, z, w; } NameinGraphicBox;

#endif
