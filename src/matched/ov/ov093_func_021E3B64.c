/*
 * function: HAND_WAZA_ProtectCheckSuccess
 * address:  0x021E3B64
 * packet:   pkt_ov093_021E3B64
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
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   HAND_COMMON_IsLastToAct  0x021E8624  thumb  ov093
 *   gProtectFailRange     0x021F2856  data   a1
 */

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int);
typedef unsigned int   u32;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int HAND_COMMON_IsLastToAct(int a, int b);
extern const u8 gProtectFailRange[];

void HAND_WAZA_ProtectCheckSuccess(int u, void *a, int c)
{
    unsigned x;

    if (c == BTL_EVENT_GetVar(2)) {
        x = BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(a, c), 3);
        if (x != 0) {
            if (x >= 10)
                x = 9;
            if (BTL_CALC_Random(gProtectFailRange[x]) != 0) {
                BTL_EVENT_OverwriteVar(0x22, 0x1a);
                return;
            }
        }
        if (HAND_COMMON_IsLastToAct((int)a, c) != 0)
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
    }
}
