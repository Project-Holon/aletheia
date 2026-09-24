/*
 * function: func_0217F774
 * address:  0x0217F774
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Refreshes the word the state object holds.
 *
 * symbols:
 *   g_021A37C8  0x021A37C8  data
 *   func_0217F730  0x0217F730  arm  ov009
 */

extern char g_021A37C8[];
extern int func_0217F730(int v);

void func_0217F774(void)
{
    *(int *)g_021A37C8 = func_0217F730(*(int *)g_021A37C8);
}

