/*
 * function: FIELD_G3D_MAP_DrawWithModels
 * address:  0x02169354
 * packet:   pkt_02169354
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3D_MAP_Draw  0x0216968C  thumb  ov010
 *   FIELD_G3D_MAP_DrawPlacedModels  0x02169710  thumb  ov010
 */
#include "../include/Obj03541.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_G3D_MAP_Draw(u8 *p);
extern int FIELD_G3D_MAP_DrawPlacedModels();

int FIELD_G3D_MAP_DrawWithModels(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
    a0 = FIELD_G3D_MAP_Draw((u8 *)a0);
loc_02169360:
    if (a0 != 1) goto loc_02169378;
loc_02169364:
a0 = t5 + 0;
a0 = a0 + 0x98;
a0 = ((struct Obj03541 *)((char *)a0))->f0;
    if (a0 == 0) goto loc_02169376;
loc_0216936E:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = FIELD_G3D_MAP_DrawPlacedModels(a0, a1);
loc_02169376:
t4 = 1;
loc_02169378:
a0 = t4 + 0;
    return a0;}
