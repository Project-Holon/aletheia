/*
 * function: func_021D4648
 * address: 0x021D4648
 * packet: pkt_ov093_021D4648
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Indexed struct arrays preserve scaled-index-before-base-load order.
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_021D4394 0x021D4394 thumb ov093
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct S { u8 pad[0x3ae4]; u32 a[4],b[4]; };
extern struct S *d_021F3B88;
extern u8 func_021D4394(u32);
u32 func_021D4648(u32 a) { u32 r; r=func_021D4394(a); if(r!=40) { if(d_021F3B88->b[r]) return d_021F3B88->a[r]; } return 0; }
