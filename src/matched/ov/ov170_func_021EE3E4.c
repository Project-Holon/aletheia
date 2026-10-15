/*
 * function: BOX2_UI_SetCursorPos
 * address:  0x021EE3E4
 * packet:   pkt_ov170_021EE3E4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202616C 0x0202616C thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 */
#include "../include/Obj24035.h"

typedef unsigned int   u32;
extern void *func_0202616C(void **obj, u32 idx);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);

void BOX2_UI_SetCursorPos(char **p, unsigned idx)
{
    unsigned char *c = func_0202616C(((struct Obj24035 *)(p[11]))->f70, idx);
    BOX2_SEQ_AddActorSurfacePos(p[11], 4, c[0], c[1], 0);
}
