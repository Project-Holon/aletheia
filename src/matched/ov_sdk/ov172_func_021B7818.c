/*
 * function: func_021B7818
 * address:  0x021B7818
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forward three arguments, the third from func_021BE0A4.
 *
 * symbols:
 *   func_021BE0A4  0x021BE0A4  thumb  ov172
 *   func_021B7830  0x021B7830  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 func_021BE0A4(void *p);
extern int func_021B7830(void *a0, char *a1, int a2);

void func_021B7818(void *p, void *q)
{
    func_021B7830(p, q, func_021BE0A4(p));
}
