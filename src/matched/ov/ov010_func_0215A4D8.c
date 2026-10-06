/*
 * function: func_0215A4D8
 * address: 0x0215A4D8
 * packet: pkt_ov010_0215A4D8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 * symbols:
 *   func_020142E8 0x020142E8 thumb
 */
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
extern u32 func_020142E8(void *bitmap, s32 id);
unsigned func_0215A4D8(void *a, unsigned b) { return func_020142E8(a, (u16)(b + 1420)); }
