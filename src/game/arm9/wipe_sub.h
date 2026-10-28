#ifndef GAME_ARM9_WIPE_SUB_H
#define GAME_ARM9_WIPE_SUB_H
struct TcbTask;
struct WipeHBlankSlots;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wipe_sub.c, prototypes copied from their definitions. */

struct WipeSys;
struct WipePanel;
struct FixedRect;
struct FadeState;
struct LineBuffers;
struct LineBuffer;
struct WindowRequests;
struct LineMask;
struct WipeBoxParam;
struct WipeBoxWork;
struct CircleParam;
struct CircleWork;
struct ShutterDesc;
struct ShutterWork;
struct ShutterBand;
struct WindowVisibleRequest;
struct WindowInsideRequest;
struct WindowOutsideRequest;
struct WindowRectRequest;

#include "../types.h"

u16 WIPE_SUB_ResolveColor(struct WipeSys *sys, u16 color);
u16 WIPE_SUB_GetEndColor(struct WipeSys *sys);
void WIPE_SUB_ResetBrightnessTask(void *task, struct WipePanel *panel);
void WIPE_SUB_RequestBrightnessReset(struct WipePanel *panel);
void WIPE_SUB_ApplyEndBrightness(struct WipePanel *panel);
void WIPE_SUB_ClearSys(struct WipeSys *sys);
u32 WIPE_SUB_PatternFadeOut(struct WipePanel *panel);
u32 WIPE_SUB_PatternFadeIn(struct WipePanel *panel);
void WIPE_SUB_PatternShutterDownOut(struct WipePanel *panel);
void WIPE_SUB_PatternShutterDownIn(struct WipePanel *panel);
void WIPE_SUB_PatternShutterUpOut(struct WipePanel *panel);
void WIPE_SUB_PatternShutterUpIn(struct WipePanel *panel);
void WIPE_SUB_PatternBoxOpenOut(struct WipePanel *panel);
void WIPE_SUB_PatternBoxOpenIn(struct WipePanel *panel);
void WIPE_SUB_PatternCircleOut(struct WipePanel *panel);
void WIPE_SUB_PatternCircleIn(struct WipePanel *panel);
void WIPE_SUB_PatternBoxSlideOut(struct WipePanel *panel);
void WIPE_SUB_PatternBoxSlideIn(struct WipePanel *panel);
s32 WIPE_SUB_CalcStep(s32 start, s32 end, s32 frames);
void WIPE_SUB_AddRect(struct FixedRect *dst, struct FixedRect *src);
void WIPE_SUB_InitRectInterp(struct FixedRect *current, struct FixedRect *target, struct FixedRect *step, const u8 *from, const u8 *to, s32 frames);
void WIPE_SUB_FadeStart(struct WipePanel *panel, u32 closing);
u32 WIPE_SUB_FadeMain(struct WipePanel *panel);
int WIPE_SUB_FadeStep(struct FadeState *fade);
void WIPE_SUB_FadeVTask(void *task, struct FadeState *fade);
void WIPE_SUB_WindowRectHBlank(void *linesArg);
void WIPE_SUB_CreateLineBuffers(struct LineBuffers *lines, u32 windowSelect, u32 screen, u32 heapId);
void WIPE_SUB_DeleteLineBuffers(struct LineBuffers *lines);
void WIPE_SUB_FreeLineBuffers(struct LineBuffers *lines);
struct LineBuffer *WIPE_SUB_GetLineBuffer(struct LineBuffers *lines, u32 index);
void WIPE_SUB_FlipLineBuffersTask(struct TcbTask * taskArg, void * linesArg);
void WIPE_SUB_RequestWindowEnd(u32 closing, struct WindowRequests *requests, u32 screen);
void WIPE_SUB_SetupWindow(struct WindowRequests *requests, u32 insidePlanes, u32 outsidePlanes, u32 window, u32 screen, u32 left, u32 top, u32 right, u32 bottom, u32 queued);
void WIPE_SUB_SetWindowVisibleMode(struct WindowRequests *requests, u32 value, u32 screen, u32 queued);
void WIPE_SUB_InitLineMask(struct LineMask *mask, u32 screen, u32 halfCount, u32 window0, u32 window1);
void *WIPE_SUB_RequestLineMaskFlip(struct LineMask *mask);
void WIPE_SUB_RequestLineMaskHBlank(struct WipeHBlankSlots *hblank, struct LineMask *mask, u32 heapId);
void WIPE_SUB_RequestLineMaskHBlankEnd(struct WipeHBlankSlots *hblank, struct LineMask *mask, u32 heapId);
void WIPE_SUB_FlipLineMaskTask(struct TcbTask * taskArg, void * maskArg);
void WIPE_SUB_LineMaskHBlank(void *maskArg);
void WIPE_SUB_BoxStart(struct WipePanel *panel, const struct WipeBoxParam *param);
u32 WIPE_SUB_BoxMain(struct WipePanel *panel);
void WIPE_SUB_BoxInit(struct WipeBoxWork *box, const struct WipeBoxParam *param, u32 frames, u32 wait, u32 screen, struct WindowRequests *windowRequests);
u32 WIPE_SUB_BoxStep(struct WipeBoxWork *box);
void WIPE_SUB_CircleStart(struct WipePanel *panel, const struct CircleParam *param);
u32 WIPE_SUB_CircleMain(struct WipePanel *panel);
void WIPE_SUB_CircleInit(struct CircleWork *circle, const struct CircleParam *param, u32 frames, u32 wait, u32 screen, struct WindowRequests *windowRequests, struct WipeHBlankSlots *hblank, u32 heapId);
u32 WIPE_SUB_CircleStep(struct CircleWork *circle);
void WIPE_SUB_CalcCircleSpan(s32 radius, s32 centerX, s32 centerY, s32 y, s32 *left, s32 *right);
void WIPE_SUB_CalcCircleLines(struct CircleWork *circle);
void WIPE_SUB_ShutterStart(struct WipePanel *panel, struct ShutterDesc *desc);
u32 WIPE_SUB_ShutterMain(struct WipePanel *panel);
void WIPE_SUB_ShutterInit(struct ShutterWork *shutter, struct ShutterDesc *desc, u32 frames, u32 wait, u32 screen, struct WindowRequests *windowRequests, struct WipeHBlankSlots *hblank, u32 heapId);
u32 WIPE_SUB_ShutterStep(struct ShutterWork *shutter);
void WIPE_SUB_ShutterExit(struct ShutterWork *shutter);
void WIPE_SUB_CalcShutterRows(struct ShutterWork *shutter);
void WIPE_SUB_CalcShutterBand(const struct ShutterBand *band, struct LineMask *mask, s32 num, s32 den);
void WIPE_SUB_SetWindowVisible(u32 value, u32 screen);
void WIPE_SUB_SetWindowInside(u32 planes, u32 effect, u32 window, u32 screen);
void WIPE_SUB_SetWindowOutside(u32 planes, u32 effect, u32 screen);
void WIPE_SUB_SetWindowRect(u32 left, u32 top, u32 right, u32 bottom, int window, int screen);
void WIPE_SUB_RequestWindowVisible(struct WindowRequests *requests, u32 value, u32 screen);
void WIPE_SUB_RequestWindowInside(struct WindowRequests *requests, u32 planes, u32 effect, u32 window, u32 screen);
void WIPE_SUB_RequestWindowOutside(struct WindowRequests *requests, u32 planes, u32 effect, u32 screen);
void WIPE_SUB_RequestWindowRect(struct WindowRequests *requests, u32 left, u32 top, u32 right, u32 bottom, u32 window, u32 screen);
void WIPE_SUB_WindowVisibleTask(struct TcbTask * taskArg, void * requestArg);
void WIPE_SUB_WindowInsideTask(struct TcbTask * taskArg, void * requestArg);
void WIPE_SUB_WindowOutsideTask(struct TcbTask * taskArg, void * requestArg);
void WIPE_SUB_WindowRectTask(struct TcbTask * taskArg, void * requestArg);
/* END mkheaders: generated region */

#endif
