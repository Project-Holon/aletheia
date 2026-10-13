/*
 * function: BTL_EVENT_ClearSuspendedFlags
 * address: 0x021D6EE8
 * packet: pkt_ov093_021D6EE8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlEventFactorList 0x021F3CB0 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Node { struct Node *prev, *next; u8 pad[0x10]; u32 flags; } Node;
extern struct { u32 tick; Node *head; } gBtlEventFactorList;
void BTL_EVENT_ClearSuspendedFlags(void)
{
    Node *n;
    for (n = gBtlEventFactorList.head; n != 0; n = n->next) n->flags &= 0xfdffffff;
}
