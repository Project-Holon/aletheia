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
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   HAND_TOKUSEI_TryAddContactSick  0x021D9E08  thumb  ov093
 *   d_021F0838     0x021F0838  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern int func_021C83D4(u8 *p);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
typedef struct { u32 raw; } Slot;
extern void BTL_CALC_MakeSickContFromKind(int, void *, Slot *);
extern void HAND_TOKUSEI_TryAddContactSick(void *, int, int, Slot, int);
extern int d_021F0838[];

void HAND_TOKUSEI_CuteCharmOnDamageReaction(int a, void *b, int c)
{
    void *q;
    void *r;
    u8 x;
    u8 y;
    Slot s;

    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0 && func_021C83D4(b) == 0) {
        q = func_021C7CF4(b, c);
        r = func_021C7CF4(b, (u8)BTL_EVENT_GetVar(3));
        x = func_021D59B4(q, 0x12);
        y = func_021D59B4(r, 0x12);
        if (x != 2 && y != 2 && x != y) {
            BTL_CALC_MakeSickContFromKind(7, q, &s);
            HAND_TOKUSEI_TryAddContactSick(b, c, 7, s, 0x1e);
        }
    }
}

int *HAND_TOKUSEI_AddCuteCharm(int *p)
{
    *p = 1;
    return d_021F0838;
}
