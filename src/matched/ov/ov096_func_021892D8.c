/*
 * function: TR_AI_CmdIfKnowsMoveParam28
 * address: 0x021892D8
 * packet: pkt_ov096_021892D8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareKnowsMoveParam28 0x021892F8 thumb ov096
 */
#include "../include/Obj21959.h"
typedef struct Obj Obj;
extern int TR_AI_CompareKnowsMoveParam28(int, Obj *, int);
int TR_AI_CmdIfKnowsMoveParam28(int a, Obj * b)
{
    TR_AI_CompareKnowsMoveParam28(a, b, 2);
    return ((struct Obj21959 *)((unsigned int)b))->fC4;
}
