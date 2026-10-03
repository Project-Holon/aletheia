/*
 * function: func_022080F4
 * address: 0x022080F4
 * packet: pkt_ov094_022080F4
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: an enum VRAM base assigned in both copy arms prevents folding
 *   each base-plus-offset into a separate literal pool word.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02043678 0x02043678 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_020437D4 0x020437D4 arm
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_02082A60 0x02082A60 arm
 *   func_02045808 0x02045808 arm
 *   func_020437AC 0x020437AC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int w[9]; } Struct36;
typedef struct { void *f0; char p4[0x40]; int f44; } E;
extern void *func_020457B0(u32, u16);
extern void *func_02043678(u32, u32, u32, u16);
struct Bmp;
struct CharBuf;
struct Obj020437AC;
struct U16Vec;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern int func_0201D304(void *, void *, int);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_0204B7C8(void *, Struct36 *);
extern void func_02082A60(const void *, void *, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_020437AC(struct Obj020437AC *p);
void func_022080F4(char *o, E *e, void *data)
{
    void *v, *bmp;
    char *pixels;
    Struct36 buf;
    u8 c[3];
    enum { VRAM_BASE = 0x06400000 } vram;
    v = func_020457B0(12, (*(u16 *)(o + 0x448) & 0x7fff) | 0x8000);
    bmp = func_02043678(8, 2, 32, (*(u16 *)(o + 0x448) & 0x7fff) | 0x8000);
    func_02043B5C(bmp, 0);
    func_02017E1C(data, 0x73, (u32)v);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(1, 4, 0);
    if (func_0201D304(v, *(void **)(o + 8), 0) > 48)
        func_0201C7A4(bmp, 2, 5, v, *(void **)(o + 8));
    else
        func_0201C7A4(bmp, 8, 5, v, *(void **)(o + 8));
    func_0201DD78(c[2], c[1], c[0]);
    pixels = func_020437D4(bmp);
    func_0204B7C8(e->f0, &buf);
    if (e->f44 != 0) {
        vram = VRAM_BASE;
        func_02082A60(pixels, (void *)(vram + 0x40 + buf.w[1]), 0xc0);
        func_02082A60(pixels + 0x100, (void *)(vram + 0x140 + buf.w[1]), 0xc0);
        func_02082A60(pixels + 0xc0, (void *)(vram + 0x400 + buf.w[1]), 0x40);
        func_02082A60(pixels + 0x1c0, (void *)(vram + 0x500 + buf.w[1]), 0x40);
    } else {
        vram = VRAM_BASE;
        func_02082A60(pixels, (void *)(vram + 0x20 + buf.w[1]), 0xe0);
        func_02082A60(pixels + 0x100, (void *)(vram + 0x120 + buf.w[1]), 0xe0);
        func_02082A60(pixels + 0xe0, (void *)(vram + 0x400 + buf.w[1]), 0x20);
        func_02082A60(pixels + 0x1e0, (void *)(vram + 0x500 + buf.w[1]), 0x20);
    }
    func_02045808(v);
    func_020437AC(bmp);
}
