/*
 * function: HAND_ITEM_MicleBerryCheckOnSwitchIn
 * address:  0x021DDF98
 * packet:   pkt_ov093_021DDF98
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
 *   HAND_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   HAND_ITEM_IsHpLowForTrigger  0x021DDE74  thumb  ov093
 *   HAND_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int HAND_ITEM_GetParam(int a, int b);
extern int HAND_ITEM_IsHpLowForTrigger(int a, void *b, int c, unsigned int d);
extern void HAND_ITEM_PushUseItem(void *a, void *b, int c);

void HAND_ITEM_MicleBerryCheckOnSwitchIn(int a, void *b, int c)
{
    u8 j;

    if (c == BTL_EVENT_GetVar(2)) {
        BTL_SERVER_FLOW_GetPokeParam(b, c);
        j = HAND_ITEM_GetParam(a, 2);
        if (HAND_ITEM_IsHpLowForTrigger(a, (void *)((int)b), c, j) != 0)
            HAND_ITEM_PushUseItem((void *)a, (void *)((int)b), c);
    }
}
