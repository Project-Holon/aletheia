/*
 * function: HAND_WAZA_SwallowOnCalcHealRatio
 * address:  0x021E18EC
 * packet:   pkt_ov093_021E18EC
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
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u8 BTL_POKEPARAM_GetCounter(u8 *a, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_SwallowOnCalcHealRatio(int a, void *p, int id)
{
    int two = 2;
    int v;
    if (id == BTL_EVENT_GetVar(2)) {
        switch (BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(p, id), 0)) {
        case 1:
        default:
            v = 1 << 10;
            break;
        case 2:
            v = two << 10;
            break;
        case 3:
            v = two << 11;
            break;
        }
        BTL_EVENT_OverwriteVar(0x35, v);
    }
}
