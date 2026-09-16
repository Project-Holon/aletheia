/*
 * function: func_020913D0
 * address:  0x020913D0
 * packet:   pkt_020913D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0209138C  0x0209138C  arm
 */

typedef unsigned int u32;

extern void *func_0209138C(u32 heap);

void *func_020913D0(u32 heap)
{
    if (heap == 0)
        return 0;
    return func_0209138C(heap);
}
