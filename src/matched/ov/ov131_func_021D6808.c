/*
 * function: P_STA_SUB_Exit
 * address: 0x021D6808
 * packet: pkt_ov131_021D6808
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_SUB_FreeWindows 0x021D6CDC thumb ov131
 */
extern void P_STA_SUB_FreeWindows(unsigned char *a, unsigned char *b);
void P_STA_SUB_Exit(void *a,void *b) {
 P_STA_SUB_FreeWindows(a,b);
}
