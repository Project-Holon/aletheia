/*
 * function: WORLDTRADE_TITLE_StateAdvance
 * address:  0x02200490
 * packet:   pkt_02200490
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_SetNextState  0x021F4E98  thumb  ov135

 *
 * Store the 0xa/2 pair and report 2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);

int WORLDTRADE_TITLE_StateAdvance(u8 *p)
{
    WORLDTRADE_SetNextState(p, 0xa, 2);
    return 2;
}
