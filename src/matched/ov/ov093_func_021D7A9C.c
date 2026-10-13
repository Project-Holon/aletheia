/*
 * function: BTL_CALC_ListResistingTypes
 * address: 0x021D7A9C
 * packet: pkt_ov093_021D7A9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlCalcTypeAffinityTable 0x021F047C data ov093 a1
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 gBtlCalcTypeAffinityTable[17][17];
u8 BTL_CALC_ListResistingTypes(int a,u8 *out) { u8 n,i; i=0; n=0; do { if(gBtlCalcTypeAffinityTable[a][i]==0 || gBtlCalcTypeAffinityTable[a][i]==2) out[n++]=i; ++i; } while(i<17); return n; }
