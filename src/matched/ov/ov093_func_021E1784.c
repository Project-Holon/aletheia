/*
 * function: HAND_WAZA_StockpileUseOnMoveFailCheck
 * address:  0x021E1784
 * packet:   pkt_ov093_021E1784
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
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
typedef unsigned int   u32;
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_StockpileUseOnMoveFailCheck(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2) && BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam((int *)b, c), 0) == 0)
        BTL_EVENT_OverwriteVar(34, 26);
}
