/*
 * unit:     yes
 * function: HAND_TOKUSEI_MarvelScaleBoostDefense, HAND_TOKUSEI_GetMarvelScaleHandlers
 * address:  0x021D919C
 * packet:   pkt_ov093_021D919C
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
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gMarvelScaleHandlers     0x021F06A8  data   ov093  a4
 */

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int);
typedef signed int     s32;
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern void BTL_EVENT_MultiplyVar(int key, s32 m);
extern int gMarvelScaleHandlers[];

void HAND_TOKUSEI_MarvelScaleBoostDefense(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(4)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(b, c))) {
            BTL_EVENT_GetVar(0x12);
            if (BTL_EVENT_GetVar(0x1a) == 1)
                BTL_EVENT_MultiplyVar(0x35, 0x1800);
        }
    }
}

int *HAND_TOKUSEI_GetMarvelScaleHandlers(int *p)
{
    *p = 1;
    return gMarvelScaleHandlers;
}
