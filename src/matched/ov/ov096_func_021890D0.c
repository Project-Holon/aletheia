/*
 * function: TR_AI_CmdIfPokeValueGreater
 * address: 0x021890D0
 * packet: pkt_ov096_021890D0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_ComparePokeValue 0x02189100 thumb ov096
 */
#include "../include/Obj21952.h"
struct Cursor;
extern int TR_AI_ComparePokeValue(struct Cursor *a, int b, int c);
int TR_AI_CmdIfPokeValueGreater(struct Cursor *a, int b)
{
    TR_AI_ComparePokeValue(a, b, 1);
    return ((struct Obj21952 *)b)->fC4;
}
