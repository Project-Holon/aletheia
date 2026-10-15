/*
 * function: DUP_FITTING_SortFrames
 * address: 0x021B9028
 * packet: pkt_ov133_021B9028
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: explicit redundant pointer/bound temporaries from the bounded permuter settled the three spill homes.
 * symbols:
 *   DUP_FITTING_FrameWeight 0x021B9118 thumb ov133
 */
#include "../include/Obj03825.h"
#include "../include/Obj10571.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 DUP_FITTING_FrameWeight(u8 *, u8 *, int);
void DUP_FITTING_SortFrames(u8 *p, int kind, u16 start)
{
    u8 *positionptr;
    u16 i, j, index, position, weight, next, best;
    u8 *tmp;
    u8 *tmp1;
    u8 **tmp2;
    u16 tmp3, tmp4;
    for (i = 0; i < ((struct Obj03825 *)p)->fA8; i++) {
        index = (u16)((start + i) % ((struct Obj03825 *)p)->fA8);
        *(u8 **)(p + index * 4 + 0x1434) = (p + 0xAC) + i * 20;
    }
    for (i = 0; i < ((struct Obj03825 *)p)->fA8; i++) {
        position = (u16)((start + i) % ((struct Obj03825 *)p)->fA8);
        best = position;
        tmp1 = p + position * 4;
        positionptr = tmp1;
        weight = DUP_FITTING_FrameWeight(p, *(u8 * *)&((struct Obj10571 *)positionptr)->f1434, kind);
        for (j = i + 1; j < *(u16 *)(p + 0xA8); j++) {
            tmp4 = *(u16 *)(p + 0xA8);
            tmp3 = tmp4;
            index = (u16)((start + j) % tmp3);
            next = DUP_FITTING_FrameWeight(p, *(u8 **)(p + index * 4 + 0x1434), kind);
            if (weight < next) { weight = next; best = index; }
        }
        if (best != position) {
            tmp = *(u8 **)(positionptr + 0x1434);
            *(u8 **)(positionptr + 0x1434) = *(u8 **)(p + best * 4 + 0x1434);
            tmp2 = (u8 **)(p + best * 4 + 0x1434);
            *tmp2 = tmp;
        }
    }
}
