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
 * Forwards (p + 0x1e0) to func_02163EB8 and returns the third argument.
 *
 * symbols:
 *   func_02163EB8  0x02163EB8  arm  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void *decrypt(char *p, void *a, void *b)
{
    void func_02163EB8(void *, void *, void *);
    func_02163EB8(p + 0x1e0, a, b);
    return b;
}
