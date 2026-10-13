/*
 * function: BTL_ABILITY_TruantStartLoafing
 * address: 0x021DAD58
 * packet: pkt_ov093_021DAD58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * interface: func_021C7CF4 uses its live r0 result and visibly loaded r1;
 * its own legacy file declares void and one parameter. Preserve this
 * caller's observed result and two-argument setup without editing callee.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *,unsigned int);
void BTL_ABILITY_TruantStartLoafing(int a, int *b, int c, int *d) { if (c == BTL_EVENT_GetVar(2)) { if (BTL_POKEPARAM_TestTurnFlag(func_021C7CF4(b,c),0)) *d = 1; } }
