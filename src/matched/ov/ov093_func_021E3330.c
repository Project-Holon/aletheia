/*
 * function: HAND_WAZA_NaturalGiftOnExecuteCheck
 * address:  0x021E3330
 * packet:   pkt_ov093_021E3330
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CanUseHeldItem  0x021C824C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CanUseHeldItem(u8 *p, int v);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_NaturalGiftOnExecuteCheck(int u, void *p, int key)
{
    u16 x;
    int k;
    if (key == BTL_EVENT_GetVar(2)) {
        if (BTL_SERVER_FLOW_CanUseHeldItem(p, key) == 0) {
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
            return;
        }
        x = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(p, key));
        k = 11;
        BTL_CALC_GetMonParamWithHeap((void *)x, k);
        if (x == 0 || BTL_CALC_GetMonParamWithHeap((void *)x, k) == 0)
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
    }
}
