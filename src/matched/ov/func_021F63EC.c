/*
 * function: WORLDTRADE_BOX_StatePrintDepositPrompt
 * address:  0x021F63EC
 * packet:   pkt_021F63EC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_BOX_PrintMessage  0x021F663C  thumb  ov135
 *   WORLDTRADE_SetNextState  0x021F4E98  thumb  ov135

 * Build through WORLDTRADE_BOX_PrintMessage and publish the 3/0xc pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_BOX_PrintMessage(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);

int WORLDTRADE_BOX_StatePrintDepositPrompt(u8 *p)
{
    WORLDTRADE_BOX_PrintMessage(p, 0x19, 1, 0, 0xf0f, 1);
    WORLDTRADE_SetNextState(p, 3, 0xc);
    return 2;
}
