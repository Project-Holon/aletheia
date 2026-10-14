/*
 * function: POKETRADE_2D_HitTestBoxGrid
 * address: 0x021E421C
 * packet: pkt_ov119_021E421C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initialize the inner counter before calculating the two outer cursors.
 */
#include "../include/Obj13918.h"
int POKETRADE_2D_HitTestBoxGrid(char *p, int x, int y)
{
    int i, j, a, b;
    char *q, *r, *s;
    for (i = 0; i < 12; i++) {
        j = 0;
        q = p + i * 5;
        s = p + i * 20;
        for (; j < 5; j++) {
            if (*(unsigned char *)(q + j + 0xebc)) {
                r = s + j * 4;
                a = ((struct Obj13918 *)r)->fDCC - 5;
                b = ((struct Obj13918 *)r)->fDCE - 8;
                if (a < 0) a -= 8;
                a /= 8;
                b /= 8;
                if (a <= x && a + 3 > x && b <= y && b + 3 > y) return 1;
            }
        }
    }
    return 0;
}
