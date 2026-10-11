/*
 * file:     unit_0689C6E4.c
 * function: func_0689C6E4
 * address:  0x0689C6E4
 * packet:   pkt_ov095_0689C6E4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb
 *   func_021D76BC  0x021D76BC  thumb
 */

int func_021D62C4(int a, int b);
void func_021D76BC(int a, int b);

void func_0689C6E4(int unused, int x)
{
    if (func_021D62C4(x, 0x15))
        func_021D76BC(0x41, 1);
    if (func_021D62C4(x, 0x1f))
        func_021D76BC(0x41, 1);
    if (func_021D62C4(x, 0x20) || func_021D62C4(x, 0x1e))
        func_021D76BC(0x51, 1);
}
