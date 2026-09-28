/*
 * function: func_02184234
 * address:  0x02184234
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Guarded forward of a word load: calls func_0218424C(p, a, *p) when p is set.
 *
 * symbols:
 *   func_0218424C  0x0218424C  arm  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void func_02184234(void *p, void *a)
{
    void func_0218424C(void *, void *, void *);
    if (p) func_0218424C(p, a, *(void **)p);
}
