/*
 * function: HAND_TOKUSEI_Pressure_AddPPCost
 * address:  0x021DB93C
 * packet:   pkt_ov093_021DB93C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   HAND_COMMON_IsMoveTarget  0x021E85F8  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   func_021DB99C  0x021DB99C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);
extern int HAND_COMMON_IsMoveTarget(int c);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern int func_021DB99C(int t);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

static inline void set8(int k, u8 v)
{
    BTL_EVENT_OverwriteVar(k, v);
}

void HAND_TOKUSEI_Pressure_AddPPCost(int a, int b, int x)
{
    int ok;
    u16 t;

    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(3), x) == 0) {
        ok = 0;
        if (HAND_COMMON_IsMoveTarget(x) != 0) {
            ok = 1;
        } else {
            t = BTL_EVENT_GetVar(0x12);
            if (WAZA_TOOL_GetCategory(t) == 10)
                ok = 1;
            else if (func_021DB99C(t) != 0)
                ok = 1;
        }
        if (ok != 0)
            set8(0x20, BTL_EVENT_GetVar(0x20) + 1);
    }
}
