/*
 * function: func_021CB15C
 * address:  0x021CB15C
 * packet:   pkt_021CB15C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

typedef struct
{
    u32 *bits;
    int count;
} Bitset;

int func_021CB15C(Bitset *p, int bit)
{
    int idx;
    int sh;

    if (bit < 0)
        return 0;
    idx = bit / 32;
    sh = bit % 32;
    if (p->count <= idx)
        return 0;
    return (p->bits[idx] & (1u << sh)) ? 1 : 0;
}
