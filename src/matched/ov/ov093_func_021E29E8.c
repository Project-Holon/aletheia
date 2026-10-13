/*
 * unit:     yes
 * function: HAND_WAZA_WringOutOnWazaPower, HAND_WAZA_AddBrine
 * address:  0x021E29E8
 * packet:   pkt_ov093_021E29E8
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
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_CALC_MulRatioMin1  0x021D7B2C  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gBrineHandlers     0x021F24AC  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct Rat;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetHpRatioFixed(struct Rat *p);
extern u32 BTL_CALC_MulRatioMin1(u32 a, u32 b);
extern int BTL_EVENT_OverwriteVar(int key, u32 v);
extern int gBrineHandlers[];

void HAND_WAZA_WringOutOnWazaPower(int a, void *b, int c)
{
    u32 r;

    if (c == BTL_EVENT_GetVar(3)) {
        r = BTL_CALC_MulRatioMin1(0x78, BTL_POKEPARAM_GetHpRatioFixed(BTL_SERVER_FLOW_GetPokeParam(b, (u8)BTL_EVENT_GetVar(4)))) / 100;
        if (r == 0)
            r = 1;
        BTL_EVENT_OverwriteVar(0x30, r);
    }
}

int *HAND_WAZA_AddBrine(int *p)
{
    *p = 1;
    return gBrineHandlers;
}
