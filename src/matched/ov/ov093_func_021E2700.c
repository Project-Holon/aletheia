/*
 * unit:     yes
 * function: HAND_WAZA_RolloutScalePower, HAND_WAZA_TripleKickGetHandlers
 * address:  0x021E2700
 * packet:   pkt_ov093_021E2700
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
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerById  0x021E03F8  thumb  ov093
 *   gTripleKickHandlers     0x021F29C8  data   ov093  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct Cnt { u32 n; int max; };

extern int BTL_EVENT_GetVar(int key);
struct QQ;
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTLV_CORE_EventScaleDamage(int n);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void HAND_WAZA_RemoveMoveHandlerById(int a, int b);
extern int gTripleKickHandlers[];

void HAND_WAZA_RolloutScalePower(void *a, void *b, int c, struct Cnt *d)
{
    void *v;
    u32 i;
    int k;

    if (c == BTL_EVENT_GetVar(3)) {
        v = BTL_SERVER_FLOW_GetPokeParam(b, c);
        k = 1;
        for (i = 0; i < d->n; i++)
            k <<= 1;
        if (BTL_POKEPARAM_TestContFlag(v, 7))
            k <<= 1;
        BTLV_CORE_EventScaleDamage(k);
        d->n++;
        if ((int)d->n >= d->max)
            HAND_WAZA_RemoveMoveHandlerById(c, BTL_EVENT_GetFactorKey(a));
    }
}

int *HAND_WAZA_TripleKickGetHandlers(int *p)
{
    *p = 2;
    return gTripleKickHandlers;
}
