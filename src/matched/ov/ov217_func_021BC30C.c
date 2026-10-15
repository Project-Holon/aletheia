/*
 * function: RESEARCH_LIST_SetScrollTarget
 * address: 0x021BC30C
 * packet: pkt_ov217_021BC30C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   RESEARCH_LIST_GetScrollRangeMax 0x021BC41C thumb ov217
 */
struct S { char pad[0x34]; int f34; int f38; };

typedef unsigned int   u32;
extern u32 RESEARCH_LIST_GetScrollRangeMax(void *p);

void RESEARCH_LIST_SetScrollTarget(struct S *p, int v)
{
    if (v < 0) {
        v = 0;
    }
    if ((int)RESEARCH_LIST_GetScrollRangeMax(p) < v) {
        v = (int)RESEARCH_LIST_GetScrollRangeMax(p);
    }
    p->f38 = p->f34;
    p->f34 = v;
}
