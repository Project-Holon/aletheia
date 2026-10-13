/*
 * function: TR_AI_CmdIfTargetNotSick11
 * address: 0x02189630
 * packet: pkt_ov096_02189630
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareTargetSick11 0x02189640 thumb ov096
 */
#include "../include/Obj21967.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern int TR_AI_CompareTargetSick11(struct Cursor *a, int b, int c);
int TR_AI_CmdIfTargetNotSick11(u8 *a, u8 *b)
{
    TR_AI_CompareTargetSick11((struct Cursor *)a, (int)b, 3); return ((struct Obj21967 *)b)->fC4;
}
