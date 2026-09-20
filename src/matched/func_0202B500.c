/*
 * function: func_0202B500
 * address:  0x0202B500
 * packet:   pkt_0202B500
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * cap: label -- two call targets have no witness outside this range:
 *   0x0202B84C (func_0202B84C) and 0x0202B710 (func_0202B710).
 *   Both are still-open band_0_64 addresses; each is called exactly once
 *   image-wide and that call site is inside this function, so the `label`
 *   class refuses (every witness is in-range). No C change can fix this:
 *   the moment either callee has its own manifest entry the site attests
 *   and this file turns EXACT untouched.
 *   All 68 bytes concrete-identical; 7 of 9 relocation sites resolved.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int  func_0202B834(u8 *p);
extern void func_0202B84C(u8 *p);
extern int  func_0202B810(void);
extern void func_0202B6CC(u8 *p);
extern void func_0202B6DC(u8 *p);
extern void func_0202B6EC(u8 *p);
extern void func_0202B6F8(u8 *p);
extern void func_0202B704(u8 *p);
extern void func_0202B710(u8 *p);

void func_0202B500(u8 *p)
{
    if (func_0202B834(p) == 1) {
        func_0202B84C(p);
        *(u32 *)(p + 8) = func_0202B810();
    }
    func_0202B6CC(p);
    func_0202B6DC(p);
    func_0202B6EC(p);
    func_0202B6F8(p);
    func_0202B704(p);
    func_0202B710(p);
    *(u32 *)(p + 0xc) = *(u32 *)(p + 0xc) + 1;
}
