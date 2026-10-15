/*
 * function: BEACON_VIEW_HitTestRow
 * address:  0x021F08E4
 * packet:   pkt_ov032_021F08E4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_PointInTriangle  0x021F089C  thumb  ov032
 */

typedef unsigned char u8;

extern int BEACON_VIEW_PointInTriangle(void *pt, int *tri);

int BEACON_VIEW_HitTestRow(u8 *p, void *pt)
{
    int i;
    int x;
    int y;
    int t[6];

    for (i = 0; i < p[0x7d]; i++) {
        x = i * 13;
        y = i * 40;
        t[0] = x;
        t[1] = y + 5;
        t[2] = x + 0xc;
        t[3] = y + 0x2b;
        t[4] = x + 0xd2;
        t[5] = y + 0x2b;
        if (BEACON_VIEW_PointInTriangle(pt, t))
            return i;
        t[0] = x;
        t[1] = y + 5;
        t[2] = x + 0xd2;
        t[3] = y + 0x2b;
        t[4] = x + 0xc6;
        t[5] = y + 5;
        if (BEACON_VIEW_PointInTriangle(pt, t))
            return i;
    }
    return -1;
}
