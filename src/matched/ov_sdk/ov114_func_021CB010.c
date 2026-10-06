/*
 * function: func_021CB010
 * address:  0x021CB010
 * packet:   pkt_ov114_021CB010
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_bn2bin (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CAB94  0x021CAB94  arm  ov114
 *
 * Big-endian byte serialisation; returns the byte count.
 */

typedef struct
{
    unsigned int *d;
    int top;
} BIGNUM;

typedef unsigned char  u8;
extern char *func_021CAB94(u8 *p);

int func_021CB010(BIGNUM *a, unsigned char *to)
{
    int n = (int)func_021CAB94((u8 *)a);
    int i = (n + 7) / 8;
    int j = i - 1;
    if (i <= 0)
        return i;
    do {
        unsigned int l = a->d[j / 4];
        *to++ = (unsigned char)(l >> (8 * (j % 4)));
    } while (j-- > 0);
    return i;
}
