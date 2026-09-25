/*
 * function: func_021DE34C
 * address:  0x021DE34C
 * packet:   pkt_ov171_021DE34C
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 */

extern void func_0204B3B4(int);

void func_021DE34C(char *p, int i)
{
    if (*(int *)(p + 0xb74 + i * 4) != 0) {
        func_0204B3B4(*(int *)(p + 0xb74 + i * 4));
        *(int *)(p + 0xb74 + i * 4) = 0;
    }
}
