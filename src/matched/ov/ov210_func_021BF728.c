/*
 * function: func_021BF728
 * address:  0x021BF728
 * packet:   pkt_ov210_021BF728
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * unblocked: FRAME_LIST_GetCursor/021B93B8/021B93C0 are unlabelled leaves in
 *           ov067 (the overlay paired with ov210); matched bottom-up and
 *           filed as pkt_021B93B0 / pkt_021B93B8 / pkt_021B93C0, so the
 *           `ov067` token resolves all three call sites as `matched,
 *           overlay`.  Extent runs 136 against 134 compiled: the
 *           unlabelled follower.
 *
 * symbols:
 *   FRAME_LIST_GetCursor  0x021B93B0  thumb ov067
 *   FRAME_LIST_GetScrollPos  0x021B93B8  thumb ov067
 *   FRAME_LIST_CanScrollDown  0x021B93C0  thumb ov067
 *   func_021BEDB8  0x021BEDB8  thumb ov210
 *   func_021BEDD0  0x021BEDD0  thumb ov210
 */
#include "../include/Obj08414.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int FRAME_LIST_GetCursor(char *p);
extern int FRAME_LIST_GetScrollPos(char *p);
extern int FRAME_LIST_CanScrollDown(char *p);
extern void func_021BEDB8(int p, int i, int v);
extern int func_021BEDD0(int p, int i);

void func_021BF728(u8 *p, int a)
{
    int r6 = FRAME_LIST_GetCursor((char *)(((struct Obj08414 *)p)->f1E0));

    if (func_021BEDD0((int)p, 6) != 0xC || a == 0) {
        if (FRAME_LIST_GetScrollPos((char *)(((struct Obj08414 *)p)->f1E0)) == 0 && r6 == 0)
            func_021BEDB8((int)p, 6, 0x12);
        else
            func_021BEDB8((int)p, 6, 4);
    }
    if (func_021BEDD0((int)p, 5) != 0xD || a == 0) {
        if (FRAME_LIST_CanScrollDown((char *)(((struct Obj08414 *)p)->f1E0)) == 0 &&
            r6 == ((struct Obj08414 *)p)->f2AC - 1)
            func_021BEDB8((int)p, 5, 0x13);
        else
            func_021BEDB8((int)p, 5, 5);
    }
}
