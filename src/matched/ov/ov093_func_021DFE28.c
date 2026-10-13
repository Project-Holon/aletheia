/*
 * function: HAND_ITEM_EjectButtonAfterDamage
 * address:  0x021DFE28
 * packet:   pkt_ov093_021DFE28
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   HAND_COMMON_IsMoveTarget  0x021E85F8  thumb  ov093
 *   BTL_SERVER_FLOW_IsPokeAfflictedByStatus  0x021C8374  thumb  ov093
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb  ov093
 *   BTL_SERVER_FLOW_TestStateFlagBit0  0x021C830C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckClientHasBackupPoke  0x021C7F24  thumb  ov093
 *   BTL_SERVER_FLOW_TrySetOnceFlag  0x021C7F4C  thumb  ov093
 *   HAND_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */
extern int BTL_EVENT_GetVar(int key);
extern int HAND_COMMON_IsMoveTarget(int id);
typedef unsigned char  u8;
struct Flag;
extern int BTL_SERVER_FLOW_IsPokeAfflictedByStatus(u8 *p, int i);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(u8 *p);
extern unsigned int BTL_SERVER_FLOW_TestStateFlagBit0(u8 *p);
extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(u8 *p, int i);
extern int BTL_SERVER_FLOW_TrySetOnceFlag(struct Flag *p);
extern void HAND_ITEM_PushUseItem(void *a, void *b, int c);

void HAND_ITEM_EjectButtonAfterDamage(int a, void *b, int c)
{
    if (HAND_COMMON_IsMoveTarget(c) != 0 && BTL_EVENT_GetVar(0x4d) == 0 && BTL_SERVER_FLOW_IsPokeAfflictedByStatus(b, c) == 0
        && BTL_SERVER_FLOW_CheckShowdownThunk(b) == 0 && BTL_SERVER_FLOW_TestStateFlagBit0(b) == 0 && BTL_SERVER_FLOW_CheckClientHasBackupPoke(b, c) != 0
        && BTL_SERVER_FLOW_TrySetOnceFlag(b) != 0) {
        HAND_ITEM_PushUseItem((void *)a, (void *)((int)b), c);
    }
}
