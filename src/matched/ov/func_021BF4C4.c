/*
 * function: func_021BF4C4
 * address:  0x021BF4C4
 * packet:   pkt_021BF4C4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   (none)

 * Releases each of the six 0x14-byte element handles against a parallel table and clears its +0x2C slot.
 */
#include "../include/Obj18262.h"


struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
typedef unsigned short u16;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void func_021BF4C4(int unused, char *q, int c, int *tbl)
{
    unsigned char i;

    for (i = 0; i < 6; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(q + i * 0x14 + 0x1c), tbl[i]);
        *(int *)(q + i * 0x14 + 0x2c) = 0;
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c)), *(unsigned short *)(q + i * 0x14 + 0x24));
    }
    ((struct Obj18262 *)q)->f94 = 6;
}

