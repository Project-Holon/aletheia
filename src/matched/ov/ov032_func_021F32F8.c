/*
 * function: func_021F32F8
 * address:  0x021F32F8
 * packet:   pkt_ov032_021F32F8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds the 0x34-byte record at +0x1B8 that func_021F34C8 tears down.
 *
 * symbols:
 *   func_021F32F8  0x021F32F8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F3214  0x021F3214  thumb  ov032
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_020257D0  0x020257D0  thumb
 *   func_02025774  0x02025774  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 pad03[5];
    s16 x;
    s16 y;
    void *f0c;
    void *f10;
    void *f14;
    void *f18;
    void *f1c;
    void *f20;
    void *f24;
    u32 f28;
    u8 pad2c[8];
} Rec;

typedef struct {
    void *bmp;
    s16 x;
    s16 y;
    u32 f08;
    u32 f0c;
    u8 f10;
    u8 f11;
    u16 f12;
    u32 f14;
} Tmpl;

extern void func_02082BCC(void *p, int v, int n);
extern void *func_021F3214(char *p, unsigned a, unsigned b, unsigned c, short x, short y, unsigned char w, unsigned char h, unsigned char z);
extern void func_0204B6F4(void *p, u8 a, u32 b);
extern void *func_02043678(u32 w, u32 h, u32 depth, u32 heap);
extern void *func_020255A0(void *sys, Tmpl *t);
extern void *func_020457B0(u32 size, u32 heap);
extern void func_02043B5C(void *bmp, u32 v);
extern void func_020257D0(void *p);
extern void func_02025774(void *p, int v);
extern void func_0204B3DC(void *p, int v);

void func_021F32F8(char *p, u8 idx)
{
    Rec *r;
    Tmpl t;

    r = (Rec *)(p + 0x1b8 + idx * 0x34);
    func_02082BCC(r, 0, 0x34);
    r->f00 = idx;
    r->f01 = 0xff;
    r->f02 = 0;
    r->f28 = *(u32 *)(p + 0xb4);
    r->x = idx * 13;
    r->y = idx * 0x28;
    r->f0c = func_021F3214(p, **(u32 **)(p + 0x140), **(u32 **)(p + 0x138), **(u32 **)(p + 0x148),
                           r->x, r->y, 0, 3, idx + 0x14);
    func_0204B6F4(r->f0c, idx, 0);
    r->f10 = func_021F3214(p, (*(u32 **)(p + 0x158))[idx], **(u32 **)(p + 0x138), **(u32 **)(p + 0x160),
                           r->x + 0x20, r->y + 0x18, 0, 3, idx + 10);
    func_0204B6F4(r->f10, idx + 9, 1);
    r->f14 = func_021F3214(p, (*(u32 **)(p + 0x170))[idx], **(u32 **)(p + 0x138), **(u32 **)(p + 0x178),
                           r->x + 0x3c, r->y + 0x18, 0, 3, idx + 5);
    r->f1c = func_02043678(0xc, 2, 0x20, *(u16 *)(p + 0x98));
    t.bmp = r->f1c;
    t.x = r->x + 0x48;
    t.y = r->y + 0x10;
    t.f08 = **(u32 **)(p + 0x138);
    t.f0c = 3;
    t.f10 = 0;
    t.f11 = 3;
    t.f12 = 0;
    t.f14 = 1;
    r->f18 = func_020255A0(*(void **)(p + 0x124), &t);
    r->f20 = func_020457B0(0xb, *(u16 *)(p + 0x98));
    r->f24 = func_020457B0(8, *(u16 *)(p + 0x98));
    func_02043B5C(r->f1c, 0);
    func_020257D0(r->f18);
    func_02025774(r->f18, 0);
    func_0204B3DC(r->f0c, 0);
    func_0204B3DC(r->f10, 0);
    func_0204B3DC(r->f14, 0);
}
