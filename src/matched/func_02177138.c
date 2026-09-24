/*
 * function: func_02177138
 * address:  0x02177138
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x700 of the block the module pointer holds, and the block again at
 * +0x710 of the second copy the pointer holds, or zero when there is no block.
 *
 * symbols:
 *   g_021AB180  0x021AB180  data
 */

extern char g_021AB180[];

int func_02177138(int a, int b)
{
    int *p = *(int **)g_021AB180;

    if (p == 0)
        return 0;
    *(int *)((char *)p + 0x700) = a;
    *(int *)((char *)*(int **)g_021AB180 + 0x710) = b;
    return 1;
}
