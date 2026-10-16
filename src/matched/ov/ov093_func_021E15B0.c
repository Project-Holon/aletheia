/*
 * function: HAND_WAZA_LevelDamageOnCalcFixedDamage
 * address:  0x021E15B0
 * packet:   pkt_ov093_021E15B0
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
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_LevelDamageOnCalcFixedDamage(int a, int b, int c)
{
    int n;

    if (c != BTL_EVENT_GetVar(3))
        return;
    n = (unsigned char)BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam((int *)b, c), 15);
    BTL_EVENT_OverwriteVar(55, n);
}
