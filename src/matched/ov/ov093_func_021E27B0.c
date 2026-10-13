/*
 * unit:     yes
 * function: HAND_WAZA_GyroBallCalcPower, HAND_WAZA_RevengeGetHandlers
 * address:  0x021E27B0
 * packet:   pkt_ov093_021E27B0
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
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper  0x021C81C8  thumb  ov093
 *   _s32_div_f     0x0209C0A4  arm
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gRevengeHandlers     0x021F2474  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_SERVER_FLOW_CalcPokeSpeedWrapper(u8 *p, u8 *x, int flag);
extern int BTL_EVENT_OverwriteVar(int key, u32 v);
extern int gRevengeHandlers[];

void HAND_WAZA_GyroBallCalcPower(int a, void *b, int c)
{
    void *x;
    void *y;
    int p;
    int q;
    u32 r;

    if (c == BTL_EVENT_GetVar(3)) {
        x = BTL_SERVER_FLOW_GetPokeParam(b, c);
        y = BTL_SERVER_FLOW_GetPokeParam(b, (u8)BTL_EVENT_GetVar(4));
        p = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(b, x, 0);
        q = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(b, y, 0);
        r = q * 25 / p + 1;
        if (r > 0x96)
            r = 0x96;
        BTL_EVENT_OverwriteVar(0x30, r);
    }
}

int *HAND_WAZA_RevengeGetHandlers(int *p)
{
    *p = 1;
    return gRevengeHandlers;
}
