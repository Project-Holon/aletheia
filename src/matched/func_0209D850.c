/*
 * unit:     no
 * function: func_0209D850
 * address:  0x0209D850
 * packet:   pkt_0209D784
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_listHead  0x021542B8  data
 */

typedef unsigned int u32;

struct Node
{
    struct Node *next;
    u32 b;
    u32 a;
};

extern struct Node *g_listHead;

void func_0209D850(u32 a, u32 b, struct Node *node)
{
    node->next = g_listHead;
    node->b = b;
    node->a = a;
    g_listHead = node;
}