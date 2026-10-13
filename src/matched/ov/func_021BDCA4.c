/*
 * function: func_021BDCA4
 * address:  0x021BDCA4
 * packet:   pkt_021BDCA4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorBgPriority  0x0204B84C  arm  arm9
 *   (none)

 * Stores the mode at +0x38, arms +0x3C and hands the mode to every +0x70 handle.
 */
#include "../include/Obj02345.h"


extern void CLACT_SetActorBgPriority(int, int);

void func_021BDCA4(char *p, unsigned char v)
{
    unsigned char i;

    ((struct Obj02345 *)p)->f38 = v;
    ((struct Obj02345 *)p)->f3C = 1;
    for (i = 0; i < ((struct Obj02345 *)p)->f68; i++)
        CLACT_SetActorBgPriority(*(int *)(p + i * 8 + 0x70), v);
}

