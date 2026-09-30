/*
 * function: func_021BEB60
 * address: 0x021BEB60
 * packet: pkt_ov110_021BEB60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: unlabelled follower 0x021BEB78, filed separately under its own shard.
 * symbols:
 *   d_021C3910 0x021C3910 data a4
 */
typedef unsigned char u8;
extern int (*const d_021C3910[])(u8 *);
int func_021BEB60(u8 *p) { return d_021C3910[p[105]](p); }
