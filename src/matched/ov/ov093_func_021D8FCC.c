/*
 * function: HAND_TOKUSEI_FlowerGiftBoostAllyAttack
 * address:  0x021D8FCC
 * packet:   pkt_ov093_021D8FCC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_IsCherrim  0x021D8E00  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int HAND_TOKUSEI_IsCherrim(void *a, int b);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
extern int WAZA_TOOL_GetDamageType(int a);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_TOKUSEI_FlowerGiftBoostAllyAttack(int u, int a, int b)
{
    u8 k;

    if (HAND_TOKUSEI_IsCherrim((void *)a, b) != 0 && BTL_SERVER_FLOW_GetEffectiveWeatherThunk((u8 *)a) == 1) {
        k = BTL_EVENT_GetVar(3);
        if (BTL_MAIN_IsPokeSamePair(b, k) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 1)
                BTL_EVENT_MultiplyVar(0x35, 3 << 11);
        }
    }
}
