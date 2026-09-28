/*
 * function: func_02092144
 * address:  0x02092144
 * packet:   pkt_02092144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 64-bit population count: the four SWAR stages of the standard bit-count
 * idiom over an unsigned long long, then the horizontal fold.  The last three
 * folds are unmasked (`x += x >> 8`, `>> 16`, `>> 32`) because the count of
 * 64 bits can never carry out of a byte, so no 0x00FF00FF mask is needed.
 *
 * The 32-bit halves of the 64-bit shifts are what pin the type: `orr r3, r3,
 * r1, lsl #31` after `lsr r3, r0, #1` is a 64-bit `>> 1`, and `and r2, r2,
 * r1, lsr #1` masks the high word separately.  The three masks are 64-bit
 * constants whose two halves happen to be equal, which is why one pool word
 * each (0x55555555, 0x33333333, 0x0F0F0F0F) serves both words.
 *
 * `x + (x >> 32)` is not emitted as a shift at all: at that point the value
 * is under 0x100, so only the low half matters and mwcc folds the 64-bit add
 * to `adds r0, r1, r0` (low word plus high word) with the carry dropped.
 *
 * The listing extent (148 bytes) includes this function's three-word pool at
 * 0x020921CC..0x020921D4; nothing here is a relocation, so the whole range is
 * compared byte for byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02092144.c \
 *       --func func_02092144 --addr 0x02092144 --cc 1.1p1 --arm
 *   EXACT, 148 bytes, no relocation sites.
 */

typedef unsigned int u32;
typedef unsigned long long u64;

u32 func_02092144(u64 x)
{
    x = x - ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0FULL;
    x = x + (x >> 8);
    x = x + (x >> 16);
    x = x + (x >> 32);
    return (u32)x & 0xFF;
}
