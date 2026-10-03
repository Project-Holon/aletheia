/*
 * function: func_021A3818
 * address:  0x021A3818
 * packet:   pkt_ov021_021A3818
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D3CC(int a0);
extern int func_0216D454();

void func_021A3818(u32 *p)
{
    u32 h = p[7];
    u32 m;
    u32 old = p[4];

    p[4] = 0;
    m = p[5];
    if (func_0216D3CC(h) == 0) {
        switch (m) {
        case 0:
            break;
        case 1:
            if (old == 0 || old == 3)
                p[4] = 1;
            else
                p[4] = 2;
            break;
        case 2:
            p[4] = 2;
            break;
        }
    } else if (func_0216D454(h) == 1) {
        switch (m) {
        case 0:
            break;
        case 1:
            if (old == 0)
                break;
            if (old == 3)
                p[4] = 0;
            else
                p[4] = 3;
            break;
        case 2:
            if (old == 0)
                break;
            if (old == 3)
                p[4] = 0;
            else
                p[4] = 3;
            break;
        }
    }
}
