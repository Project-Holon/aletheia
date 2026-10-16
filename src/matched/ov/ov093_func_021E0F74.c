/*
 * function: HAND_WAZA_WorrySeedFailOnTruantOrInsomnia
 * address:  0x021E0F74
 * packet:   pkt_ov093_021E0F74
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
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_WorrySeedFailOnTruantOrInsomnia(int unused, void *q, int id)
{
    void *m;
    int k;
    u8 t;

    if (id == BTL_EVENT_GetVar(3)) {
        t = BTL_EVENT_GetVar(4);
        m = BTL_SERVER_FLOW_GetPokeParam(q, t);
        k = 0x11;
        if (BTL_POKEPARAM_GetValue(m, 0x11) == 0x36 || BTL_POKEPARAM_GetValue(m, k) == 0xf)
            BTL_EVENT_OverwriteVar(0x40, 1);
    }
}
