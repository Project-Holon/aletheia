/*
 * function: BTL_HANDLER_ITEM_PushUseItem
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
 *   func_021C88B4 0x021C88B4 thumb ov093
 */
typedef struct Node Node;
extern void BTL_EVENT_KeepFactorRunning(Node *);
extern void func_021C88B4(void *, int, int);
void BTL_HANDLER_ITEM_PushUseItem(void *a, void *b, int c)
{
    BTL_EVENT_KeepFactorRunning(a);
    func_021C88B4(b, 0, c);
}
