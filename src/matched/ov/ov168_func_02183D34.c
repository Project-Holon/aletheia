/*
 * function: MICTEST_SetStep
 * address: 0x02183D34
 * packet: pkt_ov168_02183D34
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
void MICTEST_SetStep(unsigned int *p,unsigned int v) { p[1]=v; p[2]=0; }
