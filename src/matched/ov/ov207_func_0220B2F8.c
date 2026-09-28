/*
 * function: func_0220B2F8
 * address:  0x0220B2F8
 * packet:   pkt_0220B2F8
 * region:   ov207
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 */

extern void func_02040588(int, int);

void func_0220B2F8(int unused, char *p)
{
    if (*(int *)(p + 0x2c) != 0)
    {
        func_02040588(0, 0);
        func_02040588(2, 0);
        *(int *)(p + 0x2c) = 0;
    }
}
