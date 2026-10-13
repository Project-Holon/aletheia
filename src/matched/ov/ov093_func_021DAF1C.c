/*
 * function: HAND_TOKUSEI_FlashFireClearFlag
 * address: 0x021DAF1C
 * packet: pkt_ov093_021DAF1C
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
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 */
#include "../include/Obj13469.h"
extern int BTL_EVENT_GetVar(int);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *,unsigned int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *,int,int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *,void *);
void HAND_TOKUSEI_FlashFireClearFlag(int a, int *b, int c) { char *p; if (c == BTL_EVENT_GetVar(2) && BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(b,c),13)) { p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b,24,c); p[8] = c; ((struct Obj13469 *)p)->f4 = 13; BTL_SERVER_FLOW_CommitCmdRecord((char *)b,p); } }
