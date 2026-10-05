/*
 * function: func_021B8F00
 * address: 0x021B8F00
 * packet: pkt_ov103_021B8F00
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 (wD6 lane20): closed by reading pa/pb fields inside the loop (mwcc hoists them),
 *   declaring i before sum, the four differences declared dy1, dx1, dy2, dx2 and assigned x first,
 *   and d set in an if/else (keeps the explicit cmp #0).
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pt { int x, y; };
u8 func_021B8F00(struct Pt *pa, struct Pt *a, struct Pt *pb, struct Pt *b)
{
    int i;
    u32 sum;
    sum = 0;
    for (i = 1; i < 10; i++) {
        int dy1, dx1, dy2, dx2;
        u32 d1, d2;
        u16 d;
        dx1 = a[i].x - pa->x;
        dy1 = a[i].y - pa->y;
        dx2 = b[i].x - pb->x;
        dy2 = b[i].y - pb->y;
        if (dy1 < 0) dy1 = -dy1;
        if (dx1 < 0) dx1 = -dx1;
        d1 = dx1 + dy1;
        if (dy2 < 0) dy2 = -dy2;
        if (dx2 < 0) dx2 = -dx2;
        d2 = dx2 + dy2;
        if (d1 > d2) d = d1 - d2; else d = d2 - d1;
        if (d == 0)
            sum += 100;
        else if (d == 1)
            sum += 80;
        else if (d == 2)
            sum += 50;
        else if (d >= 3 && d <= 5)
            sum += 30;
    }
    return (u8)(sum / 9);
}
