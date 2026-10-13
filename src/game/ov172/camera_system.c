/*
 * file:     camera_system.c
 * unit:     yes
 * function: func_021B6100, func_021B6338, func_021B63B8, func_021B644C, func_021B64AC, func_021B657C, func_021B65C4, func_021B65D8, func_021B6620, func_021B662C, func_021B66B0, func_021B6744, func_021B674C, func_021B67BC, func_021B6814, func_021B6868, func_021B688C, func_021B68A0, func_021B6938, func_021B6944, func_021B6950, func_021B697C, func_021B699C, func_021B69BC, func_021B69D0, func_021B69D8, func_021B69E0, func_021B69F0
 * address:  0x021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02034F84 0x02034F84 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   OS_Terminate 0x02088234 arm
 *   OS_EnableIrqMask 0x02084968 arm
 *   func_020351F8 0x020351F8 arm
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
 *   func_02034FB8 0x02034FB8 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_GetMemberSize 0x020490A8 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   ARC_TOOL_ReadMember 0x02048F4C arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   GFL_NET_FreeAligned  0x0203D7FC  arm
 *   CAMERA_SizeToWidthCore  0x02702364  arm
 *   CAMERA_SizeToHeightCore  0x027023CC  arm
 *   d_021C88E4 0x021C88E4 data a4 ov172
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

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed int     s32;

typedef struct Camera {
    u16 heapId;
    u8 pad2[2];
    void **frames;
    u8 frameCount;
    u8 pad9[3];
    u32 allocated;
    u32 f10;
    u32 f14;
    u8 frameIndex;
    u8 pad19[3];
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
    u32 f30;
    u16 x0;
    u16 x1;
    u16 y0;
    u16 y1;
    void (*frameCb)(u32, u32);
    u32 f40;
    u8 state;
    u8 pad45[3];
    void *buf;
    u32 bufSize;
} Camera;

struct D021C88E4 {
    u16 h0;
    u8 b2;
    u8 pad3;
    u16 h4;
    u8 b6;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034F84(int);
extern int OS_IsRunOnTwl(void);
extern void OS_Terminate(void);
extern void OS_EnableIrqMask(int);
extern void func_020351F8(u32 a, u32 b);
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
extern void func_02034FB8(u32 v);
extern u32 func_020307B0(void *p);
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
Camera *func_021B6100(int id);
void func_021B6338(Camera *p);
void func_021B63B8(Camera *p);
void func_021B644C(Camera *p);
void func_021B64AC(Camera *p);
void func_021B657C(Camera *obj, int mode);
void func_021B65C4(Camera *p);
void func_021B65D8(void);
void func_021B6620(int x);
void func_021B662C(void);
void func_021B66B0(void);
void func_021B6744(Camera *p, void (*a)(u32, u32), u32 b);
void func_021B674C(Camera *p, int count, u16 heap);
void func_021B67BC(Camera *p);
void func_021B6814(Camera *a0);
void func_021B6868(Camera *p);
int func_021B688C(Camera *p);
void func_021B68A0(Camera *p);
u16 func_021B6938(Camera *p);
u16 func_021B6944(Camera *p);
void func_021B6950(Camera *p, int v);
int func_021B697C(Camera *p);
int func_021B699C(Camera *p);
void func_021B69BC(Camera *p, u32 v);
void func_021B69D0(Camera *p);
void func_021B69D8(Camera *p);
void func_021B69E0(void);
void func_021B69F0(void);
extern const char d_021C71C0[];
extern Camera *g_021C88E0;
extern struct D021C88E4 d_021C88E4;



Camera *func_021B6100(int id)
{
    Camera *p;
    int r;
    int z;
    char buf[0x48];

    z = 0;
    p = func_02030734(id, 0x50, 0, d_021C71C0, 0x6F);
    g_021C88E0 = p;
    p->heapId = id;
    p->frames = 0;
    p->frameIndex = z;
    p->frameCount = z;
    p->allocated = z;
    p->f10 = z;
    p->f14 = z;
    p->f2C = 1;
    p->f30 = 5;
    p->f1C = z;
    p->f20 = z;
    p->f24 = z;
    p->frameCb = 0;
    p->f40 = z;
    func_02034F84(0x40);
    if (OS_IsRunOnTwl() == 1) {
        r = CAMERA_InitCore();
        if (r == 0) r = CAMERA_I2CInitCore(3);
    } else {
        r = 7;
    }
    if (r == 7) OS_Terminate();
    if (r == 6) return 0;
    r = p->f2C;
    if (OS_IsRunOnTwl() == 1) CAMERA_I2CEffectExCore(r, 3, 0);
    r = p->f2C;
    if (OS_IsRunOnTwl() == 1) CAMERA_I2CAutoExposureCore(r, 1);
    r = p->f2C;
    if (OS_IsRunOnTwl() == 1) CAMERA_I2CAutoWhiteBalanceCore(r, 1);
    r = p->f2C;
    if (OS_IsRunOnTwl() == 1) r = CAMERA_I2CActivateCore(r);
    else r = 7;
    if (r == 7) OS_Terminate();
    if (r == 6) return 0;
    p->f28 = 0;
    OS_EnableIrqMask(0x20000000);
    if (OS_IsRunOnTwl() == 1) CAMERA_SetVsyncCallbackCore((void *)func_021B662C);
    if (OS_IsRunOnTwl() == 1) CAMERA_SetBufferErrorCallbackCore((void *)func_021B65D8);
    if (OS_IsRunOnTwl() == 1) CAMERA_SetRebootCallbackCore((void *)func_021B6620);
    func_021B68A0(p);
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
    func_020351F8((u32)((void *)func_021B6338), (u32)p);
    return p;
}



void func_021B6338(Camera *p)
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
    func_021B6868(p);
    if (OS_IsRunOnTwl() == 1) CAMERA_StopCore();
    MI_StopNDma(1);
    if (OS_IsRunOnTwl() == 1) CAMERA_EndCore();
}



void func_021B63B8(Camera *p)
{
    func_020351F8(0, 0);
    if (OS_IsRunOnTwl() != 0) DSPi_StopSoundCore();
    if (OS_IsRunOnTwl() != 0) DSPi_UnloadG711Core();
    func_021B6868(p);
    if (OS_IsRunOnTwl() == 1) CAMERA_StopCore();
    MI_StopNDma(1);
    if (OS_IsRunOnTwl() == 1) CAMERA_EndCore();
    func_021B65C4(p);
    func_021B67BC(p);
    func_02034FB8(0x40);
    func_020307B0(p);
    g_021C88E0 = 0;
}



void func_021B644C(Camera *p)
{
    u32 width = func_021B6938(p);
    u32 height = func_021B6944(p);
    u32 offset = OS_IsRunOnTwl() == 1 ? CAMERA_GetBytesAtOnceCore(width) : 0;
    width *= 2;
    MI_Camera_NDmaRecvAsync(1, (u32)p->frames[p->frameIndex], offset >> 2,
                 width * height, 0, func_021B66B0, 0);
}




void func_021B64AC(Camera *p)
{
    void *b;
    int a;
    void *d;
    int c;
    int r;
    switch (p->state) {
    case 1:
        func_021B657C(p, 1);
        a = p->bufSize;
        b = p->buf;
        if (OS_IsRunOnTwl() != 0) DSPi_PlayShutterSoundCore(b, a);
        p->state = 2;
        break;
    case 2:
        r = 0;
        if (OS_IsRunOnTwl() != 0) r = DSPi_IsShutterSoundPlayingCore();
        if (r == 0) {
            func_021B65C4(p);
            p->state = 3;
        }
        break;
    case 4:
        func_021B657C(p, 0);
        c = p->bufSize;
        d = p->buf;
        if (OS_IsRunOnTwl() != 0) DSPi_PlayShutterSoundCore(d, c);
        p->state = 5;
        break;
    case 5:
        r = 0;
        if (OS_IsRunOnTwl() != 0) r = DSPi_IsShutterSoundPlayingCore();
        if (r == 0) {
            func_021B65C4(p);
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



void func_021B657C(Camera *obj, int mode)
{
    Camera *p = obj;
    int which = 0;
    u32 size;
    if (mode != 1) which = 1;
    func_021B65C4(p);
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
void func_021B65C4(Camera *p)
{
    void *v = p->buf;
    if (v != 0) {
        GFL_NET_FreeAligned(v);
        p->buf = 0;
    }
}



void func_021B65D8(void)
{
    Camera *p = g_021C88E0;

    if (OS_IsRunOnTwl() == 1)
        CAMERA_StopCaptureCore();
    MI_StopNDma(1);
    if (OS_IsRunOnTwl() == 1)
        CAMERA_ClearBufferCore();
    p->f24 = 1;
    p->f1C = 1;
}



/*
 * Delegate to func_021B65D8 unless the argument is 7.
 *
 * Addresses are Black-image addresses.
 */
void func_021B6620(int x)
{
    if (x != 7) {
        func_021B65D8();
    }
}



void func_021B662C(void)
{
    Camera *p = g_021C88E0;
    u32 v;
    if (p->f10 != 0) {
        if (p->f28 <= 30) ++p->f28;
        if (p->f20 != 0) {
            v = p->f2C;
            if ((OS_IsRunOnTwl() == 1 ? CAMERA_I2CActivateCore(v) : 7) == 7)
                OS_Terminate();
            p->f28 = 0;
            p->f20 = 0;
        }
        if (p->f1C != 0) {
            func_021B644C(p);
            if (OS_IsRunOnTwl() == 1) CAMERA_ClearBufferCore();
            if (OS_IsRunOnTwl() == 1) CAMERA_StartCaptureCore();
            p->f1C = 0;
        }
    }
}



void func_021B66B0(void)
{
    Camera *p = g_021C88E0;
    int one;
    MI_StopNDma(1);
    if ((OS_IsRunOnTwl() == 1 ? CAMERA_IsBusyCore() : 0) == 1) {
        one = 1;
        if (MI_IsNDmaBusy(one) != 0) MI_StopNDma(one);
        if (p->f24 != 0) {
            p->f24 = 0;
        } else if (p->f28 > 4) {
            if (p->frameCb != 0)
                p->frameCb((u32)p->frames[p->frameIndex], p->f40);
            p->frameIndex = (p->frameIndex + 1) % p->frameCount;
        }
        if (p->f10 == 1) func_021B644C(p);
    }
}



void func_021B6744(Camera *p, void (*a)(u32, u32), u32 b)
{
    p->frameCb = a;
    p->f40 = b;
}



void func_021B674C(Camera *p, int count, u16 heap)
{
    u32 width = func_021B6938(p);
    u32 height = func_021B6944(p);
    u8 i;
    if (p->frames == 0) {
        p->frames = func_02030734(p->heapId, count * 4, 0, d_021C71C0, 0x1D7);
        p->frameCount = count;
        for (i = 0; i < count; i++)
            p->frames[i] = GFL_NET_AllocAligned(heap, height * (width * 2), d_021C71C0, 0x1DC);
        p->allocated = 1;
    }
}



void func_021B67BC(Camera *p)
{
    u8 i;
    if (p->f10 != 0) return;
    if ((OS_IsRunOnTwl() == 1 ? CAMERA_IsBusyCore() : 0) != 0) return;
    if (p->allocated == 1) {
        for (i = 0; i < p->frameCount; i++)
            GFL_NET_FreeAligned(p->frames[i]);
    }
    func_020307B0(p->frames);
    p->frameCount = 0;
    p->frames = 0;
}



void func_021B6814(Camera *a0)
{
    Camera *p = a0;
    int one = 1;

    if (p->f10 != 0)
        return;
    if ((OS_IsRunOnTwl() == 1 ? CAMERA_IsBusyCore() : 0) != 0)
        return;
    if (MI_IsNDmaBusy(one) == 1)
        MI_StopNDma(one);
    p->f10 = one;
    p->f1C = one;
    p->f28 = 0;
}



void func_021B6868(Camera *p)
{
    if (p->f10 == 1) {
        p->f10 = 0;
        p->f1C = 0;
        if (OS_IsRunOnTwl() == 1) {
            CAMERA_StopCaptureCore();
        }
    }
}



int func_021B688C(Camera *p)
{
    u8 v = p->state;
    return v == 6 || v == 0;
}



void func_021B68A0(Camera *p)
{
    int result;
    u32 width;
    u32 height;
    if (p->f10 != 0) return;
    if ((OS_IsRunOnTwl() == 1 ? CAMERA_IsBusyCore() : 0) != 0) return;
    if (OS_IsRunOnTwl() == 1) CAMERA_SetTrimmingCore(0);
    result = 0;
    p->x0 = 0;
    p->x1 = func_021B697C(p);
    p->y0 = 0;
    p->y1 = func_021B699C(p);
    width = func_021B6938(p);
    height = func_021B6944(p);
    if (OS_IsRunOnTwl() == 1) result = CAMERA_GetMaxLinesRoundCore(width, height);
    if (OS_IsRunOnTwl() == 1) CAMERA_SetTransferLinesCore(result);
    p->f14 = 0;
}



u16 func_021B6938(Camera *p)
{
    return (u16)(p->x1 - p->x0);
}



/*
 * Width of the u16 pair at +0x38/+0x3a, zero extended.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021B6944(Camera *p)
{
    return (u16)(p->y1 - p->y0);
}



void func_021B6950(Camera *p, int v)
{
    if (OS_IsRunOnTwl() == 1) CAMERA_I2CSizeExCore(3, 3, v);
    p->f30 = v;
    func_021B68A0(p);
}



/*
 * Guard on 0x02085D3C then an arm veneer call with the field at +0x30.
 *
 * Addresses are Black-image addresses.
 */
int func_021B697C(Camera *p)
{
    u32 f = p->f30;
    if (OS_IsRunOnTwl() == 1) {
        return CAMERA_SizeToWidthCore(f);
    }
    return 0;
}



int func_021B699C(Camera *p)
{
    u32 v = p->f30;
    if (OS_IsRunOnTwl() == 1) {
        return CAMERA_SizeToHeightCore(v);
    }
    return 0;
}



void func_021B69BC(Camera *p, u32 v)
{
    if (p->f2C == v) {
        return;
    }
    if (p->f20 != 0) {
        return;
    }
    p->f2C = v;
    p->f20 = 1;
}



void func_021B69D0(Camera *p)
{
    p->state = 1;
}



void func_021B69D8(Camera *p)
{
    p->state = 4;
}



/*
 * Clear the halfword at +4 and the byte at +6 of the ov172 state block. Filed
 * as the call witness for ov172 func_021B97AC.
 */
void func_021B69E0(void)
{
    d_021C88E4.h4 = 0;
    d_021C88E4.b6 = 0;
}



/*
 * Clear the 3-byte counter at g_021C88E4.
 *
 * Addresses are Black-image addresses.
 */
void func_021B69F0(void)
{
    d_021C88E4.h0 = 0;
    d_021C88E4.b2 = 0;
}
