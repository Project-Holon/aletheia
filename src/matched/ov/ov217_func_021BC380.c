/*
 * function: RESEARCH_LIST_SetListScroll
 * address: 0x021BC380
 * packet: pkt_ov217_021BC380
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   RESEARCH_LIST_GetScrollRange 0x021BC40C thumb ov217
 *   RESEARCH_LIST_SetScrollY 0x021BC3B8 thumb ov217
 */
struct S { char pad[0x34]; int f34; };

typedef unsigned int   u32;
extern int RESEARCH_LIST_GetScrollRange(void *p);
extern void RESEARCH_LIST_SetScrollY(u32 a0);

void RESEARCH_LIST_SetListScroll(struct S *p)
{
    int v = p->f34 - 24;
    if (v < -24) {
        v = -24;
    }
    if (RESEARCH_LIST_GetScrollRange(p) < v) {
        v = RESEARCH_LIST_GetScrollRange(p);
    }
    RESEARCH_LIST_SetScrollY(v);
}
