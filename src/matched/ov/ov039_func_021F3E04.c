/*
 * function: func_021F3E04
 * address: 0x021F3E04
 * packet: pkt_ov039_021F3E04
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE4C4 0x021BE4C4 thumb ov021
 *   func_0204784C 0x0204784C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BE4C4(void *p, u32 i, int delta);
extern u32 func_0204784C(int h, u32 i, int *out);
void func_021F3E04(void *p, u8 delta, u16 i, int frame) { func_0204784C(func_021BE4C4(p, 0, delta), i, &frame); }
