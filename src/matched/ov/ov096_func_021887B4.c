/*
 * function: TR_AI_CmdIfHpLess
 * address: 0x021887B4
 * packet: pkt_ov096_021887B4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareHpRatio 0x021887F4 thumb ov096
 */
#include "../include/Obj21920.h"
struct Cursor;
extern int TR_AI_CompareHpRatio(struct Cursor *a, int b, int c);
int TR_AI_CmdIfHpLess(struct Cursor *a, int b)
{
    TR_AI_CompareHpRatio(a, b, 0);
    return ((struct Obj21920 *)((unsigned int)b))->fC4;
}
