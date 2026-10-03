/*
 * function: func_0220D89C
 * address:  0x0220D89C
 * packet:   pkt_0220D89C
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 */

typedef unsigned int   u32;
extern void func_020061E4(u32 a);

void func_0220D89C(char **a, int b)
{
    if (*(int *)(*a + 0x40) == 1)
        func_020061E4(b);
}