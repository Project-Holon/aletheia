/*
 * function: P_STA_OAM_SwapInts
 * address: 0x021DBE98
 * packet: pkt_ov131_021DBE98
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
void P_STA_OAM_SwapInts(int *a, int *b) {
 int t = *a;
 *a = *b;
 *b = t;
}
