/*
 * function: func_021C7ED8
 * address: 0x021C7ED8
 * packet: pkt_ov093_021C7ED8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B997C 0x021B997C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 func_021B8DDC(u32 x);
extern int func_021B997C(u8 *, unsigned int);
int func_021C7ED8(u8 *p, int i) { return func_021B997C(*(u8 **)(p + 4), func_021B8DDC(i)); }
