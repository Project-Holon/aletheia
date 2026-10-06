/*
 * function: func_021EB378
 * address:  0x021EB378
 * packet:   pkt_ov170_021EB378
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws a window frame from 8x8 tiles, then centres a message in it.  The
 * window size locals are u8 like the getters that return them: as int
 * locals the w - 1 and h - 1 loop guards stop sharing the corner offsets'
 * common subexpressions and the function comes out 20 bytes short.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02045730 0x02045730 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_020436FC 0x020436FC arm
 *   func_020439A0 0x020439A0 arm
 *   func_020437AC 0x020437AC arm
 *   func_020307B0 0x020307B0 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_02045808 0x02045808 arm
 */

typedef struct {
    unsigned char pad[0x14];
    char *raw;
} Chr;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bmp;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj020437AC;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern unsigned func_020275E4(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021B6AE4(u8 *p, u32 a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_02045808(struct U16Vec *vec);

#define WORK(p) (*(char **)((p) + 0x2C))
#define HEAP 0x804C

void func_021EB378(char *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon)
{
    void *win = *(void **)(WORK(p) + 0x94 + idx * 8);
    void *bmp = func_02045770(win);
    unsigned char w;
    unsigned char h;
    Chr *chr;
    void *res;
    char *raw;
    void *t;
    unsigned char i;
    void *str;

    func_02045730(win);
    func_02045758(win);
    func_02045760(win);
    w = func_02045738(win);
    h = func_02045740(win);
    func_02043B5C(bmp, 4);
    res = func_02049DB4(0x74, 0x3E, 1, (u32)(&chr), HEAP);
    raw = chr->raw;
    frame *= 0x20;

    t = func_020436FC(raw + frame, 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, 0, 0, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x40), 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, (w - 1) * 8, 0, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0xC0), 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, 0, (h - 1) * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x100), 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, (w - 1) * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x60), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        func_020439A0(t, bmp, 0, 0, 0, i * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0xA0), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        func_020439A0(t, bmp, 0, 0, (w - 1) * 8, i * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x20), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        func_020439A0(t, bmp, 0, 0, i * 8, 0, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0xE0), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        func_020439A0(t, bmp, 0, 0, i * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    func_020307B0(res);

    if (icon == 1) {
        res = func_02049DB4(func_020275E4(), 0x20, 0, (u32)(&chr), HEAP);
        t = func_020436FC(chr->raw + 0x120, 0x10, 8, 0x20, HEAP);
        func_020439A0(t, bmp, 0, 0, (w - 3) * 8, 8, 0x10, 8, 5);
        func_020437AC(t);
        func_020307B0(res);
    }

    str = func_02045EC0(*(void **)(WORK(p) + 0x80), msg);
    func_021B6AE4((u8 *)(WORK(p) + 0x94 + idx * 8), (u32)(*(void **)(WORK(p) + 0x8C)), w * 8 / 2, 4, (u32)str,
                  *(unsigned *)(WORK(p) + 0x78), col, 2);
    func_02045808(str);
}
