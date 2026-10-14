/*
 * function: WORLDTRADE_DEPOSIT_PrintLevelRange
 * address:  0x021F8154
 * packet:   pkt_021F8154
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_DEPOSIT_PrintConditionLabel  0x021F8178  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void WORLDTRADE_DEPOSIT_PrintConditionLabel(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);

void WORLDTRADE_DEPOSIT_PrintLevelRange(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g)
{
    WORLDTRADE_DEPOSIT_PrintConditionLabel(win, bank, idx, e, 0, y, color, alt, (u32)g);
}
