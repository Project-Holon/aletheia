/*
 * function: GetWord
 * address:  0x021C0370
 * packet:   pkt_ov172_021C0370
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * History: lanes 2026-09-30/10-01 tried ~250 spellings of an early-return
 * little-endian arm and parked it at 7 B as an "operand narrowing tie".
 *
 * wave4 (2026-10-01): closed by the vendor .debug_line of exifdec.o. Rows:
 * 128 cmp/bne; LE 130 (ldrb src[cur], its lsl #16) and 131 (src[cur+1],
 * <<8, &0xff00, its zext16); BE 135/136; 139 bx lr. So the source is the
 * GetLong (0x021C03C0) if/else shape with two statements per arm (the LE
 * orr is attributed to line 136 only because mwcc tail-merges the last orr
 * of both arms, as GetLong's LE orr is attributed to its BE line 157).
 * Plain `word = src[cur];` lets mwcc prove the u16 narrow, both arms become
 * the same tree and the function is if-converted (48 B). The vendor kept a
 * zext16 on line 130, i.e. a masked/widened low byte: `src[cur] & 0x00ff`
 * (mirror of the BE `& 0xff00`). `(int)`, `(short)`, `& 0xffff` and
 * `(src[cur] << 0) & 0x00ff` also close; `(unsigned short)` does not.
 *
 * sdk:      GetWord (exifdec.o)
 *
 * symbols:
 *   (none)
 */

unsigned short GetWord(unsigned char *src, unsigned long cur, short Endian)
{
    unsigned short word;

    if (Endian == 0) {
        word = src[cur] & 0x00ff;
        word |= (src[cur + 1] << 8) & 0xff00;
    } else {
        word = (src[cur] << 8) & 0xff00;
        word |= src[cur + 1];
    }
    return word;
}
