/*
 * function: decrypt
 * address:  0x0216176C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Forwards (p + 0x1e0) to CPSi_rc4_crypt and returns the third argument.
 *
 * symbols:
 *   CPSi_rc4_crypt  0x02163EB8  arm  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void *decrypt(char *p, void *a, void *b)
{
    void CPSi_rc4_crypt(void *, void *, void *);
    CPSi_rc4_crypt(p + 0x1e0, a, b);
    return b;
}
