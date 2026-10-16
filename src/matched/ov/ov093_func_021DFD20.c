/*
 * function: HAND_ITEM_AbsorbBulbDamageReaction
 * address:  0x021DFD20
 * packet:   pkt_ov093_021DFD20
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
 *   BTL_POKEPARAM_CanChangeStatStage  0x021D5D14  thumb  ov093
 *   HAND_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
typedef signed char    s8;
extern int BTL_POKEPARAM_CanChangeStatStage(s8 *p, int i, int sign);
extern void HAND_ITEM_PushUseItem(void *a, void *b, int c);

void HAND_ITEM_AbsorbBulbDamageReaction(int self, int q, int id)
{
    if (id != BTL_EVENT_GetVar(4))
        return;
    if (BTL_EVENT_GetVar(0x46) != 0)
        return;
    if (BTL_EVENT_GetVar(0x16) != 10)
        return;
    if (BTL_POKEPARAM_CanChangeStatStage(BTL_SERVER_FLOW_GetPokeParam((int *)q, id), 3, 1) == 0)
        return;
    HAND_ITEM_PushUseItem((void *)self, (void *)q, id);
}
