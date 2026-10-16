/*
 * unit:     yes
 * function: HAND_TOKUSEI_CuteCharmOnDamageReaction, HAND_TOKUSEI_AddCuteCharm
 * address:  0x021D9D1C
 * packet:   pkt_ov093_021D9D1C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   HAND_TOKUSEI_TryAddContactSick  0x021D9E08  thumb  ov093
 *   gCuteCharmHandlers     0x021F0838  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(u8 *p);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
typedef struct { u32 raw; } Slot;
extern void BTL_CALC_MakeSickContFromKind(int, void *, Slot *);
extern void HAND_TOKUSEI_TryAddContactSick(void *, int, int, Slot, int);
extern int gCuteCharmHandlers[];

void HAND_TOKUSEI_CuteCharmOnDamageReaction(int a, void *b, int c)
{
    void *q;
    void *r;
    u8 x;
    u8 y;
    Slot s;

    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0 && BTL_SERVER_FLOW_CheckShowdownThunk(b) == 0) {
        q = BTL_SERVER_FLOW_GetPokeParam(b, c);
        r = BTL_SERVER_FLOW_GetPokeParam(b, (u8)BTL_EVENT_GetVar(3));
        x = BTL_POKEPARAM_GetValue(q, 0x12);
        y = BTL_POKEPARAM_GetValue(r, 0x12);
        if (x != 2 && y != 2 && x != y) {
            BTL_CALC_MakeSickContFromKind(7, q, &s);
            HAND_TOKUSEI_TryAddContactSick(b, c, 7, s, 0x1e);
        }
    }
}

int *HAND_TOKUSEI_AddCuteCharm(int *p)
{
    *p = 1;
    return gCuteCharmHandlers;
}
