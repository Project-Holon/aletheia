/*
 * function: ZUKAN_DETAIL_AREA_CreatePrintQueues
 * address:  0x021C06C8
 * packet:   pkt_021C06C8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   (none)

 * Fills four 4-byte entries with the current halfword and clears a word.
 */
#include "../include/Obj12126.h"


typedef unsigned int   u32;
extern u32 PRINTSYS_QUE_Create(void *p);

void ZUKAN_DETAIL_AREA_CreatePrintQueues(unsigned short *a, char *b, int a2)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = b + i * 4;
        ((struct Obj12126 *)e)->f34 = PRINTSYS_QUE_Create((void *)(*a));
        ((struct Obj12126 *)e)->f24 = 0;
    }
}

