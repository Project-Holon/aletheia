/*
 * file:     zonedata_p12.c
 * unit:     yes
 * function: func_02014388, func_020143CC, func_020143D8, func_020143F0, func_0201440C
 * address:  0x02014388
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02146268_Sys  0x02146268  data
 *   sub_02014368  0x02014368  thumb
 *   sub_02082BCC  0x02082BCC  arm
 */
typedef unsigned int u32;

typedef unsigned char  u8;

extern void sub_02014368(char *a0, int a1, int a2);
extern u32  sub_02082BCC(u32 dst, u32 val, u32 len);
char *func_02014388(char *a0, u32 a1);
u32 sub_020143CC(u32 a, u32 b);
void sub_020143D8(u32 a, u32 y, u32 z);
void sub_020143F0(u8 *a);
u8 sub_0201440C(u8 *a);
extern char sub_02146268_Sys[];


char *func_02014388(char *a0, u32 a1)
{
    int i;

    if (a1 == 0)
        return 0;
    if (a1 < 0x4000) {
        i = a1 >> 3;
        if (i >= 0x16c)
            return 0;
        return a0 + 0x27c + i;
    }
    i = (int)(a1 - 0x4000) / 8;
    if (i >= 8)
        return 0;
    return sub_02146268_Sys + i;
}


/*
 * A whole translation unit, matched as one byte range.
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
u32 sub_020143CC(u32 a, u32 b)
{
    return a + ((b - 0x4000) << 1);
}


/*
 * A whole translation unit, matched as one byte range.
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
void sub_020143D8(u32 a, u32 y, u32 z)
{
    u32 base = sub_020143CC(a, y);
    sub_02082BCC(base, 0, (z - y) << 1);
}


/*
 * A whole translation unit, matched as one byte range.
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
void sub_020143F0(u8 *a)
{
    sub_02014368((char *)((u32)a), 0xAA0, 0xB5F);
    a[0x3E8] = 1;
}


/*
 * A whole translation unit, matched as one byte range.
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
u8 sub_0201440C(u8 *a)
{
    u8 v = a[0x3E8];
    a[0x3E8] = 0;
    return v;
}
