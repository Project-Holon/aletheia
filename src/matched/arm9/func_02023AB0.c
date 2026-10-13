/*
 * function: WIPE_SUB_CalcShutterRows
 * address:  0x02023AB0
 * packet:   pkt_02023AB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * cap: the only call site of WIPE_SUB_CalcShutterBand (0x02023AF4) inside the image is at
 *      0x02023ADA, which is inside this function, so the `label` class refuses
 *      it (no witness outside 02023AB0..02023AF2).  Every byte reproduces:
 *      the listing extent reads 68 only because of two bytes of 00 00 padding
 *      at 0x02023AF2; the code is 66.  Promotes to EXACT the moment
 *      WIPE_SUB_CalcShutterBand has its own manifest entry.
 *
 * symbols:
 *   WIPE_SUB_CalcShutterBand  0x02023AF4  thumb
 */
#include "../include/Obj06900.h"

typedef unsigned int u32;

typedef signed int     s32;
typedef unsigned char  u8;
extern void WIPE_SUB_CalcShutterBand(u8 *desc, u8 *out, s32 num, s32 den);

void WIPE_SUB_CalcShutterRows(void *p)
{
    int i;

    for (i = 0; i < ((struct Obj06900 *)p)->f310; i++) {
        WIPE_SUB_CalcShutterBand((void *)(((struct Obj06900 *)p)->f30C + i * 4), p,
                      ((struct Obj06900 *)p)->f318,
                      ((struct Obj06900 *)p)->f314);
    }
}
