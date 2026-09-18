/*
 * function: func_02069128
 * address:  0x02069128
 * packet:   pkt_02068FF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 45 bytes of 92: the rotated outer/inner loop pair, the `v | (hi << 12)` store and the row advance are all present but the inner counter starts at the outer index in the original (`mov r4, r6` / `mov r5, r4`) and the cursor and fill-value registers differ throughout; source shape that starts the inner count from y not found
 *
 * Triangular fill: row y writes w - y halfwords starting at the row origin,
 * the value being the running counter v in the low twelve bits and the top
 * four bits of hi above it (the pair is emitted as one left-twenty-eight
 * shift and a right-sixteen in the `orr`'s shifter operand, which is the
 * narrowing cast folded into the shift).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02069128.c \
 *       --func func_02069128 --addr 0x02069128 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void func_02069128(u16 *dst, int w, int h, int stride, u32 v, u32 hi)
{
    int y;

    if (h == 0)
        return;
    for (y = 0; y < h; y++) {
        int x;
        u16 *row = dst;

        for (x = y; x < w; x++) {
            *row++ = (u16)(v | (hi << 12));
            v++;
        }
        dst += stride;
    }
}
