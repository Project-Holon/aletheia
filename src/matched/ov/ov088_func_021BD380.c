/*
 * function: SAVE_CONTROL_INTR_IsPausedOrFinished
 * address: 0x021BD380
 * packet: pkt_ov088_021BD380
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: unlabelled one-pointer game leaf; ov194 021F4AA8 reads context+36 and calls it; neighbouring 021BD374 is already matched in ov088.
 */
int SAVE_CONTROL_INTR_IsPausedOrFinished(unsigned char *p){if(p[7]==1||p[4]==3)return 1;if(p[4]==2)return 1;return 0;}
