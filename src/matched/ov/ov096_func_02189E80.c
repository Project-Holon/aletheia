/*
 * function: TR_AI_CmdIfNotFainted
 * address: 0x02189E80
 * packet: pkt_ov096_02189E80
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareFainted 0x02189E90 thumb ov096
 */
#include "../include/Obj21977.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern int TR_AI_CompareFainted(struct Cursor *a, u8 *b, int c);
int TR_AI_CmdIfNotFainted(struct Cursor *a, u8 *b)
{
    TR_AI_CompareFainted(a,b,3); return ((struct Obj21977 *)b)->fC4;
}
