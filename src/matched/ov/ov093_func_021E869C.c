/*
 * function: BTLV_CORE_CheckPartySlotPair
 * address:  0x021E869C
 * packet:   pkt_ov093_021E869C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   HAND_COMMON_IsItemBoundToSpecies  0x021E8638  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct QF;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int HAND_COMMON_IsItemBoundToSpecies(int a, int b);

int BTLV_CORE_CheckPartySlotPair(void *a, int b)
{
    void *r;
    int t;
    u16 s;

    r = BTL_SERVER_FLOW_GetPokeParam(a, b);
    t = BTL_POKEPARAM_GetSpecies(r);
    s = (int)BTL_POKEPARAM_GetItem(r);
    if (HAND_COMMON_IsItemBoundToSpecies(t, s) != 0)
        return 1;
    return 0;
}
