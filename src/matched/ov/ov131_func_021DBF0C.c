/*
 * function: func_021DBF0C
 * address: 0x021DBF0C
 * packet: pkt_ov131_021DBF0C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204AFD8 0x0204AFD8 arm
 */
extern void func_0204AFD8(int);
void func_021DBF0C(int *p) {
 int i;
 for (i = 0; i < 3; i++) {
  if (p[2 + i] != -1) {
   func_0204AFD8(p[2 + i]);
   p[2 + i] = -1;
  }
 }
}
