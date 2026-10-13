/*
 * function: func_0203F684
 * address:  0x0203F684
 * packet:   pkt_0203F540
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FX_SinCosTable_   0x020A1B38  data
 *
 * Fixed-point sine lookup: 4096-entry table at 0x020A1B38 (a flat signed
 * halfword array of interleaved pairs), indexed by (x mod 360) scaled to
 * 0xFFFF with the quotient taken against 360 again and shifted right by 4.
 * func_0203F6D8 is the identical twin at index `2 * i + 1`.
 *
 * Two details are load-bearing and cost real time:
 *
 *   - the argument is `int`, not `unsigned`.  The original opens with
 *     `lsr r1, r0, #0x1f` (the sign word) and closes the magic multiply with
 *     `add lr, r1, lr, asr #8` - the signed division shape.  The unsigned
 *     spelling compiles to `umull` against a different magic (0x6C16C16D)
 *     and is a whole-function diff.
 *   - the trailing scale is the shift `>> 4`, not a division by 16.  `/ 16`
 *     compiles to an exactness-corrected sequence (`asr r0, r2, #3` plus
 *     `add r0, r2, r0, lsr #28`), four instructions longer than the
 *     original's single `asr r1, r2, #4`.
 *
 * The 0xB60BB7 word in the pool is the compiler's own magic for /360 in the
 * `+x, asr #8` form - it is not a source-level constant and cannot be
 * matched by writing the constant out.  The table pointer resolves as
 * `literal` (x113).
 *
 * Addresses are Black-image addresses.
 */

typedef short s16;
typedef int   s32;

extern s16 FX_SinCosTable_[];

short func_0203F684(unsigned short x)
{
    return FX_SinCosTable_[2 * ((((x % 360) * 0xFFFF) / 360) >> 4)];
}
