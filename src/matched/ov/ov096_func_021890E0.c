/*
 * function: TR_AI_CmdIfPokeValueEqual
 * address: 0x021890E0
 * packet: pkt_ov096_021890E0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_ComparePokeValue 0x02189100 thumb ov096
 */
#include "../include/Obj21953.h"
struct Cursor;
extern int TR_AI_ComparePokeValue(struct Cursor *a, int b, int c);
int TR_AI_CmdIfPokeValueEqual(struct Cursor *a, int b)
{
    TR_AI_ComparePokeValue(a, b, 2);
    return ((struct Obj21953 *)b)->fC4;
}
