/*
 * function: TR_AI_CmdIfMoveParam28NotEqual
 * address: 0x0218907C
 * packet: pkt_ov096_0218907C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareMoveParam28 0x0218908C thumb ov096
 */
#include "../include/Obj21949.h"
typedef unsigned char u8;
extern void TR_AI_CompareMoveParam28(u8 *, int, int);
int TR_AI_CmdIfMoveParam28NotEqual(u8 * a, int b)
{
    TR_AI_CompareMoveParam28(a, b, 3);
    return ((struct Obj21949 *)b)->fC4;
}
