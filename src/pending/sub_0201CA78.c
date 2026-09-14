/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: sub_0201CA78
 * address:  0x0201CA78, 80 bytes including two pool words, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right (0 differing bytes, 80 of 80)
 *
 * printsys.c's second glyph blitter, the twin of sub_0201CA2C in
 * src/matched/unit_0201CA2C.c.  The two differ only in which renderer they
 * call and in the two extra stack arguments this one passes, 0xF and 0.
 *
 * Why it is capped: the `blx` at 0x0201CABC is the only branch to 0x02043AAC
 * anywhere in the image, checked over every Thumb BL/BLX pair and every ARM
 * branch in all 242 regions, and no pool word holds the address either.  The
 * `label` class therefore has no witness once the compared range holds that
 * call, and no cut helps, because the range cannot be smaller than this one
 * function.  Cutting it away from sub_0201CA2C is what let that function come
 * out EXACT, since the two are the only callers of func_0201DB04 and each is
 * now the other's witness
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * It closes the day 0x02043AAC is matched (the `matched` class) or acquires a
 * second caller.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201CA78.c \
 *       --addr 0x0201CA78 --thumb
 *
 * symbols:
 *   g_02146558   0x02146558  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *g_02146558;

extern void *func_020437D4(void *a);
extern void  func_02043AAC(void *a, void *b, u32 c, u32 d, s32 e, u32 f,
                           u32 g, u32 h, u32 i, u32 j);
extern void  func_0201DB04(u32 a, u16 b, void *c, const u8 *d);

void sub_0201CA78(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f)
{
    func_0201DB04(d, e, func_020437D4(g_02146558), f);
    func_02043AAC(g_02146558, a, 0, 0, b + f[0], c, f[1], f[3], 0xF, 0);
}
