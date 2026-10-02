/*
 * function: func_021D7D9C
 * address: 0x021D7D9C
 * packet: pkt_ov093_021D7D9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
typedef unsigned char u8;
union Slot { u32 raw; struct {u32 kind:3; u32 lo:6; u32 hi:6; u32 rest:17;} s; };
union Slot func_021D7D9C(u32 x) { union Slot s; s.raw=0; s.s.kind=3; s.s.lo=x; return s; }
