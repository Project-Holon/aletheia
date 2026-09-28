/*
 * function: func_021C69D4
 * address:  0x021C69D4
 * packet:   pkt_ov111_021C69D4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201D304  0x0201D304  thumb
 *   d_021C8768     0x021C8768  data  a2
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern void *func_02045770(void *p);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201EFA4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201F250(void *a, u32 b, void *c);
extern u32 func_0201D304(void *a, void *b, u32 c);
extern const u16 d_021C8768[];

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
} Work;

void func_021C69D4(Work *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx)
{
    u32 w;

    func_0201EFA4(p->f3204, 0, p->info->b2F + 2000, 4, mode, 1);
    func_0201EFA4(p->f3204, 1, p->info->b30, 2, mode, 1);
    func_0201EFA4(p->f3204, 2, p->info->b31, 2, mode, 1);
    func_0201F250(p->f3204, (u32)s, p->f329C);
    w = func_0201D304(s, p->f31FC, 0);
    func_0201C7D0(func_02045770(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}
