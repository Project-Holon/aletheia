/*
 * function: func_021922A4
 * address:  0x021922A4
 * packet:   pkt_ov021_021922A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Nine-slice frame: loads each frame tile into an 8x8 scratch bitmap with
 * func_02192264 and blits it over the centre, the four edges and the four
 * corners of the target bitmap.
 *
 * symbols:
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_02043678  0x02043678  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 *   func_02192264  0x02192264  thumb  ov021
 * Addresses are Black-image addresses.
 *
 * The edge loops use u16 locals truncated at their definition from the
 * CSE'd int w-1 / h-1 (spilled); the corners reuse the loop counters i
 * and j as the x/y tile positions, assigned before each tile load, so the
 * u16 truncation is scheduled ahead of the func_02192264 call.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp;
struct Obj020437AC;
extern u16 func_020437DC(const struct Bmp *bmp);
extern u32 func_020437E4(const struct Bmp *bmp);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02192264(u32 a, u32 b, u32 c, u32 d);

static inline void blit(u32 tmp, u32 bmp, u16 x, u16 y)
{
    func_020439A0((struct Bmp *)tmp, (struct Bmp *)bmp, 0, 0, x * 8, y * 8, 8, 8, 0xFFFF);
}

void func_021922A4(u32 bmp, u32 b, u32 heap)
{
    u16 w;
    u16 j;
    u16 h;
    u16 i;
    u32 tmp;
    u16 hm1;
    u16 wm1;

    w = func_020437DC((const struct Bmp *)bmp) >> 3;
    h = func_020437E4((const struct Bmp *)bmp) >> 3;
    tmp = (u32)func_02043678(1, 1, 0x20, heap);

    func_02192264(tmp, b, heap, 9);
    for (j = 0; j < h; j++)
        for (i = 0; i < w; i++)
            blit(tmp, bmp, i, j);

    func_02192264(tmp, b, heap, 1);
    for (i = 0; i < w; i++)
        blit(tmp, bmp, i, 0);

    func_02192264(tmp, b, heap, 0x11);
    hm1 = h - 1;
    for (i = 0; i < w; i++)
        blit(tmp, bmp, i, hm1);

    func_02192264(tmp, b, heap, 8);
    for (i = 0; i < h; i++)
        blit(tmp, bmp, 0, i);

    func_02192264(tmp, b, heap, 0xA);
    wm1 = w - 1;
    for (i = 0; i < h; i++)
        blit(tmp, bmp, wm1, i);

    func_02192264(tmp, b, heap, 0);
    blit(tmp, bmp, 0, 0);
    i = w - 1;
    func_02192264(tmp, b, heap, 2);
    blit(tmp, bmp, i, 0);
    i = h - 1;
    func_02192264(tmp, b, heap, 0x10);
    blit(tmp, bmp, 0, i);
    i = w - 1;
    j = h - 1;
    func_02192264(tmp, b, heap, 0x12);
    blit(tmp, bmp, i, j);

    func_020437AC((struct Obj020437AC *)tmp);
}
