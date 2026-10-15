/*
 * function: RESEARCH_LIST_StepScrollAnim
 * address: 0x021BC2D8
 * packet: pkt_ov217_021BC2D8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   RESEARCH_LIST_SetScrollValue 0x021BC330 thumb ov217
 */
struct S { char pad[0x34]; int f34; int f38; int f3c; int f40; int f44; int f48; };

extern int _s32_div_f(int, int);
typedef unsigned int   u32;
extern void RESEARCH_LIST_SetScrollValue(void *p, u32 v);

void RESEARCH_LIST_StepScrollAnim(struct S *p)
{
    int base = p->f3c;
    int n = p->f48 + 1;
    p->f48 = n;
    RESEARCH_LIST_SetScrollValue(p, base + (p->f40 - base) * n / p->f44);
}
