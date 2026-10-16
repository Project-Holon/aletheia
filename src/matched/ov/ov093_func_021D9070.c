/*
 * function: HAND_TOKUSEI_RivalryScalePower
 * address:  0x021D9070
 * packet:   pkt_ov093_021D9070
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
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_TOKUSEI_RivalryScalePower(int u, int a, int b)
{
    void *p;
    void *q;
    u8 x;
    u8 y;

    if (b == BTL_EVENT_GetVar(3)) {
        p = BTL_SERVER_FLOW_GetPokeParam((int *)a, b);
        q = BTL_SERVER_FLOW_GetPokeParam((int *)a, (u8)BTL_EVENT_GetVar(4));
        x = BTL_POKEPARAM_GetValue(p, 0x12);
        y = BTL_POKEPARAM_GetValue(q, 0x12);
        if (x != 2 && y != 2) {
            if (x == y) {
                BTL_EVENT_MultiplyVar(0x31, 5 << 10);
                return;
            }
            BTL_EVENT_MultiplyVar(0x31, 3 << 10);
        }
    }
}
