/*
 * function: SAVE_CONTROL_INTR_Pause
 * address: 0x021BD368
 * packet: pkt_ov088_021BD368
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: unlabelled one-pointer game leaf; ov194 021F4AA8 reads context+36 and calls it; neighbouring 021BD374 is already matched in ov088.
 */
void SAVE_CONTROL_INTR_Pause(unsigned char *p){if(p[4]!=3)p[6]=1;}
