/*
 * function: PMS_INPUT_MoveCursor
 * address: 0x021BEB60
 * packet: pkt_ov110_021BEB60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: unlabelled follower 0x021BEB78, filed separately under its own shard.
 * symbols:
 *   gPmsInputCursorMoveFns 0x021C3910 data a4
 */
typedef unsigned char u8;
extern int (*const gPmsInputCursorMoveFns[])(u8 *);
int PMS_INPUT_MoveCursor(u8 *p) { return gPmsInputCursorMoveFns[p[105]](p); }
