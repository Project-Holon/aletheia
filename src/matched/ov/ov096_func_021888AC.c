/*
 * function: TR_AI_CmdIfNotSick
 * address: 0x021888AC
 * packet: pkt_ov096_021888AC
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareSick 0x021888BC thumb ov096
 */
#include "../include/Obj21927.h"
struct Cursor;
extern int TR_AI_CompareSick(struct Cursor *a, int b, int c);
int TR_AI_CmdIfNotSick(struct Cursor *a, int b)
{
    TR_AI_CompareSick(a, b, 3);
    return ((struct Obj21927 *)((unsigned int)b))->fC4;
}
