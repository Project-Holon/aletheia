/*
 * function: TR_AI_CmdIfContFlag
 * address: 0x02188980
 * packet: pkt_ov096_02188980
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareContFlag 0x021889A0 thumb ov096
 */
#include "../include/Obj21930.h"
struct Cursor;
extern int TR_AI_CompareContFlag(struct Cursor *a, int b, int c);
int TR_AI_CmdIfContFlag(struct Cursor *a, int b)
{
    TR_AI_CompareContFlag(a, b, 2);
    return ((struct Obj21930 *)b)->fC4;
}
