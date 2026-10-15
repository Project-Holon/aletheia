/*
 * function: VIEWER_MAIN_BlitBrush
 * address:  0x021C5DB8
 * packet:   pkt_ov111_021C5DB8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_MAIN_BlitRect  0x021C5CF4  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern void VIEWER_MAIN_BlitRect(u8 *pix, const u8 *brush, int x, int y, int w, int h, int clip, int side);

int VIEWER_MAIN_BlitBrush(u8 *pix, const u8 *brush, int x1, int y1, int *px, int *py, int a, int b, int clip, int side)
{
    int n = 0;
    int x = *px;
    int y = *py;
    int ex = x1;
    int dx, dy;
    int ey = y1;
    int e, s;

    if (a == 0 && b == 0) {
        *px = x1;
        *py = y1;
        return n;
    }
    dx = x1 - x;
    if (dx < 0) {
        dx = -dx;
    }
    dy = y1 - y;
    if (dy < 0) {
        dy = -dy;
    }
    if (dx > dy) {
        if (x > x1) {
            s = (y > y1) ? 1 : -1;
            ex = x;
            x = x1;
            y = y1;
        } else {
            s = (y < y1) ? 1 : -1;
        }
        VIEWER_MAIN_BlitRect(pix, brush, x, y, 0xC0, 0x40, clip, side);
        x++;
        e = dx >> 1;
        n++;
        for (; x <= ex; x++) {
            e -= dy;
            if (e < 0) {
                e += dx;
                y += s;
            }
            VIEWER_MAIN_BlitRect(pix, brush, x, y, 0xC0, 0x40, clip, side);
            n++;
        }
    } else {
        if (y > y1) {
            s = (x > x1) ? 1 : -1;
            ey = y;
            y = y1;
            x = x1;
        } else {
            s = (x < x1) ? 1 : -1;
        }
        VIEWER_MAIN_BlitRect(pix, brush, x, y, 0xC0, 0x40, clip, side);
        y++;
        e = dy >> 1;
        n++;
        for (; y <= ey; y++) {
            e -= dx;
            if (e < 0) {
                e += dy;
                x += s;
            }
            VIEWER_MAIN_BlitRect(pix, brush, x, y, 0xC0, 0x40, clip, side);
            n++;
        }
    }
    *px = x1;
    *py = y1;
    return n;
}
