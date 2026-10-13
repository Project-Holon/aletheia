/*
 * function: TR_AI_CmdLoadFieldCountdown
 * address: 0x0218905C
 * packet: pkt_ov096_0218905C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_FIELD_GetCountdownValue 0x021EF884 thumb ov093
 */
#include "../include/Obj13656.h"
extern int BTL_FIELD_GetCountdownValue(void);
int TR_AI_CmdLoadFieldCountdown(int a, unsigned char *b) { ((struct Obj13656 *)b)->f38=BTL_FIELD_GetCountdownValue(); return ((struct Obj13656 *)b)->fC4; }
