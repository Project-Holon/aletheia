/*
 * function: func_021F4134
 * address: 0x021F4134
 * packet: pkt_ov039_021F4134
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021F4184 0x021F4184 thumb ov039
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201210C(void *p);
extern u32 func_02188C80(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EC4(u32 a);
extern u8 *func_0200B3A4(u32 a, u32 i);
extern void func_021F4184(u8 *p, u8 i);
void func_021F4134(void *p, u32 i) { func_021F4184(func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(func_0201210C(p)))), 2), i); }
