/*
 * function: BTL_EVENT_RemoveDeadFactors
 * address: 0x021D701C
 * packet: pkt_ov093_021D701C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlEventFactorList 0x021F3CB0 data a4
 *   BTL_EVENT_RemoveFactor 0x021D7040 thumb ov093
 */
typedef unsigned int u32;
typedef struct Node { struct Node *prev, *next; u32 pad[2]; int kind; } Node;
extern struct { u32 tick; Node *head; } gBtlEventFactorList;
extern void BTL_EVENT_RemoveFactor(Node *);
void BTL_EVENT_RemoveDeadFactors(void)
{
    Node *n;
    Node *next;
    for (n = gBtlEventFactorList.head; n != 0; n = next) {
        next = n->next;
        if (n->kind == 6) BTL_EVENT_RemoveFactor(n);
    }
}
