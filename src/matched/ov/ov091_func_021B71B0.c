/*
 * function: func_021B71B0
 * address: 0x021B71B0
 * packet: pkt_ov091_021B71B0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
struct Bank;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B1CC(struct Bank *bank);
void func_021B71B0(unsigned p) { func_0204B3B4(*(void **)(p+480)); func_0204B3B4(*(void **)(p+484)); func_0204B3B4(*(void **)(p+472)); func_0204B3B4(*(void **)(p+476)); func_0204B1CC(*(void **)(p+468)); }
