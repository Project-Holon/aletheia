/*
 * function: func_0202E938
 * address:  0x0202E938
 * packet:   pkt_0202E938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02008534  0x02008534  thumb
 *
 * An unlabelled forwarding leaf after func_0202E8D8's pop: a pool-word tail
 * call to func_02008534 (the u16 getter), the caller's argument passed through
 * untouched ("ldr r3, [pc]; bx r3").  Called from the overlays only (see
 * layout/function_starts.txt).
 */

typedef unsigned short u16;

extern u16 func_02008534(void *p);

u16 func_0202E938(void *p)
{
    return func_02008534(p);
}
