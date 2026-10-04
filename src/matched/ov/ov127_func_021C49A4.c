/*
 * function: func_021C49A4
 * address: 0x021C49A4
 * packet: pkt_ov127_021C49A4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021C49FE follow the return.
 */
#include "../include/Obj00535.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
int func_021C49A4(u8 *p, unsigned int i)
{
    switch (i) {
    case 0: return *(s16 *)&((struct Obj00535 *)p)->f4;
    case 1: return *(s16 *)&((struct Obj00535 *)p)->f6;
    case 2: return *(s16 *)&((struct Obj00535 *)p)->f8;
    case 3: return *(s16 *)&((struct Obj00535 *)p)->fA;
    case 4: return ((struct Obj00535 *)p)->fC;
    case 5: return p[21];
    case 6: return p[20];
    case 7: return ((struct Obj00535 *)p)->fE;
    case 8: return ((struct Obj00535 *)p)->f10;
    case 9: return ((struct Obj00535 *)p)->f12;
    case 10: return ((struct Obj00535 *)p)->f16;
    default: return (int)p;
    }
}
