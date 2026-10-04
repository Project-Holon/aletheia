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
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(u32);

void *func_021D8FA4(void *p, int idx)
{
    u32 v = func_021D8A24(p, idx);
    if (v == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    if (func_0203D1A4((u32)func_020399A8()) == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    return *(void **)((char *)p + (1 - idx) * 4 + 0x5DC);
}
