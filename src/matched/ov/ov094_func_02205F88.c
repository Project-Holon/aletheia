/*
 * function: func_02205F88
 * address:  0x02205F88
 * packet:   pkt_ov094_02205F88
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220A392  0x0220A392  data  ov094  a2
 *   func_02204C98  0x02204C98  thumb  ov094
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201DE00  0x0201DE00  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct { int w[9]; } Struct36;
extern const u16 d_0220A392[];
extern void *func_0204B294(u32, u32, u32, u32, const void *, u16, u16);
extern void func_0204B404(void *, Point *, int);
extern void func_0204B92C(void *, int);
extern void func_0204B878(void *, u16);
extern void *func_020457B0(u32, u16);
extern void *func_02045EC0(void *, u32);
extern int func_0201EC64(int);
extern void *func_02043678(u32, u32, u32, u16);
extern void func_02043B5C(void *, u8);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(int, int, int);
extern void func_0201EF34(int, int, int);
extern void func_0201F250(int, void *, void *);
extern void func_02204C98(void *a, void *b, int *w, int *h);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void *func_020437D4(const void *);
extern void func_0204B7C8(void *, Struct36 *);
extern void func_02082A60(const void *, void *, int);
extern void func_02045808(void *);
extern void func_0201ED04(int);
extern void func_020437AC(void *);

void func_02205F88(char *p)
{
    void *str;
    void *msg;
    int font;
    void *bmp;
    Point pos;
    int w;
    int h;
    u8 c[3];
    Struct36 buf;
    char *pixels;
    int i;
    enum { VRAM_BASE = 0x06600000 } vram;

    *(void **)(p + 0x21c) = func_0204B294(*(u32 *)(p + 0x218), *(u32 *)(p + 0x104), *(u32 *)(p + 0x108), *(u32 *)(p + 0x10c), d_0220A392, 1, *(u16 *)(p + 0x240));
    pos.x = 0x80;
    pos.y = 0x50;
    func_0204B404(*(void **)(p + 0x21c), &pos, 1);
    func_0204B92C(*(void **)(p + 0x21c), 1);
    func_0204B878(*(void **)(p + 0x21c), 0x14);
    str = func_020457B0(0x10, *(u16 *)(p + 0x240));
    msg = func_02045EC0(*(void **)(p + 0x5c), 0);
    font = func_0201EC64(*(u16 *)(p + 0x240));
    bmp = func_02043678(0xe, 4, 0x20, *(u16 *)(p + 0x240));
    func_02043B5C(bmp, 0);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(0xe, 0xa, 0);
    func_0201EF34(font, 0, 0xa5);
    func_0201F250(font, str, msg);
    func_02204C98(str, *(void **)(p + 0x224), &w, &h);
    func_0201C7A4(bmp, 0x38 - w / 2, 8, str, *(void **)(p + 0x224));
    func_0201DD78(c[2], c[1], c[0]);
    pixels = func_020437D4(bmp);
    func_0204B7C8(*(void **)(p + 0x21c), &buf);
    vram = VRAM_BASE;
    for (i = 0; i < 4; i++) {
        func_02082A60(pixels + i * 0x1c0, (void *)(vram + (i * 8 + 0xcd) * 32 + buf.w[2]), 0x100);
        func_02082A60(pixels + (i * 0x1c0 + 0x100), (void *)(vram + (i * 4 + 0xed) * 32 + buf.w[2]), 0x80);
        func_02082A60(pixels + (i * 0x1c0 + 0x180), (void *)(vram + (i * 2 + 0xfd) * 32 + buf.w[2]), 0x40);
    }
    func_02045808(str);
    func_02045808(msg);
    func_0201ED04(font);
    func_020437AC(bmp);
}
