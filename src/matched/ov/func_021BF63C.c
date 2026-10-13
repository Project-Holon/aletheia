/*
 * function: func_021BF63C
 * address:  0x021BF63C
 * packet:   pkt_021BF63C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm  arm9
 *   (none)

 * Frees the 0x14-byte record at the index held in +0x98.
 */
#include "../include/Obj00442.h"


typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

void func_021BF63C(int unused, char *p)
{
    int i = ((struct Obj00442 *)p)->f98;

    if (i == 6)
        return;
    CLACT_SetActorPaletteOffset((struct Obj *)(*(int *)(p + i * 0x14 + 0x1c)), 0, 0);
    ((struct Obj00442 *)p)->f10C = 0;
}

