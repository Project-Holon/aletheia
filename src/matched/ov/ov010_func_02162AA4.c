/*
 * function: func_02162AA4
 * address:  0x02162AA4
 * packet:   pkt_ov010_02162AA4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note 2026-10-05: the old draft (DIFF45) wrote the tail as a do/while(0) with a goto.
 * The branch-to-branch stubs are the tail `a = hw + (a - h)` written out in each arm
 * (cross-jumped later). `long w = n` keeps the final `a >= n` reload from the stack slot;
 * `hw` is unsigned (lsrs). EXACT* = 2 byte trailing pad (194 of 196 listing extent).
 *
 * symbols:
 */

typedef unsigned short u16;

u16 func_02162AA4(int v, int m, int flag, int dir, u16 n)
{
    int b, a, c;
    unsigned h, hw;
    int d;
    long w;
    if (v == 0)
        return 0;
    b = (v & 0xf0) >> 4;
    a = v & 0xf;
    c = (v & 0xf00) >> 8;
    if ((c == 0 && m == 3) || (c == 1 && m == 2) || (c == 3 && m == 0) || (c == 2 && m == 1))
        a = (b - 1) - a;
    if (flag != 0) {
        switch (dir) {
        case 0:
            if ((unsigned)(c - 2) <= 1)
                a = (b - 1) - a;
            break;
        case 1:
            if ((unsigned)c <= 1)
                a = (b - 1) - a;
            break;
        case 2:
            a = (b - 1) - a;
            break;
        }
    }
    w = n;
    h = (unsigned)b / 2;
    d = w - b;
    hw = (unsigned)w / 2;
    if (d != 0) {
        if (d % 2 != 0) {
            if (w % 2 != 0) {
                if (a < h) {
                    h = h - 1;
                    a = hw + (a - h);
                } else {
                    a = hw + (a - h);
                }
            } else {
                if (a <= h) {
                    a = (hw - 1) + (a - h);
                    goto clamp;
                } else {
                    a = hw + (a - h);
                }
            }
        } else {
            a = hw + (a - h);
        }
    }
clamp:
    if (a < 0)
        a = 0;
    else if (a >= n)
        a = w - 1;
    return a;
}
