/*
 * file:     printsys.c
 * unit:     yes
 * function: PRINTSYS_Init, PRINTSYS_QUE_Create, PRINTSYS_QUE_CreateEx, PRINTSYS_QUE_Delete, PRINTSYS_QUE_SetForceQueue, PRINTSYS_QUE_SetLimitTick, PRINTSYS_QUE_Main, PRINTSYS_QUE_IsFinished, PRINTSYS_QUE_IsExistTarget, PRINTSYS_QUE_Clear, PRINTSYS_PrintQue, PRINTSYS_PrintQueColor, PRINTSYS_SubmitJob, PRINTSYS_Print, PRINTSYS_PrintColor, PRINTSYS_SetupJob, PRINTSYS_SetJobColor, PRINTSYS_RunJob, PRINTSYS_PrintStep, PRINTSYS_PutGlyph4bpp, PRINTSYS_PutGlyph8bpp, PRINTSYS_ProcGeneralTag, PRINTSYS_ProcColorTag, PRINTSYS_PrintStream, PRINTSYS_PrintStreamCallBack, PRINTSYS_SplitWait, PRINTSYS_PrintStreamStop, PRINTSYS_PrintStreamRun, PRINTSYS_PrintStreamGetState, PRINTSYS_PrintStreamGetWaitKind, PRINTSYS_PrintStreamReleasePause, PRINTSYS_PrintStreamDelete, PRINTSYS_PrintStreamShortWait, PRINTSYS_PrintStreamSetSpeed, PRINTSYS_PrintStreamResetSpeed, PRINTSYS_PrintStreamIsOverrideSpeed, PRINTSYS_Task, PRINTSYS_Apply, PRINTSYS_MeasureTextWidth, PRINTSYS_CountLine, PRINTSYS_MeasureWidestLine, PRINTSYS_InitCallerSuppliedArray, PRINTSYS_CopyLine, PRINTSYS_CountLines, PRINTSYS_CountControlTag, PRINTSYS_SearchIndex, PRINTSYS_MeasureText, PRINTSYS_GetTagChar, PRINTSYS_IsWordSlotTag, PRINTSYS_GetTagGroup, PRINTSYS_AppendTag, PRINTSYS_GetTagKind, PRINTSYS_GetTagParam, PRINTSYS_SkipTag, PRINTSYS_GetAlignedSize, PRINTSYS_GetAllocSize, PRINTSYS_GetQueueFreeSpace, PRINTSYS_EnqueuePrint, PRINTSYS_Copy, PRINTSYS_GetNextRecord
 * address:  0x0201C41C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from printsys_head.c, printsys.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   _pGlyphBmp         0x02146558  data
 *   printsys_File   0x020A734C  data
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   GF_FONT_IsTextColorDifferent  0x0201DE18  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   OS_GetTick  0x020870D0  arm
 *   PRINTSYS_GetNextRecord  0x0201D7C4  thumb
 *   _PrintJobWork   0x0214655C  data
 *   STRBUF_GetChars  0x02045A90  arm
 *   PRINTSYS_MeasureTextWidth  0x0201D26C  thumb
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   PRINTSYS_Task  0x0201CEE0  thumb
 *   GF_FONT_ReadGlyph  0x0201DB04  thumb
 *   TCBL_DeleteTask  0x02031194  arm
 *   BMP_GetTileBytes  0x02043994  arm
 *   BMP_BlitPaletteOffset  0x02043AAC  arm
 *   STRBUF_SetEosChar  0x020457A0  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_Blit  0x020439A0  arm
 *   MSG_SPEED_GetWaitForSpeed  0x02013080  thumb
 *   PRINTSYS_EnqueuePrint  0x0201D6D8  thumb
 *   PRINTSYS_GetAllocSize  0x0201D6B8  thumb
 *   PRINTSYS_GetQueueFreeSpace  0x0201D6C4  thumb
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   PRINTSYS_PrintStep  0x0201C974  thumb
 *   PRINTSYS_PrintStreamResetSpeed   0x0201CEB8  thumb
 *   MSG_SPEED_GetSlowerWait  0x02013020  thumb
 *   MSG_SPEED_GetFasterWait  0x02013050  thumb
 *   PRINTSYS_SplitWait   0x0201CDF4  thumb
 *   GF_FONT_GetCharWidth  0x0201DC6C  thumb
 *   STRBUF_Clear  0x0204581C  arm
 *   STRBUF_AppendChar  0x02045AFC  arm
 *   GF_FONT_GetLineHeight  0x0201DC80  thumb
 *   MI_CpuCopy8         0x02082D44  arm
 *   STRBUF_GetLength  0x020458F8  arm
 */
#include "pokeparty_shared_types.h"
#include "gf_font_shared_types.h"
#include "printsys_shared_types.h"

struct Strbuf;

struct Bmp;

struct BmpWin;

struct GfFont;

struct Tcbl;

struct TcblNode;

/* Pen origin and colour mode, packed in one word of PrintCtx. */
union PrintPos {
    u32 raw;
    struct {
        s32 originX : 10;
        u32 originY : 10;
        s32 colorMode : 4;
        u32 extra : 8;
    } bits;
};

typedef void (*PrintBlitFn)(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo);

/* One print job: the pen, the colours, the font and the target bitmap. */
struct PrintCtx {
    s16 penX;
    s16 penY;
    union PrintPos pos;
    u16 letterSpacing;
    u16 lineSpacing;
    u16 textColor;
    u16 activeColor;
    struct GfFont *font;
    struct Bmp *bmp;
    PrintBlitFn blitGlyph;
};

union PrintTicks {
    u64 value;
    struct {
        u32 low;
        u32 high;
    } half;
};

union PrintQueueState {
    u8 raw;
    struct {
        u8 pending : 4;
        u8 forceQueue : 4;
    } bits;
};

/* The print queue: a byte ring of queued jobs and their strings after the
 * 0x18 byte header. */
struct PrintQueue {
    u16 head;
    u16 tail;
    u16 capacity;
    u8  frameCount;
    union PrintQueueState state;
    union PrintTicks limitTicks;
    struct PrintCtx *job;
    u16 *cursor;
    u8  data[4];
};

union TextPrinterFlags {
    u8 raw;
    struct {
        u8 halted : 1;
        u8 scrolling : 1;
        u8 advance : 1;
        u8 useOverrideSpeed : 1;
        u8 clearOverridePending : 1;
        u8 reserved : 3;
    } bits;
};

/* A streamed text print (0x50 byte task work). */
struct TextPrinter {
    u32  state;
    u32  waitKind;
    struct BmpWin *bmpWin;
    struct Bmp *bmp;
    struct TcblNode *task;
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
    union TextPrinterFlags flags;
    u8   pad23;
    PrintCallback callback;
    u32  initialCallbackArg;
    u32  nextCallbackArg;
    u32  callbackArg;
    struct PrintCtx ctx;
};

#include "gfl_heap_wrap.h"


#include "strbuf.h"


#include "gf_font.h"



typedef unsigned long long OSTick;
#include "os_tick.h"

struct PrintCtx *PRINTSYS_GetNextRecord(struct PrintQueue *queue, struct PrintCtx *job);

#include "net.h"

u32 PRINTSYS_GetAllocSize(struct Strbuf *text);

u32 PRINTSYS_GetQueueFreeSpace(const struct PrintQueue *queue);

void PRINTSYS_EnqueuePrint(struct PrintQueue *queue, struct PrintCtx *job, struct Strbuf *str);







u32 PRINTSYS_MeasureTextWidth(u16 *cursor, struct GfFont *font, u32 spacing, u16 **next);


#include "bmp_win.h"

struct TcblTask;

#include "tcbl.h"

void PRINTSYS_Task(struct TcblTask *task, void *work);


#include "msg_speed.h"

void PRINTSYS_Init(u32 heap);

struct PrintQueue *PRINTSYS_QUE_Create(u32 heap);

struct PrintQueue *PRINTSYS_QUE_CreateEx(u16 bufSize, u32 heap);

void PRINTSYS_QUE_Delete(struct PrintQueue *queue);

void PRINTSYS_QUE_SetForceQueue(struct PrintQueue *queue, u32 forceQueue);

void PRINTSYS_QUE_SetLimitTick(struct PrintQueue *queue, u32 tickLow, u32 tickHigh);

u32 PRINTSYS_QUE_Main(struct PrintQueue *queue);

u32 PRINTSYS_QUE_IsFinished(const struct PrintQueue *queue);

u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);

void PRINTSYS_QUE_Clear(struct PrintQueue *queue);

void PRINTSYS_PrintQue(void *queue, struct Bmp *bmp, u32 x, s16 y, void *str, struct GfFont *font);

void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);

void PRINTSYS_SubmitJob(struct PrintQueue *queue, struct PrintCtx *job, struct Strbuf *str);

void PRINTSYS_Print(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font);

void PRINTSYS_PrintColor(struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);

void PRINTSYS_SetupJob(struct PrintCtx *job, struct GfFont *font, struct Bmp *bmp, u32 x, s16 y);

void PRINTSYS_SetJobColor(struct PrintCtx *job, u16 color);

void PRINTSYS_RunJob(struct PrintCtx *job, struct Strbuf *str);

u16 *PRINTSYS_PrintStep(struct PrintCtx *job, u16 *cursor, u32 stopAtPause);

void PRINTSYS_PutGlyph4bpp(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo);

void PRINTSYS_PutGlyph8bpp(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo);

u16 *PRINTSYS_ProcGeneralTag(struct PrintCtx *job, u16 *cursor);

u16 *PRINTSYS_ProcColorTag(struct PrintCtx *job, u16 *cursor);

struct TextPrinter *PRINTSYS_PrintStream(struct BmpWin *win, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, s32 wait, struct Tcbl *tcbl, u32 priority, u16 heap, u16 fillColor);

struct TextPrinter *PRINTSYS_PrintStreamCallBack(struct BmpWin *win, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, s32 wait, struct Tcbl *tcbl, u32 priority, u32 heap, u16 fillColor, PrintCallback callback);

void PRINTSYS_SplitWait(int wait, u8 *speed);

void PRINTSYS_PrintStreamStop(struct TextPrinter *printer);

void PRINTSYS_PrintStreamRun(struct TextPrinter *printer);

u32 PRINTSYS_PrintStreamGetState(const struct TextPrinter *printer);

u32 PRINTSYS_PrintStreamGetWaitKind(const struct TextPrinter *printer);

void PRINTSYS_PrintStreamReleasePause(struct TextPrinter *printer);

void PRINTSYS_PrintStreamDelete(struct TextPrinter *printer);

void PRINTSYS_PrintStreamShortWait(struct TextPrinter *printer, s32 wait);

void PRINTSYS_PrintStreamSetSpeed(struct TextPrinter *printer, s32 wait);

void PRINTSYS_PrintStreamResetSpeed(struct TextPrinter *printer);

u32 PRINTSYS_PrintStreamIsOverrideSpeed(const struct TextPrinter *printer);

extern struct Bmp *_pGlyphBmp;

extern const char printsys_File[];

extern struct PrintCtx _PrintJobWork;

typedef short s16_p07;
extern struct Bmp *BMP_Create(u32 widthTiles, u32 heightTiles, u32 tileBytes, u32 heap);
extern u16   BMP_GetWidth(const struct Bmp *bmp);
extern void  BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey);
extern void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 w, u16 h, u8 value);
extern void  BMP_BlitPaletteOffset(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 w, u32 h, u16 colorKey, u16 paletteBase);
extern u8    BMP_GetTileBytes(struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void BMP_Clear(struct Bmp *bmp, u8 fillColor);
void PRINTSYS_Init(u32 heap)
{
    STRBUF_SetEosChar(0xFFFF);
    _pGlyphBmp = BMP_Create(2, 2, 0x20, heap);
}

/*
 * A 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), swapping its own
 * parameter into the callee's second argument slot and passing the literal
 * 0x400 as the first: `PRINTSYS_QUE_CreateEx(0x400, p)`.  PRINTSYS_QUE_CreateEx (0x0201C450)
 * is a bigger constructor with an inline division-by-multiplication trick
 * and is left as an unresolved extern; only its address is needed here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C440.c \
 *       --addr 0x0201C440 --thumb
 */
struct PrintQueue *PRINTSYS_QUE_Create(u32 heap)
{
    return PRINTSYS_QUE_CreateEx(0x400, heap);
}

/*
 * The head of printsys.c: the module constructor and three accessors on the
 * object it builds.  The file identity is in the image, the same way
 * src/matched/unit_0201D69C.c recovers gf_font.c: the constructor loads
 * 0x020A734C as the debug allocator's __FILE__ argument and the bytes there
 * spell "printsys.c", with "waza_tool.c" ending at 0x020A734B so the `string`
 * class carries the address.  The __LINE__ argument is 287.
 *
 * The constructor was a documented two-byte near miss and this is what closed
 * it: the field at +8 is one `u64`, not two `u32`.  Written as two words the
 * whole function is right except that the pool constant 0x1130 arrives in r1
 * instead of r2; assigning it to a 64 bit field makes the compiler take the
 * other scratch register, because the high half comes from the register that
 * already holds zero.  See
 * docs/idioms/a-u64-field-store-picks-a-different-scratch-register.md.
 *
 * PRINTSYS_QUE_SetLimitTick writes the two halves of that u64 separately, which is what
 * fixes the field as a union of the 64 bit value and a two-word struct rather
 * than a plain `u64` (docs/idioms/long-long-aligns-to-four.md is why +8 is a
 * legal offset for it at all).
 *
 * The size the constructor allocates is (u16)(n + 0x1C) rounded up to a
 * multiple of four and then + 0x18, and the rounding is a `while (v % 4)` loop
 * over a `u16` local: the signed `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * quartet is `% 4` on the promoted int, exactly as src/matched/MUSICAL_SAVE_AddProp.c
 * records for `% 8`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C450.c \
 *       --addr 0x0201C450 --thumb
 */
struct PrintQueue *PRINTSYS_QUE_CreateEx(u16 bufSize, u32 heap)
{
    u16 allocSize = bufSize + 0x1C;
    struct PrintQueue *queue;

    while (allocSize % 4 != 0) {
        allocSize++;
    }
    queue = GFL_HEAP_Alloc(heap, allocSize + 0x18, 0, printsys_File, 287);
    queue->capacity = bufSize;
    queue->limitTicks.value = 0x1130;
    queue->job = 0;
    queue->cursor = 0;
    queue->state.raw = queue->state.raw & ~0xFu;
    queue->state.raw = queue->state.raw & ~0xF0u;
    queue->frameCount = 0;
    queue->head = 0;
    queue->tail = bufSize;
    return queue;
}

void PRINTSYS_QUE_Delete(struct PrintQueue *queue)
{
    GFL_HEAP_Free(queue);
}

void PRINTSYS_QUE_SetForceQueue(struct PrintQueue *queue, u32 forceQueue)
{
    queue->state.raw = (queue->state.raw & ~0xF0u) | (u8)((u8)forceQueue << 4);
}

void PRINTSYS_QUE_SetLimitTick(struct PrintQueue *queue, u32 tickLow, u32 tickHigh)
{
    queue->limitTicks.half.low = tickLow;
    queue->limitTicks.half.high = tickHigh;
}

static inline u16 PrintQueue_WrapOffset(struct PrintQueue *queue, u16 offset)
{
    u16 result = offset;

    if (result >= queue->capacity)
        result = 0;
    return result;
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = (u8 *)ps;` before `base = (u8 *)ps + 0x18;`). Game code has no
 * line table, so these were stand-ins. The plain single assignment gives
 * EXACT in --lang c99 and --lang c: the output bytes do not change. Older
 * text in this header that asks for the double assignment is superseded.
 *
 * printsys.c: the per-frame print pump.  Bumps the frame counter at +6,
 * saves the current text colour, applies the head request's colour when its
 * 4-bit kind is 0 or 2, then runs glyphs through PRINTSYS_PrintStep until the
 * string ends or the tick budget at +8 (OS_GetTick is OS_GetTick) runs
 * out.  On string end it pops the request (PRINTSYS_GetNextRecord) and moves the
 * glyph cursor to the next record's text in the byte ring at +0x18,
 * wrapping twice at the ring size.  Restores the colour and reports idle.
 *
 * The last five bytes closed on the SHAPE OF THE INLINE WRAP HELPER: it
 * copies its parameter into a named local, conditionally zeroes the local
 * and returns it (`u16 r = o; if (r >= size) r = 0; return r;`).  The
 * early-return spelling (`if (o >= size) return 0; return o;`) truncates
 * `off + 0x1C` in place and hoists the ring-size load between the two
 * shifts; the named-local spelling keeps the image's
 * `lsls r0, r7 / lsrs r1, r0 / ldrh r0, [r5, #4]` order.  History in
 * docs/notes/PRINTSYS_QUE_Main.c.txt.
 */
u32 PRINTSYS_QUE_Main(struct PrintQueue *queue)
{
    
    u8  color[3];
    u32 timedOut;
    u16 savedColor;
    u32 jobLetter;
    u32 jobBackground;
    u8 *ring;
    u32 letter;
    u32 shadow;
    u32 background;
    u32 applyColor;
    u32 jobShadow;
    u32 jobOffset;
    u16 offset;
    u64 startTick;

    timedOut = 0;
    queue->frameCount = (u8)(queue->frameCount + 1);
    if (queue->job == 0) {
        return 1;
    }
    GF_FONT_GetTextColor(&color[2], &color[1], &color[0]);
    savedColor = (u16)(((color[2] & 0x1F) << 10) | ((color[1] & 0x1F) << 5) |
                  (color[0] & 0x1F));
    applyColor = 0;
    if (queue->job->pos.bits.colorMode == 0 || queue->job->pos.bits.colorMode == 2) {
        letter = (u8)((queue->job->activeColor >> 10) & 0x1F);
        shadow = (u8)((queue->job->activeColor >> 5) & 0x1F);
        background = (u8)(queue->job->activeColor & 0x1F);
        applyColor = 1;
    }
    if (applyColor != 0) {
        if (GF_FONT_IsTextColorDifferent(letter, shadow, background) != 0) {
            GF_FONT_SetTextColor(letter, shadow, background);
        }
    }
    startTick = OS_GetTick();
    if (queue->job != 0) {
        ring = queue->data;
        do {
            if (queue->job->pos.bits.colorMode == 1) {
                jobLetter = (u8)((queue->job->activeColor >> 10) & 0x1F);
                jobShadow = (u8)((queue->job->activeColor >> 5) & 0x1F);
                jobBackground = (u8)(queue->job->activeColor & 0x1F);
                if (GF_FONT_IsTextColorDifferent(jobLetter, jobShadow, jobBackground) != 0) {
                    GF_FONT_SetTextColor(jobLetter, jobShadow, jobBackground);
                }
                queue->job->pos.bits.colorMode = 2;
            }
            while (queue->cursor[0] != 0xFFFF) {
                queue->cursor = PRINTSYS_PrintStep(queue->job, queue->cursor, 1);
                if (OS_GetTick() - startTick > queue->limitTicks.value) {
                    timedOut = 1;
                    break;
                }
            }
            if (queue->cursor[0] == 0xFFFF) {
                jobOffset = (u16)((u8 *)queue->job - ring);
                queue->job = PRINTSYS_GetNextRecord(queue, queue->job);
                if (queue->job != 0) {
                    offset = PrintQueue_WrapOffset(queue, jobOffset + 0x1C);
                    offset = PrintQueue_WrapOffset(queue, offset + 4);
                    queue->cursor = (u16 *)(queue->data + offset);
                }
            }
        } while (timedOut == 0 && queue->job != 0);
    }
    GF_FONT_SetTextColor((u8)((savedColor >> 10) & 0x1F), (u8)((savedColor >> 5) & 0x1F),
                  (u8)(savedColor & 0x1F));
    if (queue->job != 0) {
        queue->tail = (u16)((u8 *)queue->cursor - queue->data);
        return 0;
    }
    queue->head = 0;
    queue->tail = queue->capacity;
    queue->state.bits.pending = 0;
    return 1;
}

u32 PRINTSYS_QUE_IsFinished(const struct PrintQueue *queue)
{
    if (queue->job == 0) {
        return 1;
    }
    return 0;
}

u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp)
{
    struct PrintCtx *job = queue->job;

    if (job != 0) {
        while (job != 0) {
            if (job->bmp == bmp) {
                return 1;
            }
            job = PRINTSYS_GetNextRecord(queue, job);
        }
    }
    return 0;
}

void PRINTSYS_QUE_Clear(struct PrintQueue *queue)
{
    queue->head = 0;
    queue->tail = queue->capacity;
    queue->cursor = 0;
    queue->job = 0;
}

/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     168 bytes, three functions
 *
 * printsys.c's two public print entry points and the dispatcher they share.
 * PRINTSYS_SubmitJob decides between drawing straight away and queueing the request
 * into the ring: when the module is not busy and the flags nibble in the byte
 * at +7 is clear it calls PRINTSYS_RunJob directly, otherwise it queues with
 * PRINTSYS_EnqueuePrint provided the request fits in the free space PRINTSYS_GetQueueFreeSpace
 * reports.
 *
 * Why it is capped: the `bl` at 0x0201C79C is the only branch to PRINTSYS_EnqueuePrint
 * anywhere in the image, and no pool word holds the address either, so the
 * `label` class has no witness once the compared range holds that call.  No
 * cut helps, because the range cannot be made smaller than PRINTSYS_SubmitJob and
 * the call is inside it.  The `matched` class would carry it, but
 * PRINTSYS_EnqueuePrint is not matched: it is EXACT only in a range that also holds
 * PRINTSYS_Copy, and PRINTSYS_Copy is four bytes short (the original spills
 * the byte counter and keeps the ring cursor in a callee-saved register; every
 * source shape tried makes the opposite choice).  See the header of
 * src/matched/unit_0201D7C4.c.
 *
 * It closes the day PRINTSYS_Copy's register allocation is reproduced, which
 * makes PRINTSYS_EnqueuePrint an EXACT entry and the `matched` class applies.
 *
 * PRINTSYS_SubmitJob's busy test is normalised to 0 or 1 before it is used, which is
 * what a `!= 0` assigned to a local gives; the flags nibble is read as a four
 * bit unsigned bitfield, `((u32)((u8 *)p)[7] << 24) >> 28`, the same spelling
 * src/matched/unit_0201CE5C.c needs for a one bit field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_0201C6FC.c \
 *       --addr 0x0201C6FC --thumb
 */
void PRINTSYS_PrintQue(void *queue, struct Bmp *bmp, u32 x, s16 y, void *str, struct GfFont *font)
{
    PRINTSYS_SetupJob(&_PrintJobWork, font, bmp, x, y);
    PRINTSYS_SubmitJob(queue, &_PrintJobWork, str);
}

void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font,
                  u16 color)
{
    PRINTSYS_SetupJob(&_PrintJobWork, font, bmp, x, y);
    PRINTSYS_SetJobColor(&_PrintJobWork, color);
    PRINTSYS_SubmitJob(queue, &_PrintJobWork, str);
}

void PRINTSYS_SubmitJob(struct PrintQueue *queue, struct PrintCtx *job, struct Strbuf *str)
{
    u32 busy = GFL_NET_GetNegotiationNum() != 0;
    u32 size;

    if (busy == 0 && queue->state.bits.forceQueue == 0) {
        PRINTSYS_RunJob(job, str);
        return;
    }
    size = PRINTSYS_GetAllocSize(str);
    if (size <= PRINTSYS_GetQueueFreeSpace(queue)) {
        PRINTSYS_EnqueuePrint(queue, job, str);
    }
}

/*
 * A printsys entry point: builds the shared print request in the static
 * scratch through PRINTSYS_SetupJob and hands it to PRINTSYS_RunJob with the
 * string object.  The leading STRBUF_GetChars(s) call's result is unused.
 *
 * Withdrawn 2026-09-24 (wave 20, lane 20G): the ../2.0/sp2 pin is retired.
 * The scratch address is held as an integer, a u32 local assigned
 * (u32)&_PrintJobWork and cast back at each site, matching PRINTSYS_PrintColor.c.
 * Spelled this way, dsi/1.1p1 caches the address in a callee-saved
 * register and copies it into r0 at each site, byte-exact under the
 * default compiler.
 */
void PRINTSYS_Print(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font)
{
    uptr jobAddr;

    STRBUF_GetChars(str);
    jobAddr = (uptr)&_PrintJobWork;
    PRINTSYS_SetupJob((struct PrintCtx *)jobAddr, font, bmp, x, y);
    PRINTSYS_RunJob((struct PrintCtx *)jobAddr, str);
}

/*
 * A printsys entry point: the PRINTSYS_Print body plus a
 * PRINTSYS_SetJobColor(scratch, v) step between building the shared print request
 * in the static scratch and handing it to PRINTSYS_RunJob.  The leading
 * STRBUF_GetChars(s) call's result is unused.
 *
 * What closed it (wave 20): the scratch address is held as an integer, a
 * u32 local assigned (u32)&_PrintJobWork and cast back at each of the three
 * sites.  Spelled `&_PrintJobWork` at every site, 1.1p1 value-numbers the
 * address once, caches it in r4 and schedules z's outgoing stack store
 * straight after the first call to free that register (37 bytes out).
 * Through the integer local the address is rematerialised from its one pool
 * word at every site, z stays in r4 until its store after r0..r3 as the
 * image does, and the stacked u16 read keeps the 1.1p1 base.  This retires
 * the ../2.0/sp2 near miss (2 out) the notes carried.
 */
void PRINTSYS_PrintColor(struct Bmp *bmp, u32 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color)
{
    uptr jobAddr;

    STRBUF_GetChars(str);
    jobAddr = (uptr)&_PrintJobWork;
    PRINTSYS_SetupJob((struct PrintCtx *)jobAddr, font, bmp, x, y);
    PRINTSYS_SetJobColor((struct PrintCtx *)jobAddr, color);
    PRINTSYS_RunJob((struct PrintCtx *)jobAddr, str);
}

/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     156 bytes including five pool words, one function
 *
 * printsys.c's render-context set-up: it records the surface and the string,
 * picks the blitter, packs the pen position into two ten bit fields of the
 * word at +4 and snapshots the current text colour into +0xC and +0xE.
 *
 * The two blitter addresses are the reason this is parked.  0x0201CA2C and
 * 0x0201CA78 are reached only through the two pool words in this function's
 * own literal pool, so `literal` discards both witnesses under the honesty
 * rule and no cut helps.  The `matched` class covers 0x0201CA2C now
 * (src/matched/unit_0201CA2C.c) but not 0x0201CA78, which is parked in
 * src/pending/PRINTSYS_PutGlyph8bpp.c for a reason of its own.  This file graduates
 * with that one.
 *
 * Two details worth keeping.  The three edits of the word at +4 are plain
 * integer mask-and-or arithmetic, the same spelling
 * src/matched/unit_0201C8A4.c uses, and the compiler writes the field only
 * twice for three statements because it keeps the value in a register across
 * the last two.  And the pen coordinates are read back out of the halfwords
 * that were just stored, with `ldrsh` and a register offset, which is the only
 * evidence that +0 and +2 are signed
 * (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/PRINTSYS_SetupJob.c \
 *       --addr 0x0201C808 --thumb
 */
void PRINTSYS_SetupJob(struct PrintCtx *job, struct GfFont *font, struct Bmp *bmp, u32 x, s16 y)
{
    u8 color[3];

    job->bmp = bmp;
    if (BMP_GetTileBytes(bmp) == 0x20) {
        job->blitGlyph = PRINTSYS_PutGlyph4bpp;
    } else {
        job->blitGlyph = PRINTSYS_PutGlyph8bpp;
    }
    job->font = font;
    job->penX = x;
    job->pos.raw = (job->pos.raw & 0xFFFFFC00u) | (job->penX & 0x3FF);
    job->penY = y;
    job->pos.raw = (job->pos.raw & 0xFFF003FFu) | ((job->penY & 0x3FF) << 10);
    job->pos.raw = (job->pos.raw & 0xFF0FFFFFu) | (1u << 20);
    GF_FONT_GetTextColor(&color[2], &color[1], &color[0]);
    job->textColor = (u16)(((color[2] & 0x1F) << 10) | ((color[1] & 0x1F) << 5)
                     | (color[0] & 0x1F));
    job->activeColor = job->textColor;
}

/*
 * Stores a halfword parameter at +0xE, then clears a four-bit field at bits
 * 20-23 of the word at +4 and sets it unconditionally to 1 (the mask/OR
 * pair is plain integer arithmetic, `(x & ~0xF00000) | (1 << 20)`; no
 * bitfield struct is needed since the two shift amounts in the AND/OR would
 * not match docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md's
 * shape anyway).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C8A4.c \
 *       --addr 0x0201C8A4 --thumb
 */
void PRINTSYS_SetJobColor(struct PrintCtx *job, u16 color)
{
    job->activeColor = color;
    job->pos.raw = (job->pos.raw & ~0xF00000u) | (1u << 20);
}

/*
 * printsys.c: if the 4-bit field at bits 20..23 of PrintCtx+0x04 is 1,
 * split the packed 5/5/5 triple at +0x0E and pass it to GF_FONT_IsTextColorDifferent; on a
 * nonzero result fill buf through GF_FONT_GetTextColor, pass the triple to
 * GF_FONT_SetTextColor and set done; then set the field to 2.  Render glyphs
 * through PRINTSYS_PrintStep until 0xFFFF, and if done, pass buf back to
 * GF_FONT_SetTextColor.
 *
 * Two facts the bytes pin (docs/notes/pkt_0201C8BC.c.txt has the history):
 *
 *  1. `done` is a PLAIN u8, not a volatile int.  The image reloads the
 *     zero from [sp,#4] before each of the three byte stores and forms buf's
 *     address as `add r1, sp, #8`: [sp,#4] is the SPILL slot of a register
 *     candidate, and buf is the first addressable local.  A plain int done
 *     has its zero forwarded into the stores (180 bytes); a volatile done
 *     gets a home next to buf in the local area and the stores go off
 *     `add r0, sp, #4` plus 4/5/6 (17 out).  A u8 (or u16, or signed char)
 *     flag is neither forwarded nor addressable
 *     (docs/idioms/a-narrow-flag-local-is-spilled-not-constant-propagated.md).
 *
 *  2. The rewrite mask is 0xFF0FFFFF (clear bits 20..23, the field the
 *     `<< 8 >> 28` test reads), then or 0x200000 (field = 2).  Earlier
 *     notes and docs/families/printsys.h wrote 0xFFFF0FFF.
 *
 * hi and mid are int (the u8 truncation is in the expression), lo is u8:
 * that is what puts hi in r7, mid in r6 and lo in the [sp] spill slot.
 */
void PRINTSYS_RunJob(struct PrintCtx *job, struct Strbuf *str)
{
    u16 *cursor = (u16 *)STRBUF_GetChars(str);
    u8 savedColor[3];
    u8 changed = 0;
    int letter;
    int shadow;
    u8 background;

    savedColor[0] = changed;
    savedColor[1] = changed;
    savedColor[2] = changed;
    if (((int)(job->pos.raw << 8)) >> 28 == 1) {
        int color = job->activeColor;

        letter = (u8)((color >> 10) & 0x1F);
        shadow = (u8)((color >> 5) & 0x1F);
        background = (u8)(color & 0x1F);
        if (GF_FONT_IsTextColorDifferent(letter, shadow, background) != 0) {
            GF_FONT_GetTextColor(&savedColor[2], &savedColor[1], &savedColor[0]);
            GF_FONT_SetTextColor((int)letter, (int)shadow, (int)background);
            changed = 1;
        }
        job->pos.raw = (job->pos.raw & 0xFF0FFFFF) | 0x200000;
    }
    while (*cursor != 0xFFFF) {
        cursor = (u16 *)PRINTSYS_PrintStep(job, cursor, 1);
    }
    if (changed) {
        GF_FONT_SetTextColor((int)savedColor[2], (int)savedColor[1], (int)savedColor[0]);
    }
}

/*
 * printsys.c: the glyph-run interpreter.  Walks the halfword string `p`
 * rendering one glyph per call to the renderer hook at PrintCtx+0x18 and
 * returns the cursor one halfword past the glyph it drew; 0xFFFF (end) and a
 * 0xF000 control block whose code byte is 0xBE with `f == 0` return the
 * cursor unchanged.
 *
 * Three facts the bytes pin, each one worth a whole spelling:
 *
 *  1. PrintCtx+0x04 is a SIGNED 10-BIT BITFIELD, not the `u32` flag word
 *     docs/families/printsys.h had.  The 0xFFFE (line break) arm reads it as
 *     `lsls #0x16 / asrs #0x16`, a 22-bit equal-width pair with a signed right
 *     half, which only `s32 :10` produces
 *     (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  Spelled
 *     `u32` the store is a bare `strh` and the pair is gone.
 *
 *  2. The control-code dispatch is a SWITCH, not an if/else chain.  The
 *     original tests 0xBD, 0xBE, 0xFF with three forward `beq`s and a final
 *     `b default`; an if/else chain of the same three tests emits `bne` skips
 *     instead and costs 86 concrete bytes here.  The switch is sparse (0xBD,
 *     0xBE, 0xFF), so no jump table appears, only the compare chain.
 *
 *  3. The 0xBE arm's guard is spelled `if (f != 0) { ...; break; } return p;`
 *     and NOT `if (f == 0) return p;`.  The original's `cmp r1, #0 / beq` puts
 *     the return out of line as the TAKEN target; the equality form emits
 *     `bne` and mirrors the last seven instructions
 *     (docs/idioms/the-fall-through-arm-is-the-source-order.md).  This was the
 *     last 13 concrete bytes.
 *
 * The block-layout shape also matters: the glyph body is reached by an
 * explicit `goto glyph` to a label AFTER the `while (1)`, which is what places
 * it physically last (at +0x8E) rather than in the middle.  Written as the
 * final `else` arm of the chain the compiler sinks the F000 block instead and
 * the function comes out 180 bytes, four short.
 *
 * The redundant inner `if (v == 0xF000) k = (u8)(p[1] >> 8); else k = 0xFF;`
 * inside the F000 arm is real: the original repeats the same `cmp r0, r7` test
 * (at +0x3C, reusing the flags of the outer one at +0x12) rather than assuming
 * it.  That is an inlined code-fetch helper, and collapsing it to a plain
 * `k = (u8)(p[1] >> 8)` loses the `bne`/`movs #0xff` pair.
 */
u16 *PRINTSYS_PrintStep(struct PrintCtx *job, u16 *cursor, u32 stopAtPause)
{
    u8 glyphInfo[4];
    s16 *penY = &job->penY;

    while (1) {
        u16 code = *cursor;
        if (code != 0xF000) {
            if (code != 0xFFFE) {
                if (code == 0xFFFF) {
                    return cursor;
                }
                goto glyph;
            }
            job->penX = (s16)job->pos.bits.originX;
            cursor = cursor + 1;
            *penY = (s16)(*penY + 0x10);
            continue;
        }
        {
            u32 tag;
            if (code == 0xF000) {
                tag = (u8)(cursor[1] >> 8);
            } else {
                tag = 0xFF;
            }
            switch (tag) {
            case 0xBD:
                cursor = PRINTSYS_ProcGeneralTag(job, cursor);
                break;
            case 0xFF:
                cursor = PRINTSYS_ProcColorTag(job, cursor);
                break;
            case 0xBE:
                if (stopAtPause != 0) {
                    if (code != 0xF000) {
                        continue;
                    }
                    cursor = (u16 *)((u8 *)(cursor + 3) + cursor[2] * 2);
                    break;
                }
                return cursor;
            default:
                if (code != 0xF000) {
                    continue;
                }
                cursor = (u16 *)((u8 *)(cursor + 3) + cursor[2] * 2);
                break;
            }
        }
    }
  glyph:
    {
        u16 code = *cursor;
        job->blitGlyph(job->bmp, job->penX, job->penY, job->font, code, glyphInfo);
        job->penX = (s16)(job->penX + glyphInfo[2]);
        return cursor + 1;
    }
}

/*
 * One of the two printsys.c glyph blitters, both of which forward the caller's
 * pen record to GF_FONT_ReadGlyph and then hand the result to a renderer reached
 * through the module object at 0x02146558.  The pair is cut here rather than
 * matched as one range because GF_FONT_ReadGlyph is reached from exactly two places
 * in the image, 0x0201CA4C and 0x0201CA98, one in each function: matched
 * together neither site has a witness, matched apart each is the other's `label`
 * witness.  That is
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * Its sibling at 0x0201CA78 stays parked (src/pending/PRINTSYS_PutGlyph8bpp.c): it calls
 * 0x02043AAC, and 0x0201CABC is the only branch to that address anywhere in the
 * image, so no cut reaches it.
 *
 * f is a four-byte pen record: f[0] is an x bias added to the caller's x, f[1]
 * and f[3] are passed straight through.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CA2C.c \
 *       --addr 0x0201CA2C --thumb
 */
void PRINTSYS_PutGlyph4bpp(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo)
{
    GF_FONT_ReadGlyph(font, code, BMP_GetPixels(_pGlyphBmp), (void *)glyphInfo);
    BMP_Blit(_pGlyphBmp, bmp, 0, 0, x + glyphInfo[0], y, glyphInfo[1], glyphInfo[3], 0);
}

/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     80 bytes including two pool words, one function
 *
 * printsys.c's second glyph blitter, the twin of PRINTSYS_PutGlyph4bpp in
 * src/matched/unit_0201CA2C.c.  The two differ only in which renderer they
 * call and in the two extra stack arguments this one passes, 0xF and 0.
 *
 * Why it is capped: the `blx` at 0x0201CABC is the only branch to 0x02043AAC
 * anywhere in the image, checked over every Thumb BL/BLX pair and every ARM
 * branch in all 242 regions, and no pool word holds the address either.  The
 * `label` class therefore has no witness once the compared range holds that
 * call, and no cut helps, because the range cannot be smaller than this one
 * function.  Cutting it away from PRINTSYS_PutGlyph4bpp is what let that function come
 * out EXACT, since the two are the only callers of GF_FONT_ReadGlyph and each is
 * now the other's witness
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * It closes the day 0x02043AAC is matched (the `matched` class) or acquires a
 * second caller.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/PRINTSYS_PutGlyph8bpp.c \
 *       --addr 0x0201CA78 --thumb
 */
void PRINTSYS_PutGlyph8bpp(struct Bmp *bmp, s32 x, s32 y, struct GfFont *font, u16 code, const u8 *glyphInfo)
{
    GF_FONT_ReadGlyph(font, code, BMP_GetPixels(_pGlyphBmp), (void *)glyphInfo);
    BMP_BlitPaletteOffset((struct Bmp *)_pGlyphBmp, (struct Bmp *)bmp, 0, 0, x + glyphInfo[0], y, glyphInfo[1], glyphInfo[3], 0xF, 0);
}

/*
 * printsys.c: applies one 0xF000 control block whose code byte is 0xBD -- the
 * "set colour / align line" family -- and steps the cursor past the block.
 * Called from exactly one place image-wide, 0x0201C9D0 inside PRINTSYS_PrintStep,
 * which is why PRINTSYS_PrintStep resolved that call `sole-ref/code` until this
 * file existed; it is `matched` now.
 *
 * The dispatch is a DENSE switch on a 7-entry PC-relative halfword table at
 * +0x30..+0x3D, so cases 0..6 must ALL be written, including `case 6:` which
 * is empty and shares the default's exit
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md and
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  Without the
 * empty case 6 the bound check is `cmp r1, #5` and the table has six entries.
 *
 * Two spellings the bytes pin:
 *
 *  1. The switch selector is `((u32)(u8)p[1] << 16) >> 16`, TWO stacked
 *     narrowings: the original has `lsls #0x18 / lsrs #0x18` (the byte) and
 *     then `lsls #0x10 / lsrs #0x10` (a u16) before the bound check.  Written
 *     as a plain `(u8)p[1]` into a `u16` local the second pair folds away and
 *     the function is four bytes short.  Two nested inlined accessors, one
 *     returning u8 and one u16.
 *
 *  2. The 5/5/5 pack in case 0 is `(b & 0x1F) | (((r << 27) >> 17) |
 *     ((g << 27) >> 22))`, i.e. RED shifts to bit 10 and GREEN to bit 5.  The
 *     reversed grouping is size-exact and eight bytes out; the order of the
 *     two `lsls #0x1b` operands in the image names which byte is which
 *     (docs/idioms/commutative-operand-order-names-the-temporary.md).
 *
 * Also corrected against docs/families/printsys.h as it stood: the measuring
 * arms (cases 2 and 3) hand BMP_GetWidth the handle at PrintCtx+0x14, not
 * +0x18; +0x18 is the renderer hook PRINTSYS_PrintStep calls through.  And
 * PrintCtx+0x04 is a SIGNED 10-BIT BITFIELD (`lsls #0x16 / asrs #0x16`), not
 * a u32 flag word -- the same fact src/matched/PRINTSYS_PrintStep.c records.
 *
 * Case order in the source is 0, 1, 3, 2, 4, 5, 6: the table's displacements
 * put case 3's body (0x0201CB7E) before case 2's (0x0201CBB6), and this
 * compiler emits switch arms in source order.
 */
u16 *PRINTSYS_ProcGeneralTag(struct PrintCtx *job, u16 *cursor)
{
    u32 background;
    u16 code = *cursor;
    u32 tag;

    if (code == 0xF000) {
        tag = ((u32)(u8)cursor[1] << 16) >> 16;
    } else {
        tag = 0xFFFF;
    }

    switch (tag) {
    case 0: {
        u32 letter, shadow, unusedBackground;
        letter = (u8)((code == 0xF000) ? cursor[3] : 0);
        shadow = (u8)((code == 0xF000) ? cursor[4] : 0);
        background = (u8)((code == 0xF000) ? cursor[5] : 0);
        GF_FONT_SetTextColor(letter, shadow, background);
        job->activeColor = (u16)((background & 0x1F) | (((letter << 27) >> 17) | ((shadow << 27) >> 22)));
        break;
    }
    case 1: {
        u16 color = job->textColor;
        GF_FONT_SetTextColor((u8)((color >> 10) & 0x1F), (u8)((color >> 5) & 0x1F), (u8)(color & 0x1F));
        break;
    }
    case 3: {
        s32 width = BMP_GetWidth(job->bmp);
        s32 room = (s32)(width - job->pos.bits.originX);
        u32 strWidth;
        u32 unusedMargin = 0;
        strWidth = (u32)PRINTSYS_MeasureTextWidth(cursor, job->font, 0, 0);
        {
            u32 margin = 0;
            if (*cursor == 0xF000) {
                margin = cursor[3];
            }
            job->penX = (s16)(job->pos.bits.originX + (room - (s32)strWidth) - 1 - (s32)margin);
        }
        break;
    }
    case 2: {
        s32 width = BMP_GetWidth(job->bmp);
        s32 room = (s32)(width - job->pos.bits.originX);
        s32 strWidth = PRINTSYS_MeasureTextWidth(cursor, job->font, 0, 0);
        if (strWidth < room) {
            job->penX = (s16)(job->pos.bits.originX + (room - strWidth) / 2);
        } else {
            job->penX = (s16)job->pos.bits.originX;
        }
        break;
    }
    case 4: {
        u32 offset = (code == 0xF000) ? cursor[3] : 0;
        job->penX = (s16)(job->penX + (s16)offset);
        break;
    }
    case 5: {
        u32 offset = (code == 0xF000) ? cursor[3] : 0;
        job->penX = (s16)offset;
        break;
    }
    case 6:
        break;
    default:
        break;
    }

    if (*cursor == 0xF000) {
        cursor = (u16 *)((u8 *)(cursor + 3) + cursor[2] * 2);
    }
    return cursor;
}

u16 *PRINTSYS_ProcColorTag(struct PrintCtx *job, u16 *cursor)
{
    u16 tag;
    u8 paletteRow;
    u8 background;
    int base;

    if (cursor[0] == 0xF000) {
        tag = (u16)(cursor[1] & 0xFF);
    } else {
        tag = 0xFFFF;
    }
    if (tag == 0) {
        paletteRow = (u8)((cursor[0] == 0xF000) ? cursor[3] : 0);
        if (paletteRow == 0xFF) {
            GF_FONT_SetTextColor((u8)((job->activeColor >> 10) & 0x1F), (u8)((job->activeColor >> 5) & 0x1F),
                          (u8)(job->activeColor & 0x1F));
        } else {
            int letter;
            int shadow;
            base = paletteRow * 2;
            background = (u8)(job->textColor & 0x1F);
            shadow = base + 2;
            letter = base + 1;
            GF_FONT_SetTextColor((u8)letter, (u8)shadow, background);
            job->activeColor = (u16)((((u8)letter & 0x1F) << 10) | (((u8)shadow & 0x1F) << 5)
                          | (background & 0x1F));
        }
    }
    if (cursor[0] == 0xF000) return (u16 *)((char *)cursor + 6 + cursor[2] * 2);
    return cursor;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_PrintStream.c \
 *       --func PRINTSYS_PrintStream --addr 0x0201CCE4 --cc 1.1p1 --thumb
 */
struct TextPrinter *PRINTSYS_PrintStream(struct BmpWin *win, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, s32 wait, struct Tcbl *tcbl,
                   u32 priority, u16 heap, u16 fillColor)
{
    return PRINTSYS_PrintStreamCallBack(win, x, y, str, font, wait, tcbl, priority, heap, fillColor, 0);
}

/*
 * The printsys text-record constructor: registers PRINTSYS_Task as a
 * task with a 0x50-byte work area, builds the PrintCtx at +0x34 through
 * PRINTSYS_SetupJob, splits the signed speed argument into the sign/magnitude
 * pairs at +0x18..+0x1D, and initialises every other field of struct Rec
 * (the same layout src/matched/PRINTSYS_Task.c consumes).  Returns the
 * record.
 *
 * The two-load swap the notes carried at +0x28/+0x30 (a4 read before a1)
 * was a declaration fact, not a scheduling one:
 *  - PRINTSYS_SetupJob's real prototype (src/matched/PRINTSYS_SetupJob.c) is
 *    (struct PrintCtx *, void *, void *, s16, s16), so a1 and a2 are s16
 *    parameters here;
 *  - the byte stored to +0x20 is the tenth argument declared `u16 a9`.
 *    Thumb ldrh cannot use sp as a base, which is where the notes'
 *    `*(u16 *)((u8 *)&a4 + 0x14)` came from; taking a4's address to fake
 *    it pinned the a4 load late.  With a9 a real u16 parameter nothing
 *    takes an address and the loads schedule as in the image.
 */
struct TextPrinter *PRINTSYS_PrintStreamCallBack(struct BmpWin *win, s16 x, s16 y, struct Strbuf *str,
                          struct GfFont *font, s32 wait, struct Tcbl *tcbl, u32 priority, u32 heap, u16 fillColor,
                          PrintCallback callback)
{
    struct TextPrinter *printer;
    struct TcblNode *task;
    struct Bmp *bmp;
    u8 speed[2];

    bmp = BMP_WIN_GetBmp(win);
    task = (struct TcblNode *)TCBL_AddTask((struct TcblSystem *)tcbl, PRINTSYS_Task, 0x50, priority);
    printer = TCBL_GetWork((struct TcblTask *)task);

    printer->task = task;
    PRINTSYS_SetupJob(&printer->ctx, font, bmp, x, y);
    PRINTSYS_SplitWait(wait, speed);
    printer->defaultGlyphs = speed[1];
    {
        u8 waitFrames = speed[0];
        printer->defaultWait = waitFrames;
        printer->overrideWait = waitFrames;
        printer->waitFrames = waitFrames;
    }
    {
        u8 glyphs = printer->defaultGlyphs;
        printer->overrideGlyphs = glyphs;
        printer->glyphsPerTick = glyphs;
    }
    printer->cursor = STRBUF_GetChars(str);
    printer->waitCounter = 0;
    printer->callback = callback;
    printer->initialCallbackArg = 0;
    printer->nextCallbackArg = 0;
    printer->callbackArg = 0;
    printer->bmpWin = win;
    printer->bmp = bmp;
    printer->state = 0;
    printer->fillColor = fillColor;
    printer->waitKind = 1;
    printer->scrollPixels = 0;
    printer->flags.bits.advance = 0;
    printer->flags.bits.halted = 0;
    printer->flags.bits.scrolling = 0;
    printer->callbackResult = 0;
    printer->flags.bits.useOverrideSpeed = 0;
    printer->flags.bits.clearOverridePending = 0;
    return printer;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           PRINTSYS_PrintStreamGetWaitKind, PRINTSYS_PrintStreamReleasePause, PRINTSYS_PrintStreamDelete
 *
 * PRINTSYS_SplitWait splits a signed delta into a sign-magnitude pair of output
 * bytes: byte[1]=1 and byte[0]=the value when it is non-negative, byte[1]=
 * the absolute value and byte[0]=0 when it is negative.  The two branches
 * store to the two bytes in opposite order from each other, which is what
 * the original does and is not an artefact of how it is written.
 *
 * PRINTSYS_PrintStreamStop, PRINTSYS_PrintStreamRun and PRINTSYS_PrintStreamReleasePause are three single-bit
 * operations on a byte at offset 0x22 of an object: set bit 0 (written
 * through a redundant clear-then-set, `(x & ~1) | 1`, rather than a plain
 * `x |= 1`, which is what the bytes show), clear bit 0, and set bit 2 with
 * a plain OR.  All three read and write the field through two separate
 * `((u8 *)p)[0x22]` expressions rather than a named pointer local, which is
 * what keeps the load address and the store address computed independently
 * the way the original does it.
 *
 * PRINTSYS_PrintStreamGetState and PRINTSYS_PrintStreamGetWaitKind are the two four-byte word getters this
 * neighbourhood keeps reusing (the same shape as
 * src/matched/unit_0201AA14.c's pair); disasm.py's prologue sweep does not
 * label either of them, since a two-instruction leaf saves nothing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), so both were
 * read directly out of the `.word` run the listing prints between
 * PRINTSYS_PrintStreamRun and PRINTSYS_PrintStreamReleasePause.
 *
 * PRINTSYS_PrintStreamDelete frees and clears an owned pointer at offset 0x10 if it is
 * non-null.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CDF4.c \
 *       --addr 0x0201CDF4 --thumb
 */
void PRINTSYS_SplitWait(int wait, u8 *speed)
{
    if (wait >= 0) {
        speed[1] = 1;
        speed[0] = (u8)wait;
    } else {
        speed[1] = (u8)(-wait);
        speed[0] = 0;
    }
}

void PRINTSYS_PrintStreamStop(struct TextPrinter *printer)
{
    printer->flags.raw = (printer->flags.raw & ~1u) | 1u;
}

void PRINTSYS_PrintStreamRun(struct TextPrinter *printer)
{
    printer->flags.raw = printer->flags.raw & ~1u;
}

u32 PRINTSYS_PrintStreamGetState(const struct TextPrinter *printer)
{
    return printer->state;
}

u32 PRINTSYS_PrintStreamGetWaitKind(const struct TextPrinter *printer)
{
    return printer->waitKind;
}

void PRINTSYS_PrintStreamReleasePause(struct TextPrinter *printer)
{
    printer->flags.raw = printer->flags.raw | 4u;
}

void PRINTSYS_PrintStreamDelete(struct TextPrinter *printer)
{
    if (printer->task != 0) {
        TCBL_DeleteTask((struct TcblTask *)printer->task);
        printer->task = 0;
    }
}

/*
 * Four more operations on the object src/matched/unit_0201CDF4.c works on,
 * continuing its run of single-bit edits of the flag byte at +0x22: this
 * range sets bit 4 and bit 3, clears bit 3, and reads bit 3 back.
 *
 * PRINTSYS_PrintStreamShortWait lowers a level-like byte at +0x1E and, when the new value is
 * zero, replaces the pair at +0x1C/+0x1D through PRINTSYS_PrintStreamSetSpeed with whatever
 * MSG_SPEED_GetWaitForSpeed(2) returns.  PRINTSYS_PrintStreamResetSpeed is the undo: it clears the bit and
 * restores the pair from the backup at +0x18/+0x19.
 *
 * PRINTSYS_PrintStreamIsOverrideSpeed is an unlabelled follower, eight bytes with no prologue.  It
 * reads bit 3 as a `lsls #0x1C` / `lsrs #0x1F` pair, which is the bitfield
 * extraction shape of
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md rather than
 * the `lsrs #3` / `ands #1` a shift and mask would give.
 *
 * The bit read has to be cast to u32 before the shift pair: on the promoted
 * `int` the right shift is an `asrs` and the one byte is wrong.
 *
 * Every one of the four reaches the flag byte through two independent
 * `((u8 *)p)[0x22]` expressions, the same spelling unit_0201CDF4.c needs, so
 * the load address and the store address are computed separately.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CE5C.c \
 *       --addr 0x0201CE5C --thumb
 */
void PRINTSYS_PrintStreamShortWait(struct TextPrinter *printer, s32 wait)
{
    if (wait < printer->waitCounter) {
        printer->waitCounter = (u8)wait;
        if (wait == 0) {
            PRINTSYS_PrintStreamSetSpeed(printer, MSG_SPEED_GetWaitForSpeed(2));
            printer->flags.raw = 0x10u | printer->flags.raw;
        }
    }
}

void PRINTSYS_PrintStreamSetSpeed(struct TextPrinter *printer, s32 wait)
{
    u8 speed[2];

    PRINTSYS_SplitWait(wait, speed);
    printer->overrideGlyphs = speed[1];
    printer->overrideWait = speed[0];
    printer->flags.raw = 8u | printer->flags.raw;
}

void PRINTSYS_PrintStreamResetSpeed(struct TextPrinter *printer)
{
    printer->flags.raw = printer->flags.raw & ~8u;
    printer->overrideGlyphs = printer->defaultGlyphs;
    printer->overrideWait = printer->defaultWait;
}

u32 PRINTSYS_PrintStreamIsOverrideSpeed(const struct TextPrinter *printer)
{
    return ((u32)printer->flags.raw << 28) >> 31;
}

#include "../types.h"










#include "mi_memory.h"

void PRINTSYS_Apply(struct TextPrinter *printer);

u32 PRINTSYS_CountLine(struct Strbuf *text);

u32 PRINTSYS_MeasureWidestLine(struct Strbuf *text, struct GfFont *font, u32 spacing);

u32 PRINTSYS_InitCallerSuppliedArray(struct Strbuf *text, struct GfFont *font, u32 spacing, u32 *widths, u32 maxLines);

u32 PRINTSYS_CopyLine(struct Strbuf *src, struct Strbuf *dst, u32 lineNumber);

u32 PRINTSYS_CountLines(struct Strbuf *text, struct GfFont *font);

u32 PRINTSYS_CountControlTag(struct Strbuf *text);

u32 PRINTSYS_SearchIndex(struct Strbuf *text, u8 markerId);

u32 PRINTSYS_MeasureText(struct Strbuf *text, u8 markerId, struct GfFont *font, u32 spacing);

u32 PRINTSYS_GetTagChar(void);

u32 PRINTSYS_IsWordSlotTag(const u16 *tag);

u32 PRINTSYS_GetTagGroup(const u16 *tag);

void PRINTSYS_AppendTag(struct Strbuf *text, u32 group, u32 kind, u16 paramCount, const u16 *params);

u32 PRINTSYS_GetTagKind(const u16 *tag);

u32 PRINTSYS_GetTagParam(const u16 *tag, u32 paramIndex);

u16 *PRINTSYS_SkipTag(u16 *tag);

u32 PRINTSYS_GetAlignedSize(struct Strbuf *text);

void *PRINTSYS_Copy(struct PrintQueue *queue, const u8 *src, u16 length, u16 unit);



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
 * the 0xF000/0xBE control block (PRINTSYS_Apply).  State 1 waits on flag
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
void PRINTSYS_Task(struct TcblTask *task, void *work)
{
    struct TextPrinter *printer = work;
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

    if (printer->flags.bits.halted)
        goto end;

    switch (printer->state) {
    case 0:
        if (printer->flags.bits.scrolling) {
            if (printer->scrollPixels < 0x10) {
                u16 step = 4;
                if (printer->scrollPixels + 4 > 0x10)
                    step = 0x10 - printer->scrollPixels;
                printer->scrollPixels += (u8)step;
                width = BMP_GetWidth(printer->bmp);
                height = BMP_GetHeight(printer->bmp) - step;
                BMP_Blit(printer->bmp, printer->bmp, 0, step, 0, 0, width, height, 0xFFFF);
                BMP_FillRect(printer->bmp, 0, (s16)height, width, step, printer->fillColor);
                BMP_WIN_TransferChars(printer->bmpWin);
                return;
            }
            printer->ctx.penX = printer->ctx.pos.bits.originX;
            printer->ctx.penY = 0x10;
            printer->flags.bits.scrolling = 0;
            return;
        }
        if (printer->waitCounter == 0) {
            if (printer->flags.bits.useOverrideSpeed)
                glyphsThisTick = printer->overrideGlyphs;
            else
                glyphsThisTick = printer->glyphsPerTick;
            if (printer->flags.bits.clearOverridePending) {
                PRINTSYS_PrintStreamResetSpeed(printer);
                printer->flags.bits.clearOverridePending = 0;
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
                            PRINTSYS_Apply(printer);
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
                            if (printer->flags.bits.useOverrideSpeed)
                                printer->waitCounter = printer->overrideWait;
                            else
                                printer->waitCounter = printer->waitFrames;
                        }
                        BMP_WIN_TransferChars(printer->bmpWin);
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
        if (printer->flags.bits.advance) {
            switch (printer->waitKind) {
            case 0:
                printer->flags.bits.scrolling = 1;
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
 * and steps the cursor past it (struct TextPrinter as in PRINTSYS_Task).  The
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
void PRINTSYS_Apply(struct TextPrinter *printer)
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
        printer->flags.bits.advance = 0;
        printer->ctx.penX = printer->ctx.pos.bits.originX;
        printer->ctx.penY = 0;
        break;
    case 1:
        skipLineBreak = 1;
        SetWaitState(printer, 1);
        printer->scrollPixels = 0;
        printer->flags.bits.advance = 0;
        printer->ctx.penX = printer->ctx.pos.bits.originX;
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
 *   python tools/match.py one --src src/matched/PRINTSYS_MeasureTextWidth.c
 *       --func PRINTSYS_MeasureTextWidth --addr 0x0201D26C --cc 1.1p1 --thumb
 */
u32 PRINTSYS_MeasureTextWidth(u16 *cursor, struct GfFont *font, u32 spacing, u16 **next)
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
 *   python tools/match.py one --src src/matched/PRINTSYS_CountLine.c
 *       --func PRINTSYS_CountLine --addr 0x0201D2C8 --cc 1.1p1 --thumb
 */
u32 PRINTSYS_CountLine(struct Strbuf *text)
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
 * the string object's halfword payload one line at a time with PRINTSYS_MeasureTextWidth,
 * which measures one line and writes the cursor for the next one back through
 * its fourth argument, and keeps the running maximum.  0xFFFF is the string
 * terminator (the same sentinel PRINTSYS_RunJob stops on).
 *
 * The cursor is a local whose address is taken, so it lives on the stack and
 * the loop test reloads it every iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_MeasureWidestLine.c
 *       --func PRINTSYS_MeasureWidestLine --addr 0x0201D304 --cc 1.1p1 --thumb
 */
u32 PRINTSYS_MeasureWidestLine(struct Strbuf *text, struct GfFont *font, u32 spacing)
{
    u16 *cursor;
    u32 widest;
    u32 lineWidth;

    widest = 0;
    cursor = STRBUF_GetChars(text);
    while (*cursor != 0xFFFF) {
        lineWidth = PRINTSYS_MeasureTextWidth(cursor, font, spacing, &cursor);
        if (lineWidth > widest) {
            widest = lineWidth;
        }
    }
    return widest;
}

/*
 * printsys.c: fills a caller-supplied array with the pixel width of each line
 * of a string object, at most `max` of them, and returns how many were
 * written.  PRINTSYS_MeasureTextWidth measures one line and hands back the cursor for the
 * next through its fourth argument; the cursor is a stack local because its
 * address is taken.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_InitCallerSuppliedArray.c
 *       --func PRINTSYS_InitCallerSuppliedArray --addr 0x0201D33C --cc 1.1p1 --thumb
 */
u32 PRINTSYS_InitCallerSuppliedArray(struct Strbuf *text, struct GfFont *font, u32 spacing, u32 *widths, u32 maxLines)
{
    u16 *cursor;
    u32 lineIndex;

    cursor = STRBUF_GetChars(text);
    lineIndex = 0;
    while (lineIndex < maxLines) {
        if (*cursor == 0xFFFF) {
            break;
        }
        widths[lineIndex] = PRINTSYS_MeasureTextWidth(cursor, font, spacing, &cursor);
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
 *   python tools/match.py one --src src/matched/PRINTSYS_CopyLine.c
 *       --func PRINTSYS_CopyLine --addr 0x0201D37C --cc 1.1p1 --thumb
 */
u32 PRINTSYS_CopyLine(struct Strbuf *src, struct Strbuf *dst, u32 lineNumber)
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
 * the font's line height (GF_FONT_GetLineHeight).  The line counter is a u16, so the
 * increment carries the halfword truncation pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_CountLines.c
 *       --func PRINTSYS_CountLines --addr 0x0201D42C --cc 1.1p1 --thumb
 */
u32 PRINTSYS_CountLines(struct Strbuf *text, struct GfFont *font)
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
    return (lineBreaks + 1) * GF_FONT_GetLineHeight(font);
}

/*
 * Counts the control tags of a message string for which PRINTSYS_IsWordSlotTag returns
 * true.  The walk is the one every routine in this neighbourhood uses: 0xF000
 * opens a tag and PRINTSYS_SkipTag steps over it, anything else is one halfword,
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
u32 PRINTSYS_CountControlTag(struct Strbuf *text)
{
    u16 *cursor;
    u16 count = 0;

    cursor = STRBUF_GetChars(text);

    while (cursor[0] != 0xFFFF) {
        if (cursor[0] == 0xF000) {
            if (PRINTSYS_IsWordSlotTag(cursor) != 0) {
                count = (u16)(count + 1);
            }
            cursor = PRINTSYS_SkipTag(cursor);
        } else {
            cursor = cursor + 1;
        }
    }
    return count;
}

/*
 * Finds the index of the 0xBD06 tag whose first parameter is the caller's
 * value, counting 0xFFFE separators as it goes.  The tag's parameter is read
 * with PRINTSYS_GetTagParam's body written out inline (`p[0] == 0xF000 ? p[3] : 0`),
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
u32 PRINTSYS_SearchIndex(struct Strbuf *text, u8 markerId)
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
            cursor = PRINTSYS_SkipTag(cursor);
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
u32 PRINTSYS_MeasureText(struct Strbuf *text, u8 markerId, struct GfFont *font, u32 spacing)
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
 *           PRINTSYS_GetTagKind, PRINTSYS_GetTagParam, PRINTSYS_SkipTag
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  PRINTSYS_SkipTag steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * PRINTSYS_GetTagGroup, PRINTSYS_GetTagKind and PRINTSYS_GetTagParam were read out of the `.word`
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
 *   - PRINTSYS_GetTagParam indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * PRINTSYS_AppendTag's parameter count is `u16`, not `u32`: it is passed straight to
 * STRBUF_AppendChar with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 */
u32 PRINTSYS_GetTagChar(void)
{
    return 0xF000;
}

u32 PRINTSYS_IsWordSlotTag(const u16 *tag)
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

u32 PRINTSYS_GetTagGroup(const u16 *tag)
{
    if (tag[0] == 0xF000) {
        return (u8)(tag[1] >> 8);
    }
    return 0xFF;
}

void PRINTSYS_AppendTag(struct Strbuf *text, u32 group, u32 kind, u16 paramCount, const u16 *params)
{
    u32 index;

    STRBUF_AppendChar(text, 0xF000);
    STRBUF_AppendChar(text, (u16)((u16)(group << 8) | kind));
    STRBUF_AppendChar(text, paramCount);
    for (index = 0; index < paramCount; index = (u8)(index + 1)) {
        STRBUF_AppendChar(text, params[index]);
    }
}

u32 PRINTSYS_GetTagKind(const u16 *tag)
{
    if (tag[0] == 0xF000) {
        return (u8)tag[1];
    }
    return 0xFF;
}

u32 PRINTSYS_GetTagParam(const u16 *tag, u32 paramIndex)
{
    if (tag[0] == 0xF000) {
        return *(tag + paramIndex + 3);
    }
    return 0;
}

u16 *PRINTSYS_SkipTag(u16 *tag)
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
 * PRINTSYS_GetAlignedSize sizes a string's storage: two bytes per character plus the
 * terminator, rounded up to a multiple of four.  The rounding is a `while`
 * loop over `n & 3`, not an `& ~3` or a `+ 3 & ~3`: this front end has no
 * immediate `bic`, so either of those would materialise the mask and the
 * function would be four bytes shorter with no loop at all.  The loop really
 * is in the original.
 *
 * PRINTSYS_GetQueueFreeSpace is the used-byte count of a wrap-around byte ring.  The
 * fall-through arm of `cmp r1, r2` / `bhs` is the non-wrapped case, so the
 * source wrote `if (head < tail)` first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md); written as the
 * wrapped case first it is ten of the twenty bytes wrong.
 *
 * Left open at 0x0201D6D8: PRINTSYS_EnqueuePrint and PRINTSYS_Copy reproduce the
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
u32 PRINTSYS_GetAlignedSize(struct Strbuf *text)
{
    u32 bytes = (STRBUF_GetLength(text) + 1) * 2;

    while ((bytes & 3) != 0) {
        bytes++;
    }
    return bytes;
}

u32 PRINTSYS_GetAllocSize(struct Strbuf *text)
{
    return PRINTSYS_GetAlignedSize(text) + 0x20;
}

u32 PRINTSYS_GetQueueFreeSpace(const struct PrintQueue *queue)
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
 * unresolved sites at +0x24, +0x32 and +0x44 call PRINTSYS_Copy, which is the
 * function *immediately after this one* and whose only callers in the whole
 * image are these three.  The compared range ends where 0x0201D768 begins, so
 * shrinking the range is not possible (the callee cannot go in), and the
 * `matched` class needs an EXACT entry covering 0x0201D768 that does not
 * exist yet.  It graduates the day 0x0201D768 is matched -- nothing in this C
 * changes.
 *
 * What it is: the cache-side of a record reader.  It asks
 * PRINTSYS_Copy(p, STRBUF_GetChars(c), (u16)PRINTSYS_GetAlignedSize(c), 2) for a slot
 * keyed by the record at `c`, stores a second slot for `b` (0x1c/0x1c) in a
 * stack local, zero-initialises a 4-byte stack local through a third call,
 * and then walks the list hanging off queue->job through PRINTSYS_GetNextRecord until it
 * runs out, rebasing the node pointer on p+0x18 and clamping the resulting
 * offset against p->f4 (u16) before a 4-byte MI_CpuCopy8 into the local.  When
 * queue->job is null it installs the two slots instead.
 *
 * Two details that cost a compile each: STRBUF_GetChars is ARM, not Thumb (the
 * the offset is truncated to u16 twice -- once right after the subtraction and
 * once after the +0x1c -- which is the `(u16)(...) + 0x1c` spelling in a u16
 * local, not a single cast.
 *
 * Verified with
 *   python tools/match.py one --src src/pending/PRINTSYS_EnqueuePrint.c \
 *       --func PRINTSYS_EnqueuePrint --addr 0x0201D6D8 --cc 1.1p1 --thumb
 */
void PRINTSYS_EnqueuePrint(struct PrintQueue *queue, struct PrintCtx *job, struct Strbuf *text)
{
    void *newRecord;
    struct PrintCtx *node;
    struct PrintCtx *next;
    void *textCopy;
    u32 zero;

    textCopy = PRINTSYS_Copy(queue, (const u8 *)STRBUF_GetChars(text),
                           (u16)PRINTSYS_GetAlignedSize(text), 2);
    newRecord = PRINTSYS_Copy(queue, (const u8 *)job, 0x1c, 0x1c);
    zero = 0;
    PRINTSYS_Copy(queue, (const u8 *)(&zero), 4, 4);
    node = queue->job;
    if (node != 0) {
        for (;;) {
            next = PRINTSYS_GetNextRecord(queue, node);
            if (next == 0) break;
            node = next;
        }
        {
            u16 offset = (u16)((uptr)node - (uptr)queue->data) + 0x1c;

            if (offset >= queue->capacity) offset = 0;
            MI_CpuCopy8(&newRecord, queue->data + offset, 4);
        }
        return;
    }
    queue->job = newRecord;
    queue->cursor = textCopy;
}

/*
 * printsys.c: append `len` bytes to the byte ring at +0x18 in `unit`-sized
 * copies, wrapping the head back to 0 at ring->size, and return the address
 * the first copy landed at.  The three callers are PRINTSYS_EnqueuePrint's.
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
 *   python tools/match.py one --src src/matched/PRINTSYS_Copy.c \
 *       --func PRINTSYS_Copy --addr 0x0201D768 --cc 1.1p1 --thumb
 */
void *PRINTSYS_Copy(struct PrintQueue *queue, const u8 *src, u16 length, u16 unit)
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
 * PRINTSYS_EnqueuePrint and PRINTSYS_Copy, the two functions in front of this one, are
 * still open; see the note in src/matched/unit_0201D69C.c, which this work
 * narrows.  PRINTSYS_EnqueuePrint is EXACT when it is compiled in a range with
 * PRINTSYS_Copy, and PRINTSYS_Copy is four bytes short: the original spills the
 * byte counter and keeps the ring cursor in r4, and every source shape tried
 * makes the opposite choice.  Since PRINTSYS_Copy's only callers are the three
 * inside PRINTSYS_EnqueuePrint the two cannot be cut apart, so neither lands.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D7C4.c \
 *       --addr 0x0201D7C4 --thumb
 */
struct PrintCtx *PRINTSYS_GetNextRecord(struct PrintQueue *queue, struct PrintCtx *job)
{
    u32 offset = (u16)((u8 *)job - &queue->data[0]);

    offset = (u16)((u16)offset + 0x1C);
    if (offset >= queue->capacity) {
        offset = 0;
    }
    return *(struct PrintCtx **)&queue->data[(u16)offset];
}
