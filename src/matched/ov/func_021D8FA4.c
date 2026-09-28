/*
 * function: func_021D8FA4
 * address:  0x021D8FA4
 * packet:   pkt_021D8FA4
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_021D8A24(void *, int);
extern u32 func_020399A8(u32);
extern u32 func_0203D1A4(u32);

int func_021D8FA4(void *p, int idx)
{
    u32 v = func_021D8A24(p, idx);
    if (v == 0)
        return *(int *)((char *)p + idx * 4 + 0x5DC);
    if (func_0203D1A4(func_020399A8(v)) == 0)
        return *(int *)((char *)p + idx * 4 + 0x5DC);
    return *(int *)((char *)p + (1 - idx) * 4 + 0x5DC);
}
