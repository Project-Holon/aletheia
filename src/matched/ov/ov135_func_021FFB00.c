/*
 * function: WORLDTRADE_SUBLCD_CheckButtonTouch
 * address: 0x021FFB00
 * packet: pkt_ov135_021FFB00
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_022038BE 0x022038BE data a2
 */
extern int TOUCHPANEL_HitTrg(const void *);
extern char d_022038BE;
int WORLDTRADE_SUBLCD_CheckButtonTouch(int n) { int r=TOUCHPANEL_HitTrg(&d_022038BE); if(r==-1 || r>=n) return -1; return r; }
