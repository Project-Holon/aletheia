/*
 * function: func_021B44CC
 * address:  0x021B44CC
 * packet:   pkt_ov021_021B44CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C724 0x0201C724 thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void func_021B44CC(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g)
{
    if (d <= 8) {
        func_0201C7D0((void *)b, c, d, (void *)e, (void *)f, g);
    } else {
        func_0201C724(a, b, (s16)c, (s16)d, e, f, (u32)g);
    }
}
