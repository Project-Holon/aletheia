/*
 * function: CROWD_IsTileInFront
 * address:  0x021F4388
 * packet:   pkt_ov055_021F4388
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

int CROWD_IsTileInFront(int a, int b, int c, int d, u16 hi, u16 lo, u16 dir)
{
    int x, y;

    switch (dir) {
    case 0:
        x = b - d;
        y = a - c;
        break;
    case 1:
        x = d - b;
        y = a - c;
        break;
    case 2:
        x = a - c;
        y = b - d;
        break;
    case 3:
        x = c - a;
        y = b - d;
        break;
    }
    if (x <= hi && x >= lo && y == 0) {
        return 1;
    }
    return 0;
}
