/*
 * file:     systemfont.c
 * unit:     yes
 * function: SYSTEMFONT_Load, SYSTEMFONT_GetGlyph, SYSTEMFONT_ExpandRowBits, SYSTEMFONT_GetGlyphHeight, SYSTEMFONT_GetGlyphWidth, SYSTEMFONT_SetColors
 * address:  0x020461F4
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
 *   gSystemFont        0x02146A58  data
 *   kBuiltinFontData   0x020A08D0  data
 *   systemfont_File    0x020A7E98  data
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   FS_InitFile        0x020788AC  arm
 *   FS_OpenFile        0x02078C18  arm
 *   FS_GetLength       0x02078C28  arm
 *   FS_ReadFile        0x02078B70  arm
 *   FS_CloseFile       0x02078A80  arm
 *   OS_Terminate       0x02088234  arm
 */
#include "../types.h"

#include "../sdk_fs.h"

/* Header of the font data table (built-in or loaded from the archive). */
struct SystemFontHeader {
    u32 glyphOffset;       /* byte offset of the glyph bitmaps, 8 bytes (8 rows of 1bpp) each */
    u32 widthOffset;       /* byte offset of the per-glyph width bytes */
    u8  reserved08[5];
    u8  glyphHeight;
};

struct SystemFont {
    struct SystemFontHeader *data;
    u32 fgFill;            /* foreground colour index replicated into all 8 nibbles */
    u32 bgFill;            /* background colour index replicated into all 8 nibbles */
    u32 isBuiltin;         /* 1: data is the built-in table, 0: allocated and read from a file */
};

#include "gfl_heap_wrap.h"
#include "fs_file.h"
#include "os_terminate_processor.h"
void SYSTEMFONT_Load(const char *fontFile);
void SYSTEMFONT_GetGlyph(int idx, u8 *out);
u32 SYSTEMFONT_ExpandRowBits(u32 rowBits);
int SYSTEMFONT_GetGlyphHeight(void);
int SYSTEMFONT_GetGlyphWidth(void);
void SYSTEMFONT_SetColors(u32 fg, u32 bg);
extern const char systemfont_File[];
extern const u8 kBuiltinFontData[];
extern struct SystemFont *gSystemFont;

/*
 * One-time load of the module's 16-byte record.  Returns at once if the
 * record already exists; otherwise allocates it from heap 0 and either
 * points it at the built-in table at 0x020A08D0 (argument 0) or reads the
 * named archive member into a second allocation sized from the file.
 *
 * The 0x48-byte stack local is the file handle the 0x0207xxxx archive
 * calls take: init, open, length, read, close.  A failed open terminates.
 *
 * The +0xC flag records which of the two sources was used: 1 for the
 * built-in table, 0 for the file.
 *
 * Two shapes the bytes pinned down: the file arm is the `if` and the
 * built-in arm the `else` (writing the `id == 0` test first makes the
 * built-in arm fall through and moves 140 bytes), and the flag store that
 * ends the file arm is inside it, not after the whole `if`.
 *
 * PARKED AT MATCH.  Every concrete byte is right; the one wildcard is the
 * ABS32 at +0x108, the pool word holding 0x020A08D0.
 *
 * That address has no witness of any class.  It is data, not code, so
 * `label` and `veneer` are out; the bytes there are binary (a 0x10-word
 * header followed by packed values), not a NUL-terminated run, so `string`
 * is out; and the pool word at 0x020462FC is the only occurrence of the
 * word 0x020A08D0 anywhere in the image, so `literal` discards its only
 * witness for being inside the compared range.  The function is atomic, so
 * --suggest-split has nothing to cut, and `matched` cannot apply to a data
 * address with no code defining it.  Spelling the pool word as a cast
 * constant would make the file EXACT by reading the answer out of the
 * bytes under test, which is exactly what the honesty rule forbids.
 *
 * Consequence for the chain: src/pending/TEXTPRINT_Init.c (fan-in 121) was
 * blocked only on 0x020461F4, and the `matched` class needs an EXACT entry
 * here, so it stays at MATCH too.  Both unstick together if a second
 * reference to 0x020A08D0 turns up, most likely in an overlay's pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/SYSTEMFONT_Load.c \
 *       --func SYSTEMFONT_Load --addr 0x020461F4 --cc 1.1p1 --arm
 */
void SYSTEMFONT_Load(const char *fontFile)
{
    struct FSFile file;
    u32 size;

    if (gSystemFont != 0) {
        return;
    }

    gSystemFont = GFL_HEAP_Alloc(0, sizeof(*gSystemFont), 0, systemfont_File, 68);

    if (fontFile != 0) {
        FS_InitFile(&file);
        if (FS_OpenFile(&file, fontFile) == 1) {
            size = FS_GetLength(&file);
            gSystemFont->data = GFL_HEAP_Alloc(0, size, 0, systemfont_File,
                                              77);
            FS_ReadFile(&file, gSystemFont->data, size);
            FS_CloseFile(&file);
        } else {
            OS_Terminate();
        }

        gSystemFont->isBuiltin = 0;
    } else {
        gSystemFont->data = (struct SystemFontHeader *)kBuiltinFontData;
        gSystemFont->isBuiltin = 1;
        SYSTEMFONT_SetColors(1, 15);
    }
}

/*
 * Expand one 8-byte record of the loaded module table into eight words and
 * store the record's flag byte next to them.
 *
 * gSystemFont is the module record src/pending/SYSTEMFONT_Load.c allocates:
 * its `data` field points at a header whose first two words are byte
 * offsets, the first to the record array, the second to the flag bytes.
 * `idx` selects one 8-byte record of that array; its eight bytes are each
 * run through SYSTEMFONT_ExpandRowBits and the results are merged with the two masks
 * at +04/+08 of the record before being written out as eight words.
 *
 * Shape notes (each cost real bytes):
 *  - The head offsets are spelled `idx * 32 / 4`.  That literal
 *    multiply-then-divide is what makes mwcc emit the four-instruction
 *    `lsl #5 / asr #1 / add lsr #30 / add asr #2` signed-scale sequence
 *    the original shows; the algebraically identical `idx * 8` compiles to
 *    a single `lsl #3` and reallocates the whole function.
 *  - `~v` has to be spelled `v ^ 0xFFFFFFFF`: with the `~` operator the
 *    compiler rematerialises `mvn r1, r0` inside the loop, but the mask
 *    form is strength-reduced to one `mvn r4, #0` hoisted above it plus an
 *    `eor`, which is what the original does.
 *  - The flag store groups its sum as `t = hdr + hdr[1]; t[idx]`.  Writing
 *    the same sum as one subscript expression associates the other way and
 *    emits `add r0, r0, sl` / `ldrb r0, [r1, r0]` instead of
 *    `add r0, r1, r0` / `ldrb r0, [sl, r0]` -- two bytes of diff, but no
 *    other spacing reproduces the register pair.
 *  - The record pointer is re-derived from the global at the tail (six
 *    instructions) rather than kept in a register: the loop calls out, so
 *    the cached `data` cannot legally survive, and binding it to a local
 *    loses the second pool load.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYSTEMFONT_GetGlyph.c \
 *       --func SYSTEMFONT_GetGlyph --addr 0x02046300 --cc 1.1p1 --arm
 */
void SYSTEMFONT_GetGlyph(int idx, u8 *out)
{
    u8 *row = (u8 *)gSystemFont->data + gSystemFont->data->glyphOffset
              + idx * 32 / 4;
    u32 fgFill = gSystemFont->fgFill;
    u32 bgFill = gSystemFont->bgFill;
    u32 *tileWord = (u32 *)out;
    u8 *widths;
    int i;

    for (i = 0; i < 8; i++) {
        u32 mask = SYSTEMFONT_ExpandRowBits(*row++);
        u32 notMask = mask ^ 0xFFFFFFFF;
        *tileWord++ = (fgFill & mask) | (bgFill & notMask);
    }

    widths = (u8 *)gSystemFont->data + gSystemFont->data->widthOffset;
    out[0x20] = widths[idx];
}

/*
 * Expand the low eight bits of the argument into a nibble mask: bit i set
 * turns nibble i into 0xf, so bit 0 gives 0x0000000f and bit 7 gives
 * 0xf0000000.  The 0xf0000000 sits in a register outside the loop and the
 * per-iteration shift is a register (i * 4) rather than a constant, which
 * is why the loop carries a second index register: the count itself would
 * not do, the shift needs it scaled.
 *
 * The loop is a plain `for` from zero to eight; the compiler folds the test
 * into `cmp #8` / `blt` with both the test and the or predicated on a `tst`,
 * and the accumulator lives in lr.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYSTEMFONT_ExpandRowBits.c  *       --func SYSTEMFONT_ExpandRowBits --addr 0x0204638C --cc 1.1p1 --arm
 */
u32 SYSTEMFONT_ExpandRowBits(u32 rowBits)
{
    int i;
    u32 nibbleMask = 0;

    for (i = 0; i < 8; i++) {
        if (rowBits & (1 << i))
            nibbleMask |= 0xF0000000 >> (i * 4);
    }
    return nibbleMask;
}

int SYSTEMFONT_GetGlyphHeight(void){ return gSystemFont->data->glyphHeight; }

int SYSTEMFONT_GetGlyphWidth(void){ return 7; }

/*
 * Replicate a fill byte across a word, twice: both arguments are multiplied
 * by 0x11111111 and the two products go into the context's +4 and +8 words.
 * mwccarm expands the constant multiply into a chain of `orr`s with shifted
 * operands rather than spending a `mul`, and the left-associative nesting
 * puts the bare copy of the value in the last `orr` of each chain, so the
 * shift amounts run 24, 28, 20, 16, 12, 8, 4 and then a plain register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYSTEMFONT_SetColors.c \
 *       --func SYSTEMFONT_SetColors --addr 0x020463E0 --cc 1.1p1 --arm
 */
void SYSTEMFONT_SetColors(u32 fg, u32 bg)
{
    gSystemFont->fgFill = (fg << 28) | (fg << 24) | (fg << 20) | (fg << 16) |
                          (fg << 12) | (fg << 8) | (fg << 4) | fg;
    gSystemFont->bgFill = (bg << 28) | (bg << 24) | (bg << 20) | (bg << 16) |
                          (bg << 12) | (bg << 8) | (bg << 4) | bg;
}
