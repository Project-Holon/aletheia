/*
 * function: TR_AI_CmdIfRandomEqual
 * address: 0x0218873C
 * packet: pkt_ov096_0218873C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareRandom 0x0218875C thumb ov096
 */
#include "../include/Obj21918.h"
typedef unsigned char u8;
struct Cursor;
extern int TR_AI_CompareRandom(struct Cursor *a, int unused, int c);
int TR_AI_CmdIfRandomEqual(struct Cursor *a, u8 *b)
{
    TR_AI_CompareRandom(a, (int)b, 2);
    return ((struct Obj21918 *)b)->fC4;
}
