/*
 * function: FIELD_SOUND_SYSTEM_Init
 * address:  0x02028CD4
 * packet:   pkt_02028BDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00164.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_SOUND_SYSTEM_Init(u8 *p, u32 v)
{
    int i;

    ((struct Obj00164 *)p)->f0 = v;
    ((struct Obj00164 *)p)->f4 = 0;
    ((struct Obj00164 *)p)->f1C = 0;
    ((struct Obj00164 *)p)->f8 = 0;
    ((struct Obj00164 *)p)->fC = 0;
    ((struct Obj00164 *)p)->f10 = 0;
    ((struct Obj00164 *)p)->f14 = 0;
    ((struct Obj00164 *)p)->f18 = 0;
    ((struct Obj00164 *)p)->f1A = 0;
    *(u32 *)&((struct Obj00164 *)p)->f20 = 0;
    ((struct Obj00164 *)p)->f24 = 0;

    for (i = 0; i < 10; i++)
        *(u32 *)(p + 0x28 + i * 12) = 0;

    ((struct Obj00164 *)p)->fA0 = 0;
    ((struct Obj00164 *)p)->fA1 = 0;

    for (i = 0; i < 2; i++)
        *(u16 *)(p + 0xac + i * 2) = 0xffff;

    ((struct Obj00164 *)p)->fB4 = 0;
}
