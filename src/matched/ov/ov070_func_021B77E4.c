/*
 * function: func_021B77E4
 * address: 0x021B77E4
 * packet: pkt_ov070_021B77E4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BADF0 0x021BADF0 thumb ov070
 *   func_021BB0F8 0x021BB0F8 thumb ov070
 *   func_021B6100 0x021B6100 thumb ov070
 *   func_021B7700 0x021B7700 thumb ov070
 */

extern int func_021BADF0(int p);
extern void func_021BB0F8(int p);
extern void func_021B6100(void *p, void *fn);
struct Obj;
extern void func_021B7700(struct Obj *o);
void func_021B77E4(int p) { if (func_021BADF0(p)) { func_021BB0F8(p); func_021B6100((void *)p,(void *)func_021B7700); } }
