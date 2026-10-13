/*
 * function: HAND_ITEM_RequestUseOnSuperEffectiveHit
 * address:  0x021DDA28
 * packet:   pkt_ov093_021DDA28
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   HAND_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void HAND_ITEM_PushUseItem(void *a, void *b, int c);

void HAND_ITEM_RequestUseOnSuperEffectiveHit(u8 *a, u8 *b, int c)
{
    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0 && BTL_EVENT_GetVar(0x38) > 3
        && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam((int *)b, c), 0xf) == 0)
        HAND_ITEM_PushUseItem(a, b, c);
}
