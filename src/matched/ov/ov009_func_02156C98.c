/*
 * function: func_02156C98
 * address: 0x02156C98
 * packet: pkt_ov009_02156C98
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: sole unresolved overlay blocker of concrete-correct ov115/021D43CC;
 * no ARM9 blocker. Parent confirmed no active assignment owns this leaf.
 * Caller leaves its previous integer result in r0; parameter retained.
 * symbols:
 *   g_021A8264 0x021A8264 data a4
 */
extern unsigned char *g_021A8264;
void func_02156C98(int unused) { g_021A8264[0x7A2]=0; }
