/*
 * function: TR_AI_CmdIfPokeValueNotEqual
 * address: 0x021890F0
 * packet: pkt_ov096_021890F0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_ComparePokeValue 0x02189100 thumb ov096
 */
#include "../include/Obj21954.h"
struct Cursor;
extern int TR_AI_ComparePokeValue(struct Cursor *a, int b, int c);
int TR_AI_CmdIfPokeValueNotEqual(struct Cursor *a, int b)
{
    TR_AI_ComparePokeValue(a, b, 3);
    return ((struct Obj21954 *)b)->fC4;
}
