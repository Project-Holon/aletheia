/*
 * function: func_021A9780
 * address:  0x021A9780
 * packet:   pkt_ov021_021A9780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200D4B8  0x0200D4B8  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 * Addresses are Black-image addresses.
 *
 * Lever: `const struct Unit *u` settles the argument scheduling before the
 * func_02017588 call (as in ov021_func_021A96B8.c).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef unsigned long long u64;

struct Unit {
    u8 pad00[0x20];
    u32 f20;
};

extern u32 func_0200D4B8(void *mon, int field);
extern void func_02017588(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_020185C4(void *p);

void func_021A9780(void *mon, const struct Unit *u, void *src)
{
    u16 species = func_0200D4B8(src, 4);
    u8 level = func_0200D4B8(src, 6);
    u32 pow = func_0200D4B8(src, 2);

    func_02017588(mon, species, level, u->f20, pow, func_0200D4B8(src, 3));
    func_02017E40(mon, 0x70, func_0200D4B8(src, 10));
    func_02017E40(mon, 0x9D, func_0200D4B8(src, 7));
    func_02017E40(mon, 0xA0, func_0200D4B8(src, 5));
    func_020185C4(mon);
}
