/*
 * function: LIVEBATTLEMATCH_IRC_OnFilter
 * address: 0x0217E524
 * packet: pkt_ov176_0217E524
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: callback blocker of LIVEBATTLEMATCH_IRC_StartSession
 * symbols:
 *   d_0217E630 0x0217E630 data a4
 */
extern int d_0217E630;
int LIVEBATTLEMATCH_IRC_OnFilter(int a, int b) { int value = a == b; d_0217E630 = value; return value; }
