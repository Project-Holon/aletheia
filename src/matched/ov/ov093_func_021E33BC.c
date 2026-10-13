/*
 * function: HAND_WAZA_NaturalGiftOnWazaPower
 * address:  0x021E33BC
 * packet:   pkt_ov093_021E33BC
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
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_NaturalGiftOnWazaPower(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x30, BTL_CALC_GetMonParamWithHeap((void *)((u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(a, b))), 0xb));
}
