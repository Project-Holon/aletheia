/*
 * function: HAND_WAZA_WhirlpoolOnCalcDamageRatio
 * address:  0x021E1434
 * packet:   pkt_ov093_021E1434
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
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_EVENT_MultiplyVar(int key, s32 m);

void HAND_WAZA_WhirlpoolOnCalcDamageRatio(int a, void *p, int id)
{
    int k;
    if (id == BTL_EVENT_GetVar(3)) {
        k = 4;
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(p, (u8)BTL_EVENT_GetVar(4)), 4)) {
            BTL_EVENT_MultiplyVar(0x35, k << 11);
        }
    }
}
