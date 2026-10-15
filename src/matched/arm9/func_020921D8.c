/*
 * function: __signbitd
 * address:  0x020921D8
 * packet:   pkt_02092144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;
typedef unsigned long long u64;

int __signbitd(double v)
{
    u32 *w = (u32 *)&v;

    return (w[1] & 0x80000000u) ? 1 : 0;
}
