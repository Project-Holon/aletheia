/*
 * function: BTL_SERVER_FLOW_ApplyWeatherDamage
 * address:  0x021C4EA4
 * packet:   pkt_ov093_021C4EA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed  0x021C20BC  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_PushEffectAnim  0x021C70E4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_ProcAbsorbRecovery  0x021C20D0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C8810(u8 *p);
extern int BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(u8 *p, u8 *a, int r);
struct Msg;
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021C8010(u8 *p, u32 x);
extern void BTL_SERVER_FLOW_PushEffectAnim(u8 *p, int a, int b, int c, int e, u32 f);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_SERVER_FLOW_ProcAbsorbRecovery(u8 *p, u8 *a, int c, u8 *l);

void BTL_SERVER_FLOW_ApplyWeatherDamage(u8 *p, u8 *a, int k, int n)
{
    u8 x = BTL_POKEPARAM_GetPokeId(a);
    switch (k) {
    case 4:
        func_021C8838(p + 0x1AE4, 2, 396);
        func_021C8860((struct S *)(p + 0x1AE4), x);
        break;
    case 3:
        func_021C8838(p + 0x1AE4, 2, 399);
        func_021C8860((struct S *)(p + 0x1AE4), x);
        break;
    default:
        func_021C8810(p + 0x1AE4);
        break;
    }
    if (n > 0 && BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(p, a, n) != 0) {
        func_021C99A0(p, (const struct Msg *)(p + 0x1AE4));
        func_021C8810(p + 0x1AE4);
        BTL_SERVER_FLOW_PushEffectAnim(p, 0x290, func_021C8010(p, x), 6, 0, 0);
        if ((int)func_021D59B4(a, 0xd) <= n) {
            BTL_SERVER_FLOW_PushEffectAnim(p, 0x255, 6, 6, 0, 0);
        }
        BTL_SERVER_FLOW_ProcAbsorbRecovery(p, a, n, 0);
    }
}
