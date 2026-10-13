/*
 * function: BTL_CALC_ApplyAccuracyStage
 * address: 0x021D7908
 * packet: pkt_ov093_021D7908
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlCalcAccuracyStageRatios 0x021F0462 data a1
 *   _s32_div_f 0x0209C0A4 arm
 */
extern unsigned char gBtlCalcAccuracyStageRatios[][2];
extern int _s32_div_f(int, int);
unsigned char BTL_CALC_ApplyAccuracyStage(int a, int i) { unsigned int v = _s32_div_f(a*gBtlCalcAccuracyStageRatios[i][0], gBtlCalcAccuracyStageRatios[i][1]); if(v>100) v=100; return v; }
