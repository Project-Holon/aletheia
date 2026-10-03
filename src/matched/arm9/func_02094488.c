/*
 * function: func_02094488
 * address:  0x02094488
 * packet:   pkt_02094488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02092344  0x02092344  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_02092344(void *dest, const void *src, unsigned int n);

u32 func_02094488(u8 *p, const void *src, u32 n)
{
    u32 pos = *(u32 *)(p + 8);
    u32 cap = *(u32 *)(p + 4);

    if (pos + n > cap)
        n = cap - pos;
    func_02092344(*(u8 **)p + pos, src, n);
    *(u32 *)(p + 8) += n;
    return 1;
}
