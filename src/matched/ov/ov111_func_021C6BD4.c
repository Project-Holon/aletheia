/*
 * function: func_021C6BD4
 * address:  0x021C6BD4
 * packet:   pkt_ov111_021C6BD4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   func_0201F35C  0x0201F35C  thumb
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
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201F35C(void *ctx, int n, u32 kind, u32 mode, u32 flag);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern const u16 d_021C8768[];

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work;

void func_021C6BD4(Work *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx)
{
    u32 w;

    func_0201F35C(s, n, kind, mode, 1);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}
