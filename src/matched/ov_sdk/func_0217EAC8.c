/*
 * function: func_0217EAC8
 * address:  0x0217EAC8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the second word of the table at 0x021A3730 on the two arguments.
 *
 * symbols:
 *   g_021A3730  0x021A3730  data
 */

extern char g_021A3730[];

void func_0217EAC8(int a, int b)
{
    (*(void (**)(int, int))(g_021A3730 + 8))(a, b);
}

