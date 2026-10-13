/*
 * function: TR_AI_CmdIfNotSideEffect
 * address: 0x021889F8
 * packet: pkt_ov096_021889F8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareSideEffect 0x02188A08 thumb ov096
 */
#include "../include/Obj21933.h"
struct Cursor;
extern int TR_AI_CompareSideEffect(struct Cursor *a, int b, int c);
int TR_AI_CmdIfNotSideEffect(struct Cursor *a, int b)
{
    TR_AI_CompareSideEffect(a, b, 3);
    return ((struct Obj21933 *)b)->fC4;
}
