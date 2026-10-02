/*
 * function: func_021D7108
 * address: 0x021D7108
 * packet: pkt_ov093_021D7108
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021F3CB0 0x021F3CB0 data a4
 *   func_021D713C 0x021D713C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Node { struct Node *prev, *next; u8 pad[0x10]; u32 flags; } Node;
extern struct { u32 tick; Node *head; } g_021F3CB0;
extern void func_021D713C(void *, int, int, int);
void func_021D7108(void *a, int id, int kind, int check)
{
    Node *n;
    g_021F3CB0.tick++;
    func_021D713C(a, id, kind, check);
    if (--g_021F3CB0.tick == 0) {
        for (n = g_021F3CB0.head; n != 0; n = n->next) n->flags &= 0xffff0000;
    }
}
