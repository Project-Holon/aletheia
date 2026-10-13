/*
 * function: TOWNMAP_CursorSetPos
 * address: 0x021BA3CC
 * packet: pkt_ov072_021BA3CC
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj09905.h"
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void TOWNMAP_CursorSetPos(char *p, int *q) {
    ((struct Obj09905 *)p)->f8 = q[0];
    ((struct Obj09905 *)p)->fA = q[1];
    func_0204B404(((struct Obj09905 *)p)->f0, (const struct Vec2 *)(p + 8), 0);
}
