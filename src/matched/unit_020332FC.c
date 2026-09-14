/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020332FC
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020332FC
 *
 * A packed 2-bit-per-slot array getter. The backing store is a u32 array
 * reached through offset 0x138 of the object; slot `idx` lives in word
 * `idx >> 4` at bit position `(idx & 0xf) * 2`. The companion setter at
 * 0x0203331C (immediately following, same file) computes its clear mask
 * through a `long long` NOT (docs/idioms/a-64-bit-complement-is-eors-with-minus-one-not-mvns.md)
 * that this getter does not need and is left open.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020332FC.c \
 *       --addr 0x020332FC --arm
 */

typedef unsigned int u32;

struct Obj020332FC {
    char pad[0x138];
    u32 *slots;
};

u32 sub_020332FC(struct Obj020332FC *p, u32 idx)
{
    return (p->slots[idx >> 4] >> ((idx & 0xf) * 2)) & 3;
}
