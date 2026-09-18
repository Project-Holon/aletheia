/*
 * unit:     no
 * function: func_0209A504
 * address:  0x0209A504
 * packet:   pkt_0209A0EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL fabs(): the hi word of the double is cleared via `&x`, which is the
 * address-of-a-register-parameter idiom and produces `push {r0-r3}`; the
 * mask folds to `bic r1, r1, #0x80000000`.
 */

typedef unsigned int u32;

double func_0209A504(double x)
{
    ((u32 *)&x)[1] &= 0x7fffffff;
    return x;
}