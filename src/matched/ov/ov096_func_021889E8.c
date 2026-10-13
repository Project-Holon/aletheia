/*
 * function: TR_AI_CmdIfSideEffect
 * address: 0x021889E8
 * packet: pkt_ov096_021889E8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareSideEffect 0x02188A08 thumb ov096
 */
#include "../include/Obj21932.h"
struct Cursor;
extern int TR_AI_CompareSideEffect(struct Cursor *a, int b, int c);
int TR_AI_CmdIfSideEffect(struct Cursor *a, int b)
{
    TR_AI_CompareSideEffect(a, b, 2);
    return ((struct Obj21932 *)b)->fC4;
}
