/*
 * function: BTL_CALC_RollCriticalHit
 * address: 0x021D7930
 * packet: pkt_ov093_021D7930
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlCalcCriticalRanges 0x021F041C data a1
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 */
extern unsigned char gBtlCalcCriticalRanges[];
extern unsigned int BTL_CALC_Random(unsigned int);
int BTL_CALC_RollCriticalHit(int i) { if ((unsigned char)BTL_CALC_Random(gBtlCalcCriticalRanges[i]) == 0) return 1; return 0; }
