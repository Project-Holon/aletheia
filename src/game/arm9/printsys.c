/*
 * file:     printsys.c
 * unit:     yes
 * function: GF_FONT_Task, GF_FONT_Apply, GF_FONT_MeasureTextWidth, GF_FONT_CountLine, GF_FONT_MeasureWidestLine, GF_FONT_InitCallerSuppliedArray, GF_FONT_CopyLine, GF_FONT_CountLines, GF_FONT_CountControlTag, GF_FONT_SearchIndex, GF_FONT_MeasureText, GF_FONT_GetTagChar, GF_FONT_CheckD5CC, GF_FONT_GetTagGroup, GF_FONT_AppendTag, GF_FONT_GetTagKind, GF_FONT_GetTagParam, GF_FONT_SkipTag, GF_FONT_GetAlignedSize, GF_FONT_GetAllocSize, GF_FONT_GetQueueLength, GF_FONT_CopyStrbufD6D8, GF_FONT_Copy, GF_FONT_UpdatePrintsy
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
 *   STRBUF_GetLength  0x020458F8  arm
 */
#include "gf_font_shared_types.h"
#include "printsys_shared_types.h"

struct Bmp;

struct Descriptor;

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

u32 GF_FONT_GetCharWidth(struct GfFont *font, u16 ch);

u32 GF_FONT_GetField58(struct GfFont *font);

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
