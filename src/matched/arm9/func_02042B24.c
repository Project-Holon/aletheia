/*
 * function: func_02042B24
 * address:  0x02042B24
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020422D4  0x020422D4  arm
 *   func_02040F84  0x02040F84  arm
 *
 * The halfword sibling of func_020428E8: copies a cw x ch block of u16
 * source cells into a linear w-wide screen buffer at dx/dy.  mode 0 clips
 * each row and cell with u8-wrapped coordinates and skips (the source row
 * index itself is the unwrapped sy + y); any other mode clips with plain
 * int sums, stops at the first miss, and indexes the source through
 * func_02040F84.  Closed in wave 11 with the same declarations as
 * func_020428E8 (ch, sw, sh are u8 stack parameters; func_02040F84 takes
 * u8 w/h; `u8 w, h;` puts w at sp+0x1d) and the loop counters declared
 * `u8 y, x;`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Screen {
    u16 *entries;
    u8   pad_04[0x11];
    u8   size_code;
};

extern void func_020422D4(u32 mode, u8 *a, u8 *b);
extern u16 func_02040F84(u32 x, u32 y, u8 w, u32 h);

void func_02042B24(struct Screen *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u16 *dst;
    u8 w, h;
    u8 y, x;

    dst = s->entries;
    if (dst == 0)
        return;

    func_020422D4(s->size_code, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if ((u8)(dy + y) < h && (u8)(sy + y) < sh) {
                for (x = 0; x < cw; x++) {
                    if ((u8)(dx + x) < w && (u8)(sx + x) < sw)
                        dst[dx + x + w * (dy + y)] = src[sx + x + sw * (sy + y)];
                }
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[dx + x + w * (dy + y)] = src[func_02040F84((u8)(sx + x), (u8)(sy + y), sw, (u8)sh)];
            }
        }
    }
}
