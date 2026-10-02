/*
 * function: func_021A448C
 * address:  0x021A448C
 * packet:   pkt_ov021_021A448C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 */

typedef unsigned int u32;

void *func_021A3960(unsigned char *p);
int func_0216D5F8(u32 h);

int func_021A448C(u32 *p, int a)
{
    int r = func_0216D5F8(func_021A3960(p[3]));

    if (a == 9)
        return 0;
    if (a != r && p[0] != 1 && p[0] != 3)
        return 2;
    return 1;
}
