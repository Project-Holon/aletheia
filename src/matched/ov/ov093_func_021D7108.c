/*
 * function: BTL_EVENT_DispatchEventNested
 * address: 0x021D7108
 * packet: pkt_ov093_021D7108
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlEventFactorList 0x021F3CB0 data a4
 *   BTL_EVENT_DispatchToFactors 0x021D713C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Node { struct Node *prev, *next; u8 pad[0x10]; u32 flags; } Node;
extern struct { u32 tick; Node *head; } gBtlEventFactorList;
extern void BTL_EVENT_DispatchToFactors(void *, int, int, int);
void BTL_EVENT_DispatchEventNested(void *a, int id, int kind, int check)
{
    Node *n;
    gBtlEventFactorList.tick++;
    BTL_EVENT_DispatchToFactors(a, id, kind, check);
    if (--gBtlEventFactorList.tick == 0) {
        for (n = gBtlEventFactorList.head; n != 0; n = n->next) n->flags &= 0xffff0000;
    }
}
