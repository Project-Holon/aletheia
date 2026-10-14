/*
 * function: WORLDTRADE_DEPOSIT_StatePrintGenderPrompt
 * address:  0x021F7CB4
 * packet:   pkt_021F7CB4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_DEPOSIT_PrintMessage  0x021F7538  thumb  ov135
 *   WORLDTRADE_SetNextState  0x021F4E98  thumb  ov135

 * Build through WORLDTRADE_DEPOSIT_PrintMessage and publish the 0x10/0x8 pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_DEPOSIT_PrintMessage(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);

int WORLDTRADE_DEPOSIT_StatePrintGenderPrompt(u8 *p)
{
    WORLDTRADE_DEPOSIT_PrintMessage(p, 0xa, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x10, 0x8);
    return 2;
}
