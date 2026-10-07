/*
 * file:     unit_021C6000_p04.c
 * unit:     yes
 * function: func_021C6954, func_021C69D4
 * address:  0x021C6954
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
 *   func_02045770  0x02045770  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201D304  0x0201D304  thumb
 *   d_021C8768     0x021C8768  data  a2
 */
struct Descriptor;
struct WordSet;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
    u8 pad3200[4];
    void *f3204;
    u8 pad3208[0x3294 - 0x3208];
    void *f3294[4];
    void *f32A4;
} Work_021C6954;

typedef struct {
    u8 pad0[0x2C];
    u16 h2C;
    u8 pad2E;
    u8 b2F;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 b33;
    u8 b34;
    u8 b35;
} Info;

typedef struct {
    u8 pad0[0x28];
    Info *info;
    u8 pad2C[0x31FC - 0x2C];
    void *f31FC;
    u8 pad3200[4];
    void *f3204;
    u8 pad3208[0x329C - 0x3208];
    void *f329C;
    void *f32A0;
} Work_021C69D4;

extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
void func_021C6954(Work_021C6954 *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx);
void func_021C69D4(Work_021C69D4 *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx);
extern const u16 d_021C8768[];


/*
 * Addresses are Black-image addresses.
 */
void func_021C6954(Work_021C6954 *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx)
{
    u32 w;

    func_0201EFA4(p->f3204, 0, n, digits, mode, 1);
    func_0201F250(p->f3204, (void *)((u32)s), p->f3294[k]);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    func_0201C7D0(func_02045770(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}


void func_021C69D4(Work_021C69D4 *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx)
{
    u32 w;

    func_0201EFA4(p->f3204, 0, p->info->b2F + 2000, 4, mode, 1);
    func_0201EFA4(p->f3204, 1, p->info->b30, 2, mode, 1);
    func_0201EFA4(p->f3204, 2, p->info->b31, 2, mode, 1);
    func_0201F250(p->f3204, (void *)((u32)s), p->f329C);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    func_0201C7D0(func_02045770(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}
