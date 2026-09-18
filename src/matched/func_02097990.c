/*
 * function: func_02097990
 * address:  0x02097990
 * packet:   pkt_02097990
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0209A6E8  0x0209A6E8  arm
 *   func_0209A7A8  0x0209A7A8  arm
 */

typedef unsigned int u32;
typedef unsigned long long u64;

extern u64 func_0209A6E8(u32 a0, u32 a1, u32 *out);
extern u32 func_0209A7A8(u64 v, u32 t);

u32 func_02097990(u32 a0, u32 a1, u32 a2)
{
    u32 t;
    u64 v = func_0209A6E8(a0, a1, &t);

    t += a2;
    return func_0209A7A8(v, t);
}
