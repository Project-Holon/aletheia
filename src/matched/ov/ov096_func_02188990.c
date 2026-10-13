/*
 * function: TR_AI_CmdIfNotContFlag
 * address: 0x02188990
 * packet: pkt_ov096_02188990
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareContFlag 0x021889A0 thumb ov096
 */
#include "../include/Obj21931.h"
struct Cursor;
extern int TR_AI_CompareContFlag(struct Cursor *a, int b, int c);
int TR_AI_CmdIfNotContFlag(struct Cursor *a, int b)
{
    TR_AI_CompareContFlag(a, b, 3);
    return ((struct Obj21931 *)b)->fC4;
}
