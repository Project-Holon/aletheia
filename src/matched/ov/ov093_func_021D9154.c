/*
 * function: HAND_TOKUSEI_RecklessBoostRecoilPower
 * address:  0x021D9154
 * packet:   pkt_ov093_021D9154
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_TOKUSEI_RecklessBoostRecoilPower(int u, int a, int b)
{
    u16 t;

    if (b == BTL_EVENT_GetVar(3)) {
        t = BTL_EVENT_GetVar(0x12);
        if (WAZA_TOOL_GetParam(t, 0x1e) != 0 || t == 0x1a || t == 0x88)
            BTL_EVENT_MultiplyVar(0x31, 0x1333);
    }
}
