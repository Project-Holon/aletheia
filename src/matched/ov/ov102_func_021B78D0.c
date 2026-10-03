/*
 * function: func_021B78D0
 * address: 0x021B78D0
 * packet: pkt_ov102_021B78D0
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7BC0 0x021B7BC0 thumb ov102
 */
struct Node; extern void func_02030EAC(struct Node *); extern void func_021B7BC0(void *);
void func_021B78D0(void *p) { func_02030EAC(*(struct Node **)((char *)p+0x90)); func_021B7BC0(p); }
