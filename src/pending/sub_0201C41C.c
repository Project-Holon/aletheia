/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: sub_0201C41C
 * address:  0x0201C41C, 36 bytes including two pool words, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right (0 differing bytes, 36 of 36)
 *
 * waza_tool.c, the last function of the range src/matched/unit_0201C328.c
 * covers.  It resets something with 0xFFFF and hands the result of
 * func_02043678(2, 2, 0x20, arg) to the static at 0x02146558, which
 * sub_0201CA2C and sub_0201CAC8 read back.
 *
 * Why it is capped: the `blx` at 0x0201C422 is the only branch to 0x020457A0
 * anywhere in the image, checked over every Thumb BL/BLX pair and every ARM
 * branch in all 242 regions, and no pool word holds the address either.  The
 * `label` class therefore has no witness once the compared range holds that
 * call, and no cut helps, because the range cannot be smaller than this one
 * function.  Cutting it out of unit_0201C328.c is what let the other three
 * functions of the range come out EXACT, which is the
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md remedy
 * applied to the one site that cannot be carried.  It closes the day
 * 0x020457A0 is matched (the `matched` class) or acquires a second caller.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/sub_0201C41C.c  *       --addr 0x0201C41C --thumb
 *
 * symbols:
 *   g_02146558  0x02146558  data
 */

typedef unsigned int u32;

extern void func_020457A0(u32 v);
extern void *func_02043678(u32 a, u32 b, u32 c, void *d);

extern void *g_02146558;

void sub_0201C41C(void *arg)
{
    func_020457A0(0xFFFF);
    g_02146558 = func_02043678(2, 2, 0x20, arg);
}
