/*
 * function: func_021A71E4
 * address:  0x021A71E4
 * packet:   pkt_ov021_021A71E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021B7A84  0x021B7A84  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7CD8  0x021B7CD8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct V { u32 x, y, z; } V;

extern u32 func_02188C5C(u32 a);
extern u32 func_021BB480(u32 a);
extern void func_021A3038(u32 a, V *b);
extern u32 func_021B7A84(u32 a, V *b, V *c, u16 *d, V *e);
extern u32 func_0201441C(u32 a);
extern void func_021B7CD8(u32 a, u16 *b, u32 c, u16 *d);

int func_021A71E4(u32 a, u32 *b, u16 *c, u32 d)
{
    V w;
    V in;
    V q;
    u16 r[8];
    u32 h;
    h = func_021BB480(func_02188C5C(a));
    func_021A3038(b[1], &in);
    q.x = in.x;
    q.y = in.y + 0x4000;
    q.z = in.z;
    in.y = in.y - 0x4000;
    if (func_021B7A84(h, &in, &q, &r[4], &w) != 0)
        func_021B7CD8(h, &r[4], func_0201441C(d), r);
    c[0] = r[4];
    c[1] = r[5];
    c[2] = r[6];
    c[3] = r[7];
}
