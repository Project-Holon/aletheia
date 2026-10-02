/*
 * function: func_021DC820
 * address: 0x021DC820
 * packet: pkt_ov093_021DC820
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: scalar u16/u8 stack inputs; named result preserves cmp operand order.
 * symbols:
 *   func_021D70AC 0x021D70AC thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 func_021D70AC(u8 *);
extern u8 func_021B9A40(unsigned int);
int func_021DC820(u8 *a, int b, int c, int d, u16 e, u8 f) { u8 result; if (c == 2) { result = func_021B9A40(func_021D70AC(a)); if (result != f && e <= 3) return 1; } return 0; }
