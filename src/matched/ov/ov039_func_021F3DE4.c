/*
 * function: func_021F3DE4
 * address: 0x021F3DE4
 * packet: pkt_ov039_021F3DE4
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE4C4 0x021BE4C4 thumb ov021
 *   func_02047828 0x02047828 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BE4C4(void *p, u32 i, int delta);
extern int func_02047828(int h, u32 i, int *out);
int func_021F3DE4(void *p, u8 delta, u16 i) { int v = 0; func_02047828(func_021BE4C4(p, 0, delta), i, &v); return v; }
