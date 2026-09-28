/*
 * function: func_021C6C38
 * address:  0x021C6C38
 * packet:   pkt_ov111_021C6C38
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201D304  0x0201D304  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

extern void *func_02045770(void *p);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern u32 func_0201D304(void *a, void *b, u32 c);

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work;

void func_021C6C38(Work *p, void *a, int x, int dx, int y, void *s)
{
    u32 w;

    w = func_0201D304(s, p->f31FC, 0);
    func_0201C7A4(func_02045770(a), x - (w + dx), y, s, p->f31FC);
}
