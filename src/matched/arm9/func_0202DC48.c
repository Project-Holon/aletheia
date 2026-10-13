/*
 * function: PMS_DRAW_Print
 * address:  0x0202DC48
 * packet:   pkt_0202DC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   PMS_DRAW_PrintOffset  0x0202DC60  thumb
 */

typedef unsigned int u32;

struct Obj;
extern void PMS_DRAW_PrintOffset(struct Obj *p, u32 a, void *w, u32 i, u32 e);

void PMS_DRAW_Print(u32 a, u32 b, u32 c, u32 d)
{
    u32 buf[2] = { 0, 0 };

    PMS_DRAW_PrintOffset((struct Obj *)a, b, (void *)c, d, (u32)buf);
}
