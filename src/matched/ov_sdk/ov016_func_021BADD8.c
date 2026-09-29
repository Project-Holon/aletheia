/*
 * function: func_021BADD8
 * address:  0x021BADD8
 * packet:   pkt_ov016_021BADD8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      keywrap_decrypt (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * symbols:
 *   func_021BB290  0x021BB290  thumb  ov016
 *   memcpy  0x02092344  arm
 *   _ull_mul  0x0209C054  arm
 *   func_021BAF90  0x021BAF90  thumb  ov016
 *   func_021BB7DC  0x021BB7DC  thumb  ov016
 *   memcmp  0x020923F0  arm
 *
 * RFC 3394 AES key unwrap, the mirror of keywrap_encrypt (ov016_func_021BAC20.c).
 * The object computes n as (buflen - 1) >> 3 and copies buflen - 1 bytes; both are
 * kept as the object has them.
 */

#include "../arm9_sdk/libc/memcmp/string.h"

#define KW_BSWAP64(x) \
    ((((x) & 0x00000000000000ffULL) << 56) | \
     (((x) & 0x000000000000ff00ULL) << 40) | \
     (((x) & 0x0000000000ff0000ULL) << 24) | \
     (((x) & 0x00000000ff000000ULL) << 8)  | \
     (((x) & 0x000000ff00000000ULL) >> 8)  | \
     (((x) & 0x0000ff0000000000ULL) >> 24) | \
     (((x) & 0x00ff000000000000ULL) >> 40) | \
     (((x) & 0xff00000000000000ULL) >> 56))

extern int func_021BB290(unsigned long *rk, unsigned char *cipherKey, int keyBits);
extern void func_021BB7DC(unsigned long *rk, int Nr, unsigned char *ct, unsigned char *pt);
extern void func_021BAF90(unsigned char *srcA, unsigned char *srcB, unsigned char *dst);

static int func_021BADD8(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen)
{
    unsigned long long xort;
    unsigned char aes_data[16];
    int i;
    int j;
    int n;
    int rounds;
    unsigned long aes_rk[80];
    int status;
    unsigned long long iv;

    status = 1;
    iv = 0xa6a6a6a6a6a6a6a6ULL;
    if ((buflen & 7) || (keylen & 7))
        return 0;
    n = (buflen - 1) >> 3;
    if (n < 2)
        return 0;
    rounds = func_021BB290(aes_rk, (unsigned char *)keyptr, keylen * 8);
    memcpy(aes_data, src, 8);
    src += 8;
    memcpy(dest, src, buflen - 1);
    for (j = 5; j >= 0; j--) {
        for (i = n; i > 0; i--) {
            xort = KW_BSWAP64((unsigned long long)n * j + i);
            func_021BAF90(aes_data, (unsigned char *)&xort, aes_data);
            memcpy(aes_data + 8, dest + (i - 1) * sizeof(iv), 8);
            func_021BB7DC(aes_rk, rounds, aes_data, aes_data);
            memcpy(dest + (i - 1) * sizeof(iv), aes_data + 8, 8);
        }
    }
    if (memcmp(&iv, aes_data, 8))
        status = 0;
    return status;
}
