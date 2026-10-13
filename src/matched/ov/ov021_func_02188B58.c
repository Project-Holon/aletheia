/*
 * function: FIELDMAP_Main
 * address:  0x02188B58
 * packet:   pkt_ov021_02188B58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFieldMapSeqTable  0x021D36B8  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02685.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef u32 (*Fn)(void *a, void *b);
extern Fn sFieldMapSeqTable[][2];

u32 FIELDMAP_Main(void *a, u8 *b, u32 a2, u32 a3)
{
    u32 c = ((struct Obj02685 *)b)->fCC;
    s32 r = 0;
    Fn f;
    Fn *row;

    ((struct Obj02685 *)b)->fCC = c + 1;
    row = sFieldMapSeqTable[((struct Obj02685 *)b)->fC4];
    f = row[b[0xC9]];
    if (f != 0)
        r = f(a, b);
    switch (r) {
    case 0:
        b[0xC9] = (b[0xC9] == 0);
        break;
    case 1:
        ((struct Obj02685 *)b)->fC4 = ((struct Obj02685 *)b)->fC4 + 1;
        b[0xC8] = 0;
        b[0xC9] = 0;
        break;
    case 2:
        return 1;
    }
    return 0;
}
