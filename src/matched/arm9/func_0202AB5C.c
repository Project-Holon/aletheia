/*
 * function: func_0202AB5C
 * address:  0x0202AB5C
 * packet:   pkt_0202AB5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202AC60  0x0202AC60  thumb
 *
 * iss_city_sys.c: an unlabelled forwarding leaf, a pool-word tail call to
 * func_0202AC60 with the caller's arguments passed through untouched.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202AC60(u8 *p, u32 a1);

void func_0202AB5C(u8 *p, u32 a1)
{
    func_0202AC60(p, a1);
}
