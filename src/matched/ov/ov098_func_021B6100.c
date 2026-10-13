/*
 * function: PDC_CreateArgs
 * address: 0x021B6100
 * packet: pkt_ov098_021B6100
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   gPdcSrcName 0x021B6E60 data a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct P { u32 a, b, c, d, e, f, g, h; };
extern const char gPdcSrcName[];
extern void *func_02030734(u32, u32, int, const char *, u16);
struct P *PDC_CreateArgs(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 heap)
{
    struct P *p;
    p = func_02030734(heap, 0x20, 0, gPdcSrcName, 0x50);
    p->a = a; p->b = b; p->c = c; p->d = d;
    p->e = e; p->f = f; p->g = g; p->h = 0;
    return p;
}
