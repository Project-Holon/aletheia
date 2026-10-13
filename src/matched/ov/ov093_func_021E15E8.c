/*
 * function: HAND_WAZA_PsywaveOnCalcFixedDamage
 * address:  0x021E15E8
 * packet:   pkt_ov093_021E15E8
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
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_PsywaveOnCalcFixedDamage(int a, void *p, int id)
{
    u8 k;
    u16 w;
    u16 r;
    if (id == BTL_EVENT_GetVar(3)) {
        k = func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(p, id), 15);
        w = BTL_CALC_Random(101) + 50;
        r = (k * w) / 100;
        if (r == 0) r = 1;
        BTL_EVENT_OverwriteVar(0x37, r);
    }
}
