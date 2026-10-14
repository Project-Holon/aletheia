/*
 * function: WORLDTRADE_SERVER_StateOpenSavePrompt
 * address:  0x02202038
 * packet:   pkt_02202038
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_SetNextState  0x021F4E98  thumb  ov135
 *   WORLDTRADE_ADAPTER_SetPair  0x0220251C  thumb  ov135

 * Publish the 0x29/0x22 then the 0x25/0x28 pair and report 2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_ADAPTER_SetPair(u8 *p, u16 a, u16 b);

int WORLDTRADE_SERVER_StateOpenSavePrompt(u8 *p)
{
    WORLDTRADE_SetNextState(p, 0x29, 0x22);
    WORLDTRADE_ADAPTER_SetPair(p, 0x25, 0x28);
    return 2;
}
