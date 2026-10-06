/*
 * file:     button_man_p05.c
 * unit:     yes
 * function: func_02052274, func_020522E4
 * address:  0x02052274
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
 */
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

extern u16 func_02045A98(void);
void func_02052274(u8 *a, u8 *b, u32 n);
int func_020522E4(u16 *src, char *dst, u32 *stop);


/*
 * Convert a run of n wide characters at `a` into the narrow buffer at `b`,
 * stopping early when the converter raises its flag.  func_020522E4 is the
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
 *     does.  This is the same lever that closed func_02052770 in this
 *     cluster: hoisting an address-of into a named local gives that value
 *     the lower colour and displaces the values the image wanted there.
 *
 * Unlike most of this cluster this row is dsi/1.1p1, not the 1.2 front end:
 * under ../1.2/sp2 the same C compiles to 132 bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052274.c \
 *       --func func_02052274 --addr 0x02052274 --cc 1.1p1 --arm
 */
void func_02052274(u8 *a, u8 *b, u32 n)
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
        if (func_020522E4((u16 *)(a + i * 2), (char *)(b + j), &scratch) == 1)
            j += 2;
        else
            j += 1;
        i++;
        if (scratch == 1)
            return;
    } while (i < n);
}


/*
 * The per-character encoder behind func_02052274: one UCS-2 code unit to
 * Shift-JIS.  The terminator (func_02045A98's value) writes a NUL and raises
 * *stop; printable ASCII is copied; hiragana, both katakana runs and the
 * full-width A-Z, a-z and 0-9 are offset into their Shift-JIS rows and
 * written high byte first; the long-vowel mark, U+8140 (passed through as the
 * SJIS ideographic space), and the two gender signs are special-cased; any
 * other code writes '?'.  Returns 1 when two bytes were written.
 *
 * Levers: dst is plain (signed) char -- the 0x81 lead byte is `mvn r1,#0x7e`
 * and the trail bytes 0x89/0x8a are derived from it by `add` -- and the
 * result `two` is declared BEFORE the character (declaration order decides
 * the r4/r5 colours).  dsi/1.1p1; 1.2 and 2.0 are 170-220 bytes longer.
 */
int func_020522E4(u16 *src, char *dst, u32 *stop)
{
    int two = 0;
    u16 c = *src;
    u16 v;

    if (c == func_02045A98()) {
        *dst = 0;
        if (stop != 0)
            *stop = 1;
    } else if (c >= 0x20 && c <= 0x7e) {
        *dst = c;
    } else if (c >= 0x3041 && c <= 0x3093) {
        v = c + 0x525E;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30A1 && c <= 0x30DF) {
        v = c + 0x529F;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30E0 && c <= 0x30F3) {
        v = c + 0x52A0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF21 && c <= 0xFF3A) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF41 && c <= 0xFF5A) {
        v = c - 0x7CC0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF10 && c <= 0xFF19) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c == 0x30FC) {
        dst[0] = 0x81;
        dst[1] = 0x5B;
        two = 1;
    } else if (c == 0x8140) {
        dst[0] = 0x81;
        dst[1] = 0x40;
        two = 1;
    } else if (c == 0x2642) {
        dst[0] = 0x81;
        dst[1] = 0x89;
        two = 1;
    } else if (c == 0x2640) {
        dst[0] = 0x81;
        dst[1] = 0x8A;
        two = 1;
    } else {
        *dst = '?';
    }
    return two;
}
