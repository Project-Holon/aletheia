/*
 * function: BUTTON_MAN_ConvertUcs2ToSjis
 * address:  0x02052274
 * packet:   pkt_02052274
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   BUTTON_MAN_Ucs2CharToSjis  0x020522E4  arm
 *
 * Convert a run of n wide characters at `a` into the narrow buffer at `b`,
 * stopping early when the converter raises its flag.  BUTTON_MAN_Ucs2CharToSjis is the
 * per-character encoder next door; it returns 1 when it wrote two bytes and
 * something else when it wrote one, and it reports "stop" by storing 1 into
 * the scratch word it is handed.
 *
 * Four declaration-level levers carry this function, three of them measured
 * by an earlier lane (docs/notes/pkt_02052274.c.txt) and the fourth the one
 * that finally closed it:
 *
 *  1. BOTH cursors are initialised BEFORE the `n == 0` guard.  That is what
 *     gives the original its nine-register push and `sub sp, sp, #4` pad;
 *     guard-first drops to eight callee-saved registers and 92 bytes.
 *  2. The scratch word is reset INSIDE the loop from a separate zero-valued
 *     local `z`, not once outside: `scratch = z;` is the `mov r5, r6` /
 *     `str r5, [sp]` pair.
 *  3. `i++` sits BEFORE the `scratch == 1` early return, not after it.
 *  4. `&scratch` is written INLINE at the call, NOT bound to a `u32 *p`
 *     hoisted above the loop.  With the pointer local, the scratch pointer
 *     and the zero seed trade r4 and r5 -- eight bytes out, and a residue no
 *     permuter mutation moves (164 single mutations tried, none improved,
 *     and ten hand spellings before that).  Written inline, the compiler
 *     materialises the seed first and colours it r5 exactly as the image
 *     does.  This is the same lever that closed SPL_EMITTER_FreeTexNode in this
 *     cluster: hoisting an address-of into a named local gives that value
 *     the lower colour and displaces the values the image wanted there.
 *
 * Unlike most of this cluster this row is dsi/1.1p1, not the 1.2 front end:
 * under ../1.2/sp2 the same C compiles to 132 bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_ConvertUcs2ToSjis.c \
 *       --func BUTTON_MAN_ConvertUcs2ToSjis --addr 0x02052274 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern int BUTTON_MAN_Ucs2CharToSjis(u16 *src, char *dst, u32 *stop);

void BUTTON_MAN_ConvertUcs2ToSjis(u8 *a, u8 *b, u32 n)
{
    u32 scratch;
    u32 z;
    u32 i;
    u32 j;

    i = 0;
    j = 0;
    if (n == 0)
        return;
    z = i;
    do {
        scratch = z;
        if (BUTTON_MAN_Ucs2CharToSjis((u16 *)(a + i * 2), (char *)(b + j), &scratch) == 1)
            j += 2;
        else
            j += 1;
        i++;
        if (scratch == 1)
            return;
    } while (i < n);
}
