/*
 * function: func_021A3B78
 * address:  0x021A3B78
 * packet:   pkt_ov021_021A3B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void *func_021A3960(u8 *p);
int func_0216D598(u32 h);

int func_021A3B78(u8 *p)
{
    int r = func_0216D598(func_021A3960(p));

    if (r == 1 || r == 4)
        return 1;
    return 0;
}
