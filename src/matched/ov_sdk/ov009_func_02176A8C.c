/*
 * function: func_02176A8C
 * address:  0x02176A8C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores both words the call returns into the module state block.
 *
 * symbols:
 *   g_021AAA20  0x021AAA20  data
 */

extern char g_021AAA20[];
extern unsigned long long func_020870D0(int a);

void func_02176A8C(int a, int b)
{
    unsigned long long v = func_020870D0(a);

    *(int *)(g_021AAA20 + 0x18) = (int)v;
    *(int *)(g_021AAA20 + 0x1c) = (int)(v >> 32);
}

