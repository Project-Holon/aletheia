/*
 * function: HAND_TOKUSEI_Unburden_DoubleSpeed
 * address:  0x021DBB98
 * packet:   pkt_ov093_021DBB98
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
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_TOKUSEI_Unburden_DoubleSpeed(int u, int a, int b, int *c)
{
    if (b == BTL_EVENT_GetVar(2) && *c == 1) {
        if (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam((int *)a, b)) == 0) {
            BTL_EVENT_MultiplyVar(0x35, 2 << 12);
        }
    }
}
