/*
 * function: HAND_WAZA_CaptivateFailOnSameOrNoGender
 * address:  0x021E1074
 * packet:   pkt_ov093_021E1074
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_CaptivateFailOnSameOrNoGender(int unused, void *q, int id)
{
    void *a;
    void *b;
    u8 t;
    u8 x;
    u8 y;

    if (id == BTL_EVENT_GetVar(3)) {
        t = BTL_EVENT_GetVar(4);
        a = BTL_SERVER_FLOW_GetPokeParam(q, t);
        b = BTL_SERVER_FLOW_GetPokeParam(q, id);
        x = func_021D59B4(b, 0x12);
        y = func_021D59B4(a, 0x12);
        if (x == 2 || y == 2 || x == y)
            BTL_EVENT_OverwriteVar(0x40, 1);
    }
}
