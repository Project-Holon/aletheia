/*
 * function: func_021B8AD4
 * address:  0x021B8AD4
 * packet:   pkt_ov172_021B8AD4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021B8B9C  0x021B8B9C  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern char *func_021B8B9C(int unused, char *base);
extern int func_020399A8(void);
extern int func_0203D3F8(int a, int b, int c, int d, void *e, int f, int g, int h);

void func_021B8AD4(int unused, char *base)
{
    char *p = func_021B8B9C(unused, base);
    func_0203D3F8(func_020399A8(), 0xFF, 0x2003, 0x21, p, 1, 1, 1);
}
