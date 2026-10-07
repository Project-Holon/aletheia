/*
 * file:     unit_021C6000_p05.c
 * unit:     yes
 * function: func_021C6A84, func_021C6B5C, func_021C6BD4
 * address:  0x021C6A84
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   d_021C8768  0x021C8768  data
 *   func_0201F35C  0x0201F35C  thumb
 */
struct Descriptor;
struct WordSet;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef struct {
    u8 pad0[0x2C];
    u16 h2C;
    u8 pad2E[4];
    u8 b32;
    u8 b33;
    u8 b34;
    u8 b35;
} Info;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info *info;
    u8 pad2C[0x31FC - 0x2C];
    void *f31FC;
    u8 pad3200[4];
    void *f3204;
    u8 pad3208[0x32A0 - 0x3208];
    void *f32A0;
} Work_021C6A84;

typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
    u8 pad3200[4];
    void *f3204;
    u8 pad3208[0x3294 - 0x3208];
    void *f3294[4];
    void *f32A4;
} Work_021C6B5C;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work_021C6BD4;

extern void func_0201EFA4(void *p, int idx, int v, int digits, int a, int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7D0(void *bmp, s16 x, s16 y, void *str, void *font, u16 col);
extern void func_0201F35C(void *ctx, int n, u32 kind, u32 mode, u32 flag);
void func_021C6A84(Work_021C6A84 *p, void *win, int x, int ofs, int y, void *str, int mode, int col);
void func_021C6B5C(Work_021C6B5C *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx);
void func_021C6BD4(Work_021C6BD4 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx);
extern const u16 d_021C8768[];


void func_021C6A84(Work_021C6A84 *p, void *win, int x, int ofs, int y, void *str, int mode, int col)
{
    int w;

    func_0201EFA4(p->f3204, 0, p->info->b32 + 2000, 4, mode, 1);
    func_0201EFA4(p->f3204, 1, p->info->b33, 2, mode, 1);
    func_0201EFA4(p->f3204, 2, p->info->b34, 2, mode, 1);
    func_0201EFA4(p->f3204, 3, p->info->h2C, 2, 2, 1);
    func_0201EFA4(p->f3204, 4, p->info->b35, 2, 2, 1);
    func_0201F250(p->f3204, str, p->f32A0);
    w = func_0201D304(str, (u32)p->f31FC, 0);
    func_0201C7D0(func_02045770(win), x - (w + ofs), y, str, p->f31FC, d_021C8768[col]);
}


void func_021C6B5C(Work_021C6B5C *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx)
{
    u32 w;

    func_0201EFA4(p->f3204, 0, n, 3, mode, 1);
    func_0201F250(p->f3204, (void *)((u32)s), p->f32A4);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    func_0201C7D0(func_02045770(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C6BD4(Work_021C6BD4 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx)
{
    u32 w;

    func_0201F35C(s, n, kind, mode, 1);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    func_0201C7D0(func_02045770(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}
