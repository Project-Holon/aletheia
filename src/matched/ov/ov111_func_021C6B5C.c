/*
 * function: func_021C6B5C
 * address:  0x021C6B5C
 * packet:   pkt_ov111_021C6B5C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
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

struct Descriptor;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
struct StrObj;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern const u16 d_021C8768[];

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
    u8 pad3200[4];
    void *f3204;
    u8 pad3208[0x3294 - 0x3208];
    void *f3294[4];
    void *f32A4;
} Work;

void func_021C6B5C(Work *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx)
{
    u32 w;

    func_0201EFA4(p->f3204, 0, n, 3, mode, 1);
    func_0201F250(p->f3204, (void *)((u32)s), p->f32A4);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(func_02045770(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}
