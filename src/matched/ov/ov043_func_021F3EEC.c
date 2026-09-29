/*
 * function: func_021F3EEC
 * address:  0x021F3EEC
 * packet:   pkt_ov043_021F3EEC
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf called only from func_021F3AC0. Each field gets its own
 * pool word (d_021F4480 + 0/8/4/C). The loads must be written in field
 * order x, y, w, h: loading w before y swaps the index and value registers
 * (17 bytes).
 *
 * symbols:
 *   d_021F4480  0x021F4480  data  ov043
 */

typedef unsigned char u8;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int a;
    int b;
} R;

extern R d_021F4480[];

int func_021F3EEC(u8 i, int x, int y)
{
    int x0;
    int y0;
    int w;
    int h;

    x0 = d_021F4480[i].x;
    y0 = d_021F4480[i].y;
    w = d_021F4480[i].w;
    h = d_021F4480[i].h;
    if (x0 <= x && x <= x0 + w - 1 && y0 <= y && y <= y0 + h - 1) {
        return 1;
    }
    return 0;
}
