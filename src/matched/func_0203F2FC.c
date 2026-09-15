/*
 * unit:     no
 * function: func_0203F2FC
 * address:  0x0203F2FC
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Additive byte checksum.  The accumulator is declared before the index, so
 * it takes r3 and the index is rematerialised from it with `mov ip, r3`
 * rather than a second `mov #0`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F2FC.c \
 *       --func func_0203F2FC --addr 0x0203F2FC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 func_0203F2FC(const u8 *p, u32 len)
{
    u32 sum = 0;
    u32 i;

    for (i = 0; i < len; i++) {
        sum += p[i];
    }
    return sum;
}
