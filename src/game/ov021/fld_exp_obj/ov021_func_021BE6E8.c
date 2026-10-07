/*
 * function: func_021BE6E8
 * address:  0x021BE6E8
 * packet:   pkt_ov021_021BE6E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE4C4  0x021BE4C4  thumb  ov021
 */

extern void *func_021BE4C4(int a, int b, int c);
typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);

int func_021BE6E8(int a, int b, int c, int d)
{
    int t;

    func_02047828(func_021BE4C4(a, b, c), d, &t);
    return t;
}
