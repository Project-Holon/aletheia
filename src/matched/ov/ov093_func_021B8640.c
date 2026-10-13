/*
 * function: BTL_MAIN_GetRuleSlotSpan
 * address: 0x021B8640
 * packet: pkt_ov093_021B8640
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
unsigned int BTL_MAIN_GetRuleSlotSpan(unsigned int **p) { switch ((*p)[1]) { case 0:return 1; case 1:return 3; case 2:return 5; case 3:return 5; default:return 5; } }
