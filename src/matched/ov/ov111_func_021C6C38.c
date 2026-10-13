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
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_0201D304  0x0201D304  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work;

void func_021C6C38(Work *p, void *a, int x, int dx, int y, void *s)
{
    u32 w;

    w = func_0201D304(s, (u32)p->f31FC, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(a), x - (w + dx), y, s, p->f31FC);
}
