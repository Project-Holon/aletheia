/*
 * function: BOX2_UI_MoveCursorBetweenIcons
 * address:  0x021EEF74
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202616C  0x0202616C  thumb
 *   BOX2_UI_PlaceCursorBetween  0x021EEFA4  thumb  ov170
 *
 * Pull the two tag records through the p+0x70 lookup and hand both
 * pairs to the 0x54/0x10 emitter.
 */
#include "../include/Obj12189.h"

typedef unsigned int   u32;
extern void *func_0202616C(void **obj, u32 idx);
extern void BOX2_UI_PlaceCursorBetween(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty);
void BOX2_UI_MoveCursorBetweenIcons(char *q, int a, int b)
{
    unsigned char *x = func_0202616C((void **)(((struct Obj12189 *)q)->f70), a);
    unsigned char *y = func_0202616C((void **)(((struct Obj12189 *)q)->f70), b);
    BOX2_UI_PlaceCursorBetween(q, x[0], x[1], y[0], y[1]);
}
