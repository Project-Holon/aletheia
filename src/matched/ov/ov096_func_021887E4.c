/*
 * function: TR_AI_CmdIfHpNotEqual
 * address: 0x021887E4
 * packet: pkt_ov096_021887E4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareHpRatio 0x021887F4 thumb ov096
 */
#include "../include/Obj21923.h"
struct Cursor;
extern int TR_AI_CompareHpRatio(struct Cursor *a, int b, int c);
int TR_AI_CmdIfHpNotEqual(struct Cursor *a, int b)
{
    TR_AI_CompareHpRatio(a, b, 3);
    return ((struct Obj21923 *)((unsigned int)b))->fC4;
}
