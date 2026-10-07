/*
 * function: func_021D7404
 * address: 0x021D7404
 * packet: pkt_ov093_021D7404
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
typedef struct Node { struct Node *prev, *next; u32 pad[2]; int kind; u32 pad14; u32 flags; u8 pad1c[0x1f]; u8 sub; } Node;
extern struct { u32 tick; Node *head; } g_021F3CB0;
void func_021D7404(u32 sub, int kind)
{
    Node *n;
    for (n = g_021F3CB0.head; n != 0; n = n->next) {
        if (n->sub == sub && n->kind == kind) n->flags |= 0x40000000;
    }
}
