/*
 * function: MICTEST_MarkStepDone
 * address: 0x02183D44
 * packet: pkt_ov168_02183D44
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 6-byte body followed by two bytes of zero alignment padding.
 */
void MICTEST_MarkStepDone(unsigned int *p) { p[3]=1; }
