/*
 * function: func_02025154
 * address:  0x02025154
 * packet:   pkt_02024DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     infowin tile-rect writer: fills a w*h u16 screen buffer with
 *           charbase + base + (pal << 12) + i + j*16 and hands it to
 *           func_020410D0.  x/y/w/h are u8 (the callee takes u8 w/h);
 *           `j * 16`, not `j << 4`, fixes the adds operand order.
 *
 * symbols:
 *   func_020410D0       0x020410D0  arm
 *   gInfoWin            0x0214693C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct InfoWin {
    u32 f00;
    u16 f04;
    u8  f06;
    u8  f07;
};

extern struct InfoWin *gInfoWin;

extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, void *a5, u8 a6,
                   u8 a7, u8 a8, u8 a9);

void func_02025154(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h)
{
    u16 buf[14];
    u8 i;
    u8 j;
    u32 p;
    struct InfoWin *q;

    i = 0;
    if (i < w) {
        p = base + (blk << 12);
        q = gInfoWin;
        do {
            for (j = 0; j < h; j++) {
                buf[j * w + i] = (u16)(q->f00 + (i + p + j * 16));
            }
            i++;
        } while (i < w);
    }
    func_020410D0(gInfoWin->f06, x, y, w, h, buf, 0, 0, w, h);
}
