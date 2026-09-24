/*
 * function: func_021D97E4
 * address:  0x021D97E4
 * packet:   pkt_021D97E4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E5D40   0x021E5D40  thumb
 *   func_021E89D0   0x021E89D0  thumb
 *   func_021E8A00   0x021E8A00  thumb
 *   func_021E5EF8   0x021E5EF8  thumb
 *   func_021E5F24   0x021E5F24  thumb
 *
 * If the +0x1c block is live, forward it to 0x021E5F24 together with the
 *     function's own second argument, the +0x14 and +0x10 words and the +8
 *     word, plus the literal 0x57.  Six arguments, so the last two ride on the
 *     stack; the two-word frame exists only for them.
 */

typedef unsigned long u32;

extern void func_021E5F24(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);

void func_021D97E4(char *obj, u32 arg)
{
    if (*(u32 *)(obj + 0x1c) != 0)
        func_021E5F24(*(u32 *)(obj + 0x1c), arg, *(u32 *)(obj + 0x14),
                      *(u32 *)(obj + 0x10), *(u32 *)(obj + 8), 0x57);
}

