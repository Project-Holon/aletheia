/*
 * function: HAND_WAZA_EndeavorOnNoEffectCheck
 * address:  0x021E1508
 * packet:   pkt_ov093_021E1508
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
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_EndeavorOnNoEffectCheck(int a, void *p, int id)
{
    void *x;
    void *y;
    u8 t;
    if (id == BTL_EVENT_GetVar(3)) {
        t = BTL_EVENT_GetVar(4);
        x = BTL_SERVER_FLOW_GetPokeParam(p, t);
        y = BTL_SERVER_FLOW_GetPokeParam(p, id);
        if (func_021D59B4(x, 13) - func_021D59B4(y, 13) <= 0) {
            BTL_EVENT_OverwriteVar(0x40, 1);
        }
    }
}
