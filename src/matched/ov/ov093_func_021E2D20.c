/*
 * function: HAND_WAZA_PresentOnWazaPower
 * address:  0x021E2D20
 * packet:   pkt_ov093_021E2D20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_PresentOnWazaPower(int u, int a, int b)
{
    int x;
    u32 r;

    if (b == BTL_EVENT_GetVar(3)) {
        x = 0x50;
        r = BTL_CALC_Random(0x50);
        if (r < 0x28)
            x = 0x28;
        else if (r >= 0x46)
            x = 0x78;
        BTL_EVENT_OverwriteVar(0x30, x);
    }
}
