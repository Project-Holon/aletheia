/*
 * function: func_021F80A0
 * address: 0x021F80A0
 * packet: pkt_ov112_021F80A0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F539C 0x021F539C thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F539C(void **p);
void func_021F80A0(int a,u8 *p) { func_021F539C(*(void **)(p+0x58)); *(int *)(p+0x4c)=1; }
