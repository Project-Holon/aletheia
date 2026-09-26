/*
 * function: func_0217F7AC
 * address:  0x0217F7AC
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Util_RandInt: longrand() modulo (max-min), offset by min.  max==min returns
 * min without touching the RNG.
 *
 * The `% range` result is bound to a local before adding min: that is what
 * makes the compiler keep min in a callee-saved register and emit the direct
 * `add r0, r1, r5` return instead of a branch plus `mov r0, r5` (and it drops
 * the four-byte conditional-pop epilogue).  The modulo is unsigned (u32),
 * so it calls the runtime division entry at 0x0209C2B0.
 *
 * symbols:
 *   func_0217F774  0x0217F774  arm  ov009
 *   _u32_div_f     0x0209C2B0  arm
 */

extern int func_0217F774(void);

unsigned int func_0217F7AC(unsigned int min, unsigned int max)
{
    unsigned int range = max - min;
    unsigned int r;

    if (range == 0)
        return min;
    r = func_0217F774() % range;
    return r + min;
}
