/*
 * unit:     yes
 * function: HAND_WAZA_SurfDoubleDamageVsDiving, HAND_WAZA_GetStompHandlers
 * address:  0x021E39C0
 * packet:   pkt_ov093_021E39C0
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
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gStompHandlers     0x021F2804  data   a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern int gStompHandlers[];

void HAND_WAZA_SurfDoubleDamageVsDiving(int u, void *a, int c)
{
    int n;

    if (c == BTL_EVENT_GetVar(3)) {
        n = 4;
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(a, (u8)BTL_EVENT_GetVar(4)), 4) != 0)
            BTL_EVENT_MultiplyVar(0x35, n << 11);
    }
}

int *HAND_WAZA_GetStompHandlers(int *p)
{
    *p = 1;
    return gStompHandlers;
}
