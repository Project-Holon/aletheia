/*
 * function: TR_AI_CmdIfNotKnowsMoveEffectSequence
 * address: 0x021892E8
 * packet: pkt_ov096_021892E8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareKnowsMoveEffectSequence 0x021892F8 thumb ov096
 */
#include "../include/Obj21960.h"
typedef struct Obj Obj;
extern int TR_AI_CompareKnowsMoveEffectSequence(int, Obj *, int);
int TR_AI_CmdIfNotKnowsMoveEffectSequence(int a, Obj * b)
{
    TR_AI_CompareKnowsMoveEffectSequence(a, b, 3);
    return ((struct Obj21960 *)((unsigned int)b))->fC4;
}
