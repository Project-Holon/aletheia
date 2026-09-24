/*
 * function: func_021EA728
 * address:  0x021EA728
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Sibling of func_021EA1C0 with (0x1c, 0) and the 0x228F buffer.
 */

extern int func_02030734(int, int, int, int, int);


void func_021EA728(void *p)
{
    int v = func_02030734(0x4c, 0x1c, 0, 0x021F140C, 0x228F);
    *(int *)(*(int *)((char *)p + 0x2c) + 0x60) = v;
}
