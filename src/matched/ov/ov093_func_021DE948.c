/*
 * unit: yes
 * function: HAND_ITEM_ChoiceBand_BoostAttack, HAND_ITEM_GetChoiceSpecsHandlers
 * address: 0x021DE948
 * packet: pkt_ov093_021DE948
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DE974.
 * symbols:
 *   gChoiceSpecsHandlers 0x021F18EC data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 */
extern int BTL_EVENT_GetVar(int);
extern int gChoiceSpecsHandlers;
extern void BTL_EVENT_MultiplyVar(int,int);
extern int WAZA_TOOL_GetDamageType(int a);
void HAND_ITEM_ChoiceBand_BoostAttack(int a,int b,int c) { if(c==BTL_EVENT_GetVar(3)) { if(WAZA_TOOL_GetDamageType((unsigned short)BTL_EVENT_GetVar(18))==1) BTL_EVENT_MultiplyVar(53,6144); } }
int *HAND_ITEM_GetChoiceSpecsHandlers(int *p) { *p=3; return &gChoiceSpecsHandlers; }
