/*
 * function: TR_AI_CmdIfNotKnowsMove
 * address: 0x021891E4
 * packet: pkt_ov096_021891E4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareKnowsMove 0x021891F4 thumb ov096
 */
#include "../include/Obj21958.h"
typedef struct Obj Obj;
extern int TR_AI_CompareKnowsMove(int, Obj *, int);
int TR_AI_CmdIfNotKnowsMove(int a, Obj * b)
{
    TR_AI_CompareKnowsMove(a, b, 3);
    return ((struct Obj21958 *)((unsigned int)b))->fC4;
}
