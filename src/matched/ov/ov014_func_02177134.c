/*
 * unit: yes
 * function: func_02177134, func_02177140, func_02177148
 * address: 0x02177134
 * packet: pkt_ov014_02177134
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02179628 0x02179628 thumb ov014
 *   func_02177D0C 0x02177D0C thumb ov014
 *   func_021775BC 0x021775BC thumb ov014
 */
extern void func_02179628(unsigned v);
int func_02177134(int a) { func_02179628(a); return 1; }
extern int func_02177D0C(int);
extern int func_021775BC(int);
int func_02177140(int a) { return func_02177D0C(a); }
int func_02177148(int a) { return func_021775BC(a); }
