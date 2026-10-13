/*
 * function: EVENT_COMM_COMMON_PrintListWindowB
 * address: 0x0217F574
 * packet: pkt_ov018_0217F574
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_COMM_COMMON_PrintToWindow 0x0217F470 thumb ov018
 */
extern void EVENT_COMM_COMMON_PrintToWindow(void **, void *, void *, unsigned int, int, int);
void EVENT_COMM_COMMON_PrintListWindowB(void **p, unsigned int index, int a, int b)
{
    EVENT_COMM_COMMON_PrintToWindow(p, p[5], p[8], index, a, b);
}
