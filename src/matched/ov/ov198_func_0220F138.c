/*
 * function: func_0220F138
 * address:  0x0220F138
 * packet:   pkt_0220F138
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B898 0x0204B898 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 */

extern int func_0204B898(void);
extern void func_0204B8C4(void *, int);
extern void func_0204B878(void *, int);

void func_0220F138(void *a, int b)
{
    if (b != func_0204B898())
    {
        func_0204B8C4(a, 0);
        func_0204B878(a, b);
    }
}
