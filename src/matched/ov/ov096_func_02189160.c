/*
 * function: TR_AI_CmdIfDamageBelow
 * address: 0x02189160
 * packet: pkt_ov096_02189160
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareDamage 0x02189170 thumb ov096
 */
#include "../include/Obj21956.h"
struct Cursor;
extern int TR_AI_CompareDamage(struct Cursor *a, int b, int c);
int TR_AI_CmdIfDamageBelow(struct Cursor *a, int b)
{
    TR_AI_CompareDamage(a, b, 1);
    return ((struct Obj21956 *)b)->fC4;
}
