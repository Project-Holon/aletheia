/*
 * unit:     no
 * function: func_0209A368
 * address:  0x0209A368
 * packet:   pkt_0209A0EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     EXACT* not EXACT: scan_listing puts the next label 4 bytes past
 *           this function's real end (0x0209A390, a pool-adjacent follower),
 *           so the printed extent is 44 against a compiled 40.  Bytes all
 *           match and there are no relocation sites.
 *
 * MSL copysign(): combines the magnitude of the first double with the sign
 * of the second, reading both hi words off the stack after `push {r0-r3}`
 * (the address-of-a-register-parameter idiom, doubled for two doubles).
 */

typedef unsigned int u32;

double func_0209A368(double x, double y)
{
    ((u32 *)&x)[1] = (((u32 *)&x)[1] & 0x7fffffff) | (((u32 *)&y)[1] & 0x80000000);
    return x;
}