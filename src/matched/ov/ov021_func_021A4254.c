/*
 * function: func_021A4254
 * address:  0x021A4254
 * packet:   pkt_ov021_021A4254
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 */

typedef unsigned int u32;

void *func_021A3960(unsigned char *p);
int func_0216D3CC(void *h);
int func_0216D5F8(void *h);

int func_021A4254(u32 *p, int a)
{
    void *h = func_021A3960((unsigned char *)p[3]);

    if (func_0216D3CC(h) == 1)
        return 1;
    if (a != 9 && p[0] == 3 && a != func_0216D5F8(h))
        return 1;
    return 0;
}
