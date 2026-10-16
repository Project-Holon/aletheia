/*
 * file:     camera_system.c
 * unit:     yes
 * function: CTVT_CAMERA_Create, CTVT_CAMERA_OnPowerOff, CTVT_CAMERA_Delete, CTVT_CAMERA_StartFrameDma, CTVT_CAMERA_UpdateShutterSound, CTVT_CAMERA_LoadShutterSound, CTVT_CAMERA_FreeShutterSound, CTVT_CAMERA_OnBufferError, CTVT_CAMERA_OnReboot, CTVT_CAMERA_OnVsync, CTVT_CAMERA_OnFrameDmaDone, CTVT_CAMERA_SetFrameCallback, CTVT_CAMERA_AllocFrames, CTVT_CAMERA_FreeFrames, CTVT_CAMERA_StartCapture, CTVT_CAMERA_StopCapture, CTVT_CAMERA_IsShutterSoundIdle, CTVT_CAMERA_ResetTrimming, CTVT_CAMERA_GetWidth, CTVT_CAMERA_GetHeight, CTVT_CAMERA_SetSize, CTVT_CAMERA_GetSizeWidth, CTVT_CAMERA_GetSizeHeight, CTVT_CAMERA_SelectCamera, CTVT_CAMERA_RequestShutterSound0, CTVT_CAMERA_RequestShutterSound1
 * address:  0x021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from camera_system.c, draw_system.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   UI_SetKeepAwakeFlagsGlobal 0x02034F84 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   OS_Terminate 0x02088234 arm
 *   OS_EnableIrqMask 0x02084968 arm
 *   UI_SetIntrDataGlobal 0x020351F8 arm
 *   d_021C71C0 0x021C71C0 data a4
 *   g_021C88E0 0x021C88E0 data a4
 *   OS_Sleep 0x02085A38 arm
 *   CAMERA_EndCore  0x02700B34  arm
 *   CAMERA_StopCore  0x02700BD0  arm
 *   CAMERA_I2CActivateCore  0x02700DB8  arm
 *   CAMERA_I2CSizeExCore  0x02700FE4  arm
 *   CAMERA_IsBusyCore  0x027020F0  arm
 *   CAMERA_StartCaptureCore  0x02702108  arm
 *   CAMERA_StopCaptureCore  0x0270212C  arm
 *   CAMERA_SetTrimmingCore  0x02702158  arm
 *   CAMERA_ClearBufferCore  0x027021E4  arm
 *   CAMERA_SetTransferLinesCore  0x0270229C  arm
 *   CAMERA_GetMaxLinesRoundCore  0x027022F8  arm
 *   CAMERA_GetBytesAtOnceCore  0x0270234C  arm
 *   DSPi_PlayShutterSoundCore  0x02706174  arm
 *   DSPi_StopSoundCore  0x027062C8  arm
 *   DSPi_IsShutterSoundPlayingCore  0x02706324  arm
 *   DSPi_UnloadG711Core  0x027072E0  arm
 *   MI_IsNDmaBusy  0x0272FC90  arm
 *   MI_StopNDma  0x0272FCE0  arm
 *   MI_Camera_NDmaRecvAsync  0x0272FE54  arm
 *   UI_ClearKeepAwakeFlagsGlobal 0x02034FB8 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_GetMemberSize 0x020490A8 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   ARC_TOOL_ReadMember 0x02048F4C arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   GFL_NET_FreeAligned  0x0203D7FC  arm
 *   CAMERA_SizeToWidthCore  0x02702364  arm
 *   CAMERA_SizeToHeightCore  0x027023CC  arm
 *   CAMERA_SetVsyncCallbackCore  0x027000F8  arm  twl
 *   CAMERA_SetBufferErrorCallbackCore  0x02700108  arm  twl
 *   CAMERA_SetRebootCallbackCore  0x02700118  arm  twl
 *   CAMERA_InitCore  0x02700938  arm  twl
 *   CAMERA_I2CInitCore  0x02700CB4  arm  twl
 *   CAMERA_I2CEffectExCore  0x02701248  arm  twl
 *   CAMERA_I2CAutoExposureCore  0x027017DC  arm  twl
 *   CAMERA_I2CAutoWhiteBalanceCore  0x02701908  arm  twl
 *   CAMERA_SetOutputFormatCore  0x0270218C  arm  twl
 *   DSPi_OpenStaticComponentG711Core  0x0270723C  arm  twl
 *   DSPi_LoadG711Core  0x02707278  arm  twl
 *   MI_FreeWram  0x02730B04  arm  twl
 *   MI_CancelWram  0x02730FBC  arm  twl
 */
#include "ctvt_types.h"

typedef struct Camera {
    u16 heapId;
    u8 pad2[2];
    void **frames;
    u8 frameCount;
    u8 pad9[3];
    u32 allocated;
    u32 capturing;
    u32 transferOffset;
    u8 frameIndex;
    u8 pad19[3];
    u32 restartPending;
    u32 switchPending;
    u32 skipNextFrame;
    u32 vsyncCount;
    u32 activeCamera;
    u32 sizeMode;
    u16 x0;
    u16 x1;
    u16 y0;
    u16 y1;
    void (*frameCb)(u32, u32);
    u32 frameCbArg;
    u8 state;
    u8 pad45[3];
    void *buf;
    u32 bufSize;
} Camera;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void UI_SetKeepAwakeFlagsGlobal(int);

extern int OS_IsRunOnTwl(void);

extern void OS_Terminate(void);

extern void OS_EnableIrqMask(int);

extern void UI_SetIntrDataGlobal(u32 a, u32 b);

extern void OS_Sleep(u32 msec);

extern int DSPi_IsShutterSoundPlayingCore(void);

extern void DSPi_UnloadG711Core(void);

extern void CAMERA_StopCore(void);

extern void MI_StopNDma(int);

extern void CAMERA_EndCore(void);

int CAMERA_InitCore(void);

int CAMERA_I2CInitCore(int);

void CAMERA_I2CEffectExCore(int, int, int);

void CAMERA_I2CAutoExposureCore(int, int);

void CAMERA_I2CAutoWhiteBalanceCore(int, int);

u32 CAMERA_I2CActivateCore(u32 a0);

void CAMERA_SetVsyncCallbackCore(void *);

void CAMERA_SetBufferErrorCallbackCore(void *);

void CAMERA_SetRebootCallbackCore(void *);

void CAMERA_SetOutputFormatCore(int);

void MI_FreeWram(int, int);

void MI_CancelWram(int, int);

void DSPi_OpenStaticComponentG711Core(void *);

int DSPi_LoadG711Core(void *, int, int);

extern void UI_ClearKeepAwakeFlagsGlobal(u32 v);

extern u32 GFL_HEAP_Free(void *p);

extern u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);

extern void *GFL_NET_AllocAligned(u32, u32, const char *, u16);

extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

extern void DWCi_ScreenDC_FlushRange(void *, u32);

extern void GFL_NET_FreeAligned(void *p);

extern u32 CAMERA_I2CSizeExCore(u32 a, u32 b, u32 c);

void DSPi_StopSoundCore(void);

u32 CAMERA_GetBytesAtOnceCore(u32 a0);

void MI_Camera_NDmaRecvAsync(u32 a0, u32 a1, u32 a2, u32 a3, int s0, void (*s1)(void), int s2);

void DSPi_PlayShutterSoundCore(void *, int);

void CAMERA_StopCaptureCore(void);

void CAMERA_ClearBufferCore(void);

void CAMERA_StartCaptureCore(void);

int CAMERA_IsBusyCore(void);

int MI_IsNDmaBusy(int ch);

void CAMERA_SetTrimmingCore(int);

int CAMERA_GetMaxLinesRoundCore(u32, u32);

void CAMERA_SetTransferLinesCore(int);

u32 CAMERA_SizeToWidthCore(u32 v);

u32 CAMERA_SizeToHeightCore(u32 v);

Camera *CTVT_CAMERA_Create(int id);

void CTVT_CAMERA_OnPowerOff(Camera *p);

void CTVT_CAMERA_Delete(Camera *p);

void CTVT_CAMERA_StartFrameDma(Camera *p);

void CTVT_CAMERA_UpdateShutterSound(Camera *p);

void CTVT_CAMERA_LoadShutterSound(Camera *obj, int mode);

void CTVT_CAMERA_FreeShutterSound(Camera *p);

void CTVT_CAMERA_OnBufferError(void);

void CTVT_CAMERA_OnReboot(int x);

void CTVT_CAMERA_OnVsync(void);

void CTVT_CAMERA_OnFrameDmaDone(void);

void CTVT_CAMERA_SetFrameCallback(Camera *p, void (*a)(u32, u32), u32 b);

void CTVT_CAMERA_AllocFrames(Camera *p, int count, u16 heap);

void CTVT_CAMERA_FreeFrames(Camera *p);

void CTVT_CAMERA_StartCapture(Camera *a0);

void CTVT_CAMERA_StopCapture(Camera *p);

int CTVT_CAMERA_IsShutterSoundIdle(Camera *p);

void CTVT_CAMERA_ResetTrimming(Camera *p);

u16 CTVT_CAMERA_GetWidth(Camera *p);

u16 CTVT_CAMERA_GetHeight(Camera *p);

void CTVT_CAMERA_SetSize(Camera *p, int v);

int CTVT_CAMERA_GetSizeWidth(Camera *p);

int CTVT_CAMERA_GetSizeHeight(Camera *p);

void CTVT_CAMERA_SelectCamera(Camera *p, u32 v);

void CTVT_CAMERA_RequestShutterSound0(Camera *p);

void CTVT_CAMERA_RequestShutterSound1(Camera *p);

extern const char d_021C71C0[];

extern Camera *g_021C88E0;

Camera *CTVT_CAMERA_Create(int id)
{
    Camera *p;
    int r;
    int z;
    char buf[0x48];

    z = 0;
    p = GFL_HEAP_Alloc(id, 0x50, 0, d_021C71C0, 0x6F);
    g_021C88E0 = p;
    p->heapId = id;
    p->frames = 0;
    p->frameIndex = z;
    p->frameCount = z;
    p->allocated = z;
    p->capturing = z;
    p->transferOffset = z;
    p->activeCamera = 1;
    p->sizeMode = 5;
    p->restartPending = z;
    p->switchPending = z;
    p->skipNextFrame = z;
    p->frameCb = 0;
    p->frameCbArg = z;
    UI_SetKeepAwakeFlagsGlobal(0x40);
    if (OS_IsRunOnTwl() == 1) {
        r = CAMERA_InitCore();
        if (r == 0) r = CAMERA_I2CInitCore(3);
    } else {
        r = 7;
    }
    if (r == 7) OS_Terminate();
    if (r == 6) return 0;
    r = p->activeCamera;
    if (OS_IsRunOnTwl() == 1) CAMERA_I2CEffectExCore(r, 3, 0);
    r = p->activeCamera;
    if (OS_IsRunOnTwl() == 1) CAMERA_I2CAutoExposureCore(r, 1);
    r = p->activeCamera;
    if (OS_IsRunOnTwl() == 1) CAMERA_I2CAutoWhiteBalanceCore(r, 1);
    r = p->activeCamera;
    if (OS_IsRunOnTwl() == 1) r = CAMERA_I2CActivateCore(r);
    else r = 7;
    if (r == 7) OS_Terminate();
    if (r == 6) return 0;
    p->vsyncCount = 0;
    OS_EnableIrqMask(0x20000000);
    if (OS_IsRunOnTwl() == 1) CAMERA_SetVsyncCallbackCore((void *)CTVT_CAMERA_OnVsync);
    if (OS_IsRunOnTwl() == 1) CAMERA_SetBufferErrorCallbackCore((void *)CTVT_CAMERA_OnBufferError);
    if (OS_IsRunOnTwl() == 1) CAMERA_SetRebootCallbackCore((void *)CTVT_CAMERA_OnReboot);
    CTVT_CAMERA_ResetTrimming(p);
    if (OS_IsRunOnTwl() == 1) CAMERA_SetOutputFormatCore(1);
    p->buf = 0;
    p->state = 0;
    MI_FreeWram(1, 0);
    MI_CancelWram(1, 0);
    MI_CancelWram(1, 1);
    MI_FreeWram(2, 0);
    MI_CancelWram(2, 0);
    MI_CancelWram(2, 1);
    if (OS_IsRunOnTwl() != 0) DSPi_OpenStaticComponentG711Core(buf);
    if (OS_IsRunOnTwl() != 0) r = DSPi_LoadG711Core(buf, 0xFF, 0xFF);
    else r = 0;
    if (r == 0) OS_Terminate();
    UI_SetIntrDataGlobal((u32)((void *)CTVT_CAMERA_OnPowerOff), (u32)p);
    return p;
}

void CTVT_CAMERA_OnPowerOff(Camera *p)
{
    int result;
    /* stand-in: the goto into the loop body gives the original block order; while/for forms differ */
    goto test;
    do {
        OS_Sleep(10);
test:
        result = 0;
        if (OS_IsRunOnTwl() != 0) result = DSPi_IsShutterSoundPlayingCore();
    } while (result == 1);
    if (OS_IsRunOnTwl() != 0) DSPi_UnloadG711Core();
    CTVT_CAMERA_StopCapture(p);
    if (OS_IsRunOnTwl() == 1) CAMERA_StopCore();
    MI_StopNDma(1);
    if (OS_IsRunOnTwl() == 1) CAMERA_EndCore();
}

void CTVT_CAMERA_Delete(Camera *p)
{
    UI_SetIntrDataGlobal(0, 0);
    if (OS_IsRunOnTwl() != 0) DSPi_StopSoundCore();
    if (OS_IsRunOnTwl() != 0) DSPi_UnloadG711Core();
    CTVT_CAMERA_StopCapture(p);
    if (OS_IsRunOnTwl() == 1) CAMERA_StopCore();
    MI_StopNDma(1);
    if (OS_IsRunOnTwl() == 1) CAMERA_EndCore();
    CTVT_CAMERA_FreeShutterSound(p);
    CTVT_CAMERA_FreeFrames(p);
    UI_ClearKeepAwakeFlagsGlobal(0x40);
    GFL_HEAP_Free(p);
    g_021C88E0 = 0;
}

void CTVT_CAMERA_StartFrameDma(Camera *p)
{
    u32 width = CTVT_CAMERA_GetWidth(p);
    u32 height = CTVT_CAMERA_GetHeight(p);
    u32 offset = OS_IsRunOnTwl() == 1 ? CAMERA_GetBytesAtOnceCore(width) : 0;
    width *= 2;
    MI_Camera_NDmaRecvAsync(1, (u32)p->frames[p->frameIndex], offset >> 2,
                 width * height, 0, CTVT_CAMERA_OnFrameDmaDone, 0);
}

void CTVT_CAMERA_UpdateShutterSound(Camera *p)
{
    void *b;
    int a;
    void *d;
    int c;
    int r;
    switch (p->state) {
    case 1:
        CTVT_CAMERA_LoadShutterSound(p, 1);
        a = p->bufSize;
        b = p->buf;
        if (OS_IsRunOnTwl() != 0) DSPi_PlayShutterSoundCore(b, a);
        p->state = 2;
        break;
    case 2:
        r = 0;
        if (OS_IsRunOnTwl() != 0) r = DSPi_IsShutterSoundPlayingCore();
        if (r == 0) {
            CTVT_CAMERA_FreeShutterSound(p);
            p->state = 3;
        }
        break;
    case 4:
        CTVT_CAMERA_LoadShutterSound(p, 0);
        c = p->bufSize;
        d = p->buf;
        if (OS_IsRunOnTwl() != 0) DSPi_PlayShutterSoundCore(d, c);
        p->state = 5;
        break;
    case 5:
        r = 0;
        if (OS_IsRunOnTwl() != 0) r = DSPi_IsShutterSoundPlayingCore();
        if (r == 0) {
            CTVT_CAMERA_FreeShutterSound(p);
            p->state = 6;
        }
        break;
    case 0:
    case 3:
    case 6:
    default:
        break;
    }
}

void CTVT_CAMERA_LoadShutterSound(Camera *obj, int mode)
{
    Camera *p = obj;
    int which = 0;
    u32 size;
    if (mode != 1) which = 1;
    CTVT_CAMERA_FreeShutterSound(p);
    which = (u16)which;
    size = ARC_TOOL_GetMemberSize(0xD4, which);
    p->bufSize = size;
    p->buf = GFL_NET_AllocAligned(p->heapId, size, d_021C71C0, 0x13B);
    ARC_TOOL_ReadMember(p->buf, 0xD4, which);
    DWCi_ScreenDC_FlushRange(p->buf, p->bufSize);
}

/*
 * Release the word at +0x48 through 0x0203D7FC and clear it.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_CAMERA_FreeShutterSound(Camera *p)
{
    void *v = p->buf;
    if (v != 0) {
        GFL_NET_FreeAligned(v);
        p->buf = 0;
    }
}

void CTVT_CAMERA_OnBufferError(void)
{
    Camera *p = g_021C88E0;

    if (OS_IsRunOnTwl() == 1)
        CAMERA_StopCaptureCore();
    MI_StopNDma(1);
    if (OS_IsRunOnTwl() == 1)
        CAMERA_ClearBufferCore();
    p->skipNextFrame = 1;
    p->restartPending = 1;
}

/*
 * Delegate to CTVT_CAMERA_OnBufferError unless the argument is 7.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_CAMERA_OnReboot(int x)
{
    if (x != 7) {
        CTVT_CAMERA_OnBufferError();
    }
}

void CTVT_CAMERA_OnVsync(void)
{
    Camera *p = g_021C88E0;
    u32 v;
    if (p->capturing != 0) {
        if (p->vsyncCount <= 30) ++p->vsyncCount;
        if (p->switchPending != 0) {
            v = p->activeCamera;
            if ((OS_IsRunOnTwl() == 1 ? CAMERA_I2CActivateCore(v) : 7) == 7)
                OS_Terminate();
            p->vsyncCount = 0;
            p->switchPending = 0;
        }
        if (p->restartPending != 0) {
            CTVT_CAMERA_StartFrameDma(p);
            if (OS_IsRunOnTwl() == 1) CAMERA_ClearBufferCore();
            if (OS_IsRunOnTwl() == 1) CAMERA_StartCaptureCore();
            p->restartPending = 0;
        }
    }
}

void CTVT_CAMERA_OnFrameDmaDone(void)
{
    Camera *p = g_021C88E0;
    int one;
    MI_StopNDma(1);
    if ((OS_IsRunOnTwl() == 1 ? CAMERA_IsBusyCore() : 0) == 1) {
        one = 1;
        if (MI_IsNDmaBusy(one) != 0) MI_StopNDma(one);
        if (p->skipNextFrame != 0) {
            p->skipNextFrame = 0;
        } else if (p->vsyncCount > 4) {
            if (p->frameCb != 0)
                p->frameCb((u32)p->frames[p->frameIndex], p->frameCbArg);
            p->frameIndex = (p->frameIndex + 1) % p->frameCount;
        }
        if (p->capturing == 1) CTVT_CAMERA_StartFrameDma(p);
    }
}

void CTVT_CAMERA_SetFrameCallback(Camera *p, void (*a)(u32, u32), u32 b)
{
    p->frameCb = a;
    p->frameCbArg = b;
}

void CTVT_CAMERA_AllocFrames(Camera *p, int count, u16 heap)
{
    u32 width = CTVT_CAMERA_GetWidth(p);
    u32 height = CTVT_CAMERA_GetHeight(p);
    u8 i;
    if (p->frames == 0) {
        p->frames = GFL_HEAP_Alloc(p->heapId, count * 4, 0, d_021C71C0, 0x1D7);
        p->frameCount = count;
        for (i = 0; i < count; i++)
            p->frames[i] = GFL_NET_AllocAligned(heap, height * (width * 2), d_021C71C0, 0x1DC);
        p->allocated = 1;
    }
}

void CTVT_CAMERA_FreeFrames(Camera *p)
{
    u8 i;
    if (p->capturing != 0) return;
    if ((OS_IsRunOnTwl() == 1 ? CAMERA_IsBusyCore() : 0) != 0) return;
    if (p->allocated == 1) {
        for (i = 0; i < p->frameCount; i++)
            GFL_NET_FreeAligned(p->frames[i]);
    }
    GFL_HEAP_Free(p->frames);
    p->frameCount = 0;
    p->frames = 0;
}

void CTVT_CAMERA_StartCapture(Camera *a0)
{
    Camera *p = a0;
    int one = 1;

    if (p->capturing != 0)
        return;
    if ((OS_IsRunOnTwl() == 1 ? CAMERA_IsBusyCore() : 0) != 0)
        return;
    if (MI_IsNDmaBusy(one) == 1)
        MI_StopNDma(one);
    p->capturing = one;
    p->restartPending = one;
    p->vsyncCount = 0;
}

void CTVT_CAMERA_StopCapture(Camera *p)
{
    if (p->capturing == 1) {
        p->capturing = 0;
        p->restartPending = 0;
        if (OS_IsRunOnTwl() == 1) {
            CAMERA_StopCaptureCore();
        }
    }
}

int CTVT_CAMERA_IsShutterSoundIdle(Camera *p)
{
    u8 v = p->state;
    return v == 6 || v == 0;
}

void CTVT_CAMERA_ResetTrimming(Camera *p)
{
    int result;
    u32 width;
    u32 height;
    if (p->capturing != 0) return;
    if ((OS_IsRunOnTwl() == 1 ? CAMERA_IsBusyCore() : 0) != 0) return;
    if (OS_IsRunOnTwl() == 1) CAMERA_SetTrimmingCore(0);
    result = 0;
    p->x0 = 0;
    p->x1 = CTVT_CAMERA_GetSizeWidth(p);
    p->y0 = 0;
    p->y1 = CTVT_CAMERA_GetSizeHeight(p);
    width = CTVT_CAMERA_GetWidth(p);
    height = CTVT_CAMERA_GetHeight(p);
    if (OS_IsRunOnTwl() == 1) result = CAMERA_GetMaxLinesRoundCore(width, height);
    if (OS_IsRunOnTwl() == 1) CAMERA_SetTransferLinesCore(result);
    p->transferOffset = 0;
}

u16 CTVT_CAMERA_GetWidth(Camera *p)
{
    return (u16)(p->x1 - p->x0);
}

/*
 * Width of the u16 pair at +0x38/+0x3a, zero extended.
 *
 * Addresses are Black-image addresses.
 */
u16 CTVT_CAMERA_GetHeight(Camera *p)
{
    return (u16)(p->y1 - p->y0);
}

void CTVT_CAMERA_SetSize(Camera *p, int v)
{
    if (OS_IsRunOnTwl() == 1) CAMERA_I2CSizeExCore(3, 3, v);
    p->sizeMode = v;
    CTVT_CAMERA_ResetTrimming(p);
}

/*
 * Guard on 0x02085D3C then an arm veneer call with the field at +0x30.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_CAMERA_GetSizeWidth(Camera *p)
{
    u32 f = p->sizeMode;
    if (OS_IsRunOnTwl() == 1) {
        return CAMERA_SizeToWidthCore(f);
    }
    return 0;
}

int CTVT_CAMERA_GetSizeHeight(Camera *p)
{
    u32 v = p->sizeMode;
    if (OS_IsRunOnTwl() == 1) {
        return CAMERA_SizeToHeightCore(v);
    }
    return 0;
}

void CTVT_CAMERA_SelectCamera(Camera *p, u32 v)
{
    if (p->activeCamera == v) {
        return;
    }
    if (p->switchPending != 0) {
        return;
    }
    p->activeCamera = v;
    p->switchPending = 1;
}

void CTVT_CAMERA_RequestShutterSound0(Camera *p)
{
    p->state = 1;
}

void CTVT_CAMERA_RequestShutterSound1(Camera *p)
{
    p->state = 4;
}
