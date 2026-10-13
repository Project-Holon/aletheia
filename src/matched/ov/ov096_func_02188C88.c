/*
 * function: func_02188C88
 * address: 0x02188C88
 * packet: pkt_ov096_02188C88
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_FLOW_GetTurnCount 0x021C8138 thumb ov093
 */
#include "../include/Obj10176.h"
struct Q7; extern unsigned short BTL_SERVER_FLOW_GetTurnCount(struct Q7 *);
int func_02188C88(int a, unsigned char *b) { ((struct Obj10176 *)b)->f38=BTL_SERVER_FLOW_GetTurnCount(*(struct Q7 * *)&((struct Obj10176 *)b)->fB4); return ((struct Obj10176 *)b)->fC4; }
