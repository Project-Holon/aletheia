/*
 * function: pow
 * address:  0x0209AB80
 * packet:   pkt_0209AB80
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   __ieee754_pow  0x020979BC  arm
 */

extern void __ieee754_pow(void);

void pow(void)
{
    __ieee754_pow();
}
