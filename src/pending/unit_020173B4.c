/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x020173B4..0x020173E8, 52 bytes, three functions
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * Why it is capped: func_020173C8 is the only reference to func_02016380 in
 * the image and func_020173D0 the only caller of func_0201AD88, so neither
 * target has a witness outside the range and no cut helps.  Keeping
 * func_020173B4 with them costs nothing, because its own pool word is then
 * the `local` class rather than the only witness for func_020173C8.
 *
 * func_020173C8 exists only so that func_02015F2C has a callback with the
 * right signature: it is the eight byte pool-word tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md and does nothing else.
 *
 * 0x02146270 is a RAM record whose halfword at +0x02 func_02019C54 compares
 * against, and the two pool words that name it, 0x020173E4 here and
 * 0x02019C74 there, attest each other.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_020173B4.c \
 *       --addr 0x020173B4 --thumb
 *
 * The `matched` class does not reach it: neither func_02016380 nor
 * func_0201AD88 is matched, so no EXACT entry covers either address.
 *
 * symbols:
 *   func_02015F2C  0x02015F2C  thumb
 *   func_02016380  0x02016380  thumb
 *   func_0201AD88  0x0201AD88  thumb
 *   unk_02146270   0x02146270  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02015F2C(void *a, void *b, void (*fn)(void *), u32 flag);
extern void func_02016380(void *p);
extern void func_0201AD88(void *p);

struct Unk146270 {
    u16 unk00;
    u16 unk02;
};

extern struct Unk146270 unk_02146270;

void func_020173C8(void *p);

void func_020173B4(void *p)
{
    func_02015F2C(p, p, func_020173C8, 1);
}

void func_020173C8(void *p)
{
    func_02016380(p);
}

void func_020173D0(void *p)
{
    func_0201AD88(p);
    unk_02146270.unk02 = 0x28B;
}
