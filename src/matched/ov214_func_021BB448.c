/*
 * function: func_021BB448
 * address:  0x021BB448
 * packet:   pkt_021BB448
 * region:   ov214
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 */

extern int func_02048AC4(int);
extern void func_02046788(int);

void func_021BB448(int *p)
{
    func_02046788(func_02048AC4(*p));
}