/*
 * function: TR_AI_CmdIfHpEqual
 * address: 0x021887D4
 * packet: pkt_ov096_021887D4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareHpRatio 0x021887F4 thumb ov096
 */
#include "../include/Obj21922.h"
struct Cursor;
extern int TR_AI_CompareHpRatio(struct Cursor *a, int b, int c);
int TR_AI_CmdIfHpEqual(struct Cursor *a, int b)
{
    TR_AI_CompareHpRatio(a, b, 2);
    return ((struct Obj21922 *)((unsigned int)b))->fC4;
}
