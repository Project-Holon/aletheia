/*
 * function: HAND_ITEM_CellBatteryDamageReaction
 * address:  0x021DFDA4
 * packet:   pkt_ov093_021DFDA4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_CanChangeStatStage  0x021D5D14  thumb  ov093
 *   HAND_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
typedef signed char    s8;
extern int BTL_POKEPARAM_CanChangeStatStage(s8 *p, int i, int sign);
extern void HAND_ITEM_PushUseItem(void *a, void *b, int c);

void HAND_ITEM_CellBatteryDamageReaction(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0 && BTL_EVENT_GetVar(0x16) == 0xc) {
        if (BTL_POKEPARAM_CanChangeStatStage(BTL_SERVER_FLOW_GetPokeParam((int *)b, c), 1, 1) != 0) {
            HAND_ITEM_PushUseItem((void *)a, (void *)b, c);
        }
    }
}
