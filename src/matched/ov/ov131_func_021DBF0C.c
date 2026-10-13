/*
 * function: P_STA_OAM_FreeCellRes
 * address: 0x021DBF0C
 * packet: pkt_ov131_021DBF0C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
void P_STA_OAM_FreeCellRes(int *p) {
 int i;
 for (i = 0; i < 3; i++) {
  if (p[2 + i] != -1) {
   CLACT_ReleaseCellAnim(p[2 + i]);
   p[2 + i] = -1;
  }
 }
}
