/*
 * file:     ctvt_camera.c
 * unit:     yes
 * function: CTVT_CAMVIEW_Create, CTVT_CAMVIEW_Delete, CTVT_CAMVIEW_Update, CTVT_CAMVIEW_UploadWindows, CTVT_CAMVIEW_StopCapture, CTVT_CAMVIEW_IsShutterIdle, CTVT_CAMVIEW_OnCameraFrame, CTVT_CAMVIEW_MarkWindowDirty, CTVT_CAMVIEW_ClearWindowDirty, CTVT_CAMVIEW_StartLayoutChange, CTVT_CAMVIEW_IsLayoutChanging, CTVT_CAMVIEW_GetWindowHeight, CTVT_CAMVIEW_GetWindowWidth, CTVT_CAMVIEW_GetOwnSlotBuffer, CTVT_CAMVIEW_GetSlotBuffer, CTVT_CAMVIEW_GetSlotBufferStep, CTVT_CAMVIEW_SetWindowCurRect, CTVT_CAMVIEW_SetWindowTargetRect, CTVT_CAMVIEW_StepWindow, CTVT_CAMVIEW_StepValue, CTVT_CAMVIEW_SetWindowLayout, CTVT_CAMVIEW_RequestWindowAnimation, CTVT_CAMVIEW_IsWindowMoving, CTVT_CAMVIEW_SetCameraEffect, CTVT_CAMVIEW_RequestShutterSound0, CTVT_CAMVIEW_RequestShutterSound1
 * address:  0x021B6EE0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from draw_system.c, ctvt_comm.c, ctvt_draw.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   ARC_UTIL_LoadHandleMember 0x0204A380 arm
 *   COMM_TVT_SYS_GetArc 0x021BE010 thumb ov172
 *   COMM_TVT_SYS_IsNetIdle 0x021BE100 thumb ov172
 *   CTVT_CAMERA_Create 0x021B6100 thumb ov172
 *   CTVT_CAMERA_SetSize 0x021B6950 thumb ov172
 *   CTVT_CAMERA_SelectCamera 0x021B69BC thumb ov172
 *   CTVT_CAMERA_AllocFrames 0x021B674C thumb ov172
 *   CTVT_CAMERA_SetFrameCallback 0x021B6744 thumb ov172
 *   CTVT_CAMERA_StartCapture 0x021B6814 thumb ov172
 *   CTVT_CAMVIEW_SetWindowCurRect 0x021B7888 thumb ov172
 *   CTVT_CAMVIEW_SetWindowTargetRect 0x021B78A0 thumb ov172
 *   d_021C71E0 0x021C71E0 data a4
 *   FX_Inv 0x0207C778 arm
 *   G2x_SetBGyAffine_ 0x0207D59C arm
 *   CTVT_CAMERA_Delete 0x021B63B8 thumb ov172
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   CTVT_CAMVIEW_StepWindow 0x021B78B8 thumb ov172
 *   CTVT_CAMERA_UpdateShutterSound 0x021B64AC thumb ov172
 *   COMM_TVT_SYS_GetLayoutMode 0x021BE05C thumb ov172
 *   COMM_TVT_SYS_GetHalfRes 0x021BE078 thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   COMM_TVT_SYS_ClearAndTransferNameWindows 0x021BE1E4 thumb ov172
 *   CTVT_COMM_GetSlotConnected 0x021B8B8C thumb ov172
 *   CTVT_COMM_GetSlotReady 0x021B8BAC thumb ov172
 *   DC_FlushRange 0x020862F0 arm
 *   GX_LoadBG3Scr 0x0207ECF0 arm
 *   G2_GetBG3ScrPtr 0x0207E100 arm
 *   MIi_CpuClear32 0x02082A7C arm
 *   APP_ENV_HasParentalControlBits 0x0202EB14 thumb
 *   CTVT_CAMERA_StopCapture  0x021B6868  thumb  ov172
 *   CTVT_CAMERA_IsShutterSoundIdle  0x021B688C  thumb  ov172
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   COMM_TVT_SYS_GetSelfSlot 0x021BE0A4 thumb ov172
 *   COMM_TVT_SYS_GetMessageActive 0x021BE0AC thumb ov172
 *   COMM_TVT_SYS_GetViewSwapped 0x021BE0B4 thumb ov172
 *   MIi_CpuCopy32 0x02082A90 arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   COMM_TVT_SYS_GetCameraBusy 0x021BE0F8 thumb ov172
 *   COMM_TVT_SYS_SetCameraBusy 0x021BE0FC thumb ov172
 *   d_021C71F0 0x021C71F0 data a4
 *   CTVT_COMM_IsSlotActive 0x021B8BA4 thumb ov172
 *   CTVT_CAMVIEW_SetWindowLayout 0x021B796C thumb ov172
 *   gCtvtWindowHeightTable     0x021C6E9C  data   ov172
 *   gCtvtWindowWidthTable     0x021C6EA8  data   ov172
 *   gCtvtSlotStepTable    0x021C6EB4  data  ov172
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   CTVT_CAMERA_RequestShutterSound0  0x021B69D0  thumb  ov172
 *   CTVT_CAMERA_RequestShutterSound1  0x021B69D8  thumb  ov172
 *   CTVT_CAMVIEW_StartLayoutChange 0x021B7740 thumb ov172
 *   CTVT_CAMVIEW_GetWindowHeight 0x021B77B8 thumb ov172
 *   CTVT_CAMVIEW_ClearWindowDirty 0x021B7724 thumb ov172
 *   CTVT_CAMVIEW_MarkWindowDirty 0x021B7714 thumb ov172
 *   CTVT_CAMVIEW_IsShutterIdle 0x021B7590 thumb ov172
 *   CTVT_CAMVIEW_StopCapture 0x021B7578 thumb ov172
 *   CTVT_CAMVIEW_IsLayoutChanging 0x021B77B4 thumb ov172
 *   CAMERA_I2CEffectExCore  0x02701248  arm  twl
 *   CTVT_CAMVIEW_RequestShutterSound1  0x021B7B80  thumb  ov172
 *   CTVT_CAMVIEW_SetCameraEffect  0x021B7B3C  thumb  ov172
 *   CTVT_CAMVIEW_RequestShutterSound0  0x021B7B64  thumb  ov172
 *   CTVT_CAMVIEW_Create 0x021B6EE0 thumb ov172
 *   CTVT_CAMVIEW_Delete 0x021B70A8 thumb ov172
 *   CTVT_CAMVIEW_Update  0x021B712C  thumb  ov172
 *   CTVT_CAMVIEW_UploadWindows  0x021B71B8  thumb  ov172
 *   CTVT_CAMVIEW_IsWindowMoving 0x021B7B30 thumb ov172
 */
#include "ctvt_camera_types.h"

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/arc_util.h"
struct CtvtWork;
struct ArcHandle;
#include "comm_tvt_sys.h"
#include "camera_system.h"
union MtxFx22;
#include "../arm9/fx_cp.h"
#include "../arm9/g2.h"
struct CtvtComm;
#include "ctvt_comm.h"
#include "../arm9/os_cache.h"
#include "../arm9/gx_load2d.h"
#include "../arm9/gx_bgcnt.h"
#include "../arm9/mi_memory.h"
#include "../arm9/app_env.h"
struct CtvtCamView;
#include "../arm9/gf_panic.h"
#include "../arm9/gfl_use.h"
/* The DS code passes a stale register value to OS_IsRunOnTwl; the host build calls it without an argument. */
#ifdef __MWERKS__
extern int OS_IsRunOnTwl(int);
#define CTVT_IS_RUN_ON_TWL(v) OS_IsRunOnTwl(v)
#else
#include "../arm9/os_emulator.h"
#define CTVT_IS_RUN_ON_TWL(v) OS_IsRunOnTwl()
#endif
#include "../twl/camera_api.h"
extern const char d_021C71E0[];
extern const char d_021C71F0[];
extern u32 gCtvtWindowHeightTable[];
extern u32 gCtvtWindowWidthTable[];
extern u32 gCtvtSlotStepTable[];

char *CTVT_CAMVIEW_Create(void *work, u16 heapId);
void CTVT_CAMVIEW_Delete(u8 *unused, CtvtCamView *view);
void CTVT_CAMVIEW_Update(char *unused, CtvtCamView *view);
void CTVT_CAMVIEW_UploadWindows(void *work, CtvtCamView *view);
void CTVT_CAMVIEW_StopCapture(struct CtvtWork *unused, CtvtCamView *view);
int CTVT_CAMVIEW_IsShutterIdle(struct CtvtWork *unused, CtvtCamView *view);
void CTVT_CAMVIEW_OnCameraFrame(char *frame, void *work);
void CTVT_CAMVIEW_MarkWindowDirty(void *work, CtvtCamView *view, int slot);
void CTVT_CAMVIEW_ClearWindowDirty(void *work, CtvtCamView *view, int slot);
void CTVT_CAMVIEW_StartLayoutChange(void *work, CtvtCamView *view, int revealArg, int clearArg);
u32 CTVT_CAMVIEW_IsLayoutChanging(struct CtvtWork *unused, CtvtCamView *view);
u32 CTVT_CAMVIEW_GetWindowHeight(void *work, struct CtvtCamView *unused);
u32 CTVT_CAMVIEW_GetWindowWidth(void *work, struct CtvtCamView *unused);
u32 CTVT_CAMVIEW_GetOwnSlotBuffer(void *work, CtvtCamView *view);
int CTVT_CAMVIEW_GetSlotBuffer(void *work, CtvtCamView *view, int slot);
u32 CTVT_CAMVIEW_GetSlotBufferStep(void *work, struct CtvtCamView *unused);
void CTVT_CAMVIEW_SetWindowCurRect(CtvtCamViewWindow *win, u16 x, u16 y, u16 w, u16 h);
void CTVT_CAMVIEW_SetWindowTargetRect(CtvtCamViewWindow *win, u16 x, u16 y, u16 w, u16 h);
int CTVT_CAMVIEW_StepWindow(CtvtCamView *view, CtvtCamViewWindow *win);
int CTVT_CAMVIEW_StepValue(CtvtCamView *view, u16 *value, u16 *limit);
void CTVT_CAMVIEW_SetWindowLayout(void *work, CtvtCamView *view, int slot);
void CTVT_CAMVIEW_RequestWindowAnimation(int unused, CtvtCamView *view, int slot);
u32 CTVT_CAMVIEW_IsWindowMoving(u8 *unused, CtvtCamView *view, int slot);
void CTVT_CAMVIEW_SetCameraEffect(struct CtvtWork *unused, struct CtvtCamView *unused2, int effect);
void CTVT_CAMVIEW_RequestShutterSound0(int unused, CtvtCamView *view);
void CTVT_CAMVIEW_RequestShutterSound1(struct CtvtWork *unused, CtvtCamView *view);

/* Allocates the view; with the DSi camera present it also opens the camera,
 * three work buffers and the placeholder pictures in a private heap. */
char *CTVT_CAMVIEW_Create(void *work, u16 heapId)
{
    CtvtCamView *view;
    u32 arcHandle;
    void *halfPicture;
    u8 i;

    view = GFL_HEAP_Alloc(heapId, 0xB4, 1, d_021C71E0, 0x67);
    arcHandle = (unsigned int)COMM_TVT_SYS_GetArc(work);
    if (COMM_TVT_SYS_IsNetIdle() == 1) {
        view->heapId = 0x6E;
        GFL_HEAP_CreateChildHeap(1, 0x6E, 0x80000);
        view->camera = CTVT_CAMERA_Create(view->heapId);
        CTVT_CAMERA_SetSize((Camera *)view->camera, 5);
        CTVT_CAMERA_SelectCamera((Camera *)view->camera, 1);
        CTVT_CAMERA_AllocFrames((Camera *)view->camera, 2, (u16)((view->heapId & 0x7FFF) | 0x8000));
        CTVT_CAMERA_SetFrameCallback((Camera *)view->camera, (void (*)(u32, u32))((u32)((void *)CTVT_CAMVIEW_OnCameraFrame)), (u32)work);
        CTVT_CAMERA_StartCapture(view->camera);
        view->spareBufA = GFL_HEAP_Alloc((u16)((view->heapId & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x76);
        view->spareBufB = GFL_HEAP_Alloc((u16)((view->heapId & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x77);
        view->cropBuf = GFL_HEAP_Alloc((u16)((view->heapId & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x78);
        view->noSignalFull = ARC_UTIL_LoadHandleMember((void *)arcHandle, 0x19, 0, view->heapId);
        halfPicture = ARC_UTIL_LoadHandleMember((void *)arcHandle, 0x1A, 0, view->heapId);
    } else {
        view->noSignalFull = ARC_UTIL_LoadHandleMember((void *)arcHandle, 0x19, 0, heapId);
        halfPicture = ARC_UTIL_LoadHandleMember((void *)arcHandle, 0x1A, 0, heapId);
    }
    view->noSignalHalf = halfPicture;
    i = 0;
    view->dirtyMask = i;
    view->settleCount = i;
    view->layoutDirty = i;
    view->revealY = 0xC0;
    view->revealPending = i;
    view->clearPending = i;
    view->halfRes = i;
    view->revealing = i;
    view->shutterReq0 = i;
    view->shutterReq1 = i;
    view->screenBuf = GFL_HEAP_Alloc((u16)((heapId & 0x7FFF) | 0x8000), 0x18000, 1, d_021C71E0, 0x8C);
    for (i = 0; i < 4; i++) {
        CTVT_CAMVIEW_SetWindowCurRect(&view->window[i], 0, 0, 0, 0);
        CTVT_CAMVIEW_SetWindowTargetRect(&view->window[i], 0, 0, 0, 0);
        view->window[i].moving = 0;
        view->window[i].animate = 1;
        view->window[i].seOnArrive = 1;
    }
    return (char *)view;
}

/* Frees the buffers and, when the camera exists, the camera and its heap; also
 * resets the BG2 affine matrix. */
void CTVT_CAMVIEW_Delete(u8 *unused, CtvtCamView *view)
{
    int matrix[4];
    matrix[0] = FX_Inv(4096);
    matrix[3] = FX_Inv(4096);
    matrix[1] = 0;
    matrix[2] = 0;
    G2x_SetBGyAffine_(0x04000030, (union MtxFx22 *)matrix, 0, 0, 0, 0);
    GFL_HEAP_Free(view->screenBuf);
    GFL_HEAP_Free(view->noSignalHalf);
    GFL_HEAP_Free(view->noSignalFull);
    if (COMM_TVT_SYS_IsNetIdle() == 1) {
        GFL_HEAP_Free(view->cropBuf);
        GFL_HEAP_Free(view->spareBufA);
        GFL_HEAP_Free(view->spareBufB);
        CTVT_CAMERA_Delete(view->camera);
        GFL_HEAP_DeleteChecked(110);
    }
    GFL_HEAP_Free(view);
}

static inline void setWindow0(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000040 = ((x1 << 8) & 0xff00) | (x2 & 255);
    *(volatile u16 *)0x04000044 = ((y1 << 8) & 0xff00) | (y2 & 255);
}

static inline void setWindow1(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000042 = ((x1 << 8) & 0xff00) | (x2 & 255);
    *(volatile u16 *)0x04000046 = ((y1 << 8) & 0xff00) | (y2 & 255);
}

/* Per frame: steps the window slides, runs the shutter sound state and opens
 * the window mask (WIN0/WIN1) 8 lines per frame while revealing. */
void CTVT_CAMVIEW_Update(char *unused, CtvtCamView *view)
{
    u8 i;
    if (view->layoutDirty == 0) {
        for (i = 0; i < 4; i++) {
            if (CTVT_CAMVIEW_StepWindow(view, &view->window[i]) == 1) {
                view->dirtyMask |= (u8)(1 << i);
                break;
            }
        }
    }
    if (COMM_TVT_SYS_IsNetIdle() == 1) CTVT_CAMERA_UpdateShutterSound(view->camera);
    if (view->revealY < 0xc0 && view->revealing == 0) {
        view->revealY += 8;
        setWindow0(0, 0, 255, view->revealY);
        setWindow1(128, 0, 0, view->revealY);
    }
}

/* Copies the composed plane to VRAM when it changed and, after a layout change,
 * recomputes the window rectangles for the current resolution. Then copies
 * each dirty window's picture (live frame or placeholder) into the plane. */
void CTVT_CAMVIEW_UploadWindows(void *work, CtvtCamView *view)
{
    int screenSplit;
    u32 halfRes;
    u32 members;
    u32 dst;
    int h;
    int bit;
    u8 i;
    int m[4];

    screenSplit = COMM_TVT_SYS_GetLayoutMode(work);
    halfRes = COMM_TVT_SYS_GetHalfRes(work);
    members = (unsigned int)COMM_TVT_SYS_GetComm(work);
    if (COMM_TVT_SYS_GetMemberCount(work) < 2)
        return;
    if (screenSplit == 0) {
        if (view->dirtyMask != 0) {
            DC_FlushRange((u16 *)view->screenBuf, 0x18000);
            GX_LoadBG3Scr(view->screenBuf, 0, 0x18000);
            view->dirtyMask = 0;
        }
    } else {
        if (view->layoutDirty == 1) {
            u8 n = 0;
            for (i = 0; i < 4; i++) {
                if ((1 << i) & view->dirtyMask)
                    n++;
            }
            if (n != COMM_TVT_SYS_GetMemberCount(work))
                return;
            if (view->settleCount < 2) {
                view->dirtyMask = 0;
                view->settleCount++;
                for (i = 0; i < 4; i++) {
                    if (CTVT_COMM_GetSlotConnected(work, (char *)members, i) == 1 && CTVT_COMM_GetSlotReady(work, (char *)members, i) == 0)
                        view->dirtyMask |= (u8)(1 << i);
                }
                return;
            }
            if (view->revealY < 0xC0)
                return;
            if (view->revealPending == 1) {
                view->revealY = 0;
                view->revealing = 1;
                view->revealPending = 0;
                *(volatile u16 *)0x04000040 = 0xFF;
                *(volatile u16 *)0x04000044 = 0;
                *(volatile u16 *)0x04000042 = 0x8000;
                *(volatile u16 *)0x04000046 = 0;
            }
            if (view->clearPending == 1) {
                view->clearPending = 0;
                COMM_TVT_SYS_ClearAndTransferNameWindows(work);
            }
            MIi_CpuClear32(0, G2_GetBG3ScrPtr(), 0x18000);
            view->layoutDirty = 0;
            if (view->halfRes != COMM_TVT_SYS_GetHalfRes(work)) {
                view->halfRes = COMM_TVT_SYS_GetHalfRes(work);
                if (view->halfRes == 1) {
                    m[0] = FX_Inv(0x2000);
                    m[3] = FX_Inv(0x2000);
                } else {
                    m[0] = FX_Inv(0x1000);
                    m[3] = FX_Inv(0x1000);
                }
                m[1] = 0;
                m[2] = 0;
                G2x_SetBGyAffine_(0x04000030, (union MtxFx22 *)m, 0, 0, 0, 0);
                for (i = 0; i < 4; i++) {
                    if (view->halfRes == 1) {
                        *(u16 *)((u8 *)view + 0x48 + i * 0x1C) = (u32)*(u16 *)((u8 *)view + 0x48 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)view + 0x4A + i * 0x1C) = (u32)*(u16 *)((u8 *)view + 0x4A + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)view + 0x4C + i * 0x1C) = (u32)*(u16 *)((u8 *)view + 0x4C + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)view + 0x4E + i * 0x1C) = (u32)*(u16 *)((u8 *)view + 0x4E + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)view + 0x40 + i * 0x1C) = (u32)*(u16 *)((u8 *)view + 0x40 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)view + 0x42 + i * 0x1C) = (u32)*(u16 *)((u8 *)view + 0x42 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)view + 0x44 + i * 0x1C) = (u32)*(u16 *)((u8 *)view + 0x44 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)view + 0x46 + i * 0x1C) = (u32)*(u16 *)((u8 *)view + 0x46 + i * 0x1C) >> 1;
                    } else {
                        view->window[i].tgtX <<= 1;
                        view->window[i].tgtY <<= 1;
                        view->window[i].tgtW <<= 1;
                        view->window[i].tgtH <<= 1;
                        view->window[i].curX <<= 1;
                        view->window[i].curY <<= 1;
                        view->window[i].curW <<= 1;
                        view->window[i].curH <<= 1;
                    }
                }
            }
            view->revealing = 0;
        }
        for (i = 0; i < 4; i++) {
            bit = 1 << i;
            if (!(bit & view->dirtyMask))
                continue;
            if (CTVT_COMM_GetSlotConnected(work, (char *)members, i) == 1) {
                u32 srcSlot = i;
                int w;
                int j;
                if (screenSplit == 1 && srcSlot != 0)
                    srcSlot = 1;
                if (halfRes == 0) {
                    w = 0x80;
                    h = (u16)(screenSplit == 1 ? 0xC0 : 0x60);
                } else {
                    w = 0x40;
                    h = (u16)(screenSplit == 1 ? 0x60 : 0x30);
                }
                if (CTVT_COMM_GetSlotReady(work, (char *)members, i) == 1 && APP_ENV_HasParentalControlBits() == 0) {
                    dst = (u32)((char *)view->screenBuf + srcSlot * (w * h * 2));
                    DC_FlushRange((void *)dst, w * h * 2);
                } else if (halfRes == 0) {
                    if (screenSplit == 1) {
                        dst = (u32)view->noSignalFull;
                        DC_FlushRange((void *)dst, 0xC000);
                    } else {
                        dst = (u32)((char *)view->noSignalFull + 0x3000);
                        DC_FlushRange((void *)dst, 0x6000);
                    }
                } else {
                    if (screenSplit == 1) {
                        dst = (u32)view->noSignalHalf;
                        DC_FlushRange((void *)dst, 0x3000);
                    } else {
                        dst = (u32)((char *)view->noSignalHalf + 0xC00);
                        DC_FlushRange((void *)dst, 0x1800);
                    }
                }
                for (j = 0; j < view->window[i].curH; j++) {
                    int r = j + (h - view->window[i].curH);
                    GX_LoadBG3Scr((void *)((w - view->window[i].curW) * 2 + (dst + r * w * 2)),
                                  view->window[i].curX * 2 + (j + view->window[i].curY) * 0x200,
                                  view->window[i].curW * 2);
                }
            }
            view->dirtyMask -= (u8)bit;
        }
    }
}

/* Stops the camera capture when a camera exists. */
void CTVT_CAMVIEW_StopCapture(struct CtvtWork *unused, CtvtCamView *view)
{
    if (COMM_TVT_SYS_IsNetIdle() == 1) {
        CTVT_CAMERA_StopCapture(view->camera);
    }
}

/* Returns 1 when no shutter sound plays (or when there is no camera). */
int CTVT_CAMVIEW_IsShutterIdle(struct CtvtWork *unused, CtvtCamView *view)
{
    if (COMM_TVT_SYS_IsNetIdle() == 1) {
        return CTVT_CAMERA_IsShutterSoundIdle(view->camera);
    }
    return 1;
}

/* Camera frame callback: crops the centre 128x192 of the 256 wide frame into
 * cropBuf and, when the window of this player is free, copies it into the plane. */
void CTVT_CAMVIEW_OnCameraFrame(char *frame, void *work)
{
    CtvtCamView *view;
    int screenSplit;
    u32 halfRes;
    int x;
    u32 selfSlot;
    u32 slot;
    u16 y;
    int w;
    u16 h;
    int i;

    view = (CtvtCamView *)COMM_TVT_SYS_GetCamView(work);
    screenSplit = COMM_TVT_SYS_GetLayoutMode(work);
    halfRes = COMM_TVT_SYS_GetHalfRes(work);
    selfSlot = COMM_TVT_SYS_GetSelfSlot(work);
    if (COMM_TVT_SYS_GetMessageActive(work) == 1 || COMM_TVT_SYS_GetMemberCount(work) < 2)
        return;
    if (view->dirtyMask & (1 << selfSlot))
        return;
    if (COMM_TVT_SYS_GetViewSwapped(work) == 0) {
        for (i = 0; i < 0xc0; i++)
            MIi_CpuCopy32(frame + i * 0x200 + 0x80, (char *)view->cropBuf + i * 0x100, 0x100);
    }
    if (screenSplit == 0) {
        GF_PANIC_Fail(d_021C71F0, 0, d_021C71F0);
        return;
    }
    slot = selfSlot;
    if (screenSplit == 1 && selfSlot > 1)
        slot = 1;
    if (halfRes == 0) {
        x = 0;
        y = (screenSplit == 1) ? 0 : 0x30;
        w = 0x80;
        h = (screenSplit == 1) ? 0xc0 : 0x60;
    } else {
        x = 0x20;
        y = (screenSplit == 1) ? 0x30 : 0x50;
        w = 0x40;
        h = (screenSplit == 1) ? 0x60 : 0x30;
    }
    if (COMM_TVT_SYS_GetCameraBusy(work) != 0)
        return;
    COMM_TVT_SYS_SetCameraBusy(work, 1);
    for (i = 0; i < h; i++)
        MIi_CpuCopy32((void *)((u32)view->cropBuf + (y + i) * 0x100 + x * 2),
                      (void *)((u32)view->screenBuf + w * h * 2 * slot + w * i * 2), w * 2);
    COMM_TVT_SYS_SetCameraBusy(work, 0);
    view->dirtyMask |= (u8)(1 << selfSlot);
}

/* Marks the window of a slot as having new pixels. */
void CTVT_CAMVIEW_MarkWindowDirty(void *work, CtvtCamView *view, int slot)
{
    view->dirtyMask |= (u8)(1 << slot);
}

/* Clears the dirty bit of a slot unless a layout change is pending. */
void CTVT_CAMVIEW_ClearWindowDirty(void *work, CtvtCamView *view, int slot)
{
    int bit;
    if (view->layoutDirty == 0) {
        bit = 1 << slot;
        if (view->dirtyMask & bit)
            view->dirtyMask -= (u8)bit;
    }
}

/* Starts a layout change: remembers the reveal and clear requests, snaps or
 * starts sliding every window. */
void CTVT_CAMVIEW_StartLayoutChange(void *work, CtvtCamView *view, int revealArg, int clearArg)
{
    char *members;
    u8 i;

    members = (char *)COMM_TVT_SYS_GetComm(work);
    view->layoutDirty = 1;
    if (view->revealPending == 0) view->revealPending = revealArg;
    if (view->clearPending == 0) view->clearPending = clearArg;
    view->dirtyMask = 0;
    view->settleCount = 0;
    if (COMM_TVT_SYS_IsNetIdle() == 0)
        view->dirtyMask |= (u8)(1 << COMM_TVT_SYS_GetSelfSlot(work));
    for (i = 0; i < 4; i++) {
        if (CTVT_COMM_IsSlotActive(work, members, i) == 1)
            CTVT_CAMVIEW_SetWindowLayout(work, view, i);
    }
}

u32 CTVT_CAMVIEW_IsLayoutChanging(struct CtvtWork *unused, CtvtCamView *view)
{
    return view->layoutDirty;
}

/* Window height from table gCtvtWindowHeightTable; halved for half resolution. */
u32 CTVT_CAMVIEW_GetWindowHeight(void *work, struct CtvtCamView *unused)
{
    u32 i = COMM_TVT_SYS_GetLayoutMode(work);
    if (COMM_TVT_SYS_GetHalfRes(work) == 0)
        return (u16)gCtvtWindowHeightTable[i];
    return (gCtvtWindowHeightTable[i] << 15) >> 16;
}

/* Window width from table gCtvtWindowWidthTable; halved for half resolution. */
u32 CTVT_CAMVIEW_GetWindowWidth(void *work, struct CtvtCamView *unused)
{
    u32 i = COMM_TVT_SYS_GetLayoutMode(work);
    if (COMM_TVT_SYS_GetHalfRes(work) == 0)
        return (u16)gCtvtWindowWidthTable[i];
    return (gCtvtWindowWidthTable[i] << 15) >> 16;
}

u32 CTVT_CAMVIEW_GetOwnSlotBuffer(void *work, CtvtCamView *view)
{
    return CTVT_CAMVIEW_GetSlotBuffer(work, view, COMM_TVT_SYS_GetSelfSlot(work));
}

int CTVT_CAMVIEW_GetSlotBuffer(void *work, CtvtCamView *view, int slot)
{
    int step = CTVT_CAMVIEW_GetSlotBufferStep(work, view);
    if (COMM_TVT_SYS_GetLayoutMode(work) == 1 && slot != 0)
        return (int)view->screenBuf + step;
    return (int)view->screenBuf + step * slot;
}

/* Slot step from table gCtvtSlotStepTable; quartered for half resolution. */
u32 CTVT_CAMVIEW_GetSlotBufferStep(void *work, struct CtvtCamView *unused)
{
    u32 i = COMM_TVT_SYS_GetLayoutMode(work);
    if (COMM_TVT_SYS_GetHalfRes(work) == 0) {
        return gCtvtSlotStepTable[i];
    }
    return gCtvtSlotStepTable[i] >> 2;
}

/* Starts a slide: sets the current rectangle and flags the window as moving. */
void CTVT_CAMVIEW_SetWindowCurRect(CtvtCamViewWindow *win, u16 x, u16 y, u16 w, u16 h)
{
    win->moving = 1;
    win->curX = x;
    win->curY = y;
    win->curW = w;
    win->curH = h;
}

/* Sets the target rectangle and flags the window as moving. */
void CTVT_CAMVIEW_SetWindowTargetRect(CtvtCamViewWindow *win, u16 x, u16 y, u16 w, u16 h)
{
    win->moving = 1;
    win->tgtX = x;
    win->tgtY = y;
    win->tgtW = w;
    win->tgtH = h;
}

/* One slide step of a window; returns 1 while it moved. Plays the arrival
 * sound once when it stops. */
int CTVT_CAMVIEW_StepWindow(CtvtCamView *view, CtvtCamViewWindow *win)
{
    int result, zero;
    if (win->moving == 1) {
        zero = 0;
        result = 0;
        result |= CTVT_CAMVIEW_StepValue(view, &win->curX, &win->tgtX);
        result |= CTVT_CAMVIEW_StepValue(view, &win->curY, &win->tgtY);
        result |= CTVT_CAMVIEW_StepValue(view, &win->curW, &win->tgtW);
        result |= CTVT_CAMVIEW_StepValue(view, &win->curH, &win->tgtH);
        if (result == 0) win->moving = zero;
        if (win->seOnArrive == 1) {
            win->seOnArrive = 0;
            GFL_USE_PlaySeDefaultVolume(0x66e);
        }
        win->animate = 0;
        return 1;
    }
    return 0;
}

/* Steps a value towards a limit by 4 (half resolution) or 8 and clamps at the
 * limit. Returns 1 when the value moved. */
int CTVT_CAMVIEW_StepValue(CtvtCamView *view, u16 *value, u16 *limit)
{
    unsigned char step = (view->halfRes == 1) ? 4 : 8;
    u16 lim = *limit;
    u16 v = *value;
    if (v < lim) {
        if ((int)(v + step) < (int)lim)
            *value = v + step;
        else
            *value = lim;
        return 1;
    }
    if (v > lim) {
        if ((int)(v - step) > (int)lim)
            *value = v - step;
        else
            *value = lim;
        return 1;
    }
    return 0;
}

/* Sets the slide target of a window for a layout change (screenSplit and
 * halfRes pick the rectangles) and, without animation, snaps to it. */
void CTVT_CAMVIEW_SetWindowLayout(void *work, CtvtCamView *view, int slot)
{
    int screenSplit;
    int mode;
    screenSplit = COMM_TVT_SYS_GetLayoutMode(work);
    mode = slot;
    if (screenSplit == 1 && slot != 0)
        mode = 1;
    if (view->halfRes == 0) {
        view->window[slot].tgtX = (mode == 0 || mode == 2) ? 0 : 0x80;
        view->window[slot].tgtY = (mode == 0 || mode == 1) ? 0 : 0x60;
        view->window[slot].tgtW = 0x80;
        view->window[slot].tgtH = (screenSplit == 1) ? 0xc0 : 0x60;
    } else {
        view->window[slot].tgtX = (mode == 0 || mode == 2) ? 0 : 0x40;
        view->window[slot].tgtY = (mode == 0 || mode == 1) ? 0 : 0x30;
        view->window[slot].tgtW = 0x40;
        view->window[slot].tgtH = (screenSplit == 1) ? 0x60 : 0x30;
    }
    if (view->window[slot].animate == 0) {
        view->window[slot].curX = view->window[slot].tgtX;
        view->window[slot].curY = view->window[slot].tgtY;
        view->window[slot].curW = view->window[slot].tgtW;
        view->window[slot].curH = view->window[slot].tgtH;
    } else {
        view->window[slot].seOnArrive = 1;
        switch (mode) {
        case 0:
            if (view->halfRes == 0)
                CTVT_CAMVIEW_SetWindowCurRect(&view->window[slot], 0, 0, 0x80, 0);
            else
                CTVT_CAMVIEW_SetWindowCurRect(&view->window[slot], 0, 0, 0x40, 0);
            break;
        case 1:
            if (view->halfRes == 0)
                CTVT_CAMVIEW_SetWindowCurRect(&view->window[slot], 0x80, 0, 0, (screenSplit == 1) ? 0xc0 : 0x60);
            else
                CTVT_CAMVIEW_SetWindowCurRect(&view->window[slot], 0x40, 0, 0, (screenSplit == 1) ? 0x60 : 0x30);
            break;
        case 2:
            if (view->halfRes == 0)
                CTVT_CAMVIEW_SetWindowCurRect(&view->window[slot], 0, 0x60, 0x80, 0);
            else
                CTVT_CAMVIEW_SetWindowCurRect(&view->window[slot], 0, 0x30, 0x40, 0);
            break;
        case 3:
            if (view->halfRes == 0)
                CTVT_CAMVIEW_SetWindowCurRect(&view->window[slot], 0x80, 0x60, 0, 0x60);
            else
                CTVT_CAMVIEW_SetWindowCurRect(&view->window[slot], 0x40, 0x30, 0, 0x30);
            break;
        }
    }
    view->window[slot].moving = 1;
}

/* Requests an animated slide and a sound for a window. */
void CTVT_CAMVIEW_RequestWindowAnimation(int unused, CtvtCamView *view, int slot)
{
    view->window[slot].animate = 1;
    view->window[slot].seOnArrive = 1;
}

/* Returns the moving flag of a window. */
u32 CTVT_CAMVIEW_IsWindowMoving(u8 *unused, CtvtCamView *view, int slot)
{
    return view->window[slot].moving;
}

/* Sets the camera colour effect (0 normal, 1, 3 and 5 are the key choices). */
void CTVT_CAMVIEW_SetCameraEffect(struct CtvtWork *unused, struct CtvtCamView *unused2, int effect)
{
    int r = COMM_TVT_SYS_IsNetIdle();
    if (r != 1) {
        return;
    }
    r = CTVT_IS_RUN_ON_TWL(r);
    if (r != 1) {
        return;
    }
    CAMERA_I2CEffectExCore(3, 3, effect);
}

/* Asks the camera for the first shutter sound. */
void CTVT_CAMVIEW_RequestShutterSound0(int unused, CtvtCamView *view)
{
    if (COMM_TVT_SYS_IsNetIdle() != 1) {
        return;
    }
    CTVT_CAMERA_RequestShutterSound0(view->camera);
    view->shutterReq0 = 1;
}

/* Asks the camera for the second shutter sound, once the first was requested. */
void CTVT_CAMVIEW_RequestShutterSound1(struct CtvtWork *unused, CtvtCamView *view)
{
    if (COMM_TVT_SYS_IsNetIdle() != 1) {
        return;
    }
    if (view->shutterReq0 != 1) {
        return;
    }
    if (view->shutterReq1 != 0) {
        return;
    }
    CTVT_CAMERA_RequestShutterSound1(view->camera);
    view->shutterReq1 = 1;
}
