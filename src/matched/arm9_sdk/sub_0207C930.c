/*
 * function: FX_DivAsync
 * address:  0x0207C930
 * packet:   pkt_0207C930
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Start the hardware divider in 64/32 mode: DIVCNT = 1, the 64-bit
 * numerator is (numer << 32) (low word 0, high word the first argument),
 * the 32-bit denominator is the second argument.  The paired reader is
 * FX_GetDivResult, which waits on DIVCNT bit 15 and rounds the result.
 *
 * symbols:
 *   (none; all addresses are constants)
 */

typedef unsigned int   u32;
typedef unsigned short u16;
typedef volatile u32   vu32;
typedef volatile u16   vu16;

void FX_DivAsync(u32 numer, u32 denom)
{
    vu32 *base = (vu32 *)0x04000280;

    *(vu16 *)base = 1;
    base[4] = 0;
    base[5] = numer;
    base[6] = denom;
    base[7] = 0;
}
