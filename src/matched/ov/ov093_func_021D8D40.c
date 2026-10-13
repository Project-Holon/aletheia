/*
 * function: HAND_TOKUSEI_PlusMinusBoostSpecialPower
 * address:  0x021D8D40
 * packet:   pkt_ov093_021D8D40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   HAND_TOKUSEI_CheckAllyHasAbility  0x021D8D9C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int HAND_TOKUSEI_CheckAllyHasAbility(void *a, int k, u8 *buf, int v);
extern int WAZA_TOOL_GetDamageType(int a);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_TOKUSEI_PlusMinusBoostSpecialPower(int u, int a, int b, int c)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (HAND_TOKUSEI_CheckAllyHasAbility((void *)a, b, (u8 *)c, 0x39) != 0 || HAND_TOKUSEI_CheckAllyHasAbility((void *)a, b, (u8 *)c, 0x3a) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 2)
                BTL_EVENT_MultiplyVar(0x35, 6 << 10);
        }
    }
}
