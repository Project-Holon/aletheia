/*
 * file:     clact_p17.c
 * unit:     yes
 * function: func_0204E388, func_0204E410, func_0204E4C0
 * address:  0x0204E388
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045A98  0x02045A98  arm
 *   g_020A1480  0x020A1480  data
 *   g_020A1482  0x020A1482  data
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u16 func_02045A98(void);
void func_0204E388(char *p, u16 *out, int max);
u16 func_0204E410(u8 c);
u16 func_0204E4C0(u16 c);
extern u8 g_020A1480[];
extern u16 g_020A1482[];


/*
 *           (the tool prints "no witness outside 0204E388..0204E410"); both
 *           are the single caller site and neither packet is this lane's.
 *
 * Byte-identical at 136 bytes with every concrete byte right; only the two
 * PC24 call fields at +0x4C and +0x54 stay wildcarded.  No `--suggest-split`
 * cut exists: the compared range is already one function and both call sites
 * are inside it.
 *
 * Shape notes worth keeping.  `return` type is void: the epilogue is
 * `bl func_02045A98; strh r0,[r5]; pop` and nothing copies r0 afterwards, but
 * a u16 return forces `c` live across the loop and costs a callee-saved sb.
 * The first byte must be spelled `u8 ch = *p; p++;` -- `u8 ch = *p++;` emits
 * `ldrb r0,[r6],#1` and loses the `and r0,r0,#0xff` that reuses the loop
 * test's `ldrsb`, four bytes short.  The lead-byte test is one `||` of a `&&`
 * and a compare, and the two-byte value is spelled `(ch << 8) + *p`, not
 * `|`: the original shows `add r0,r1,r0,lsl #8` (one byte at +0x40).
 */
void func_0204E388(char *p, u16 *out, int max)
{
    int n = 0;
    u16 c;

    while (*p != 0 && n < max - 1) {
        u8 ch = *p;

        p++;
        if ((ch >= 0x81 && ch <= 0x9f) || ch >= 0xe0)
            c = func_0204E4C0((u16)((ch << 8) + (u8)*p++));
        else
            c = func_0204E410(ch);
        if (c != 0xfffe) {
            *out++ = c;
            n++;
        }
    }
    *out = func_02045A98();
}


/*
 * Byte-perfect: 176 compiled against 176, ZERO concrete byte mismatches,
 * `match.py one` prints MATCH only because the two pool words it needs are
 * attesting nothing outside this range:
 *
 *   +00A4 ABS32 g_020A1480 -> unresolved: 020A1480 (data) has no witness
 *          outside 0204E410..0204E4C0
 *   +00A8 ABS32 g_020A1482 -> unresolved: 020A1482 (data) has no witness
 *          outside 0204E410..0204E4C0
 *
 * Blocking class: literal (own-pool-only data).  0x020A1480 holds sixteen
 * 4-byte records {u16 key; u16 value}; the function reads the low byte of
 * each key and the halfword value at +2.  These two words are referenced
 * from inside this function only, so no witness exists anywhere in the
 * image and the site cannot be closed from a lane; this is the documented
 * unfilable park class, not a codegen question.
 *
 * The spelling that closed the last register residue (a new lever relative
 * to docs/notes/pkt_0204E410.c.txt): bind the derived byte offset to a named
 * local *inside* the loop body
 *
 *     u32 off = i << 2;
 *     if (c == g_020A1480[i * 4]) return *(u16 *)((u8 *)g_020A1482 + off);
 *
 * With the offset written inline at both sites the loop counter is coloured
 * into r3, which forces the byte offset to be re-derived inside the equal
 * arm (`lsleq r1, r3, #2`); naming `off` leaves the counter in ip and hoists
 * `lsl r3, ip, #2` above the compare, exactly as the image has it.  That
 * took the residue from 25 bytes to 0.
 */
u16 func_0204E410(u8 c)
{
    u32 i;

    if (c >= 0x61 && c <= 0x7a)
        return (u16)(c + 0x79);
    if (c >= 0x41 && c <= 0x5a)
        return (u16)(c + 0x7f);
    if (c >= 0x30 && c <= 0x39)
        return (u16)(c + 0x86);
    if (c >= 0x21 && c <= 0x2f)
        return (u16)(c + 0xd3);
    for (i = 0; i < 0x10; i++) {
        u32 off = i << 2;

        if (c == g_020A1480[i * 4])
            return *(u16 *)((u8 *)g_020A1482 + off);
    }
    return 0x101;
}


/*
 * A character-code remap: five contiguous Shift-JIS-style ranges relocated by
 * a constant delta, then four single codes mapped individually, with 0x0101
 * as the fallback.  No relocations at all; every one of the seven pool words
 * at 0x0204E5CC is material.
 *
 * The shape that reproduces it is the plain chain of `if (c >= base && c <=
 * base + n) return c + delta;` with BOTH constants written relative to the
 * same base: the compiler materialises `base` once per arm into r2 and
 * derives the upper bound as `add r1, r2, #n` and the delta as `rsb r1, r2,
 * #k` (or `sub` where the delta is negative), which is why the deltas here
 * are spelled `(4 - 0x829F)` rather than as their folded values.  Writing a
 * delta as a bare constant costs each arm its own pool word.
 *
 * The last group shares its base too: 0x8189 feeds `moveq r0, #0xcc`,
 * `add r1, r2, #1`, `sub r1, r2, #0x49` and `sub r1, r2, #0x2e`, so all four
 * single-code tests must be written against 0x8189, not as literals.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E4C0.c \
 *       --func func_0204E4C0 --addr 0x0204E4C0 --cc 1.1p1 --arm
 */
u16 func_0204E4C0(u16 c)
{
    if (c >= 0x829F && c <= 0x829F + 0x52)
        return c + (4 - 0x829F);
    if (c >= 0x8340 && c <= 0x8340 + 0x53)
        return c + (0x57 - 0x8340);
    if (c >= 0x8281 && c <= 0x8281 + 0x19)
        return c + (0xDA - 0x8281);
    if (c >= 0x8260 && c <= 0x8260 + 0x19)
        return c + (0x8260 - 0x10400);
    if (c >= 0x824F && c <= 0x824F + 9)
        return c + (0xAC - 0x824F);
    if (c == 0x8189)
        return 0xCC;
    if (c == 0x8189 + 1)
        return 0xC5;
    if (c == 0x8189 - 0x49)
        return 2;
    if (c == 0x8189 - 0x2E)
        return 0x51;
    return 0x0101;
}
