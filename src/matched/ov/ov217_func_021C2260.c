/*
 * function: ARROW_HideAll
 * address:  0x021C2260
 * packet:   pkt_ov217_021C2260
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 */
#include "../include/Obj26021.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);

void ARROW_HideAll(void *p)
{
    s32 i;
    s32 n = ((struct Obj26021 *)p)->f298;
    for (i = 0; i < n; i++)
        CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)((char *)p + 0x3c + i * 0x18), 0);
}
