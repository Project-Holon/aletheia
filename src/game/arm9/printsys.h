#ifndef GAME_ARM9_PRINTSYS_H
#define GAME_ARM9_PRINTSYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of printsys.c, prototypes copied from their definitions. */

struct PrintQueue;
struct Bmp;
struct GfFont;
struct Strbuf;
struct PrintCtx;
struct TextPrinter;
struct BmpWin;
struct Tcbl;
struct TcblTask;

#include "../types.h"
#include "../arm9/printsys_shared_types.h"

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
void PRINTSYS_Task(struct TcblTask *task, void *work);
void PRINTSYS_Apply(struct TextPrinter *printer);
u32 PRINTSYS_MeasureTextWidth(u16 *cursor, struct GfFont *font, u32 spacing, u16 **next);
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
u32 PRINTSYS_GetAllocSize(struct Strbuf *text);
u32 PRINTSYS_GetQueueFreeSpace(const struct PrintQueue *queue);
void PRINTSYS_EnqueuePrint(struct PrintQueue *queue, struct PrintCtx *job, struct Strbuf *text);
void *PRINTSYS_Copy(struct PrintQueue *queue, const u8 *src, u16 length, u16 unit);
struct PrintCtx *PRINTSYS_GetNextRecord(struct PrintQueue *queue, struct PrintCtx *job);
/* END mkheaders: generated region */

#endif
