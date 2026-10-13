/*
 * function: TR_AI_CmdIfRandomNotEqual
 * address: 0x0218874C
 * packet: pkt_ov096_0218874C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareRandom 0x0218875C thumb ov096
 */
#include "../include/Obj21919.h"
typedef unsigned char u8;
struct Cursor;
extern int TR_AI_CompareRandom(struct Cursor *a, int unused, int c);
int TR_AI_CmdIfRandomNotEqual(struct Cursor *a, u8 *b)
{
    TR_AI_CompareRandom(a, (int)b, 3);
    return ((struct Obj21919 *)b)->fC4;
}
