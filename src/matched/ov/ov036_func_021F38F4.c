/*
 * function: func_021F38F4
 * address:  0x021F38F4
 * packet:   pkt_ov036_021F38F4
 * region:   ov036
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void func_021F38F4(unsigned char *p)
{
    int i;
    int j;

    p[0x1f] = 14;
    p[0x1e] = 0;
    for (i = 0; i < 15; i++) {
        p[i] = i;
        p[i + 0xf] = 0;
    }
    for (j = 0; j < 7; j++)
        p[0x20 + j] = j;
    for (i = 0; i < 2; i++)
        p[0x27 + i] = i;
    for (i = 0; i < 10; i++)
        p[0x29 + i] = i;
}
