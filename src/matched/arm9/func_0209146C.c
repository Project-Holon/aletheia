/*
 * function: func_0209146C
 * address:  0x0209146C
 * packet:   pkt_020913FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020913D0  0x020913D0  arm
 *   func_020923B0  0x020923B0  arm
 */

typedef unsigned int u32;

extern void *func_020913D0(u32 heap);
extern void *func_020923B0(void *p, int c, u32 n);

void *func_0209146C(u32 a0, u32 a1)
{
    u32 size = a1;
    void *p;

    size = size * a0;
    p = func_020913D0(size);
    if (p != 0)
        func_020923B0(p, 0, size);
    return p;
}
