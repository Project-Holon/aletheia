/*
 * function: func_021BF41C
 * address:  0x021BF41C
 * packet:   pkt_021BF41C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *   (none)

 * Releases the sixth 0x14-byte element handle at +0x1C and the two at +0xA0 and +0xA4.
 */
#include "../include/Obj12120.h"


struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);

void func_021BF41C(int unused, char *q, u32 a2)
{
    unsigned char i;

    for (i = 0; i < 6; i++)
        CLACT_DeleteActor((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c)));
    CLACT_ReleaseCharacter(((struct Obj12120 *)q)->fA0);
    CLACT_ReleaseCellAnim(((struct Obj12120 *)q)->fA4);
}

