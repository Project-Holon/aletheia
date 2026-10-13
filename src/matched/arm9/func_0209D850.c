/*
 * unit:     no
 * function: __register_global_object
 * address:  0x0209D850
 * packet:   pkt_0209D784
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     EXACT* not EXACT: scan_listing finds no func_ label between
 *           0x0209D850 and 0x020A8FE6, so target_extent reports 46998 bytes
 *           while the compiled function is 32.  The next real label after
 *           this run of list nodes and descriptor data is far below.
 * symbols:
 *   __global_destructor_chain  0x021542B8  data
 */

typedef unsigned int u32;

struct Node
{
    struct Node *next;
    u32 b;
    u32 a;
};

extern struct Node *__global_destructor_chain;

void __register_global_object(u32 a, u32 b, struct Node *node)
{
    node->next = __global_destructor_chain;
    node->b = b;
    node->a = a;
    __global_destructor_chain = node;
}