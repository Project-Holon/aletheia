/*
 * function: func_021599EC
 * address:  0x021599EC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * For every one of the three 0xc-byte records whose +0x70 triple is zero,
 * pulls the +0x7c triple down into +0x70 and clears +0x7c.
 *
 * symbols:
 *

 */

struct S { int a, b, c; };

void func_021599EC(char *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        char *e = p + i * 0xc;

        if (*(int *)(e + 0x70) == 0) {
            *(struct S *)(e + 0x70) = *(struct S *)(e + 0x7c);
            *(int *)(e + 0x7c) = 0;
        }
    }
}


