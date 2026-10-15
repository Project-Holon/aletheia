/*
 * file:     gf_font.c
 * unit:     yes
 * function: GF_FONT_Task, GF_FONT_Apply, GF_FONT_MeasureTextWidth, GF_FONT_CountLine, GF_FONT_MeasureWidestLine, GF_FONT_InitCallerSuppliedArray, GF_FONT_CopyLine, GF_FONT_CountLines, GF_FONT_CountControlTag, GF_FONT_SearchIndex, GF_FONT_MeasureText, GF_FONT_GetTagChar, GF_FONT_CheckD5CC, GF_FONT_GetTagGroup, GF_FONT_AppendTag, GF_FONT_GetTagKind, GF_FONT_GetTagParam, GF_FONT_SkipTag, GF_FONT_GetAlignedSize, GF_FONT_GetAllocSize, GF_FONT_GetQueueLength, GF_FONT_CopyStrbufD6D8, GF_FONT_Copy, GF_FONT_UpdatePrintsy, GF_FONT_Create, GF_FONT_Delete, GF_FONT_LoadResource, GF_FONT_FreeBuffers, GF_FONT_SetFormat, GF_FONT_InitPreloadedGlyphs, GF_FONT_InitStreamedGlyphs, GF_FONT_ExitFormat, GF_FONT_FreeGlyphData, GF_FONT_ExitStreamedGlyphs, GF_FONT_ReadGlyph, GF_FONT_GetGlyphIndex, GF_FONT_ReadPreloadedGlyph, GF_FONT_ReadStreamedGlyph, GF_FONT_DecodeGlyph, GF_FONT_GetCharWidth, GF_FONT_GetField58, GF_FONT_GetProportionalWidth, GF_FONT_GetFixedWidth, GF_FONT_InitTextColor, GF_FONT_SetDefaultTextColor, GF_FONT_SetTextColor, GF_FONT_GetTextColor, GF_FONT_IsTextColorDifferent, GF_FONT_DecodeGlyph8x8, GF_FONT_InitBitReader, GF_FONT_ReadBits, GF_FONT_DecodeGlyph8x16, GF_FONT_DecodeGlyph16x8, GF_FONT_DecodeGlyph16x16, WORDSET_CreateDefault
 * address:  0x0201CEE0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gf_font.c by tools/splitfile.py.
 *
 * symbols:
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   PRINTSYS_PrintStep  0x0201C974  thumb
 *   PRINTSYS_PrintStreamResetSpeed   0x0201CEB8  thumb
 *   MSG_SPEED_GetSlowerWait  0x02013020  thumb
 *   MSG_SPEED_GetFasterWait  0x02013050  thumb
 *   PRINTSYS_SplitWait   0x0201CDF4  thumb
 *   GF_FONT_GetCharWidth  0x0201DC6C  thumb
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_Clear  0x0204581C  arm
 *   STRBUF_AppendChar  0x02045AFC  arm
 *   GF_FONT_GetField58  0x0201DC80  thumb
 *   memcpy         0x02082D44  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   gGfFontFileName  0x020A7358 data
 *   func_020307B0  0x020307B0  arm
 *   GF_FONT_GetProportionalWidth       0x0201DC88  thumb
 *   ARC_TOOL_GetHandleMemberOffsetOut       0x020494F4  arm
 *   ARC_TOOL_GetHandleMemberSize       0x020493D4  arm
 *   sub_0204944C        0x0204944C  arm
 *   gFontFormatInitFuncs  0x0209E73C  data
 *   gFontFormatExitFuncs  0x0209E744  data
 *   func_0204960C  0x0204960C  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   gFontState   0x02146578  data
 *   gGlyphExpandTable   0x02146588  data
 *   gTopBitMasks   0x0209E74C  data
 *   STRBUF_GetLength  0x020458F8  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   WORDSET_Create 0x0201EC74 thumb arm9
 */
#include "gf_font_shared_types.h"

struct Bmp;

struct Descriptor;

struct ArcFile;

typedef signed short   s16;

struct PrintCtx {
    s16   penX;
    s16   penY;
    s32   originX : 10;
    u32   originY : 10;
    s32   colorMode : 4;
    u32   extra : 8;
    u16   letterSpacing;
    u16   lineSpacing;
    u16   textColor;
    u16   shadowColor;
    void *font;
    void *bmp;
    void *blitGlyph;
};

struct TextPrinter {
    u32  state;
    u32  waitKind;
    struct Descriptor *updateTarget;
    struct Bmp *bmp;
    void *task;
    u16 *cursor;
    u8   defaultWait;
    u8   defaultGlyphs;
    u8   waitFrames;
    u8   glyphsPerTick;
    u8   overrideWait;
    u8   overrideGlyphs;
    u8   waitCounter;
    u8   scrollPixels;
    u8   fillColor;
    u8   callbackResult;
    struct {
        u8 halted : 1;
        u8 scrolling : 1;
        u8 advance : 1;
        u8 useOverrideSpeed : 1;
        u8 clearOverridePending : 1;
        u8 reserved : 3;
    } flags;
    u8   pad23;
    u8 (*callback)(u32);
    u32  initialCallbackArg;
    u32  nextCallbackArg;
    u32  callbackArg;
    struct PrintCtx ctx;
};

struct PrintQueue {
    u16 head;
    u16 tail;
    u16 capacity;
    u8  submitCount;
    u8  stateBits;
    u32 timeoutTicksLow;
    u32 timeoutTicksHigh;
    void *firstRecord;
    void *text;
    u8  data[4];
};

struct CMap {
    u16 ccodeBegin;
    u16 ccodeEnd;
    u16 mappingMethod;
    u16 reserved;
    struct CMap *pNext;
    u16 mapInfo[1];
};

typedef signed   char  s8;

struct BitReader {
    const u8 *src;
    u32       bitsLeft;
    u8        current;
};

struct FontState {
    u8               textColor[3];
    u8               pad;
    struct BitReader reader;
};

struct FontInfo {
    u8  fontType;
    u8  lineHeight;
    u16 nullGlyphIndex;
    u8  defaultLeft;
    u8  defaultGlyphWidth;
    u8  defaultCharWidth;
    u8  encoding;
    u32 glyphBlockOffset;
    u32 widthBlockOffset;
    u32 mapBlockOffset;
};

struct GlyphInfo {
    u8  cellWidth;
    u8  cellHeight;
    u16 cellSize;
    s8  baseline;
    u8  maxCharWidth;
    u8  bitsPerPixel;
    u8  flags;
};

struct GlyphWidthTable {
    u8  defaultWidths[3];
    u8  pad3;
    u32 classOffset;
    u32 hashOffset;
    u32 chainOffset;
};

struct GfFont;

typedef void (*GlyphReadFunc)(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics);

typedef void (*GlyphDecodeFunc)(const u8 *src, u32 lastGroupBits, u16 *dst);

typedef u32 (*CharWidthFunc)(struct GfFont *font, u32 glyphIndex);

struct GfFont {
    u32 format;
    GlyphReadFunc readGlyph;
    GlyphDecodeFunc decodeGlyph;
    u8 *glyphData;
    u8 pad10[0x40];
    struct ArcFile *arc;
    u32 fileId;
    struct FontInfo info;
    CharWidthFunc getCharWidth;
    u16 missingGlyphIndex;
    u8  isFixedWidth;
    u8  pad73;
    struct GlyphInfo glyph;
    u16 lastGroupBits;
    u8  tilesWide;
    u8  tilesHigh;
    u32 arcBase;
    struct GlyphWidthTable *widthTable;
    u8 *charMap;
    u32 glyphDataOffset;
    void *scratch;
};

typedef void (*FormatInitFunc)(struct GfFont *font, u32 tilesWide, u32 tilesHigh, u32 heapId);

typedef void (*FormatExitFunc)(struct GfFont *font);

extern u16 BMP_GetWidth(const struct Bmp *bmp);

extern u16 BMP_GetHeight(const struct Bmp *bmp);

extern void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 width, u32 height, u32 transparentColor);

extern void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 width, u32 height, u32 fillColor);

extern void BMP_Clear(struct Bmp *bmp, u8 fillColor);

extern void BMP_WIN_TransferChars(struct Descriptor *target);

extern u16 *PRINTSYS_PrintStep(struct PrintCtx *ctx, u16 *cursor, u32 stopAtPause);

extern void PRINTSYS_PrintStreamResetSpeed(struct TextPrinter *printer);

extern signed char MSG_SPEED_GetSlowerWait(void);

extern signed char MSG_SPEED_GetFasterWait(void);

extern void PRINTSYS_SplitWait(s32 speedSetting, u8 *waitAndGlyphs);

extern u16 *STRBUF_GetChars(struct Strbuf *text);

extern void STRBUF_Clear(struct Strbuf *text);

extern void STRBUF_AppendChar(struct Strbuf *text, u16 value);

extern u16 STRBUF_GetLength(struct Strbuf *text);

extern void *memcpy(void *dst, const void *src, u32 n);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *fileName, u16 line);

extern struct ArcFile *func_020490F4(unsigned int id, unsigned int heap);

extern u32 func_020307B0(void *block);

extern void sub_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);

extern void ARC_TOOL_GetHandleMemberOffsetOut(struct ArcFile *arc, u32 member, u32 *out);

extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);

extern void ARC_TOOL_DeleteHandle(struct ArcFile *arc);

extern void func_0204960C(struct ArcFile *arc, u32 offset);

extern void ARC_TOOL_ReadHandle(struct ArcFile *arc, u32 size, void *dst);

void GF_FONT_Task(void *task, struct TextPrinter *printer);

void GF_FONT_Apply(struct TextPrinter *printer);

u32 GF_FONT_MeasureTextWidth(u16 *cursor, struct GfFont *font, u32 spacing, u16 **next);

u32 GF_FONT_CountLine(struct Strbuf *text);

u32 GF_FONT_MeasureWidestLine(struct Strbuf *text, struct GfFont *font, u32 spacing);

u32 GF_FONT_InitCallerSuppliedArray(struct Strbuf *text, struct GfFont *font, u32 spacing, u32 *widths, u32 maxLines);

u32 GF_FONT_CopyLine(struct Strbuf *src, struct Strbuf *dst, u32 lineNumber);

u32 GF_FONT_CountLines(struct Strbuf *text, struct GfFont *font);

u32 GF_FONT_CountControlTag(struct Strbuf *text);

u32 GF_FONT_SearchIndex(struct Strbuf *text, u8 markerId);

u32 GF_FONT_MeasureText(struct Strbuf *text, u8 markerId, struct GfFont *font, u32 spacing);

u32 GF_FONT_GetTagChar(void);

u32 GF_FONT_CheckD5CC(const u16 *tag);

u32 GF_FONT_GetTagGroup(const u16 *tag);

void GF_FONT_AppendTag(struct Strbuf *text, u32 group, u32 kind, u16 paramCount, const u16 *params);

u32 GF_FONT_GetTagKind(const u16 *tag);

u32 GF_FONT_GetTagParam(const u16 *tag, u32 paramIndex);

u16 *GF_FONT_SkipTag(u16 *tag);

u32 GF_FONT_GetAlignedSize(struct Strbuf *text);

u32 GF_FONT_GetAllocSize(struct Strbuf *text);

u32 GF_FONT_GetQueueLength(const struct PrintQueue *queue);

void GF_FONT_CopyStrbufD6D8(struct PrintQueue *queue, void *record, struct Strbuf *text);

void *GF_FONT_Copy(struct PrintQueue *queue, const u8 *src, u16 length, u16 unit);

void *GF_FONT_UpdatePrintsy(struct PrintQueue *queue, void *record);

struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);

u32 GF_FONT_Delete(struct GfFont *font);

void GF_FONT_LoadResource(struct GfFont *font, int fileId, u32 isFixedWidth, u32 heapId);

void GF_FONT_FreeBuffers(struct GfFont *font);

void GF_FONT_SetFormat(struct GfFont *font, u32 format, u32 heapId);

void GF_FONT_InitPreloadedGlyphs(struct GfFont *font, u32 tilesWide, u32 tilesHigh, u8 heapId);

void GF_FONT_InitStreamedGlyphs(struct GfFont *font, int tilesWide, int tilesHigh);

void GF_FONT_ExitFormat(struct GfFont *font);

void GF_FONT_FreeGlyphData(struct GfFont *font);

void GF_FONT_ExitStreamedGlyphs(struct GfFont *font);

void GF_FONT_ReadGlyph(struct GfFont *font, u16 ch, void *dst, u8 *metrics);

u32 GF_FONT_GetGlyphIndex(struct GfFont *font, u16 ch);

void GF_FONT_ReadPreloadedGlyph(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics);

void GF_FONT_ReadStreamedGlyph(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics);

void GF_FONT_DecodeGlyph(const struct GfFont *font, const u8 *glyph, u32 lastGroupBits, void *dst, u8 *metrics);

u32 GF_FONT_GetCharWidth(struct GfFont *font, u16 ch);

u32 GF_FONT_GetField58(struct GfFont *font);

u32 GF_FONT_GetProportionalWidth(struct GfFont *font, u32 glyphIndex);

u32 GF_FONT_GetFixedWidth(struct GfFont *font, u32 glyphIndex);

void GF_FONT_InitTextColor(void);

void GF_FONT_SetDefaultTextColor(void);

void GF_FONT_SetTextColor(u32 red, u32 green, u32 blue);

void GF_FONT_GetTextColor(u8 *red, u8 *green, u8 *blue);

u32 GF_FONT_IsTextColorDifferent(u32 red, u32 green, u32 blue);

void GF_FONT_DecodeGlyph8x8(const u8 *src, u32 lastGroupBits, u16 *dst);

void GF_FONT_InitBitReader(struct BitReader *reader, const u8 *src);

u8 GF_FONT_ReadBits(struct BitReader *reader, u8 count);

void GF_FONT_DecodeGlyph8x16(const u8 *src, u32 lastGroupBits, u16 *dst);

void GF_FONT_DecodeGlyph16x8(const u8 *src, u32 lastGroupBits, u16 *dst);

void GF_FONT_DecodeGlyph16x16(const u8 *src, u32 lastGroupBits, u16 *dst);

struct WordSet *WORDSET_CreateDefault(u16 heapId);

struct WordSet *WORDSET_Create(u32 slotCount, u32 textCapacity, u16 heapId);

extern const char gGfFontFileName[];

extern const char gGfFontFileName[];

extern FormatInitFunc gFontFormatInitFuncs[];

extern const char gGfFontFileName[];

extern FormatExitFunc gFontFormatExitFuncs[];

extern struct FontState gFontState;

extern u16 gGlyphExpandTable[256];

extern const u8         gTopBitMasks[];

static inline u32 TagGroupOrNone(u16 code, const u16 *tag)
{
    if (code == 0xF000)
        return (u8)(tag[1] >> 8);
    return 0xFF;
}

/*
 * The per-frame task callback that PRINTSYS_PrintStreamCallBack installs for a printsys
 * text record (the 0x50-byte object, struct PrintCtx at +0x34).  State 0
 * either scrolls the window up by at most four lines (flag bit 1) or, once
 * the wait counter at +0x1e is spent, prints up to glyphsPerTick/overrideGlyphs glyphs through
 * PRINTSYS_PrintStep, handling 0xFFFF (end: state 2), 0xFFFE (line break) and
 * the 0xF000/0xBE control block (GF_FONT_Apply).  State 1 waits on flag
 * bit 2 and then clears or scrolls the window.
 *
 * Shape facts, each measured against the bytes:
 *  - The flag byte at +0x22 is a struct of 1-bit fields.  Reads through
 *    the bitfield give the lsls/lsrs pairs off ONE cached ldrb; writes
 *    through the same bitfield reload the byte each time.  Spelled with
 *    `((u8 *)p)[0x22]` masks the tests fold to `tst` and the writes reuse
 *    the cached byte.
 *  - The two early exits are `goto end`, not `return`: they land on the
 *    function's LAST epilogue through a branch island, as a `break` would
 *    (docs/idioms/an-empty-switch-arm-breaks-to-the-last-epilogue-not-the-nearest.md).
 *  - The glyph loop is `i = 0; if (i < n) { ...; do { } while (i < n); }`
 *    with `ctx = &p->ctx;` in the guarded preheader.  A `for` loop puts
 *    the store before the guard and duplicates the test.
 *  - The dispatch is a switch on the loaded halfword, and the control-code
 *    helper takes that VALUE: its own `== 0xF000` test then reuses the
 *    switch's compare, which is the dead `bne` at 0x0201D01E.  Given the
 *    pointer it reloads the halfword and is eight bytes long.
 *  - `case 1: default:` share one arm in the inner mode switch, which is
 *    why the image has `cmp r0, #1` followed by an unconditional `b`.
 *
 * note 2026-10-05: removed the stand-in first store of the pair
 * `ctx = (struct PrintCtx *)p; ctx = &p->ctx;`. The single
 * `ctx = &p->ctx;` is EXACT in --lang c99 and --lang c.
 */
void GF_FONT_Task(void *task, struct TextPrinter *printer)
{
    s32 glyphsThisTick;
    s32 glyphIndex;
    u32 width;
    s32 height;
    struct PrintCtx *ctx;
    u16 code;

    if (printer->callback != 0 && printer->callbackResult != 0) {
        printer->callbackResult = printer->callback(printer->callbackArg);
        if (printer->callbackResult != 0)
            goto end;
        printer->callbackArg = printer->nextCallbackArg;
    }

    if (printer->flags.halted)
        goto end;

    switch (printer->state) {
    case 0:
        if (printer->flags.scrolling) {
            if (printer->scrollPixels < 0x10) {
                u16 step = 4;
                if (printer->scrollPixels + 4 > 0x10)
                    step = 0x10 - printer->scrollPixels;
                printer->scrollPixels += (u8)step;
                width = BMP_GetWidth(printer->bmp);
                height = BMP_GetHeight(printer->bmp) - step;
                BMP_Blit(printer->bmp, printer->bmp, 0, step, 0, 0, width, height, 0xFFFF);
                BMP_FillRect(printer->bmp, 0, (s16)height, width, step, printer->fillColor);
                BMP_WIN_TransferChars(printer->updateTarget);
                return;
            }
            printer->ctx.penX = printer->ctx.originX;
            printer->ctx.penY = 0x10;
            printer->flags.scrolling = 0;
            return;
        }
        if (printer->waitCounter == 0) {
            if (printer->flags.useOverrideSpeed)
                glyphsThisTick = printer->overrideGlyphs;
            else
                glyphsThisTick = printer->glyphsPerTick;
            if (printer->flags.clearOverridePending) {
                PRINTSYS_PrintStreamResetSpeed(printer);
                printer->flags.clearOverridePending = 0;
            }
            glyphIndex = 0;
            if (glyphIndex < glyphsThisTick) {
                ctx = &printer->ctx;
                do {
                    code = *printer->cursor;
                    switch (code) {
                    case 0xFFFF:
                        printer->state = 2;
                        break;
                    case 0xF000:
                        if (TagGroupOrNone(code, printer->cursor) == 0xBE) {
                            GF_FONT_Apply(printer);
                            if (printer->callback != 0) {
                                printer->callbackResult = printer->callback(printer->callbackArg);
                                if (printer->callbackResult != 0)
                                    glyphIndex = glyphsThisTick;
                                else
                                    printer->callbackArg = printer->nextCallbackArg;
                            }
                            if (printer->state != 0 || printer->waitCounter != 0)
                                glyphIndex = glyphsThisTick;
                            break;
                        }
                    default:
                        printer->cursor = PRINTSYS_PrintStep(ctx, printer->cursor, 0);
                        code = *printer->cursor;
                        if (code == 0xFFFF) {
                            printer->state = 2;
                        } else if (code != 0xFFFE) {
                            if (printer->flags.useOverrideSpeed)
                                printer->waitCounter = printer->overrideWait;
                            else
                                printer->waitCounter = printer->waitFrames;
                        }
                        BMP_WIN_TransferChars(printer->updateTarget);
                        if (printer->callback != 0) {
                            printer->callbackResult = printer->callback(printer->callbackArg);
                            if (printer->callbackResult != 0)
                                glyphIndex = glyphsThisTick;
                            else
                                printer->callbackArg = printer->nextCallbackArg;
                        }
                        break;
                    }
                    glyphIndex++;
                } while (glyphIndex < glyphsThisTick);
            }
        } else {
            printer->waitCounter--;
        }
        return;
    case 1:
        if (printer->flags.advance) {
            switch (printer->waitKind) {
            case 0:
                printer->flags.scrolling = 1;
                printer->state = 0;
                return;
            case 1:
            default:
                BMP_Clear(printer->bmp, printer->fillColor);
                printer->state = 0;
                return;
            }
        }
        return;
    }
end:
    ;
}

static inline u32 TagKindByte(const u16 *tag)
{
    return (u8)tag[1];
}

static inline u16 TagKindOrNone(u16 code, const u16 *tag)
{
    if (code == 0xF000)
        return TagKindByte(tag);
    return 0xFFFF;
}

static inline u16 TagParam(u16 code, const u16 *tag, u32 paramIndex)
{
    if (code == 0xF000)
        return *(tag + paramIndex + 3);
    return 0;
}

static inline u16 TagParamOfCursor(const u16 *tag, u32 paramIndex)
{
    u16 code = tag[0];
    if (code == 0xF000)
        return *(tag + paramIndex + 3);
    return 0;
}

static inline u16 *SkipTag(u16 *tag)
{
    if (tag[0] == 0xF000)
        return tag + 3 + tag[2];
    return tag;
}

static inline void SetWaitState(struct TextPrinter *printer, u32 waitKind)
{
    printer->state = 1;
    printer->waitKind = waitKind;
}

/*
 * Applies the 0xF000 control block the text record's cursor is parked on
 * and steps the cursor past it (struct TextPrinter as in GF_FONT_Task).  The
 * block's kind (low byte of its second halfword) is a dense 0..9 switch:
 * 0/1 pause for a key (mode 0 or 1) and home the pen, 2 sets the wait,
 * 3/4/9 set the per-glyph delay pair at +0x1a/+0x1b (9 through the
 * speed setting MSG_SPEED_GetSlowerWait / MSG_SPEED_GetFasterWait and PRINTSYS_SplitWait), 5/6/7
 * set the callback argument, 8 clears the window.  A pause also skips a
 * 0xFFFE that directly follows the block.
 *
 * Shape facts measured against the bytes:
 *  - `*cur` is a named local: it is the LEFT operand of the header test
 *    (docs/idioms/cmp-operand-order-names-the-temporary.md), and the
 *    per-case argument reads reuse it.  Only case 6's second read goes
 *    back through p->cur, after the +0x2c store.
 *  - The kind helper returns u32 `(u8)p[1]` into a u16 return, which is
 *    the (u8) then (u16) shift-pair stack in the header arm only.
 *  - state/mode are written by an inline taking the record as its own
 *    parameter; written in line, mwcc hoists the flag-byte load above
 *    those two stores and cases 0/1 stop cross-jumping (20 bytes).
 *  - In the shared tail the pen x copy precedes the pen y clear.
 */
void GF_FONT_Apply(struct TextPrinter *printer)
{
    u32 skipLineBreak;
    u8 speed[2];
    u16 *cursor;
    u16 code;

    cursor = printer->cursor;
    code = cursor[0];
    skipLineBreak = 0;
    switch (TagKindOrNone(code, cursor)) {
    case 0:
        skipLineBreak = 1;
        SetWaitState(printer, 0);
        printer->scrollPixels = 0;
        printer->flags.advance = 0;
        printer->ctx.penX = printer->ctx.originX;
        printer->ctx.penY = 0;
        break;
    case 1:
        skipLineBreak = 1;
        SetWaitState(printer, 1);
        printer->scrollPixels = 0;
        printer->flags.advance = 0;
        printer->ctx.penX = printer->ctx.originX;
        printer->ctx.penY = 0;
        break;
    case 2:
        printer->waitCounter = TagParam(code, cursor, 0);
        break;
    case 3:
        printer->waitFrames = TagParam(code, cursor, 0);
        break;
    case 4:
        printer->waitFrames = printer->defaultWait;
        break;
    case 9:
        switch ((u8)TagParam(code, cursor, 0)) {
        case 0:
        default:
            speed[0] = printer->defaultWait;
            speed[1] = printer->defaultGlyphs;
            break;
        case 1:
            PRINTSYS_SplitWait(MSG_SPEED_GetSlowerWait(), speed);
            break;
        case 2:
            PRINTSYS_SplitWait(MSG_SPEED_GetFasterWait(), speed);
            break;
        }
        printer->waitFrames = speed[0];
        printer->glyphsPerTick = speed[1];
        break;
    case 5:
        printer->callbackArg = TagParam(code, cursor, 0);
        break;
    case 6:
        printer->nextCallbackArg = TagParam(code, cursor, 0);
        printer->callbackArg = TagParamOfCursor(printer->cursor, 0);
        break;
    case 7:
        printer->nextCallbackArg = printer->initialCallbackArg;
        printer->callbackArg = printer->initialCallbackArg;
        break;
    case 8:
        BMP_Clear(printer->bmp, printer->fillColor);
        break;
    }

    cursor = SkipTag(printer->cursor);
    printer->cursor = cursor;
    if (skipLineBreak != 0 && *cursor == 0xFFFE)
        printer->cursor = cursor + 1;
}

/*
 * printsys.c: measures one line of a string object.  It sums the per-glyph
 * advance GF_FONT_GetCharWidth returns plus a fixed inter-character spacing until it
 * hits the line break 0xFFFE or the terminator 0xFFFF, steps over embedded
 * 0xF000 blocks (three header halfwords plus the payload count at +4), and,
 * when the fourth argument is non-NULL, writes back the cursor for the next
 * line (past the break, if that is what stopped it).
 *
 * 0xFFFF is not pooled: the compiler keeps the pooled 0xFFFE in a register and
 * derives the terminator as `adds r6, r0, #1`.
 *
 * The repeated `c == 0xF000` test is the source's own: the block skip re-tests
 * the code word it was selected by, and the compiler keeps the second branch
 * while folding away the second compare.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_MeasureTextWidth.c
 *       --func GF_FONT_MeasureTextWidth --addr 0x0201D26C --cc 1.1p1 --thumb
 */
u32 GF_FONT_MeasureTextWidth(u16 *cursor, struct GfFont *font, u32 spacing, u16 **next)
{
    u32 width;
    u16 code;

    width = 0;
    while ((code = *cursor) != 0xFFFF && code != 0xFFFE) {
        if (code != 0xF000) {
            width += spacing + GF_FONT_GetCharWidth(font, code);
            cursor++;
        } else {
            if (code == 0xF000) {
                cursor = cursor + 3 + cursor[2];
            }
        }
    }
    if (next != 0) {
        if (code == 0xFFFE) {
            cursor++;
        }
        *next = cursor;
    }
    return width;
}

/*
 * printsys.c: counts the lines of a string object, i.e. one plus the number
 * of 0xFFFE line-break codes before the 0xFFFF terminator.  0xF000 opens an
 * embedded block whose halfword length sits at +4, so the walker steps over
 * three header halfwords plus that many payload halfwords.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_CountLine.c
 *       --func GF_FONT_CountLine --addr 0x0201D2C8 --cc 1.1p1 --thumb
 */
u32 GF_FONT_CountLine(struct Strbuf *text)
{
    u16 *cursor;
    u32 lineCount;
    u16 code;

    cursor = STRBUF_GetChars(text);
    code = *cursor;
    lineCount = 1;
    while (code != 0xFFFF) {
        if (code != 0xF000) {
            if (code == 0xFFFE) {
                lineCount++;
            }
            cursor++;
        } else {
            if (code == 0xF000) {
                cursor = cursor + 3 + cursor[2];
            }
        }
        code = *cursor;
    }
    return lineCount;
}

/*
 * printsys.c: the width of the widest line of a multi-line string.  It walks
 * the string object's halfword payload one line at a time with GF_FONT_MeasureTextWidth,
 * which measures one line and writes the cursor for the next one back through
 * its fourth argument, and keeps the running maximum.  0xFFFF is the string
 * terminator (the same sentinel PRINTSYS_RunJob stops on).
 *
 * The cursor is a local whose address is taken, so it lives on the stack and
 * the loop test reloads it every iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_MeasureWidestLine.c
 *       --func GF_FONT_MeasureWidestLine --addr 0x0201D304 --cc 1.1p1 --thumb
 */
u32 GF_FONT_MeasureWidestLine(struct Strbuf *text, struct GfFont *font, u32 spacing)
{
    u16 *cursor;
    u32 widest;
    u32 lineWidth;

    widest = 0;
    cursor = STRBUF_GetChars(text);
    while (*cursor != 0xFFFF) {
        lineWidth = GF_FONT_MeasureTextWidth(cursor, font, spacing, &cursor);
        if (lineWidth > widest) {
            widest = lineWidth;
        }
    }
    return widest;
}

/*
 * printsys.c: fills a caller-supplied array with the pixel width of each line
 * of a string object, at most `max` of them, and returns how many were
 * written.  GF_FONT_MeasureTextWidth measures one line and hands back the cursor for the
 * next through its fourth argument; the cursor is a stack local because its
 * address is taken.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_InitCallerSuppliedArray.c
 *       --func GF_FONT_InitCallerSuppliedArray --addr 0x0201D33C --cc 1.1p1 --thumb
 */
u32 GF_FONT_InitCallerSuppliedArray(struct Strbuf *text, struct GfFont *font, u32 spacing, u32 *widths, u32 maxLines)
{
    u16 *cursor;
    u32 lineIndex;

    cursor = STRBUF_GetChars(text);
    lineIndex = 0;
    while (lineIndex < maxLines) {
        if (*cursor == 0xFFFF) {
            break;
        }
        widths[lineIndex] = GF_FONT_MeasureTextWidth(cursor, font, spacing, &cursor);
        lineIndex++;
    }
    return lineIndex;
}

/*
 * printsys.c: copies line `n` of a string object into a second, freshly
 * cleared string object and returns whether the line existed.  Phase one skips
 * n line breaks, phase two appends the line a halfword at a time and closes it
 * with the 0xFFFF terminator.  Embedded 0xF000 blocks are skipped in phase one
 * and copied verbatim in phase two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_CopyLine.c
 *       --func GF_FONT_CopyLine --addr 0x0201D37C --cc 1.1p1 --thumb
 */
u32 GF_FONT_CopyLine(struct Strbuf *src, struct Strbuf *dst, u32 lineNumber)
{
    u16 *tagEnd;
    u16 *cursor;
    u16 code;

    cursor = STRBUF_GetChars(src);
    STRBUF_Clear(dst);
    while (lineNumber != 0) {
        while ((code = *cursor) != 0xFFFF && code != 0xFFFE) {
            if (code != 0xF000) {
                cursor++;
            } else {
                if (code == 0xF000) {
                    cursor = cursor + 3 + cursor[2];
                }
            }
        }
        lineNumber--;
        if (code == 0xFFFF) {
            break;
        }
        cursor++;
    }
    if (lineNumber == 0 && *cursor != 0xFFFF) {
        while ((code = *cursor) != 0xFFFF && code != 0xFFFE) {
            if (code != 0xF000) {
                STRBUF_AppendChar(dst, *cursor++);
            } else {
                if (code == 0xF000) {
                    tagEnd = cursor + 3;
                tagEnd = tagEnd + cursor[2];
                } else {
                    tagEnd = cursor;
                }
                while (cursor < tagEnd) {
                    STRBUF_AppendChar(dst, *cursor++);
                }
            }
        }
        STRBUF_AppendChar(dst, 0xFFFF);
        return 1;
    }
    return 0;
}

/*
 * printsys.c: the pixel height of a string object, i.e. its line count times
 * the font's line height (GF_FONT_GetField58).  The line counter is a u16, so the
 * increment carries the halfword truncation pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_CountLines.c
 *       --func GF_FONT_CountLines --addr 0x0201D42C --cc 1.1p1 --thumb
 */
u32 GF_FONT_CountLines(struct Strbuf *text, struct GfFont *font)
{
    u16 *cursor;
    u16 code;
    u16 lineBreaks;

    cursor = STRBUF_GetChars(text);
    code = *cursor;
    lineBreaks = 0;
    while (code != 0xFFFF) {
        if (code == 0xFFFE) {
            lineBreaks++;
        }
        if (code == 0xF000) {
            if (code == 0xF000) {
                cursor = cursor + 3 + cursor[2];
            }
        } else {
            cursor++;
        }
        code = *cursor;
    }
    return (lineBreaks + 1) * GF_FONT_GetField58(font);
}

/*
 * Counts the control tags of a message string for which GF_FONT_CheckD5CC returns
 * true.  The walk is the one every routine in this neighbourhood uses: 0xF000
 * opens a tag and GF_FONT_SkipTag steps over it, anything else is one halfword,
 * and 0xFFFF ends the string.
 *
 * The counter and the cursor are interchanged unless the cursor is declared
 * first: the original keeps the cursor in r4 and the counter in r5 while the
 * counter is the one initialised first, which is
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md read in
 * the direction that costs the time.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D478.c \
 *       --addr 0x0201D478 --thumb
 */
u32 GF_FONT_CountControlTag(struct Strbuf *text)
{
    u16 *cursor;
    u16 count = 0;

    cursor = STRBUF_GetChars(text);

    while (cursor[0] != 0xFFFF) {
        if (cursor[0] == 0xF000) {
            if (GF_FONT_CheckD5CC(cursor) != 0) {
                count = (u16)(count + 1);
            }
            cursor = GF_FONT_SkipTag(cursor);
        } else {
            cursor = cursor + 1;
        }
    }
    return count;
}

/*
 * Finds the index of the 0xBD06 tag whose first parameter is the caller's
 * value, counting 0xFFFE separators as it goes.  The tag's parameter is read
 * with GF_FONT_GetTagParam's body written out inline (`p[0] == 0xF000 ? p[3] : 0`),
 * including the redundant re-test of p[0] that the caller has already made: that
 * guard is in the bytes and removing it costs four instructions.
 *
 * 0xFFFE is not a second pool word.  The original loads 0xFFFF once and derives
 * 0xFFFE with `subs r4, r0, #1`, which is ordinary common subexpression
 * elimination on the constant and needs nothing in the source.
 *
 * The leading call to STRBUF_GetChars whose result is discarded is in the original
 * and is reproduced rather than tidied.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D4BC.c \
 *       --addr 0x0201D4BC --thumb
 */
u32 GF_FONT_SearchIndex(struct Strbuf *text, u8 markerId)
{
    u16 *cursor;
    u16 lineBreaks = 0;
    u32 param;

    STRBUF_GetChars(text);
    cursor = STRBUF_GetChars(text);
    while (cursor[0] != 0xFFFF) {
        if (cursor[0] == 0xFFFE) {
            lineBreaks = (u16)(lineBreaks + 1);
        }
        if (cursor[0] == 0xF000) {
            if (cursor[1] == 0xBD06) {
                if (cursor[0] == 0xF000) {
                    param = cursor[3];
                } else {
                    param = 0;
                }
                if (markerId == param) {
                    return (u8)lineBreaks;
                }
            }
            cursor = GF_FONT_SkipTag(cursor);
        } else {
            cursor = cursor + 1;
        }
    }
    return 0;
}

/*
 * Measures a message string up to the 0xBD06 tag whose parameter is the
 * caller's value, in the font c, adding d of spacing per character.  0xFFFE
 * resets the running width, a 0xBD04 tag adds its parameter, and anything that
 * is not a tag is measured with GF_FONT_GetCharWidth.
 *
 * The halfword under the cursor has to be a named local.  Written as `p[0]` at
 * each of its five uses the compiler caches it in r1, which is the second
 * argument register, and the call to GF_FONT_GetCharWidth then needs no move; the
 * original caches it in r2 and spends `adds r1, r2, #0`, which is two bytes and
 * is the only difference between the two spellings.  That is the argument form
 * of docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D528.c \
 *       --addr 0x0201D528 --thumb
 */
u32 GF_FONT_MeasureText(struct Strbuf *text, u8 markerId, struct GfFont *font, u32 spacing)
{
    u32 width = 0;
    u16 *cursor;
    u32 param;
    u16 code;

    cursor = STRBUF_GetChars(text);
    while (cursor[0] != 0xFFFF) {
        code = cursor[0];
        if (cursor[0] == 0xFFFE) {
            width = 0;
            cursor = cursor + 1;
        } else if (cursor[0] != 0xF000) {
            width = width + (spacing + GF_FONT_GetCharWidth(font, code));
            cursor = cursor + 1;
        } else {
            if (cursor[1] == 0xBD06) {
                if (cursor[0] == 0xF000) {
                    param = cursor[3];
                } else {
                    param = 0;
                }
                if (markerId == param) {
                    return (u8)width;
                }
            }
            if (cursor[1] == 0xBD04) {
                if (cursor[0] == 0xF000) {
                    param = cursor[3];
                } else {
                    param = 0;
                }
                width = width + param;
            }
            if (cursor[0] == 0xF000) {
                cursor = cursor + 3 + cursor[2];
            }
        }
    }
    return 0;
}

/*
 *           GF_FONT_GetTagKind, GF_FONT_GetTagParam, GF_FONT_SkipTag
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  GF_FONT_SkipTag steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * GF_FONT_GetTagGroup, GF_FONT_GetTagKind and GF_FONT_GetTagParam were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - GF_FONT_GetTagParam indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * GF_FONT_AppendTag's parameter count is `u16`, not `u32`: it is passed straight to
 * STRBUF_AppendChar with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
u32 GF_FONT_GetTagChar(void)
{
    return 0xF000;
}

u32 GF_FONT_CheckD5CC(const u16 *tag)
{
    u32 group;

    if (tag[0] == 0xF000) {
        group = (u8)(tag[1] >> 8);
    } else {
        group = 0xFF;
    }
    switch (group) {
    case 1:
    case 2:
        return 1;
    }
    return 0;
}

u32 GF_FONT_GetTagGroup(const u16 *tag)
{
    if (tag[0] == 0xF000) {
        return (u8)(tag[1] >> 8);
    }
    return 0xFF;
}

void GF_FONT_AppendTag(struct Strbuf *text, u32 group, u32 kind, u16 paramCount, const u16 *params)
{
    u32 index;

    STRBUF_AppendChar(text, 0xF000);
    STRBUF_AppendChar(text, (u16)((u16)(group << 8) | kind));
    STRBUF_AppendChar(text, paramCount);
    for (index = 0; index < paramCount; index = (u8)(index + 1)) {
        STRBUF_AppendChar(text, params[index]);
    }
}

u32 GF_FONT_GetTagKind(const u16 *tag)
{
    if (tag[0] == 0xF000) {
        return (u8)tag[1];
    }
    return 0xFF;
}

u32 GF_FONT_GetTagParam(const u16 *tag, u32 paramIndex)
{
    if (tag[0] == 0xF000) {
        return *(tag + paramIndex + 3);
    }
    return 0;
}

u16 *GF_FONT_SkipTag(u16 *tag)
{
    if (tag[0] == 0xF000) {
        return tag + 3 + tag[2];
    }
    return tag;
}

/*
 * The first three functions of gf_font.c.  The file identity is in the image:
 * the constructor at 0x0201D7EC passes 0x020A7358 to the debug allocator at
 * 0x02030734 and the bytes there spell "gf_font.c"; 0x0201D9BC and 0x0201DA88
 * name the same string.  This unit stops at 0x0201D6D8 because the two
 * functions after it are an unsolved register allocation, not a missing
 * declaration; see the note at the end of this comment.
 *
 * GF_FONT_GetAlignedSize sizes a string's storage: two bytes per character plus the
 * terminator, rounded up to a multiple of four.  The rounding is a `while`
 * loop over `n & 3`, not an `& ~3` or a `+ 3 & ~3`: this front end has no
 * immediate `bic`, so either of those would materialise the mask and the
 * function would be four bytes shorter with no loop at all.  The loop really
 * is in the original.
 *
 * GF_FONT_GetQueueLength is the used-byte count of a wrap-around byte ring.  The
 * fall-through arm of `cmp r1, r2` / `bhs` is the non-wrapped case, so the
 * source wrote `if (head < tail)` first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md); written as the
 * wrapped case first it is ten of the twenty bytes wrong.
 *
 * Left open at 0x0201D6D8: GF_FONT_CopyStrbufD6D8 and GF_FONT_Copy reproduce the
 * right size and the right instruction multiset but allocate registers the
 * other way round.  The original keeps the ring's write cursor in a
 * callee-saved register across the MI_CpuCopy8 call and spills the loop
 * counter; every source shape tried so far (three local layouts, six
 * declaration orders, struct against scalars, one against two assignments of
 * the buffer base) gives the opposite choice and 72 differing bytes, with no
 * variation between them.  The buffer base is assigned twice, once as the
 * object pointer and once with 0x18 added, which is the aggregate-member
 * non-folding of
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md, but
 * modelling it as an aggregate member does not move the diff either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D69C.c \
 *       --addr 0x0201D69C --thumb
 */
u32 GF_FONT_GetAlignedSize(struct Strbuf *text)
{
    u32 bytes = (STRBUF_GetLength(text) + 1) * 2;

    while ((bytes & 3) != 0) {
        bytes++;
    }
    return bytes;
}

u32 GF_FONT_GetAllocSize(struct Strbuf *text)
{
    return GF_FONT_GetAlignedSize(text) + 0x20;
}

u32 GF_FONT_GetQueueLength(const struct PrintQueue *queue)
{
    if (queue->head < queue->tail) {
        return queue->tail - queue->head;
    }
    return queue->tail + (queue->capacity - queue->head);
}

/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * 144 bytes, 0x0201D6D8..0x0201D768, one function, every concrete byte
 * reproduced (0 differing bytes of 144) -- the diff is empty apart from the
 * three wildcarded call fields.
 *
 * Blocked on the `label` class, and it is a one-address wall: all three
 * unresolved sites at +0x24, +0x32 and +0x44 call GF_FONT_Copy, which is the
 * function *immediately after this one* and whose only callers in the whole
 * image are these three.  The compared range ends where 0x0201D768 begins, so
 * shrinking the range is not possible (the callee cannot go in), and the
 * `matched` class needs an EXACT entry covering 0x0201D768 that does not
 * exist yet.  It graduates the day 0x0201D768 is matched -- nothing in this C
 * changes.
 *
 * What it is: the cache-side of a record reader.  It asks
 * GF_FONT_Copy(p, STRBUF_GetChars(c), (u16)GF_FONT_GetAlignedSize(c), 2) for a slot
 * keyed by the record at `c`, stores a second slot for `b` (0x1c/0x1c) in a
 * stack local, zero-initialises a 4-byte stack local through a third call,
 * and then walks the list hanging off queue->firstRecord through GF_FONT_UpdatePrintsy until it
 * runs out, rebasing the node pointer on p+0x18 and clamping the resulting
 * offset against p->f4 (u16) before a 4-byte memcpy into the local.  When
 * queue->firstRecord is null it installs the two slots instead.
 *
 * Two details that cost a compile each: STRBUF_GetChars is ARM, not Thumb (the
 * the offset is truncated to u16 twice -- once right after the subtraction and
 * once after the +0x1c -- which is the `(u16)(...) + 0x1c` spelling in a u16
 * local, not a single cast.
 *
 * Verified with
 *   python tools/match.py one --src src/pending/GF_FONT_CopyStrbufD6D8.c \
 *       --func GF_FONT_CopyStrbufD6D8 --addr 0x0201D6D8 --cc 1.1p1 --thumb
 */
void GF_FONT_CopyStrbufD6D8(struct PrintQueue *queue, void *record, struct Strbuf *text)
{
    void *newRecord;
    void *node;
    void *next;
    void *textCopy;
    u32 zero;

    textCopy = GF_FONT_Copy(queue, (const u8 *)STRBUF_GetChars(text),
                           (u16)GF_FONT_GetAlignedSize(text), 2);
    newRecord = GF_FONT_Copy(queue, record, 0x1c, 0x1c);
    zero = 0;
    GF_FONT_Copy(queue, (const u8 *)(&zero), 4, 4);
    node = queue->firstRecord;
    if (node != 0) {
        for (;;) {
            next = GF_FONT_UpdatePrintsy(queue, node);
            if (next == 0) break;
            node = next;
        }
        {
            u16 offset = (u16)((u32)node - (u32)queue->data) + 0x1c;

            if (offset >= queue->capacity) offset = 0;
            memcpy(&newRecord, queue->data + offset, 4);
        }
        return;
    }
    queue->firstRecord = newRecord;
    queue->text = textCopy;
}

/*
 * printsys.c: append `len` bytes to the byte ring at +0x18 in `unit`-sized
 * copies, wrapping the head back to 0 at ring->size, and return the address
 * the first copy landed at.  The three callers are GF_FONT_CopyStrbufD6D8's.
 *
 * Rewritten from the start in wave 20 (lane printsys_fresh; 63 bytes out for
 * the inherited source).  What closed it: the head advance is the compound
 * `pos += unit` over a u16 `unit`.  The explicit `pos = (u16)(pos + unit)`
 * gives the loaded head and the advanced head separate webs, the loaded one
 * is cheaper than the counter and is spilled; the compound form keeps both in
 * one live range (r4 in the image), so the counter is the one spilled to
 * [sp,#4].  With a u32 `unit` the compound form truncates `unit` as a loop
 * invariant (100 bytes).  The remaining slot order is the declaration order
 * start, buf, i, pos.
 *
 * note 2026-10-05: removed the redundant first store `buf = ring;` (a
 * stand-in: arm9 game code has no line table to prove it). The single
 * `buf = (u8 *)ring + 0x18;` is EXACT in --lang c99 and --lang c; so is a
 * static inline accessor RingData(ring), so the plain form is kept.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_Copy.c \
 *       --func GF_FONT_Copy --addr 0x0201D768 --cc 1.1p1 --thumb
 */
void *GF_FONT_Copy(struct PrintQueue *queue, const u8 *src, u16 length, u16 unit)
{
    u16 startOffset;
    u8 *data;
    u16 copied;
    u16 writePos;

    copied = 0;
    data = queue->data;
    startOffset = queue->head;
    while (copied < length) {
        writePos = queue->head;
        MI_CpuCopy8(src, data + writePos, unit);
        writePos += unit;
        if (writePos >= queue->capacity) {
            writePos = 0;
        }
        queue->head = writePos;
        src += unit;
        copied += unit;
    }
    return data + startOffset;
}

/*
 * Steps the printsys.c record ring one slot on and returns the word stored
 * there, which is the next record or NULL.  The ring lives at +0x18 of the
 * object src/matched/unit_0201C450.c builds and its records are 0x1C bytes.
 *
 * Four `lsls #16` / `lsrs #16` pairs for one offset is the tell that the
 * arithmetic went through a `u16`-parameter helper the compiler inlined: the
 * argument is truncated, the parameter is truncated again on entry, the return
 * value is truncated, and the caller truncates it once more before indexing.
 * Reproducing them needs a `u32` local with an explicit `(u16)` written at each
 * of the four points; a `u16` local folds the redundant casts away and the
 * function is ten bytes short.
 *
 * GF_FONT_CopyStrbufD6D8 and GF_FONT_Copy, the two functions in front of this one, are
 * still open; see the note in src/matched/unit_0201D69C.c, which this work
 * narrows.  GF_FONT_CopyStrbufD6D8 is EXACT when it is compiled in a range with
 * GF_FONT_Copy, and GF_FONT_Copy is four bytes short: the original spills the
 * byte counter and keeps the ring cursor in r4, and every source shape tried
 * makes the opposite choice.  Since GF_FONT_Copy's only callers are the three
 * inside GF_FONT_CopyStrbufD6D8 the two cannot be cut apart, so neither lands.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D7C4.c \
 *       --addr 0x0201D7C4 --thumb
 */
void *GF_FONT_UpdatePrintsy(struct PrintQueue *queue, void *record)
{
    u32 offset = (u16)((u8 *)record - &queue->data[0]);

    offset = (u16)((u16)offset + 0x1C);
    if (offset >= queue->capacity) {
        offset = 0;
    }
    return *(void **)&queue->data[(u16)offset];
}

/*
 * gf_font.c's constructor: allocates the 0x94-byte font object, opens the
 * resource handle for `a0`, records the archive id at +0x54, then hands the
 * object to GF_FONT_LoadResource (metrics and buffers) and GF_FONT_SetFormat (the format
 * selector).  A null allocation returns straight out, which is why both calls
 * sit inside the one guard.
 *
 * Promoted 2026-09-21 from src/pending/GF_FONT_Create.c with no change to the
 * C: both calls now resolve on the `matched` class from
 * src/matched/sub_0201D854.c and src/matched/sub_0201DA00.c, which were
 * MATCH-parked when this file was written.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_Create.c \
 *       --func GF_FONT_Create --addr 0x0201D7EC --cc 1.1p1 --thumb
 *   EXACT, 80 bytes, 5 relocation sites, all 5 resolved.
 */
struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId)
{
    struct GfFont *font = func_02030734(heapId, 0x94, 0, gGfFontFileName, 0xC0);

    if (font != 0) {
        font->arc = func_020490F4(archiveId, heapId);
        font->fileId = fileId;
        GF_FONT_LoadResource(font, fileId, isFixedWidth, heapId);
        GF_FONT_SetFormat(font, format, heapId);
    }
    return font;
}

u32 GF_FONT_Delete(struct GfFont *font)
{
    GF_FONT_ExitFormat(font);
    GF_FONT_FreeBuffers(font);
    return func_020307B0(font);
}

/*
 * note:     promoted 2026-09-21: the +0x16C ABS32 to 0x0201DC88 is now
 *           attested `matched` by src/matched/GF_FONT_GetProportionalWidth.c, which closed
 *           this file's last unresolved site.  13 of 13 relocations resolve.
 *
 * gf_font.c's metrics and buffer initialiser, 372 bytes, the largest function
 * in the file and the one GF_FONT_Create calls right after the allocation.  It
 * pulls five sections out of the font resource: the 0x14-byte header block at
 * +0x58, the glyph directory at +0x80, either the whole glyph body (preloaded,
 * into a buffer at +0x84) or nothing (streamed), the eight metric bytes at
 * +0x74, and the character map at +0x88.  The hook at +0x6C is set to
 * GF_FONT_GetProportionalWidth for the streamed case and GF_FONT_GetFixedWidth for the preloaded one,
 * and that is the pointer src/matched/unit_0201DC6C.c calls through.  It
 * finishes by priming the fallback advance at +0x70 from the glyph for '?'
 * (0x3F).
 *
 * Three details cost time:
 *
 *   - **`x / 8` and `x % 8` on the same `u8` field get different signedness
 *     treatment.**  The division is a bare `lsrs #3` and the modulo is the
 *     full signed `lsls #29` / `subs` / `rors #29` sequence, in the same
 *     expression, on the same `ldrb`.  Writing the field into a `u32` local
 *     first makes mwcc lower the modulo test to `movs #7` / `tst` and the
 *     function is sixteen bytes short; writing the field expression out twice
 *     keeps the `int` promotion and reproduces both.  An `s32` local does not
 *     compile at all here.
 *   - **248, 266 and 271 are three `__LINE__` arguments and only two pool
 *     words.**  248 is small enough for `movs`; 266 takes a pool word and 271
 *     is that word plus a constant `adds #5`
 *     (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *   - **The fallback advance is stored twice.**  `font->missingGlyphIndex = 0;` then the
 *     result of GF_FONT_GetGlyphIndex over it; the first store is not dead, because
 *     GF_FONT_GetGlyphIndex reads the field on the path where no block matches.
 *
 * Every concrete byte is reproduced.  Three relocations stay wildcarded:
 *
 *   - ARC_TOOL_GetHandleMemberOffsetOut is an ARM SDK entry point whose only call site in the
 *     image is the one in this function, so the `label` class has nothing
 *     outside the range to point at.  This alone caps the function.
 *   - GF_FONT_GetProportionalWidth is a 64-byte unlabelled Thumb leaf, the streamed-glyph
 *     hook, and this pool word is its only reference image-wide.  It is not in
 *     any manifest entry: unit_0201DC6C stops at 0x0201DC88.  Matching it
 *     would convert this site to the `matched` class.
 *   - GF_FONT_GetFixedWidth resolves on `matched` from src/matched/unit_0201DD58.c and
 *     is listed here only because the pool word sits inside the compared
 *     range.
 *
 * The fields at +0x60, +0x64 and +0x68 are declared `u32` here rather than the
 * `void *` src/matched/unit_0201DC6C.c gives them, because this function does
 * arithmetic on all three; the loads are identical either way.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201D854.c  *       --func GF_FONT_LoadResource --addr 0x0201D854 --cc 1.1p1 --thumb
 */
void GF_FONT_LoadResource(struct GfFont *font, int fileId, u32 isFixedWidth, u32 heapId)
{
    u32 size;

    if (font->arc == 0) {
        return;
    }
    sub_0204944C(font->arc, fileId, 0x18, 0x14, &font->info);
    ARC_TOOL_GetHandleMemberOffsetOut(font->arc, fileId, &font->arcBase);
    font->isFixedWidth = (u8)isFixedWidth;
    if (isFixedWidth != 0) {
        font->widthTable = 0;
        font->getCharWidth = GF_FONT_GetFixedWidth;
    } else {
        size = font->info.mapBlockOffset - font->info.widthBlockOffset;
        font->widthTable = func_02030734(heapId, size, 0, gGfFontFileName, 248);
        font->getCharWidth = GF_FONT_GetProportionalWidth;
        sub_0204944C(font->arc, fileId, font->info.widthBlockOffset, size, font->widthTable);
    }
    sub_0204944C(font->arc, fileId, font->info.glyphBlockOffset, 8, &font->glyph);
    font->tilesWide = (u8)(font->glyph.cellWidth / 8 + ((font->glyph.cellWidth % 8) ? 1 : 0));
    font->tilesHigh = (u8)(font->glyph.cellHeight / 8 + ((font->glyph.cellHeight % 8) ? 1 : 0));
    font->lastGroupBits = (u16)((font->glyph.cellWidth * 2) % 8);
    if (font->lastGroupBits == 0) {
        font->lastGroupBits = 8;
    }
    font->glyphDataOffset = font->info.glyphBlockOffset + 8;
    font->scratch = func_02030734(heapId, font->glyph.cellSize, 0, gGfFontFileName, 266);
    size = ARC_TOOL_GetHandleMemberSize(font->arc, fileId) - font->info.mapBlockOffset;
    font->charMap = func_02030734(heapId, size, 0, gGfFontFileName, 271);
    sub_0204944C(font->arc, fileId, font->info.mapBlockOffset, size, font->charMap);
    font->missingGlyphIndex = 0;
    font->missingGlyphIndex = (u16)GF_FONT_GetGlyphIndex(font, 0x3F);
}

/*
 * gf_font.c's buffer release: frees the three heap blocks the constructor hung
 * off the object at +0x90, +0x84 and +0x88 and closes the resource handle at
 * +0x50, each guarded by its own null check.
 *
 * All three offsets are past the reach of a Thumb `ldr` immediate, so each
 * access costs an `adds rN, #imm` that is an encoding artefact rather than a
 * pointer in the source (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D9C8.c \
 *       --addr 0x0201D9C8 --thumb
 */
void GF_FONT_FreeBuffers(struct GfFont *font)
{
    if (font->scratch != 0) {
        func_020307B0(font->scratch);
    }
    if (font->widthTable != 0) {
        func_020307B0(font->widthTable);
    }
    if (font->charMap != 0) {
        func_020307B0(font->charMap);
    }
    if (font->arc != 0) {
        ARC_TOOL_DeleteHandle(font->arc);
    }
}

/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * gf_font.c's format selector: it records the requested glyph format in the
 * object's first word and dispatches on it through a four-entry table of
 * initialisers, handing each the cell width and height the constructor left at
 * +0x7E and +0x7F.  GF_FONT_ExitFormat, src/pending/sub_0201DADC.c, is the matching
 * teardown and dispatches on the same word through the neighbouring table.
 *
 * Every concrete byte is reproduced.  The one unresolved relocation is the
 * table base 0x0209E73C: the pool word inside this function is the only word
 * in the image that holds it, so the `literal` class has no witness left once
 * the compared range is excluded, and no cut helps because the function is
 * twenty bytes of dispatch with nothing to cut away.  It needs a second
 * reference to the table, most likely from an overlay, to move.
 *
 * This is also what keeps GF_FONT_Create, src/pending/sub_0201D7EC.c, out of
 * src/matched: its only witness for the call to this function would be having
 * it local in the same unit, and a unit that spans it inherits this same
 * unresolved table word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201DA00.c \
 *       --func GF_FONT_SetFormat --addr 0x0201DA00 --cc 1.1p1 --thumb
 */
void GF_FONT_SetFormat(struct GfFont *font, u32 format, u32 heapId)
{
    font->format = format;
    gFontFormatInitFuncs[format](font, font->tilesWide, font->tilesHigh, heapId);
}

void GF_FONT_InitPreloadedGlyphs(struct GfFont *font, u32 tilesWide, u32 tilesHigh, u8 heapId)
{
    u32 size;
    GlyphDecodeFunc decode;

    size = ARC_TOOL_GetHandleMemberSize(font->arc, font->fileId) - font->glyphDataOffset;
    font->glyphData = func_02030734(heapId, size, 0, gGfFontFileName, 363);
    sub_0204944C(font->arc, font->fileId, font->glyphDataOffset, size, font->glyphData);
    font->readGlyph = GF_FONT_ReadPreloadedGlyph;
    if (tilesWide == 1) {
        decode = GF_FONT_DecodeGlyph8x8;
        if (tilesHigh != 1) {
            decode = GF_FONT_DecodeGlyph8x16;
        }
        font->decodeGlyph = decode;
    } else {
        decode = GF_FONT_DecodeGlyph16x8;
        if (tilesHigh != 1) {
            decode = GF_FONT_DecodeGlyph16x16;
        }
        font->decodeGlyph = decode;
    }
}

/*
 * gf_font.c's format-1 hook installer: clears +0xC, plants the shared measure
 * hook GF_FONT_ReadStreamedGlyph at +4, and picks one of four glyph decoders for +8 on the
 * 2x2 cross of the two flags (a == 1 selects the first pair, b == 1 the first
 * of each pair).  src/matched/GF_FONT_DecodeGlyph8x8.c is the (1,1) decoder.
 *
 * Promoted 2026-09-21.  The file was parked at MATCH with the last pool word
 * declared as `func_0201E938`, an address that is NOT a function start: it is
 * the first `bl` inside GF_FONT_DecodeGlyph16x16.  Because the naming convention derives
 * the address from the identifier, the extern was pinned sixteen bytes into
 * the fourth decoder, where nothing can attest it (and, being a `bl`, it was
 * even guessed ARM).  The pool word is 0x0201E929, i.e. thumb GF_FONT_DecodeGlyph16x16;
 * renaming the extern is the whole fix and the concrete bytes never changed.
 * The lesson is that a wildcarded relocation hides a wrong address as
 * effectively as a missing witness does.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_InitStreamedGlyphs.c \
 *       --func GF_FONT_InitStreamedGlyphs --addr 0x0201DAA4 --cc 1.1p1 --thumb
 *   EXACT, 56 bytes, 5 relocation sites, all 5 resolved.
 */
void GF_FONT_InitStreamedGlyphs(struct GfFont *font, int tilesWide, int tilesHigh)
{
    font->glyphData = 0;
    font->readGlyph = GF_FONT_ReadStreamedGlyph;
    if (tilesWide == 1)
        font->decodeGlyph = (tilesHigh == 1) ? GF_FONT_DecodeGlyph8x8 : GF_FONT_DecodeGlyph8x16;
    else
        font->decodeGlyph = (tilesHigh == 1) ? GF_FONT_DecodeGlyph16x8 : GF_FONT_DecodeGlyph16x16;
}

/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * gf_font.c's format teardown, the mirror of GF_FONT_SetFormat: it dispatches on
 * the format word the selector stored at +0 through a second four-entry table
 * that sits two words after the first one.  Twenty bytes, one indirect call.
 *
 * Every concrete byte is reproduced.  The unresolved relocation is the table
 * base 0x0209E744 and the pool word here is its only witness image-wide, the
 * same dead end as src/pending/sub_0201DA00.c.  Note that the two tables being
 * eight bytes apart is *not* usable as evidence: expressing one as an offset
 * from the other would be a claim that they are one object, and the image does
 * not say so.
 *
 * This is in turn what keeps GF_FONT_Delete, src/pending/sub_0201D83C.c, out of
 * src/matched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201DADC.c \
 *       --func GF_FONT_ExitFormat --addr 0x0201DADC --cc 1.1p1 --thumb
 */
void GF_FONT_ExitFormat(struct GfFont *font)
{
    gFontFormatExitFuncs[font->format](font);
}

/*
 * gf_font.c's glyph-buffer release, an empty hook, and the entry point every
 * text routine in the region reaches a glyph through.
 *
 * GF_FONT_ExitStreamedGlyphs is two bytes, `bx lr`, which is `void f(void) {}`, a hook that
 * was never filled in.  It carries no label because it has no prologue.
 *
 * GF_FONT_ReadGlyph looks up the glyph with GF_FONT_GetGlyphIndex and dispatches through the
 * function pointer at +4 of the font object.  GF_FONT_GetGlyphIndex itself, the glyph
 * index lookup at 0x0201DB20, is still open: it reproduces all 154 bytes bar a
 * consistent interchange of r4 with r6, the run cursor against the two binary
 * search bounds, and no declaration order, scope or type tried moves it.  Its
 * one non-obvious detail is worth recording anyway: the base pointer at +0x88
 * has to be spelled `*(struct FontRun **)((u8 *)p + 0x88)` at the top of the
 * function and `font->charMap` at the rebasing site, or the compiler keeps one copy
 * in a register across the loop and spends an extra move; the original
 * rematerialises the address in the cold path instead.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DAF0.c \
 *       --addr 0x0201DAF0 --thumb
 */
void GF_FONT_FreeGlyphData(struct GfFont *font)
{
    func_020307B0(font->glyphData);
    font->glyphData = 0;
}

void GF_FONT_ExitStreamedGlyphs(struct GfFont *font)
{
}

void GF_FONT_ReadGlyph(struct GfFont *font, u16 ch, void *dst, u8 *metrics)
{
    font->readGlyph(font, GF_FONT_GetGlyphIndex(font, ch), dst, metrics);
}

/*
 * gf_font.c's character-to-glyph-index lookup: NitroSystem's character-map
 * search (NNSG2dFontCodeMap: ccodeBegin, ccodeEnd, mappingMethod, reserved,
 * pNext, mapInfo[]) walked Game Freak style.  The chain pointer is stored as
 * an address in the resource file and is rebased from the load address
 * (+0x68) onto the copy (+0x88); +0x70 is the font's default glyph.  Method
 * 0 is a direct run, 1 a table, 2 a binary search over (code, index) pairs.
 *
 * Two details closed it (docs/notes/sub_0201DB20.c.txt has every
 * measurement):
 *
 *   - the rebase re-reads +0x88 as `*(u8 **)((u8 *)f + 0x88)`, so it is not
 *     CSE'd with the first read (wave 15, 139 -> 15 bytes out);
 *   - the chain step goes through a second pointer local `n` and ends in the
 *     copy `m = n;`.  When m's loop-carried definition is an arithmetic
 *     result (`m = rebase(m)`, even `m = m + 4`), mwcc colours m after every
 *     other local whatever the declaration order, and m takes r6.  With the
 *     copy, m, lo and hi colour in declaration order, which is the image's
 *     m r4, lo r5, hi r6 (wave 21 lane F2, 15 -> 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DB20.c \
 *       --func GF_FONT_GetGlyphIndex --addr 0x0201DB20 --cc 1.1p1 --thumb
 */
u32 GF_FONT_GetGlyphIndex(struct GfFont *font, u16 ch)
{
    struct CMap *map;
    s32 low;
    s32 high;
    struct CMap *next;

    map = (struct CMap *)font->charMap;
    for (;;) {
        if (map->ccodeBegin <= ch && map->ccodeEnd >= ch) {
            switch (map->mappingMethod) {
            case 0:
                return map->mapInfo[0] + (ch - map->ccodeBegin);
            case 1:
                return map->mapInfo[(u16)(ch - map->ccodeBegin)];
            case 2: {
                low = 0;
                high = map->mapInfo[0] - 1;
                while (low <= high) {
                    s32 middle = low + (high - low) / 2;
                    s32 pairIndex = 2 * middle + 1;
                    if (map->mapInfo[pairIndex] < ch)
                        low = middle + 1;
                    else if (ch < map->mapInfo[pairIndex])
                        high = middle - 1;
                    else
                        return map->mapInfo[pairIndex + 1];
                }
                break;
            }
            }
            return font->missingGlyphIndex;
        }
        next = map->pNext;
        if (next != 0)
            next = (struct CMap *)(*(u8 **)&font->charMap + ((u32)next - font->info.mapBlockOffset));
        else
            return 0;
        map = next;
    }
}

/*
 * gf_font.c's glyph fetch for a preloaded font: copy glyph record i
 * (mapSize bytes) out of the resident body into the scratch buffer, then
 * hand it to GF_FONT_DecodeGlyph with the last-tile column count.
 *
 * The lever (wave 16) is `const` on the font parameter, which is only read
 * here.  With a plain pointer the outgoing stack argument `out` was stored
 * third in the final call's setup; with `const struct GfFont *` it is stored
 * last, as in the image (12 bytes out before, every spelling and 3000
 * permuter compiles flat: docs/notes/sub_0201DBBC.c.txt).  Field names
 * follow docs/families/gf_font.h.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DBBC.c \
 *       --func GF_FONT_ReadPreloadedGlyph --addr 0x0201DBBC --cc 1.1p1 --thumb
 */
void GF_FONT_ReadPreloadedGlyph(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics)
{
    MI_CpuCopy8(font->glyphData + glyphIndex * font->glyph.cellSize, font->scratch, font->glyph.cellSize);
    GF_FONT_DecodeGlyph(font, font->scratch, font->lastGroupBits, dst, metrics);
}

/*
 * gf_font.c's glyph fetch for a streamed font: seek the resource handle to
 * the header base plus the glyph directory plus record i, read mapSize bytes
 * into the scratch buffer, then hand it to GF_FONT_DecodeGlyph with the last-tile
 * column count.
 *
 * The lever (wave 16) is `const` on the font parameter, exactly as in its
 * sibling src/matched/sub_0201DBBC.c: it moves the outgoing stack argument
 * `out` from third to last in the final call's setup (12 bytes out before,
 * docs/notes/sub_0201DBBC.c.txt).  The listing extent includes the two-byte
 * alignment pad at 0x0201DC42, hence EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DBBC.c \
 *       --func GF_FONT_ReadStreamedGlyph --addr 0x0201DBF4 --cc 1.1p1 --thumb
 */
void GF_FONT_ReadStreamedGlyph(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics)
{
    func_0204960C(font->arc, font->arcBase + (font->glyphDataOffset + glyphIndex * font->glyph.cellSize));
    ARC_TOOL_ReadHandle(font->arc, font->glyph.cellSize, font->scratch);
    GF_FONT_DecodeGlyph(font, font->scratch, font->lastGroupBits, dst, metrics);
}

/*
 * gf_font.c's glyph hand-off: the rendering hook installed at +8 of the font
 * object is called on the glyph bitmap, which starts three bytes into the
 * glyph record, and the record's own three metric bytes plus the byte at +0x59
 * of the font object are copied into the caller's four-byte descriptor.
 *
 * The width is a `u32` parameter and the hook takes it as `u16`, which is what
 * the single `lsls #16` / `lsrs #16` pair before the call is: a `u16`
 * parameter here would make the caller truncate instead and both callers in
 * this packet are two bytes short.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DC44.c \
 *       --func GF_FONT_DecodeGlyph --addr 0x0201DC44 --cc 1.1p1 --thumb
 */
void GF_FONT_DecodeGlyph(const struct GfFont *font, const u8 *glyph, u32 lastGroupBits, void *dst, u8 *metrics)
{
    font->decodeGlyph(glyph + 3, (u16)lastGroupBits, dst);
    metrics[0] = glyph[0];
    metrics[1] = glyph[1];
    metrics[2] = glyph[2];
    metrics[3] = font->info.lineHeight;
}

/*
 * The gf_font.c width query and the accessor for the byte at +0x59.
 *
 * GF_FONT_GetCharWidth returns whatever the function pointer at +0x6C returns, and the
 * tail call shape (`ldr r2, [r4, #0x6c]`, `blx r2`, `pop {r4, pc}`) is the same
 * bytes whether the C declares a return value or not, so the return type is
 * fixed by the caller instead: GF_FONT_MeasureText adds the result to a running width.
 *
 * GF_FONT_GetField58 has no label in the listing; it is three halfwords between two
 * literal pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DC6C.c \
 *       --addr 0x0201DC6C --thumb
 */
u32 GF_FONT_GetCharWidth(struct GfFont *font, u16 ch)
{
    return font->getCharWidth(font, GF_FONT_GetGlyphIndex(font, ch));
}

u32 GF_FONT_GetField58(struct GfFont *font)
{
    return font->info.lineHeight;
}

/*
 * gf_font.c streamed-glyph lookup: classify glyph `id` through a
 * 2-bit-per-glyph table, fall back to a 9-bit hash, then walk a run of
 * variable-length records for a matching 2-byte code.  See
 * docs/notes/GF_FONT_GetProportionalWidth.c.txt for the full structural derivation.
 *
 * No relocations: every table is reached through offsets stored in the
 * resource header at obj+0x84.
 *
 * EXACT*, not EXACT: GF_FONT_GetFixedWidth immediately after this one is an
 * unlabelled leaf, so the inferred extent runs long (240 vs 208).  Report
 * the unlabelled follower at 0x0201DD58 rather than editing
 * layout/function_starts.txt.
 *
 * The closing lever (2026-09-21): the record header must be read with a
 * fused post-increment, `cnt = *p++;`.  Spelling it as the two statements
 * `cnt = *p; p++;` swaps the cursor and the scan counter between r2 and r3
 * for the whole tail, which is the 17-byte residue the note records.
 */
u32 GF_FONT_GetProportionalWidth(struct GfFont *font, u32 glyphIndex)
{
    struct GlyphWidthTable *table = font->widthTable;
    u32 bitPos = glyphIndex * 2;
    u8  packed = ((u8 *)table + table->classOffset)[bitPos >> 3];
    u8  widthClass = (u8)((packed >> (6 - (bitPos & 7))) & 3);
    u16 slot;
    s8  entry;
    u16 skip;
    u8 *record;
    u8  count;
    u8  index;

    if (widthClass < 3)
        return ((u8 *)table)[widthClass];

    slot = (u16)(((glyphIndex & 0x1ff) ^ (u16)(((((glyphIndex >> 12) ^ (glyphIndex >> 11)) ^ (glyphIndex >> 10)) ^ (glyphIndex >> 9)) & 1) << 3) & 0x1ff);

    entry = ((s8 *)((u8 *)table + table->hashOffset))[slot];
    if (entry >= 0)
        return (u8)entry;

    skip = (u16)((u16)(-entry) - 1);
    record = (u8 *)table + table->chainOffset;
    while (skip != 0) {
        u8 recordCount = *record;
        u16 remaining = (u16)(skip - 1);
        record += recordCount + recordCount * 2 + 1;
        skip = remaining;
    }

    count = *record++;
    index = 0;
    while (index < count) {
        u16 key = (u16)((record[0] << 8) | record[1]);
        if (glyphIndex == key)
            return record[2];
        index = (u8)(index + 1);
        record += 3;
    }
    return font->info.defaultCharWidth;
}

/*
 * Three unlabelled leaves of gf_font.c: the accessor for the byte at +0x5E and
 * a two-step thunk that resets the text colour to (1, 2, 0).
 *
 * GF_FONT_InitTextColor and GF_FONT_SetDefaultTextColor are both the pool-word-and-bx shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes, and neither carries
 * a label, because a tail call saves nothing and the prologue sweep never fires.
 * The chain is real: GF_FONT_InitTextColor tail-calls GF_FONT_SetDefaultTextColor, which tail-calls
 * GF_FONT_SetTextColor with three constants.  Writing it as one function that calls
 * GF_FONT_SetTextColor directly loses eight bytes.
 *
 * GF_FONT_SetTextColor itself, the 4x4x4x4 colour expansion at 0x0201DD78, is still
 * open: the original keeps its two outer loop counters in ip and lr and spills
 * only the third, and no declaration order tried reproduces that split.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DD58.c \
 *       --addr 0x0201DD58 --thumb
 */
u32 GF_FONT_GetFixedWidth(struct GfFont *font, u32 glyphIndex)
{
    return font->info.defaultCharWidth;
}

void GF_FONT_InitTextColor(void)
{
    GF_FONT_SetDefaultTextColor();
}

void GF_FONT_SetDefaultTextColor(void)
{
    GF_FONT_SetTextColor(1, 2, 0);
}

/*
 * gf_font.c's text-colour setter, 136 bytes.  It records the three requested
 * palette indices in gFontState (the three bytes src/matched/unit_0201DE00.c
 * reads back) and then rebuilds the 256-entry expansion table at 0x02146588: a
 * byte of four 2-bit pixels indexes it and the halfword it yields is the same
 * four pixels widened to a nibble each.  The four nested loops enumerate the
 * four pixels; the local array is { 0, r, g, b }, so pixel value 0 stays 0 and
 * 1..3 map to the three requested indices.
 *
 * Two details cost time:
 *
 *   - **The disjunction is written innermost-term-first.**  Spelled
 *     `c[i] | c[j] << 4 | c[k] << 8 | c[l] << 12` the left-associated prefix
 *     `c[i] | c[j] << 4` is invariant in the two inner loops, mwcc hoists it,
 *     and the function is four bytes short with the partial results living in
 *     `ip` and `lr`.  Written the other way round, `c[l] << 12` leads and no
 *     prefix of the chain is loop-invariant, so only the three shifted terms
 *     are hoisted, one per loop level, which is what the original does.
 *   - **The four loop counters are signed.**  The back edges are `blt`, not
 *     `blo`; `u32` counters cost four wrong bytes and nothing else.
 *
 * The store order in the prologue is also load-bearing: the four array slots
 * are written first, the three global bytes after them, and the flat output
 * index last.  Any other order leaves the `strb`s and the `str`s interleaved
 * differently and up to eighteen bytes differ, with the instruction multiset
 * unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DD78.c \
 *       --func GF_FONT_SetTextColor --addr 0x0201DD78 --cc 1.1p1 --thumb
 */
void GF_FONT_SetTextColor(u32 red, u32 green, u32 blue)
{
    u32 palette[4];
    s32 pixel0;
    s32 pixel1;
    s32 pixel2;
    s32 pixel3;
    u32 entry;

    palette[0] = 0;
    palette[1] = red;
    palette[2] = green;
    palette[3] = blue;
    gFontState.textColor[0] = (u8)red;
    gFontState.textColor[1] = (u8)green;
    gFontState.textColor[2] = (u8)blue;
    entry = 0;
    for (pixel0 = 0; pixel0 < 4; pixel0++) {
        for (pixel1 = 0; pixel1 < 4; pixel1++) {
            for (pixel2 = 0; pixel2 < 4; pixel2++) {
                for (pixel3 = 0; pixel3 < 4; pixel3++) {
                    gGlyphExpandTable[entry] = (u16)((palette[pixel3] << 12) | (palette[pixel2] << 8) |
                                              (palette[pixel1] << 4) | palette[pixel0]);
                    entry++;
                }
            }
        }
    }
}

/*
 * The current text colour, read back and compared.  gFontState is the three
 * bytes GF_FONT_SetTextColor stores the last requested colour into.
 *
 * GF_FONT_IsTextColorDifferent returns 1 when the colour differs, and its shape is the
 * disjunction form rather than the conjunction: the first two comparisons branch
 * to one shared `movs r0, #1` block and only the last one branches past it,
 * which is what `if (r != c[0] || g != c[1] || b != c[2]) return 1;` gives.
 * Written as `if (all equal) return 0; return 1;` the arms swap and ten of the
 * forty bytes are wrong
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DE00.c \
 *       --addr 0x0201DE00 --thumb
 */
void GF_FONT_GetTextColor(u8 *red, u8 *green, u8 *blue)
{
    *red = gFontState.textColor[0];
    *green = gFontState.textColor[1];
    *blue = gFontState.textColor[2];
}

u32 GF_FONT_IsTextColorDifferent(u32 red, u32 green, u32 blue)
{
    if (red != gFontState.textColor[0] || green != gFontState.textColor[1] || blue != gFontState.textColor[2]) {
        return 1;
    }
    return 0;
}

static inline u8 ReadBits(struct BitReader *reader, u8 count)
{
    u8  highBits;
    u32 lowBits;
    u8  current;
    u32 bitsTaken;

    if (reader->bitsLeft < count) {
        highBits = reader->current;
        highBits &= gTopBitMasks[reader->bitsLeft];
        bitsTaken = reader->bitsLeft;
        count = (u8)(count - (u8)bitsTaken);
        reader->src++;
        reader->current = *reader->src;
        reader->bitsLeft = 8;
    } else {
        highBits = 0;
        bitsTaken = 0;
    }

    current = reader->current;
    lowBits = gTopBitMasks[count] & current;
    reader->bitsLeft = reader->bitsLeft - count;
    if (reader->bitsLeft == 0) {
        reader->src++;
        reader->current = *reader->src;
        reader->bitsLeft = 8;
    } else {
        reader->current = (u8)(current << count);
    }
    return (u8)((lowBits >> bitsTaken) | highBits);
}

/*
 * gf_font.c's format-1 glyph decoder, one of the four hooks GF_FONT_InitStreamedGlyphs
 * installs at font->decodeGlyph (src/pending/sub_0201DAA4.c): the one for format 1
 * with b == 1.
 *
 * Sixteen 4-pixel groups of a compressed 2bpp 8x8 glyph.  Every even group is
 * a whole literal byte (read_bits of 8 bits) and every odd one is `n` bits
 * wide; each group's byte then indexes the 256-entry 2bpp->4bpp expansion
 * table at 0x02146588 that GF_FONT_SetTextColor rebuilds (src/matched/sub_0201DD78.c),
 * so the sixteen halfwords written to dst are the glyph in 4bpp.  `n` is the
 * caller's bit depth and is a runtime value, which is why the even and odd
 * reads are the same inlined reader with a constant and a variable count.
 *
 * The reader is the source of GF_FONT_ReadBits (src/matched/GF_FONT_ReadBits.c), the
 * out-of-line copy of it that sits just past this function, inlined here
 * sixteen times; `static inline` is load-bearing, plain `static` compiles to
 * sixteen `bl`s and 260 bytes.  Its state is the second half of the global at
 * 0x02146578, whose first three bytes are the text colour GF_FONT_SetTextColor
 * stores and src/matched/unit_0201DE00.c reads back; that is why the inlined
 * field accesses sit at +4/+8/+12 rather than at +0/+4/+8 as they do in the
 * out-of-line call.
 *
 * What cost the last eight bytes: the outer parameter must be `u32 n`, not
 * `u8 n`.  With a u8 parameter mwcc treats the register as an already
 * zero-extended byte, so the inlined expansions compare `r->avail` against
 * the raw argument and keep `n` alive in two registers; the original
 * re-materialises `(u8)n` once per expansion, before the `avail < n`
 * comparison, which is what a conversion from a wider argument gives you.
 * Every block is the same length either way, so the whole difference is one
 * register choice and a pool 8 bytes further along.
 *
 * Extent note: the listing's 1672 bytes for this function run to 0x0201E4C8,
 * eight bytes past the last code byte (0x0201E4BE) - the two-word literal
 * pool at 0x0201E4C0 (gTopBitMasks, gGlyphExpandTable) is this function's own.  It is
 * inside this packet, not the neighbouring 0x0201E000..0x0202E000 lane; the
 * next function starts at 0x0201E4C8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_DecodeGlyph8x8.c \
 *       --func GF_FONT_DecodeGlyph8x8 --addr 0x0201DE40 --cc 1.1p1 --thumb
 *   EXACT, 1672 bytes, 5 relocation sites, all 5 resolved.
 */
void GF_FONT_DecodeGlyph8x8(const u8 *src, u32 lastGroupBits, u16 *dst)
{
    gFontState.reader.src = src;
    gFontState.reader.current = *src;
    gFontState.reader.bitsLeft = 8;

    dst[0] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[1] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[2] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[3] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[4] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[5] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[6] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[7] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[8] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[9] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[10] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[11] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[12] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[13] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[14] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[15] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
}

/*
 * Opens the bit reader the glyph decompressor in this packet runs on: the
 * cursor at +0 is the byte pointer, +4 is the number of bits still unread out
 * of the byte cached at +8, and the first byte is latched on the spot.
 *
 * Twelve bytes, no prologue: the function saves nothing, so disasm.py's
 * prologue sweep never labels it and it prints as part of the `.word` run in
 * front of func_0201E4D4
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The bit count is assigned last.  Written before the cached byte the two
 * stores swap and the constant 8 is materialised earlier, four bytes wrong.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201E4C8.c \
 *       --func GF_FONT_InitBitReader --addr 0x0201E4C8 --cc 1.1p1 --thumb
 */
void GF_FONT_InitBitReader(struct BitReader *reader, const u8 *src)
{
    reader->src = src;
    reader->current = src[0];
    reader->bitsLeft = 8;
}

/*
 * The bit reader behind the compressed glyph stream: pulls `n` bits out of a
 * byte stream, most significant bit first.  The state is three fields, the
 * read pointer at +0, the number of bits still unconsumed in the byte at +4,
 * and that byte itself at +8; gTopBitMasks is the 0..8 entry table of top-bit
 * masks.  When the request straddles a byte boundary the leading bits are
 * taken first, the next byte is fetched, and the two halves are OR'd back
 * together.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_ReadBits.c
 *       --func GF_FONT_ReadBits --addr 0x0201E4D4 --cc 1.1p1 --thumb
 */
u8 GF_FONT_ReadBits(struct BitReader *reader, u8 count)
{
    u8  highBits;
    u32 lowBits;
    u8  current;
    u32 bitsTaken;

    if (reader->bitsLeft < count) {
        highBits = reader->current;
        highBits &= gTopBitMasks[reader->bitsLeft];
        bitsTaken = reader->bitsLeft;
        count = (u8)(count - (u8)bitsTaken);
        reader->src++;
        reader->current = *reader->src;
        reader->bitsLeft = 8;
    } else {
        highBits = 0;
        bitsTaken = 0;
    }

    current = reader->current;
    lowBits = gTopBitMasks[count] & current;
    reader->bitsLeft = reader->bitsLeft - count;
    if (reader->bitsLeft == 0) {
        reader->src++;
        reader->current = *reader->src;
        reader->bitsLeft = 8;
    } else {
        reader->current = (u8)(current << count);
    }
    return (u8)((lowBits >> bitsTaken) | highBits);
}

/*
 * One of the four compressed-glyph decoders src/matched/GF_FONT_InitStreamedGlyphs.c and
 * src/matched/sub_0201DA24.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/sub_0201E4C8.c
 * opens it, src/matched/GF_FONT_ReadBits.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/sub_0201DD78.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/GF_FONT_DecodeGlyph8x8.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Thirty-two halfwords, one flat 8x8-at-4bpp glyph in address order, with the
 * widths alternating 8, n, 8, n, ...  The simplest of the four: one cursor,
 * dst[0] through dst[31] in order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_DecodeGlyph8x16.c \
 *       --func GF_FONT_DecodeGlyph8x16 --addr 0x0201E538 --cc 1.1p1 --thumb
 *   EXACT, 512 bytes, 35 relocation sites, all 35 resolved.
 */
void GF_FONT_DecodeGlyph8x16(const u8 *src, u32 lastGroupBits, u16 *dst)
{
    GF_FONT_InitBitReader(&gFontState.reader, src);
    dst[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[1] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[3] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[5] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[7] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[9] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[11] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[13] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[15] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[16] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[17] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[18] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[19] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[20] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[21] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[22] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[23] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[24] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[25] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[26] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[27] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[28] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[29] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[30] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[31] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
}

/*
 * One of the four compressed-glyph decoders src/matched/GF_FONT_InitStreamedGlyphs.c and
 * src/matched/sub_0201DA24.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/sub_0201E4C8.c
 * opens it, src/matched/GF_FONT_ReadBits.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/sub_0201DD78.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/GF_FONT_DecodeGlyph8x8.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Thirty-two halfwords in TWO interleaved cursors, `dst` and `dst2 = dst + 16`,
 * written four at a time: dst[2i], dst[2i+1], dst2[2i], dst2[2i+1], with widths
 * 8, 8, 8, n.  The second cursor is what puts dst+0x20 in r7 for the whole
 * body; written as dst[16 + k] instead the compiler recomputes the base from
 * dst at every far store and the function is longer.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_DecodeGlyph16x8.c \
 *       --func GF_FONT_DecodeGlyph16x8 --addr 0x0201E738 --cc 1.1p1 --thumb
 *   EXACT, 496 bytes, 35 relocation sites, all 35 resolved.
 */
void GF_FONT_DecodeGlyph16x8(const u8 *src, u32 lastGroupBits, u16 *dst)
{
    u16 *dst2 = dst + 16;

    GF_FONT_InitBitReader(&gFontState.reader, src);
    dst[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[1] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[1] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[3] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[3] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[5] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[5] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[7] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[7] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[9] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[9] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[11] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[11] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[13] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[13] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[15] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[15] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
}

/*
 * One of the four compressed-glyph decoders src/matched/GF_FONT_InitStreamedGlyphs.c and
 * src/matched/sub_0201DA24.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/sub_0201E4C8.c
 * opens it, src/matched/GF_FONT_ReadBits.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/sub_0201DD78.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/GF_FONT_DecodeGlyph8x8.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Forty-eight halfwords across FOUR 8x8 tiles, the widest of the four decoders.
 * The tiles are written three halfwords at a time, dst[k], dst[k+1], dst2[k],
 * with widths 8, 8, n, where `dst2 = dst + 16` is the tile below.
 *
 * WHICH INDEX GOES THROUGH WHICH CURSOR IS LOAD-BEARING, and it is what cost
 * the time here.  The second tile pair lives at halfword 32..63, and its low
 * tile (32..47) must be written as `dst[32..47]`, i.e. through the FIRST
 * cursor, while its high tile (48..63) goes through `dst2[32..47]`.  Routing
 * the whole second pair through `dst2` (dst2[16..47], which is the same
 * address arithmetic) lets mwcc keep one base live across both blocks: sixty
 * bytes short, 413 bytes out, and a clean r5/r6/r7 rotation in the permuter's
 * --explain map.  Splitting them back restores the original's recomputed
 * `adds r0, r5, #0 / adds r0, #0x40 / strh` at every far store, which is the
 * shape the image actually has.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_DecodeGlyph16x16.c \
 *       --func GF_FONT_DecodeGlyph16x16 --addr 0x0201E928 --cc 1.1p1 --thumb
 *   EXACT, 828 bytes, 51 relocation sites, all 51 resolved.
 */
void GF_FONT_DecodeGlyph16x16(const u8 *src, u32 lastGroupBits, u16 *dst)
{
    u16 *dst2 = dst + 16;

    GF_FONT_InitBitReader(&gFontState.reader, src);
    dst[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[1] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[3] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[5] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[7] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[9] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[11] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[13] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[15] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[32] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[33] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[32] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[34] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[35] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[34] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[36] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[37] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[36] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[38] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[39] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[38] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[40] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[41] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[40] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[42] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[43] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[42] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[44] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[45] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[44] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[46] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[47] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[46] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
}

/*
 * The first function of wordset.c.  The file identity is in the image: the
 * constructor at 0x0201EC74, immediately after this, passes 0x020A7364 to the
 * debug allocator at 0x02030734, and the bytes there spell "wordset.c".  The
 * string before it is "gf_font.c", whose terminator at 0x020A7360 plus three
 * bytes of padding fixes 0x020A7364 by construction, so the `string` class
 * carries the address; see src/matched/unit_0201ED04.c for the rest of the
 * file and the near miss at 0x0201EC74 that keeps this function on its own.
 *
 * Sixteen bytes: a pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) that fills in the default
 * entry count 8 and the default per-entry string size 0x20.  It cannot be one
 * unit with 0x0201EC74 because that function is 14 bytes of prologue
 * scheduling away from EXACT and csrc.py refuses anything less.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201EC64.c \
 *       --addr 0x0201EC64 --thumb
 */
struct WordSet *WORDSET_CreateDefault(u16 heapId)
{
    return WORDSET_Create(8, 0x20, heapId);
}
