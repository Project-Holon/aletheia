/*
 * function: HAND_TOKUSEI_PinchBoostType
 * address:  0x021D8CAC
 * packet:   pkt_ov093_021D8CAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u32 BTL_CALC_DivideMaxHp(void *p, u32 n);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_TOKUSEI_PinchBoostType(int a, int b, int c)
{
    void *p;
    u32 lim;

    if (b == BTL_EVENT_GetVar(3)) {
        p = BTL_SERVER_FLOW_GetPokeParam((int *)a, b);
        lim = BTL_CALC_DivideMaxHp(p, 3);
        if (BTL_POKEPARAM_GetValue(p, 13) <= lim) {
            if (c == BTL_EVENT_GetVar(22))
                BTL_EVENT_MultiplyVar(0x35, 3 << 11);
        }
    }
}
