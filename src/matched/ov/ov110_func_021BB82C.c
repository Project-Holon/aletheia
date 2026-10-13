/*
 * function: PMSIV_CATEGORY_IsFadeOutDone
 * address: 0x021BB82C
 * packet: pkt_ov110_021BB82C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_FADE_IsBrightnessDone 0x021BC93C thumb ov110
 */
typedef unsigned char u8;
extern int PMSIV_FADE_IsBrightnessDone(u8 *);
int PMSIV_CATEGORY_IsFadeOutDone(u8 *p) { return PMSIV_FADE_IsBrightnessDone(p+0x18); }
