/*
 * function: EVENT_COMM_COMMON_PrintListWindow
 * address: 0x0217F4A0
 * packet: pkt_ov018_0217F4A0
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_COMM_COMMON_SetupListWindow 0x0217F434 thumb ov018
 *   EVENT_COMM_COMMON_PrintToWindow 0x0217F470 thumb ov018
 */
extern void EVENT_COMM_COMMON_SetupListWindow(void **);
extern void EVENT_COMM_COMMON_PrintToWindow(void **, void *, void *, unsigned int, int, int);
void EVENT_COMM_COMMON_PrintListWindow(void **p, unsigned int index, int a, int b)
{
    EVENT_COMM_COMMON_SetupListWindow(p);
    EVENT_COMM_COMMON_PrintToWindow(p, p[3], p[7], index, a, b);
}
