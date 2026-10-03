/*
 * function: ov208_func_021C36CC
 * address: 0x021C36CC
 * packet: pkt_ov208_021C36CC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_020439A0 0x020439A0 arm
 *   ov208_func_021C3A24 0x021C3A24 thumb ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Descriptor;
struct Bmp;

extern void *func_02045770(struct Descriptor *d);
extern void func_02043AF4(struct Bmp *b, u32 x, u32 y, u32 w, u32 h, u32 color);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y,
                          int sx, int sy, u32 w, u32 h, u32 key);
extern void ov208_func_021C3A24(u16 *heap, u8 *p, int key);

struct Ov208Scroll {
    u8 pad0[0x18];
    s16 a;
    s16 b;
    u8 pad1c[0x20 - 0x1c];
    struct Descriptor *desc;
    u8 pad24[0x2c - 0x24];
    struct Bmp *dst;
    s16 c;
    s16 d;
};

void ov208_func_021C36CC(u16 *heap, struct Ov208Scroll *p, int key)
{
    s16 *qd;
    struct Bmp *bmp;
    s16 x;
    s16 *qa;
    s16 n;
    bmp = func_02045770(p->desc);
    x = (s16)(((s16)(p->a + (p->b << 3)) + 0xee) % 0xf8);
    n = 0;
    qa = &p->a;
    p->a = *qa + 2;
    while (p->a >= 8) {
        func_02043AF4(bmp, (s16)(p->b << 3), 0, 8, 0x78, 0);
        p->b = (p->b + 1) % 0x1f;
        *qa = *qa - 8;
    }
    if (p->a > 0)
        func_02043AF4(bmp, (s16)(p->b << 3), 0, (u16)p->a, 0x78, 0);
    qd = &p->d;
    while (n < 2) {
        s16 end;
        s16 d;
        int w;
        d = p->c - p->d;
        end = (s16)(x + 2 - n);
        if (d <= 0)
            break;
        if (end > 0xf8)
            end = 0xf8;
        if (end - x > d)
            end = (s16)(x + d);
        w = end - x;
        func_020439A0(p->dst, bmp, p->d, 0, x, 0, w, 0x78, 0xffff);
        n = (s16)(n + (s16)w);
        x = (s16)(end % 0xf8);
        *qd = *qd + n;
    }
    while (n < 2) {
        s16 end;
        int w;
        end = (s16)(x + 2 - n);
        if (end > 0xf8)
            end = 0xf8;
        w = end - x;
        func_02043AF4(bmp, x, 0x37, (u16)w, 1, 0xf);
        n = (s16)(n + (s16)w);
        x = (s16)(end % 0xf8);
    }
    ov208_func_021C3A24(heap, (u8 *)p, key);
}



