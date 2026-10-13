/*
 * function: HAND_ITEM_Metronome_BoostConsecutiveUse
 * address:  0x021DEC70
 * packet:   pkt_ov093_021DEC70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   func_021DED0C  0x021DED0C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMoveStreak  0x021D679C  thumb  ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   HAND_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern int func_021DED0C(u16 v);
struct QL;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetMoveStreak(u8 *p);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern int HAND_ITEM_GetParam(int a, int b);

void HAND_ITEM_Metronome_BoostConsecutiveUse(int a, void *b, int c)
{
    void *m;
    u16 n;
    u16 v;
    u16 id;
    int t;
    float x;

    if (c == BTL_EVENT_GetVar(3)) {
        if (func_021DED0C(BTL_EVENT_GetVar(0x12)) == 0) {
            m = BTL_SERVER_FLOW_GetPokeParam(b, c);
            n = (int)BTL_POKEPARAM_GetMoveStreak(m);
            if (n >= 1) {
                id = BTL_EVENT_GetVar(0x12);
                if (id == BTL_POKEPARAM_GetLastUsedMoveId(m)) {
                    v = n * HAND_ITEM_GetParam(a, 2) + 100;
                    if (v > 200)
                        v = 200;
                    if (v != 0)
                        x = 0.5f + (float)(v << 12);
                    else
                        x = (float)(v << 12) - 0.5f;
                    t = (int)x;
                    BTL_EVENT_MultiplyVar(0x35, t / 100);
                }
            }
        }
    }
}
