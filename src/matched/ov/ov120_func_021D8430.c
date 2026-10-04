/*
 * function: func_021D8430
 * address: 0x021D8430
 * packet: pkt_ov120_021D8430
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   func_021D60FC 0x021D60FC thumb ov120
 *   func_0202DB0C 0x0202DB0C thumb
 */
#include "../include/Obj06444.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PmsDraw;
extern u32 func_021D60FC(u8 *p);
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
void func_021D8430(u8 *p,void *q)
{
    if(!((struct Obj06444 *)p)->fCC)
        ((struct Obj06444 *)p)->fCC=func_0202DB0C(func_021D60FC(q),0,(u32)(((struct Obj06444 *)p)->fA4),(u32)(((struct Obj06444 *)p)->f14),8,4,((struct Obj06444 *)p)->fC8);
}
