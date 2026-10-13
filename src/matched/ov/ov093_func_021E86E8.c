/*
 * function: BTLV_CORE_CheckEitherSlotPair
 * address:  0x021E86E8
 * packet:   pkt_ov093_021E86E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_CheckPartySlotCondition  0x021E86C8  thumb  ov093
 *   BTLV_CORE_CheckPartySlotPair  0x021E869C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   HAND_COMMON_IsItemBoundToSpecies  0x021E8638  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTLV_CORE_CheckPartySlotCondition(void *a, int b);
extern int BTLV_CORE_CheckPartySlotPair(void *a, int b);
struct QF;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int HAND_COMMON_IsItemBoundToSpecies(int a, int b);

int BTLV_CORE_CheckEitherSlotPair(void *a, int b, int c)
{
    void *x;
    void *y;
    int t;
    u16 h;

    if (BTLV_CORE_CheckPartySlotCondition(a, b) != 0)
        return 1;
    if (BTLV_CORE_CheckPartySlotPair(a, c) != 0)
        return 1;
    x = BTL_SERVER_FLOW_GetPokeParam(a, b);
    y = BTL_SERVER_FLOW_GetPokeParam(a, c);
    t = BTL_POKEPARAM_GetSpecies(x);
    h = (int)BTL_POKEPARAM_GetItem(y);
    if (HAND_COMMON_IsItemBoundToSpecies(t, h) != 0)
        return 1;
    return 0;
}
