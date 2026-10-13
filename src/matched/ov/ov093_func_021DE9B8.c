/*
 * function: HAND_ITEM_ChoiceScarf_BoostSpeed
 * address: 0x021DE9B8
 * packet: pkt_ov093_021DE9B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: remaining two bytes are zero alignment padding.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
void HAND_ITEM_ChoiceScarf_BoostSpeed(int a,int b,int c) { if(c==BTL_EVENT_GetVar(2)) BTL_EVENT_MultiplyVar(53,6144); }
