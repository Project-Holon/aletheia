/*
 * function: TR_AI_CmdIfKnowsMove
 * address: 0x021891D4
 * packet: pkt_ov096_021891D4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareKnowsMove 0x021891F4 thumb ov096
 */
#include "../include/Obj21957.h"
typedef struct Obj Obj;
extern int TR_AI_CompareKnowsMove(int, Obj *, int);
int TR_AI_CmdIfKnowsMove(int a, Obj * b)
{
    TR_AI_CompareKnowsMove(a, b, 2);
    return ((struct Obj21957 *)((unsigned int)b))->fC4;
}
