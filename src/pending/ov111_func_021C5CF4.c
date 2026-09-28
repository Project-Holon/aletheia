/*
 * function: func_021C5CF4
 * address:  0x021C5CF4
 * packet:   pkt_ov111_021C5CF4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  the range guards compile to direct branches where the original has 'b skip' trampolines, and k and xx swap r3 and r4; see docs/notes/pkt_ov111_021C5CF4.c.txt
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

void func_021C5CF4(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int side)
{
    int j;
    int i;
    int k = 0;
    int xx;
    int yy;
    int ofs;

    for (j = 0; j < 4; j++) {
        yy = y + j;
        for (i = 0; i < 4; i++, k++) {
            xx = x + i;
            if (xx < 0 || yy < 0) {
                continue;
            }
            if (xx >= w || yy >= h) {
                continue;
            }
            if (mode == 1) {
                if ((side == 0 && xx >= 0x60) || (side == 1 && xx <= 0x5F)) {
                    continue;
                }
            }
            ofs = xx % 8 + ((yy % 8) * 8 + (xx / 8 + (yy / 8) * 0x18) * 64);
            if (src[k] == 1) {
                dst[ofs] = 7;
            } else if (src[k] == 2) {
                dst[ofs] = 0;
            }
        }
    }
}
