/*
 * function: func_021A1C04
 * address:  0x021A1C04
 * packet:   pkt_ov021_021A1C04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02034A5C  0x02034A5C  arm
 */

typedef unsigned char u8;

void func_02034A5C(int x);

void func_021A1C04(u8 *p)
{
    if (*(int *)(p + 0x28) != -1) {
        func_02034A5C(*(int *)(p + 0x28));
        *(int *)(p + 0x28) = -1;
    }
}
