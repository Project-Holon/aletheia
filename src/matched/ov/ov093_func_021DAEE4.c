/*
 * function: HAND_TOKUSEI_FlashFireBoostFireDamage
 * address: 0x021DAEE4
 * packet: pkt_ov093_021DAEE4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: BTL_SERVER_FLOW_GetPokeParam uses its live r0 result and visibly loaded r1;
 * its own legacy file declares void and one parameter. Preserve this
 * caller's observed result and two-argument setup without editing callee.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_POKEPARAM_TestContFlag 0x021D5BDC thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *,unsigned int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void BTL_EVENT_MultiplyVar(int,int);
void HAND_TOKUSEI_FlashFireBoostFireDamage(int a, int *b, int c) { if (c == BTL_EVENT_GetVar(3) && BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(b,c),13) && BTL_EVENT_GetVar(22) == 9) BTL_EVENT_MultiplyVar(53,6144); }
