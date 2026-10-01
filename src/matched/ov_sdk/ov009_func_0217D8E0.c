/*
 * function: func_0217D8E0
 * address:  0x0217D8E0
 * packet:   pkt_ov009_0217D8E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsLargeIntDiv (gslargeint.o)
 *
 * symbols:
 *   func_0217D904                  0x0217D904  arm ov009
 */

typedef unsigned int l_word;
typedef int gsi_bool;

typedef struct gsLargeInt_s {
    l_word mLength;
    l_word mData[64];
} gsLargeInt_t;

extern gsi_bool func_0217D904(const l_word *src1, l_word length1, const gsLargeInt_t *divisor, gsLargeInt_t *dest, gsLargeInt_t *remainder);

gsi_bool func_0217D8E0(const gsLargeInt_t *src1, const gsLargeInt_t *divisor, gsLargeInt_t *dest, gsLargeInt_t *remainder)
{
    return func_0217D904(src1->mData, src1->mLength, divisor, dest, remainder);
}
