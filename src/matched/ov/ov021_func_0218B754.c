/*
 * function: FIELD_BUILDMODEL_Create
 * address:  0x0218B754
 * packet:   pkt_ov021_0218B754
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates and initialises a 0x13F8-byte object.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   gBuildModelFileName     0x021DD9CC  data  ov021  a4
 *   FIELD_BUILDMODEL_InitSeason  0x0218BCE4  thumb
 *   FIELD_BUILDMODEL_ClearEntry  0x0218C490  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02071.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern int gBuildModelFileName;
typedef unsigned int   u32;
extern void FIELD_BUILDMODEL_InitSeason(u32 *p, u8 v);
extern void FIELD_BUILDMODEL_ClearEntry(char *p, char *q);

char *FIELD_BUILDMODEL_Create(int a, int b, u16 c)
{
    char *p;
    int i;
    unsigned j;
    int z = 0;

    p = (char *)func_02030734(a, 0x13F8, 0, (const char *)&gBuildModelFileName, 0x193);
    ((struct Obj02071 *)p)->f0 = a;
    ((struct Obj02071 *)p)->f4 = b;
    FIELD_BUILDMODEL_InitSeason((u32 *)(p + 8), c);
    for (i = 0; i < 7; i++)
        *(int *)(p + 0x1DC + i * 4) = z;
    for (j = 0; j < 0x120; j++)
        FIELD_BUILDMODEL_ClearEntry(p, p + 0x1F8 + j * 16);
    ((struct Obj02071 *)p)->f1B0 = 0;
    ((struct Obj02071 *)p)->f1B4 = 0;
    ((struct Obj02071 *)p)->f1B8 = 0;
    ((struct Obj02071 *)p)->f1BC = 0;
    ((struct Obj02071 *)p)->f1C0 = 0;
    ((struct Obj02071 *)p)->f1C4 = 0;
    ((struct Obj02071 *)p)->f1C8 = 0;
    ((struct Obj02071 *)p)->f1CC = 0;
    ((struct Obj02071 *)p)->f1D4 = 0;
    ((struct Obj02071 *)p)->f1D8 = 0;
    return p;
}
