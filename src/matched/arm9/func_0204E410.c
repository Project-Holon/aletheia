/*
 * function: func_0204E410
 * address:  0x0204E410
 * packet:   pkt_0204E410
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   g_020A1480  0x020A1480  data
 *   g_020A1482  0x020A1482  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 g_020A1480[];
extern u16 g_020A1482[];

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
