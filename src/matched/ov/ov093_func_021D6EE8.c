/*
 * function: func_021D6EE8
 * address: 0x021D6EE8
 * packet: pkt_ov093_021D6EE8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021F3CB0 0x021F3CB0 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Node { struct Node *prev, *next; u8 pad[0x10]; u32 flags; } Node;
extern struct { u32 tick; Node *head; } g_021F3CB0;
void func_021D6EE8(void)
{
    Node *n;
    for (n = g_021F3CB0.head; n != 0; n = n->next) n->flags &= 0xfdffffff;
}
