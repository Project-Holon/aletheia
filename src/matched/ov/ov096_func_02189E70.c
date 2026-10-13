/*
 * function: TR_AI_CmdIfFainted
 * address: 0x02189E70
 * packet: pkt_ov096_02189E70
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareFainted 0x02189E90 thumb ov096
 */
#include "../include/Obj21976.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern int TR_AI_CompareFainted(struct Cursor *a, u8 *b, int c);
int TR_AI_CmdIfFainted(struct Cursor *a, u8 *b)
{
    TR_AI_CompareFainted(a,b,2); return ((struct Obj21976 *)b)->fC4;
}
