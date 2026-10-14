/*
 * function: WORLDTRADE_SEARCH_StatePrintConditionPrompt
 * address:  0x021FEEFC
 * packet:   pkt_021FEEFC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_SEARCH_PrintMessage  0x021FF318  thumb  ov135
 *   WORLDTRADE_SetNextState  0x021F4E98  thumb  ov135

 * Build through WORLDTRADE_SEARCH_PrintMessage and publish the 0x10/0xe pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 k, int b, int c, int d);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);

int WORLDTRADE_SEARCH_StatePrintConditionPrompt(u8 *p)
{
    WORLDTRADE_SEARCH_PrintMessage(p, 0xbe, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x17, 0xe);
    return 2;
}
