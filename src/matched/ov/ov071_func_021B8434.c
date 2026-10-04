/*
 * function: func_021B8434
 * address:  0x021B8434
 * packet:   pkt_ov071_021B8434
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub called by func_021B7EE0.
 *
 * symbols:
 *   func_02028484  0x02028484  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Blk;
extern s32 func_02028484(struct Blk *blk, void *h);

int func_021B8434(u8 *p, u8 *q)
{
    return func_02028484((struct Blk *)(p + 0x38), (void *)(*(u32 *)(q + 0x40)));
}
