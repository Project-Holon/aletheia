/*
 * function: CRYPTOi__BN_is_bit_set
 * address:  0x021CB15C
 * packet:   pkt_021CB15C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sCryptoBnNumBitsWordBits  0x021CE202  data
 */

typedef unsigned int u32;

typedef struct
{
    u32 *sCryptoBnNumBitsWordBits;
    int count;
} Bitset;

int CRYPTOi__BN_is_bit_set(Bitset *p, int bit)
{
    int idx;
    int sh;

    if (bit < 0)
        return 0;
    idx = bit / 32;
    sh = bit % 32;
    if (p->count <= idx)
        return 0;
    return (p->sCryptoBnNumBitsWordBits[idx] & (1u << sh)) ? 1 : 0;
}
