/*
 * function: func_021AE4E0
 * address:  0x021AE4E0
 * packet:   pkt_ov021_021AE4E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 */

extern void *func_021A3074(unsigned char *p);
extern int func_0216D454(int a0);
extern int func_0216D5A0(int x);

int func_021AE4E0(int *p)
{
    if (func_0216D454(func_021A3074(p[0x34 / 4])) == 0)
        return 0;
    p[0] = 3;
    switch (func_0216D5A0(p[2])) {
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        p[0] = 7;
        break;
    }
    return 1;
}
