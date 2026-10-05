/*
 * function: func_021E64B8
 * address:  0x021E64B8
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Run the three sub-updates for both halves.
 *
 * symbols:
 *   func_021E62D4  0x021E62D4  thumb
 */

extern void func_021E62D4(void *p, int i, int j);

void func_021E64B8(void *p)
{
    int j, i;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            func_021E62D4(p, i, j);
}

