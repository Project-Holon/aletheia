/*
 * function: TR_AI_CmdIfRandomLess
 * address: 0x0218871C
 * packet: pkt_ov096_0218871C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareRandom 0x0218875C thumb ov096
 */
#include "../include/Obj21916.h"
typedef unsigned char u8;
struct Cursor;
extern int TR_AI_CompareRandom(struct Cursor *a, int unused, int c);
int TR_AI_CmdIfRandomLess(struct Cursor *p, int q)
{
    TR_AI_CompareRandom(p, q, 0);
    return ((struct Obj21916 *)q)->fC4;
}
