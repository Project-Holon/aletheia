/*
 * function: func_0218C47C
 * address:  0x0218C47C
 * packet:   pkt_ov021_0218C47C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047828  0x02047828  arm
 */

typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);

int func_0218C47C(int *p, int id)
{
    int out;
    func_02047828((struct AnmCtl *)(*p), (unsigned short)id, &out);
    return out;
}
