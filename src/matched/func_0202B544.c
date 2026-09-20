/*
 * function: func_0202B544
 * address:  0x0202B544
 * packet:   pkt_0202B500
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Parked: four of the six call sites resolve (0x0202B7B8, 0x0202B7C8,
 * 0x0202B7D4, 0x0202B7E0 are manifest entries).  The two that stay unresolved
 * are 0x0202B7BC and 0x0202B7EC, whose own single callees are the four-byte
 * Thumb linker veneers at 0x0202AB5C and 0x0202B90C - artifact class, no C
 * spelling produces them, so neither thunk can ever earn a manifest entry and
 * no cut of this file frees the site.  Every concrete byte reproduces.
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0202B7B8(u32 a, u32 b);
extern void func_0202B7BC(u32 a, u32 b);
extern void func_0202B7C8(u32 a, u32 b);
extern void func_0202B7D4(u32 a, u32 b);
extern void func_0202B7E0(u32 a, u32 b);
extern void func_0202B7EC(u32 a, u32 b);

void func_0202B544(u32 a, u32 b)
{
    func_0202B7B8(a, b);
    func_0202B7BC(a, b);
    func_0202B7C8(a, b);
    func_0202B7D4(a, b);
    func_0202B7E0(a, b);
    func_0202B7EC(a, b);
}
