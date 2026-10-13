/*
 * function: BTL_HANDLER_ITEM_RollChance
 * address: 0x021DCFD0
 * packet: pkt_ov093_021DCFD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * interface: 021C82B8 forwards r1=2 unchanged to 021B911C; r0 is consumed
 * after the call at 021DCFEA, requiring a result despite its legacy void extern.
 * symbols:
 *   BTL_CALC_RollPercent 0x021D7AF0 thumb ov093
 *   func_021C82B8 0x021C82B8 thumb ov093
 */
extern int BTL_CALC_RollPercent(unsigned int);
extern int func_021C82B8(int *,int);
int BTL_HANDLER_ITEM_RollChance(int *a,unsigned int b) { if(BTL_CALC_RollPercent(b)) return 1; if(func_021C82B8(a,2)) return 1; return 0; }
