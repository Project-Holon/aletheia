/*
 * function: B_BAG_MAIN_RecreateCursor
 * address: 0x0220D924
 * packet: pkt_ov197_0220D924
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: an outer switch preserves the unconditional default-arm branch.
 * symbols:
 *   B_BAG_MAIN_DeleteCursor 0x0220D914 thumb ov197
 *   B_BAG_MAIN_CreateCursor 0x0220D8C4 thumb ov197
 */
#include "../include/Obj03347.h"
typedef unsigned char u8;
typedef signed short s16;
extern unsigned int B_BAG_MAIN_DeleteCursor(u8 *);
typedef unsigned int   u32;
extern void B_BAG_MAIN_CreateCursor(u8 *p, u32 index, u32 value);
void B_BAG_MAIN_RecreateCursor(u8 *p, int state, int value)
{
    switch (*(int *)&((struct Obj03347 *)p)->f598) {
    case 0: value = 0; break;
    default:
        switch (state) {
        case 0: value = p[0x533]; break;
        case 1: value = *(s16 *)(*(char * *)&((struct Obj03347 *)p)->f0 + p[0x533] * 2 + 0x30); break;
        case 2: value = 0; break;
        }
        break;
    }
    B_BAG_MAIN_DeleteCursor(p);
    B_BAG_MAIN_CreateCursor(p, state, value);
}
