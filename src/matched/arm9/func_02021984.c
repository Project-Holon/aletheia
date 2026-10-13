/*
 * function: PALANM_MaskColorBits
 * address:  0x02021984
 * packet:   pkt_02021984
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Narrows *pv to the channel's own bit width. The width is an 8-bit field of
 * the channel record's word at +8: bits[5:13) for channels 0..3 and
 * bits[9:17) for 4..0xD. The mask is not built with a shift -- the original
 * really does accumulate `1 << n` in a u16 loop, so the source has to be
 * written as the loop, not as `(1 << w) - 1`.
 *
 * Three spellings are load-bearing. The `(u8)` narrowing of the width is
 * applied AFTER the if/else, not inside each arm, so both arms share the
 * `lsrs r4, r0, #0x18` (the shared-exit idiom). `w` is u32, not u8, or the
 * narrowing costs a second shift pair. And the do-while guard must be
 * spelled `if (n < w)` against the already-zeroed counter, not `if (w != 0)`
 * or `if (0 < w)`: only that form emits the original's `bls`, the others
 * emit `beq` -- a single byte, and the last one left in this function.
 *
 * EXACT* only: 62 bytes compiled, listing extent 64; the extra halfword at
 * 0x020219C2 is alignment padding, not an unlabelled follower.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;

struct Chan02021984 {
    u32 f0;
    u32 f4;
    u32 f8;
};

void PALANM_MaskColorBits(s32 idx, struct Chan02021984 *c, u16 *pv)
{
    u32 t;
    u16 m;
    u8 n;
    u32 w;

    if (idx < 4) {
        t = c->f8 << 0x13;
    } else {
        t = c->f8 >> 9 << 0x18;
    }
    w = t >> 0x18;

    m = 0;
    n = 0;
    if (n < w) {
        do {
            m = (u16)(m + (u16)(1 << n));
            n++;
        } while (n < w);
    }

    *pv = *pv & m;
}
