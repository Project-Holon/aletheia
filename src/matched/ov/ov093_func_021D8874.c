/*
 * function: HAND_TOKUSEI_HustleBoostPower
 * address:  0x021D8874
 * packet:   pkt_ov093_021D8874
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
int WAZA_TOOL_GetDamageType(int a);
u32 BTL_CALC_MulRatio(u32 a, u32 b);
int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_TOKUSEI_HustleBoostPower(void *a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 1) {
            BTL_EVENT_OverwriteVar(0x33, BTL_CALC_MulRatio(BTL_EVENT_GetVar(0x33), 3 << 11));
        }
    }
}
