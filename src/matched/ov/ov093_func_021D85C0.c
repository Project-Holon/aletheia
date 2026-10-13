/*
 * unit: yes
 * function: BTL_CALC_RollChanceOrFlag, BTL_CALC_GetIntimidateHandlers
 * address: 0x021D85C0
 * packet: pkt_ov093_021D85C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: 021D85D4 loads r1=1 and 021D85DC compares returned r0.
 * func_021C82B8's legacy void signature is widened here to the observed
 * return; its tail target 021B911C returns zero. Preserve the loaded r1.
 * lever: assigning the boolean to a reuses r4 and preserves the early exit.
 * symbols:
 *   gIntimidateHandlers 0x021F08C0 data ov093 a4
 *   BTL_CALC_RollPercent 0x021D7AF0 thumb ov093
 *   func_021C82B8 0x021C82B8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 gIntimidateHandlers[];
extern int BTL_CALC_RollPercent(u32);
extern int func_021C82B8(int,int);
int BTL_CALC_RollChanceOrFlag(int a,u32 b) { if (BTL_CALC_RollPercent(b)) return 1; a=func_021C82B8(a,1)!=0; return a; }
u8 *BTL_CALC_GetIntimidateHandlers(u32 *p) { *p=2; return gIntimidateHandlers; }
