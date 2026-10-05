/*
 * function: func_021BE12C
 * address:  0x021BE12C
 * packet:   pkt_021BE12C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02048C4C 0x02048C4C arm
 *   func_02046788 0x02046788 arm
 */

extern int func_02048C4C(int);
extern void func_02046788(int);

void func_021BE12C(int *p)
{
    func_02046788(func_02048C4C(p[1]));
}
