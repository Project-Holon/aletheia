/*
 * file:     textprint.c
 * unit:     yes
 * function: TEXTPRINT_Init, TEXTPRINT_PrintCodes, TEXTPRINT_PrintText, TEXTPRINT_SjisToGlyphCodes, TEXTPRINT_AsciiToGlyphCode, TEXTPRINT_SjisToGlyphCode
 * address:  0x0204E130
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
 *   g_TextPrintWork     0x02146A78  data
 *   SYSTEMFONT_Load  0x020461F4  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   SYSTEMFONT_GetGlyphHeight  0x020463C0  arm
 *   SYSTEMFONT_GetGlyphWidth  0x020463D8  arm
 *   SYSTEMFONT_SetColors  0x020463E0  arm
 *   BMP_CreateFromBuffer  0x020436FC  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   SYSTEMFONT_GetGlyph  0x02046300  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_Delete  0x020437AC  arm
 *   s_textprint_c   0x020A7F80  data
 *   g_TextPrintSymbolKeys  0x020A1480  data
 *   g_TextPrintSymbolGlyphs  0x020A1482  data
 *   GFL_HEAP_Free  0x020307B0  arm
 */
struct Bmp;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

/* Work record of the debug text printer: one rendered 8x8 glyph (4bpp, 0x20
 * bytes), its advance width, and the print cursor. */
typedef struct {
    u8  glyphPixels[0x20];
    u8  glyphWidth;
    u8  padding21;
    u16 cursorX;
    u16 cursorY;
} TextPrintWork;

/* Same object as struct DebugConsole in gf_overlay.c (bytes 0..0xB; the
 * flags byte at 0xB is not read here). */
typedef struct {
    struct Bmp *charBitmap;
    u16 cursorX;
    u16 cursorY;
    u8  advanceX;
    u8  advanceY;
    u8  fgColor : 4;
    u8  bgColor : 4;
} TextParam;

extern int SYSTEMFONT_GetGlyphHeight(void);  /* glyph height */
extern int SYSTEMFONT_GetGlyphWidth(void);  /* full-width space width */
extern void  SYSTEMFONT_SetColors(u32 fgColor, u32 bgColor);
extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heapId);
extern u16   STRBUF_GetEosChar(void);  /* string terminator code */
extern void SYSTEMFONT_GetGlyph(int glyphIndex, u8 *glyphOut);
extern void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 w, u32 h, u32 colorKey);
extern void BMP_Delete(struct Bmp *bmp);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int align, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *block);
void TEXTPRINT_Init(u32 fontId);
extern void SYSTEMFONT_Load(u32 fontId);
void TEXTPRINT_PrintCodes(const u16 *codes, TextParam *console);
void TEXTPRINT_PrintText(char *text, TextParam *console);
void TEXTPRINT_SjisToGlyphCodes(char *text, u16 *out, int maxCodes);
u16 TEXTPRINT_AsciiToGlyphCode(u8 asciiChar);
u16 TEXTPRINT_SjisToGlyphCode(u16 sjisChar);
extern TextPrintWork *g_TextPrintWork;  /* the printer singleton */
extern const char s_textprint_c[];
extern u8 g_TextPrintSymbolKeys[];    /* symbol key table: 16 records, key byte */
extern u16 g_TextPrintSymbolGlyphs[];   /* symbol key table: same records, glyph code at +2 */



/*
 * Idempotent one-time init of the singleton at 0x02146A78: if it is already
 * live, return; otherwise run SYSTEMFONT_Load and allocate a 0x26-byte record
 * from heap 0 into the global.
 *
 * The guard's load landing in r1 rather than r0 is the arity tell: the
 * incoming parameter is still live in r0 because it is forwarded unchanged
 * to SYSTEMFONT_Load, so the global's load has to go somewhere else.  Written
 * `void TEXTPRINT_Init(void)` with `SYSTEMFONT_Load()`, the load takes r0 and
 * two bytes are wrong; an unused parameter does not do it either, since a
 * dead parameter frees its register immediately.  The caller at 0x020055BA
 * sets `movs r0, #0` before the `blx`, confirming the one argument.  The
 * heap id the allocator gets is a freshly materialised 0, not that
 * parameter, which is why the parameter is not saved across the call.
 *
 * The file string at 0x020A7F80 is "textprint.c", __LINE__ = 51.  The
 * alignment argument is `mov r2, r0`, the heap id's zero re-used, so heap
 * and align must both be spelled 0 with heap first.
 *
 * Byte-correct, capped at MATCH: the PC24 at +0x1c (SYSTEMFONT_Load) has no
 * witness outside 0204E130..0204E180.  This function is 0x020461F4's only
 * caller image-wide, so the `label` class is unavailable, the two are far
 * apart so no unit can make the site `local`, and there is no EXACT entry
 * for 0x020461F4 to serve as a `matched` witness.  It unsticks when
 * 0x020461F4 is decompiled to EXACT (it is a seven-register-push function
 * in another packet, not reachable inside this run's territory).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/TEXTPRINT_Init.c \
 *       --func TEXTPRINT_Init --addr 0x0204E130 --cc 1.1p1 --arm
 */
void TEXTPRINT_Init(u32 fontId)
{
    if (g_TextPrintWork == 0) {
        SYSTEMFONT_Load(fontId);
        g_TextPrintWork = GFL_HEAP_Alloc(0, 0x26, 0, s_textprint_c, 51);
    }
}


/*
 * textprint.c: draw a u16 string with the fixed 8x8 debug font into
 * console->charBitmap at the console cursor.  Control codes: 1 newline (x
 * back to the console's start column, y down by font height + advanceY),
 * 2 a full-width space (7), 3 a half space; every other code renders glyph
 * code - 4 into the 0x26-byte work record at g_TextPrintWork and blits it.  The
 * cursor is written back to the console at the end.
 *
 * Shape facts: case 2 is `x = x + spaceWidth` (the compound form
 * truncates it to u16 first); the loop test is `endCode != *codes` (cmp
 * operand order); locals declared endCode, glyphBmp, spaceWidth, glyphHeight so the callee-saved registers
 * land as in the image.
 */
void TEXTPRINT_PrintCodes(const u16 *codes, TextParam *console)
{
    u16 endCode;
    struct Bmp *glyphBmp;
    u32 spaceWidth;
    u32 glyphHeight;
    u16 code;

    glyphHeight = SYSTEMFONT_GetGlyphHeight();
    spaceWidth = SYSTEMFONT_GetGlyphWidth();
    g_TextPrintWork->cursorX = console->cursorX;
    g_TextPrintWork->cursorY = console->cursorY;
    SYSTEMFONT_SetColors(console->fgColor, console->bgColor);
    glyphBmp = BMP_CreateFromBuffer(g_TextPrintWork, 1, 1, 0x20, 0);
    endCode = STRBUF_GetEosChar();
    while (endCode != *codes) {
        code = *codes;
        codes++;
        switch (code) {
        case 1:
            g_TextPrintWork->cursorX = console->cursorX;
            g_TextPrintWork->cursorY += (u16)(glyphHeight + console->advanceY);
            break;
        case 2:
            g_TextPrintWork->cursorX = g_TextPrintWork->cursorX + spaceWidth;
            break;
        case 3:
            g_TextPrintWork->cursorX += (u16)(spaceWidth / 2);
            break;
        default:
            SYSTEMFONT_GetGlyph((u16)(code - 4), (u8 *)g_TextPrintWork);
            BMP_Blit(glyphBmp, console->charBitmap, 0, 0, g_TextPrintWork->cursorX, g_TextPrintWork->cursorY,
                          g_TextPrintWork->glyphWidth, glyphHeight, 0);
            g_TextPrintWork->cursorX += (u16)(g_TextPrintWork->glyphWidth + console->advanceX);
            break;
        }
    }
    console->cursorX = g_TextPrintWork->cursorX;
    console->cursorY = g_TextPrintWork->cursorY;
    BMP_Delete(glyphBmp);
}



/*
 * textprint.c's one-shot formatter: carve a 0x200-byte scratch buffer with
 * the three-argument allocator (heap id 0), format into its first 0x100
 * bytes, run the second pass over the caller's argument, then release the
 * buffer.  Argument order at the allocator is (heap, size, align), and the
 * stacked fifth argument is __LINE__ = 0xae.
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 * 96 of 96 bytes and 3 of 5 relocations resolve; the two sites that stay
 * wildcarded are the calls to 0x0204E180 and 0x0204E388, which are the two
 * OPEN rows of this same packet (pkt_0204E130) and have no branch witness
 * outside this range.  Blocking evidence class: label/matched, no outside
 * witness.  Filing either callee as an EXACT manifest entry promotes this file
 * with no change to the C (it is a `chain` row for exactly those two
 * addresses).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/TEXTPRINT_PrintText.c \
 *       --func TEXTPRINT_PrintText --addr 0x0204E328 --cc 1.1p1 --arm
 */
void TEXTPRINT_PrintText(char *text, TextParam *console)
{
    void *codeBuf = GFL_HEAP_Alloc(0, 0x200, 0, s_textprint_c, 0xae);

    TEXTPRINT_SjisToGlyphCodes(text, codeBuf, 0x100);
    TEXTPRINT_PrintCodes((const u16 *)codeBuf, console);
    GFL_HEAP_Free(codeBuf);
}



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
 * `bl STRBUF_GetEosChar; strh r0,[r5]; pop` and nothing copies r0 afterwards, but
 * a u16 return forces `c` live across the loop and costs a callee-saved sb.
 * The first byte must be spelled `u8 ch = *p; p++;` -- `u8 ch = *p++;` emits
 * `ldrb r0,[r6],#1` and loses the `and r0,r0,#0xff` that reuses the loop
 * test's `ldrsb`, four bytes short.  The lead-byte test is one `||` of a `&&`
 * and a compare, and the two-byte value is spelled `(ch << 8) + *p`, not
 * `|`: the original shows `add r0,r1,r0,lsl #8` (one byte at +0x40).
 */
void TEXTPRINT_SjisToGlyphCodes(char *text, u16 *out, int maxCodes)
{
    int count = 0;
    u16 glyphCode;

    while (*text != 0 && count < maxCodes - 1) {
        u8 ch = *text;

        text++;
        if ((ch >= 0x81 && ch <= 0x9f) || ch >= 0xe0)
            glyphCode = TEXTPRINT_SjisToGlyphCode((u16)((ch << 8) + (u8)*text++));
        else
            glyphCode = TEXTPRINT_AsciiToGlyphCode(ch);
        if (glyphCode != 0xfffe) {
            *out++ = glyphCode;
            count++;
        }
    }
    *out = STRBUF_GetEosChar();
}



/*
 * Byte-perfect: 176 compiled against 176, ZERO concrete byte mismatches,
 * `match.py one` prints MATCH only because the two pool words it needs are
 * attesting nothing outside this range:
 *
 *   +00A4 ABS32 g_TextPrintSymbolKeys -> unresolved: 020A1480 (data) has no witness
 *          outside 0204E410..0204E4C0
 *   +00A8 ABS32 g_TextPrintSymbolGlyphs -> unresolved: 020A1482 (data) has no witness
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
 *     if (c == g_TextPrintSymbolKeys[i * 4]) return *(u16 *)((u8 *)g_TextPrintSymbolGlyphs + off);
 *
 * With the offset written inline at both sites the loop counter is coloured
 * into r3, which forces the byte offset to be re-derived inside the equal
 * arm (`lsleq r1, r3, #2`); naming `off` leaves the counter in ip and hoists
 * `lsl r3, ip, #2` above the compare, exactly as the image has it.  That
 * took the residue from 25 bytes to 0.
 */
u16 TEXTPRINT_AsciiToGlyphCode(u8 asciiChar)
{
    u32 slot;

    if (asciiChar >= 0x61 && asciiChar <= 0x7a)
        return (u16)(asciiChar + 0x79);
    if (asciiChar >= 0x41 && asciiChar <= 0x5a)
        return (u16)(asciiChar + 0x7f);
    if (asciiChar >= 0x30 && asciiChar <= 0x39)
        return (u16)(asciiChar + 0x86);
    if (asciiChar >= 0x21 && asciiChar <= 0x2f)
        return (u16)(asciiChar + 0xd3);
    for (slot = 0; slot < 0x10; slot++) {
        u32 byteOffset = slot << 2;

        if (asciiChar == g_TextPrintSymbolKeys[slot * 4])
            return *(u16 *)((u8 *)g_TextPrintSymbolGlyphs + byteOffset);
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
 *   python tools/match.py one --src src/matched/TEXTPRINT_SjisToGlyphCode.c \
 *       --func TEXTPRINT_SjisToGlyphCode --addr 0x0204E4C0 --cc 1.1p1 --arm
 */
u16 TEXTPRINT_SjisToGlyphCode(u16 sjisChar)
{
    if (sjisChar >= 0x829F && sjisChar <= 0x829F + 0x52)
        return sjisChar + (4 - 0x829F);
    if (sjisChar >= 0x8340 && sjisChar <= 0x8340 + 0x53)
        return sjisChar + (0x57 - 0x8340);
    if (sjisChar >= 0x8281 && sjisChar <= 0x8281 + 0x19)
        return sjisChar + (0xDA - 0x8281);
    if (sjisChar >= 0x8260 && sjisChar <= 0x8260 + 0x19)
        return sjisChar + (0x8260 - 0x10400);
    if (sjisChar >= 0x824F && sjisChar <= 0x824F + 9)
        return sjisChar + (0xAC - 0x824F);
    if (sjisChar == 0x8189)
        return 0xCC;
    if (sjisChar == 0x8189 + 1)
        return 0xC5;
    if (sjisChar == 0x8189 - 0x49)
        return 2;
    if (sjisChar == 0x8189 - 0x2E)
        return 0x51;
    return 0x0101;
}
