/*
 * function: CRYPTOi__BN_num_bits_word
 * address:  0x021CAB34
 * packet:   pkt_ov114_021CAB34
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_num_bits_word (crypto_bobj1.o)
 *
 * symbols:
 *   sCryptoBnNumBitsWordBits  0x021CE202  data
 *
 * The static nibble->bit-count table BN_num_bits_word::sCryptoBnNumBitsWordBits, 16 signed
 * bytes, is pinned at its image address rather than defined locally so the
 * pool word resolves to the vendor object's datum.
 */

typedef unsigned long ulong;

extern const char sCryptoBnNumBitsWordBits[];

int CRYPTOi__BN_num_bits_word(ulong l)
{
    int sh;
    if (l & 0xffff0000UL) {
        if (l & 0xff000000UL)
            sh = 24;
        else
            sh = 16;
    } else {
        if (l & 0xff00UL)
            sh = 8;
        else
            sh = 0;
    }
    l >>= sh;
    if (l & 0xf0)
        return sCryptoBnNumBitsWordBits[l >> 4] + sh + 4;
    return sCryptoBnNumBitsWordBits[l] + sh;
}
