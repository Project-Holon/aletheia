/*
 * function: func_021B6EEC
 * address: 0x021B6EEC
 * packet: pkt_ov071_021B6EEC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 */
struct Grid;
struct Obj020437AC;
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
void func_021B6EEC(void **p) { func_0202570C(p[1]); func_020437AC(p[0]); p[1] = 0; p[0] = 0; }
