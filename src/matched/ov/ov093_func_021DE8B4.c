/*
 * unit:     yes
 * function: HAND_ITEM_SoulDew_BoostSpDefense, HAND_ITEM_GetThickClubHandlers
 * address:  0x021DE8B4
 * packet:   pkt_ov093_021DE8B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gThickClubHandlers     0x021F13A4  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int k);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int gThickClubHandlers;

void HAND_ITEM_SoulDew_BoostSpDefense(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(4)) {
        if ((u32)BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam((int *)a, b)) - 0x17c <= 1) {
            if (BTL_EVENT_GetVar(0x1a) == 2)
                BTL_EVENT_MultiplyVar(0x35, 6 << 10);
        }
    }
}

int *HAND_ITEM_GetThickClubHandlers(int *p)
{
    *p = 1;
    return &gThickClubHandlers;
}
