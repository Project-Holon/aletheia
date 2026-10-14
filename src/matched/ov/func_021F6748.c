/*
 * function: WORLDTRADE_BOX_CalcLevel
 * address:  0x021F6748
 * packet:   pkt_021F6748
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb  arm9
 *

 * Store the query byte at +3 of the second argument.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 POKE_TOOL_CalcBoxLevel(void *p);

void WORLDTRADE_BOX_CalcLevel(u32 a, u8 *q)
{
    q[3] = POKE_TOOL_CalcBoxLevel((void *)a);
}
