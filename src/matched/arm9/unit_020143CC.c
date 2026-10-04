/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020143CC
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020143CC, sub_020143D8, sub_020143F0, sub_0201440C
 *
 * symbols:
 *   sub_02014368  0x02014368  thumb
 *   sub_02082BCC  0x02082BCC  arm
 *
 * alias: sub_020143CC turns a large id (b >= 0x4000) into a byte offset
 * into the caller's own buffer, two bytes per id; sub_020143D8 zero-fills
 * the span between two such ids by tail-calling the ARM memset-shaped
 * sub_02082BCC (the same target unit_02014274.c's sub_020142D8 reaches
 * directly, this file reaches it through sub_020143CC first).
 *
 * sub_020143F0 clears a whole run of flag bits with sub_02014368
 * (unit_020142E8.c, out of range here) and then sets one more byte flag at
 * a fixed offset (0x3E8) of its own; sub_0201440C is the matching
 * read-and-clear accessor for that same flag byte.  Both are leaves with
 * no `lr` to save, so disasm.py's sweep does not label sub_0201440C
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020143CC.c \
 *       --addr 0x020143CC --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void sub_02014368(char *a0, int a1, int a2);
extern u32  sub_02082BCC(u32 dst, u32 val, u32 len);

u32 sub_020143CC(u32 a, u32 b)
{
    return a + ((b - 0x4000) << 1);
}

void sub_020143D8(u32 a, u32 y, u32 z)
{
    u32 base = sub_020143CC(a, y);
    sub_02082BCC(base, 0, (z - y) << 1);
}

void sub_020143F0(u8 *a)
{
    sub_02014368((char *)((u32)a), 0xAA0, 0xB5F);
    a[0x3E8] = 1;
}

u8 sub_0201440C(u8 *a)
{
    u8 v = a[0x3E8];
    a[0x3E8] = 0;
    return v;
}
