/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: func_0204B764, func_0204B784, func_0204B7C8
 * address:  0x0204B764
 * packet:   pkt_0204B764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020637BC  0x020637BC  arm
 *
 * Three aggregate struct copies out of a cell actor, laid out as one unit so
 * the whole 140-byte range (padding included) is the evidence.
 *
 * docs/notes/pkt_0204B764.c.txt records these as a two-instruction scheduling
 * residue; that note is SUPERSEDED for all three.  The spelling that closes it
 * is in the body below: the unit's middle function binds the copy to a named
 * struct local (`Struct36 s; ... s = *src; *(Struct36 *)(dst + 0x1c) = s;`),
 * which is what puts the source address ahead of the destination move, and the
 * two wrappers cast the base once and assign through it.  `tu` reports EXACT,
 * 3 code sections, 140 bytes, 2 of 2 relocation sites resolved.
 *
 * The previous header carried one per-function block per function rather than
 * one `unit: yes` block, so `manifest --verify` recorded only the LAST of the
 * three and 0x0204B764 / 0x0204B784 stayed open in the worklist although the
 * bytes had been reproduced.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B764.c \
 *       --addr 0x0204B764 --arm
 */

typedef struct Struct20 {
    int w[5];
} Struct20;

typedef struct Struct36 {
    int w[9];
} Struct36;

extern void func_020637BC(void *ptr, int val);

static inline void copy_inline1(const Struct36 *src, Struct36 *dst) {
    *dst = *src;
}
static inline void copy_inline2(Struct36 *dst, const Struct36 *src) {
    *dst = *src;
}

void func_0204B764(const char *src, Struct20 *dst)
{
    const Struct20 *s = (const Struct20 *)(src + 0x40);
    *dst = *s;
}

void func_0204B784(char *dst, const Struct36 *src)
{
    Struct36 s;
    func_020637BC((void *)src, 1);
    func_020637BC((void *)src, 2);
    s = *src;
    *(Struct36 *)(dst + 0x1c) = s;
}

void func_0204B7C8(const char *src, Struct36 *dst)
{
    const Struct36 *s = (const Struct36 *)(src + 0x1c);
    *dst = *s;
}
