/*
 * function: func_021D3F88
 * address: 0x021D3F88
 * packet: pkt_ov093_021D3F88
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent follower 021D3F98 is already filed separately; bitfield clear produces bics.
 */
typedef unsigned char u8;
struct S { u8 a,b; u8 bit:1; u8 rest:7; };
void func_021D3F88(struct S *p) { p->a=0; p->bit=0; }
