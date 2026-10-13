/*
 * function: HAND_TOKUSEI_GutsBoostAttack
 * address:  0x021D8CF4
 * packet:   pkt_ov093_021D8CF4
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
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_TOKUSEI_GutsBoostAttack(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam((int *)a, b)) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 1)
                BTL_EVENT_MultiplyVar(0x35, 3 << 11);
        }
    }
}
