/*
 * function: BTL_CALC_ApplyStatStage
 * address: 0x021D78E4
 * packet: pkt_ov093_021D78E4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlStatStageRatios 0x021F0448 data a1
 *   _u32_div_f 0x0209C2B0 arm
 */
extern unsigned char gBtlStatStageRatios[][2];
extern unsigned int _u32_div_f(unsigned int, unsigned int);
unsigned short BTL_CALC_ApplyStatStage(unsigned short a, int i) { return _u32_div_f((unsigned short)(a*gBtlStatStageRatios[i][0]), gBtlStatStageRatios[i][1]); }
