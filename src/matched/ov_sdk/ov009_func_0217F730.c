/*
 * function: nextlongrand
 * address:  0x0217F730
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * nextlongrand: one step of the GameSpy Park-Miller LCG (multiplier 16807,
 * modulus 2**31-1), written in 16-bit halves so the product fits a 32-bit
 * register.  The two `if (lo > LONGRAND_MAX)` folds are the compiler's
 * `(x & 0x7fffffff) + (x >> 31)` reduction, emitted as cmn/bic/addhi.
 *
 * Reached from longrand (0x0217F774) <- Util_RandInt (0x0217F7AC) <-
 * gpiEncodeString.
 */

#define RANa         16807
#define LONGRAND_MAX 2147483647L

int nextlongrand(long seed)
{
    unsigned long lo, hi;

    lo = RANa * (unsigned long)(seed & 0xFFFF);
    hi = RANa * ((unsigned long)seed >> 16);
    lo += (hi & 0x7FFF) << 16;
    if (lo > LONGRAND_MAX) {
        lo &= LONGRAND_MAX;
        ++lo;
    }
    lo += hi >> 15;
    if (lo > LONGRAND_MAX) {
        lo &= LONGRAND_MAX;
        ++lo;
    }
    return (int)lo;
}
