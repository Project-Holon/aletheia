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
 * note:     EXACT* not EXACT: scan_listing finds no func_ label between
 *           0x0209D850 and 0x020A8FE6, so target_extent reports 46998 bytes
 *           while the compiled function is 32.  The next real label after
 *           this run of list nodes and descriptor data is far below.
 * symbols:
 *   g_listHead  0x021542B8  data
 */

typedef unsigned int u32;

struct DestructorChain
{
    struct DestructorChain *next;
    u32 destructor;
    u32 object;
};

extern struct DestructorChain *g_listHead;

void func_0209D850(u32 object, u32 destructor, struct DestructorChain *chain)
{
    chain->next = g_listHead;
    chain->destructor = destructor;
    chain->object = object;
    g_listHead = chain;
}