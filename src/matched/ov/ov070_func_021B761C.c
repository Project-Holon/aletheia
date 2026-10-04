/*
 * function: func_021B761C
 * address: 0x021B761C
 * packet: pkt_ov070_021B761C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BADF0 0x021BADF0 thumb ov070
 *   func_021B6100 0x021B6100 thumb ov070
 *   func_021B75A4 0x021B75A4 thumb ov070
 *   func_020061E4 0x020061E4 thumb
 */

extern int func_021BADF0(int p);
extern void func_020061E4(unsigned int id);
extern void func_021B6100(char *p, int k);
struct Obj;
extern void func_021B75A4(struct Obj *o);
void func_021B761C(int p) { if (func_021BADF0(p)) { func_020061E4(0x55C); func_021B6100((void *)p,(int)((void *)func_021B75A4)); } }
