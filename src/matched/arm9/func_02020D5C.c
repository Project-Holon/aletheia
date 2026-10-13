/*
 * function: BMP_CURSOR_Draw
 * address:  0x02020D5C
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blits one cursor/icon out of its cell holder, choosing between two
 * targets by the descriptor's mode word: mode 1 draws through the
 * 0x0201C6FC window path and latches a "drawn" flag on the caller's
 * handle, anything else falls back to the plain 8x8 palette-0xf blit
 * at 0x020439A0 when a surface is configured, and releases the cell
 * afterwards.
 *
 * symbols:
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_020439A0  0x020439A0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045770  0x02045770  arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

struct Desc {
    u32   mode;
    void *f4;
    void *f8;
};

struct Handle {
    void *cell;
    u8    drawn;
};

struct PrintSys;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
struct Bmp;
struct Descriptor;
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_02045334(struct Descriptor *d);
extern void *func_02045770(struct Descriptor *p);

void BMP_CURSOR_Draw(struct Desc *d, u32 x, u32 y, struct Handle *h,
                   void *dst, u32 f)
{
    if (d->mode == 1) {
        func_0201C6FC(dst, (u32)func_02045770(h->cell), (s16)x, (s16)y, d->f4, f);
        h->drawn = 1;
    } else if (d->f8 != 0) {
        func_020439A0(d->f8, func_02045770(h->cell), 0, 0,
                      x + 2, y + 2, 8, 8, 0xf);
        func_02045334(h->cell);
    }
}
