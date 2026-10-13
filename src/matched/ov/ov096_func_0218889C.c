/*
 * function: TR_AI_CmdIfSick
 * address: 0x0218889C
 * packet: pkt_ov096_0218889C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareSick 0x021888BC thumb ov096
 */
#include "../include/Obj21926.h"
struct Cursor;
extern int TR_AI_CompareSick(struct Cursor *a, int b, int c);
int TR_AI_CmdIfSick(struct Cursor *a, int b)
{
    TR_AI_CompareSick(a, b, 2);
    return ((struct Obj21926 *)((unsigned int)b))->fC4;
}
