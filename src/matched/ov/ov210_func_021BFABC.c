/*
 * function: func_021BFABC
 * address: 0x021BFABC
 * packet: pkt_ov210_021BFABC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   func_021BF7B0 0x021BF7B0 thumb ov210
 */
#include "../include/Obj25630.h"
extern int FRAME_LIST_GetScrollPos(char *);
extern void func_021BF7B0(char *p, int idx, int y, int flag);
void func_021BFABC(char *ctx, int slot, int index)
{
    unsigned center = FRAME_LIST_GetScrollPos(*(char * *)&((struct Obj25630 *)ctx)->f1E0);
    signed short lower = center - 7;
    signed short upper = center + 7;
    if (lower < 0) lower = 0;
    if (index >= lower && index < center) {
        func_021BF7B0(ctx, slot, (signed short)(192 - (center - index) * 24), 0);
    } else if (index >= center && index < upper) {
        func_021BF7B0(ctx, slot, (signed short)((index - center) * 24), 1);
    }
}
