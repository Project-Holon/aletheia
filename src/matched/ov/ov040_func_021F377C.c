/*
 * function: func_021F377C
 * address: 0x021F377C
 * packet: pkt_ov040_021F377C
 * region: ov040
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02188D2C(int *p);
extern void func_021897A0(u8 *p, int i);
extern void func_021BE418(u8 *p, u16 i);
void func_021F377C(u8 *p) { u8 *q; q = (u8 *)func_02188D2C((int *)p); func_021897A0(p, 1); func_021BE418(q, 0); }
