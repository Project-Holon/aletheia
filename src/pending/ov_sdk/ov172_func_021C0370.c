/*
 * function: func_021C0370
 * address:  0x021C0370
 * packet:   pkt_ov172_021C0370
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * w9_nm: 27 B -> 7 B: `word = (unsigned short)src[cur] | word;` in the little-endian arm makes
 * the big-endian arm byte-identical (branches, not predication, in both arms). Left: the
 * little-endian arm wants zext(word) as the first orr operand and the byte shifted
 * (`lsl r0,r3,#16 ... orr r0,r1,r0,lsr #16`); this compile has the byte plain and the word
 * shifted. Tried: 14 spellings (locals u16, casts, return forms, else nesting, |= vs =, operand order).
 *
 * sdk:      GetWord (exifdec.o)
 *
 * symbols:
 *   (none)
 */

unsigned short func_021C0370(unsigned char *src, unsigned long cur, short Endian)
{
    unsigned short word;

    if (Endian == 0) {
        word = (src[cur + 1] << 8) & 0xff00;
        word = (unsigned short)src[cur] | word;
        return word;
    }
    word = (src[cur] << 8) & 0xff00;
    word |= src[cur + 1];
    return word;
}
