/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x0201854C..0x02018598, 76 bytes, two functions
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * Why it is capped: func_02018584 is the only caller of func_02019BA4 in the
 * whole image, so the `label` class has no witness once the compared range
 * holds that call, and no cut helps because the range cannot be made smaller
 * than the one function that needs it.  Same class as 0x02005DE4 and
 * 0x02005A98 in docs/MATCHING.md.  Keeping func_0201854C with it costs
 * nothing, since func_0201854C is in turn the only caller of func_02018584.
 *
 * The three ids this reads, 5, 0x6F and 0x9E, are the same three
 * func_020188B4 and func_02019CA0 read, and all three values are truncated to
 * u16 at the call rather than at the assignment, which is what fixes
 * func_02018584's parameters as u16 and the accessor's return as a word.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_0201854C.c \
 *       --addr 0x0201854C --thumb
 *
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   func_02019BA4  0x02019BA4  thumb
 *   func_02019C90  0x02019C90  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02019BA4(u32 x, u32 i);
extern u32 func_02019C90(u16 a, u16 b, u32 k);

u32 func_02018584(u16 a, u16 b, u16 c);

u32 func_0201854C(void *p)
{
    u32 a = func_02017E88(p, 5, 0);
    u32 b = func_02017E88(p, 0x6F, 0);
    u32 c = func_02017E88(p, 0x9E, 0);

    return func_02018584((u16)a, (u16)b, (u16)c);
}

u32 func_02018584(u16 a, u16 b, u16 c)
{
    return func_02019BA4(func_02019C90(a, b, 0x17), c);
}
