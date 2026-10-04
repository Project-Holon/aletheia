/*
 * function: func_021BAA14
 * address: 0x021BAA14
 * packet: pkt_ov072_021BAA14
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
void func_021BAA14(unsigned int *p) { if (*p) func_0204B3B4((struct Obj *)(*p)); func_02082BCC(p,0,0x44); }
