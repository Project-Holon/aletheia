/*
 * function: RESEARCH_LIST_AdvanceEndIndex
 * address: 0x021BBD40
 * packet: pkt_ov217_021BBD40
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   RESEARCH_LIST_GetEntryCount 0x021BC6DC thumb ov217
 */
typedef unsigned char u8;

extern int _s32_div_f(int, int);
typedef unsigned int   u32;
extern u32 RESEARCH_LIST_GetEntryCount(void *p);

void RESEARCH_LIST_AdvanceEndIndex(u8 *p, int a)
{
    int base = p[0x32];
    int x = (int)RESEARCH_LIST_GetEntryCount(p);
    int s = base + a;
    p[0x33] = (u8)((s + x) % (int)RESEARCH_LIST_GetEntryCount(p));
}
