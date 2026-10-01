/*
 * function: func_021B6FF0
 * address:  0x021B6FF0
 * packet:   pkt_ov021_021B6FF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5CC  0x0215A5CC  thumb ov010
 *   func_0201292C  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5CC(void *);
extern void *func_0201292C(void *);
extern void func_02007E50(void *, u32, int, u32);

void func_021B6FF0(void *a, void *b, u32 *c)
{
    u32 v;
    void *r;
    u16 x;

    v = func_0215A5CC(a);
    r = func_0201292C(b);
    x = *c;
    if (x != 0 && x <= 0x272) {
        func_02007E50(r, x, 1, v);
    }
}
