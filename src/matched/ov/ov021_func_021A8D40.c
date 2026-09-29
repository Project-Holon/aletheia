/*
 * function: func_021A8D40
 * address:  0x021A8D40
 * packet:   pkt_ov021_021A8D40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_0203F684  0x0203F684  arm
 *   func_0207E5D0  0x0207E5D0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct W {
    u8 pad00[0x134];
    u32 f134;
};

extern s32 func_0203F684(u16 a);
extern void func_0207E5D0(void *src, u32 off, u32 n);

void func_021A8D40(void *unused, struct W *w)
{
    s32 t = func_0203F684(w->f134) + 0x1000;
    u16 c[2];

    c[1] = (t * 8 / 0x2000 + 9) | ((0x1F << 10) | ((t * 5 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&c[1], 0x142, 2);
    c[0] = (t * 0x1F / 0x2000) |
           (((t * 6 / 0x2000 + 0x19) << 10) | ((t * 13 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&c[0], 0x15E, 2);
    w->f134 += 6;
}
