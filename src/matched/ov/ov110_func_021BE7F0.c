/*
 * function: func_021BE7F0
 * address: 0x021BE7F0
 * packet: pkt_ov110_021BE7F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3918 0x021C3918 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 */
extern const unsigned char d_021C3918[];
extern int TOUCHPANEL_HitTrg(const void *);
int func_021BE7F0(void) { return TOUCHPANEL_HitTrg(d_021C3918); }
