/*
 * function: func_021BE890
 * address: 0x021BE890
 * packet: pkt_ov110_021BE890
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C39C4 0x021C39C4 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 */
typedef struct { unsigned char b[16]; } Box;
extern const Box d_021C39C4;
extern int TOUCHPANEL_HitTrg(const void *);
int func_021BE890(void *a0) { Box box=d_021C39C4; return TOUCHPANEL_HitTrg(&box); }
