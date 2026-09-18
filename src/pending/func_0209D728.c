/*
 * function: func_0209D728
 * address:  0x0209D728
 * packet:   pkt_0209D728
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  the only literal witnesses for g_count (0x02153FB4) and
 *           g_nodePool (0x02153FB8) are this function's own pool words at
 *           0x0209D76C/0x0209D770, inside the compared range, so the
 *           `literal` class refuses both (attest_data_table also fails: the
 *           words stored at 0x02153FB4/8 are a runtime counter and link
 *           fields, not a run of pointers into a region).  The `bl
 *           func_0209D850` at +0038 will resolve via the `matched` class
 *           once pkt_0209D784 is verified, but the two data sites keep this
 *           at MATCH for good.  All 68 bytes of code reproduce the original;
 *           the 8-byte extent tail is the listing's next-label padding.
 *
 * symbols:
 *   g_count      0x02153FB4  data
 *   g_nodePool   0x02153FB8  data
 *
 * Node-pool allocator: hands out slots from a 0x40 x 12-byte pool that ends
 * exactly where the free-list head g_listHead lives (0x02153FB8 + 0x300 ==
 * 0x021542B8, the global func_0209D850 pushes onto).  The guard is
 * equality-only in the bytes (`cmp ip,#0x40; mvneq r0,#0; popeq`), so the
 * source must test `== 0x40`, not `>=`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0209D728.c \
 *       --func func_0209D728 --addr 0x0209D728 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Node
{
    struct Node *next;
    u32 b;
    u32 a;
};

extern u32 g_count;
extern struct Node g_nodePool[0x40];

extern void func_0209D850(u32 a, u32 b, struct Node *node);

u32 func_0209D728(u32 x)
{
    if (g_count == 0x40)
        return -1;

    func_0209D850(0, x, &g_nodePool[g_count++]);
    return 0;
}