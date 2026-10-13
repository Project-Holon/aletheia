/*
 * function: HAND_ITEM_PushUseItem
 * address: 0x021DD044
 * packet: pkt_ov093_021DD044
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_KeepFactorRunning 0x021D70C8 thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord 0x021C88B4 thumb ov093
 */
typedef struct Node Node;
extern void BTL_EVENT_KeepFactorRunning(Node *);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *, int, int);
void HAND_ITEM_PushUseItem(void *a, void *b, int c)
{
    BTL_EVENT_KeepFactorRunning(a);
    BTL_SERVER_FLOW_PushCmdRecord(b, 0, c);
}
