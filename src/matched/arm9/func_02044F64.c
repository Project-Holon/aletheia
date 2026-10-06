/*
 * function: func_02044F64
 * address:  0x02044F64
 * packet:   pkt_02044F64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02043678  0x02043678  arm
 *   func_02043814  0x02043814  arm
 *   func_020437AC  0x020437AC  arm
 *   _s32_div_f     0x0209C0A4  arm
 *
 * bmp.c de-tile entry point: builds a new descriptor of the same extent
 * and depth, copies the 8x8-tiled pixels of src into it in linear order,
 * and either returns it or (keep == 0) copies it back over src, frees it
 * and returns NULL.
 *
 * WHAT CLOSED IT (wave 12, 2026-09-23), after three passes stuck at 6
 * bytes on the f04/f06 load-register pair: the four extents are u16
 * LOCALS, `w = width / 8` etc.  The `lsl #13 / lsr #16` pair the older
 * sources spelled as `(u32)(f * 8192) >> 16` is simply the u16 truncation
 * of an unsigned divide by 8.  With all four u16 the residue drops to 13,
 * and assigning them in the order h, w, dep, d (height before width) is
 * what gives the image's colouring; declaration order is inert.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Bmp { u8 *pixels; u16 width; u16 height; u16 depth; };

extern struct Bmp *func_02043678(u32 w, u32 h, u32 depth, u32 heap);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
struct Obj020437AC;
extern void func_020437AC(struct Obj020437AC *p);

struct Bmp *func_02044F64(struct Bmp *src, u32 keep, u32 heap)
{
    struct Bmp *dst;
    s32 i, n;
    u16 w;
    u16 h;
    u16 d;
    u16 dep;

    h = src->height / 8;
    w = src->width / 8;
    dep = src->depth;
    d = dep / 8;
    dst = func_02043678(w, h, dep, heap);
    n = w * h * dep;
    for (i = 0; i < n; i++) {
        s32 q, r, x, y;
        q = i / (w * d);
        r = i % (w * d);
        y = r % d;
        x = r / d;
        dst->pixels[i] = src->pixels[(q % 8) * d + y + (q / 8 * w + x) * dep];
    }
    if (keep == 0) {
        func_02043814(dst, src);
        func_020437AC((struct Obj020437AC *)dst);
        dst = 0;
    }
    return dst;
}
