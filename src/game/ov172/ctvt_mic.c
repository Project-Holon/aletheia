/*
 * file:     ctvt_mic.c
 * unit:     yes
 * function: CTVT_MIC_Create, CTVT_MIC_Delete, CTVT_MIC_Update, CTVT_MIC_SetMode, CTVT_MIC_OnVBlank, CTVT_MIC_StartCapture, CTVT_MIC_OnCaptureComplete, CTVT_MIC_StopCapture, CTVT_MIC_IsCapturing, CTVT_MIC_GetReadyBytes, CTVT_MIC_GetBuffer, CTVT_MIC_EncodeAdpcm, CTVT_MIC_DecodeAdpcm, CTVT_MIC_InitChannel, CTVT_MIC_FreeChannel, CTVT_MIC_PostUpdate, CTVT_MIC_PlayVoice, CTVT_MIC_StopVoice, CTVT_MIC_GetPlayState, CTVT_MIC_GetLength, CTVT_MIC_GetPlayPos, CTVT_MIC_GetPlayRatio, CTVT_MIC_IsCaptureDone
 * address:  0x021B9F9C
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
 *   func_02030734 0x02030734 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   GFL_NET_FreeAligned  0x0203D7FC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082A7C 0x02082A7C arm
 *   func_02034714 0x02034714 arm
 *   CTVT_MIC_Create 0x021B9F9C thumb ov172
 *   CTVT_MIC_Delete 0x021BA01C thumb ov172
 *   CTVT_MIC_Update 0x021BA050 thumb ov172
 *   CTVT_MIC_SetMode 0x021BA094 thumb ov172
 *   CTVT_MIC_OnVBlank 0x021BA098 thumb ov172
 *   CTVT_MIC_StartCapture 0x021BA0BC thumb ov172
 *   CTVT_MIC_OnCaptureComplete 0x021BA114 thumb ov172
 *   CTVT_MIC_StopCapture 0x021BA120 thumb ov172
 *   CTVT_MIC_IsCapturing 0x021BA158 thumb ov172
 *   CTVT_MIC_GetReadyBytes 0x021BA15C thumb ov172
 *   CTVT_MIC_GetBuffer 0x021BA170 thumb ov172
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   CTVT_MIC_StopVoice 0x021BA234 thumb ov172
 *   CTVT_MIC_PlayVoice 0x021BA1E8 thumb ov172
 *   CTVT_MIC_DecodeAdpcm 0x021BA194 thumb ov172
 *   CTVT_MIC_IsCaptureDone 0x021BA270 thumb ov172
 *   CTVT_MIC_GetPlayState 0x021BA244 thumb ov172
 *   CTVT_MIC_GetLength 0x021BA248 thumb ov172
 *   CTVT_MIC_GetPlayPos 0x021BA24C thumb ov172
 *   CTVT_MIC_GetPlayRatio 0x021BA254 thumb ov172
 *   CTVT_MIC_EncodeAdpcm 0x021BA174 thumb ov172
 *   func_0208B24C 0x0208B24C arm
 *   func_0208B8B0 0x0208B8B0 arm
 *   func_0208BEF0 0x0208BEF0 arm
 *   func_0208BF54 0x0208BF54 arm
 *   CTVT_MIC_InitChannel 0x021BA1B4 thumb ov172
 *   func_02005654 0x02005654 thumb
 *   gCtvtMicAllocSite 0x021C7218 data a4
 *   gCtvtMicIirFilter 0x021C720C data a4
 *   gCtvtMic 0x021C88EC data a4
 *   func_0200566C  0x0200566C  thumb
 *   CTVT_MIC_FreeChannel  0x021BA1D8  thumb  ov172
 *   func_0208B4B8 0x0208B4B8 arm
 *   NNS_SndWaveOutIsPlaying 0x02072CC4 arm
 *   CTVT_MIC_PostUpdate 0x021BA1E4 thumb ov172
 *   func_0208B500 0x0208B500 arm
 *   func_0208B528 0x0208B528 arm
 *   SNDEXi_SetIirFilter  0x027047C0  arm  twl
 *   MI_CpuFill8  0x02082BCC  arm
 *   CTVT_ADPCM_Encode  0x021B6A00  thumb  ov172
 *   CTVT_ADPCM_Decode  0x021B6A18  thumb  ov172
 *   NNS_SndWaveOutAllocChannel  0x02072A44  arm
 *   NNSi_SndWaveOutUnlockChannel  0x02072A88  arm
 *   NNS_SndWaveOutStart  0x02072AA0  arm
 *   NNS_SndWaveOutStop 0x02072BDC arm
 *   func_0209C2B0  0x0209C2B0  arm
 */
#include "ctvt_types.h"

extern u32 func_020307B0(void *p);

typedef enum MICResult { MIC_SUCCESS, MIC_BUSY, MIC_ILLEGAL, MIC_SEND_ERROR } MICResult;

typedef struct MICAutoParam {
    int type;
    void *buffer;
    u32 size;
    u32 rate;
    int loop;
    void (*callback)(MICResult, void *);
    void *arg;
} MICAutoParam;

extern int OS_IsRunOnTwl();

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);

extern void GFL_NET_FreeAligned(void *);

extern void func_02082A7C();

extern void func_0208B24C(void);

extern void func_0208B8B0(void);

extern u32 func_0208BEF0(u32);

extern u32 func_0208BF54(u8);

extern void CTVT_MIC_InitChannel(CtvtMic *mic, u32 heap);

extern int func_02005654(int, int);

extern void func_0200566C(void);

extern void CTVT_MIC_FreeChannel(CtvtMic *mic);

extern void *func_0208B4B8(void);

extern int NNS_SndWaveOutIsPlaying(struct NnsWaveOutSlot *);

extern void CTVT_MIC_PostUpdate(CtvtMic *mic);

extern MICResult func_0208B500(MICAutoParam *);

extern int func_0208B528(void);

CtvtMic *CTVT_MIC_Create(u32 heap);

void SNDEXi_SetIirFilter(int, void *);

void CTVT_MIC_Delete(CtvtMic *mic);

void CTVT_MIC_Update(CtvtMic *mic);

void CTVT_MIC_SetMode(int mode);

void CTVT_MIC_OnVBlank(void);

int CTVT_MIC_StartCapture(CtvtMic *mic);

void CTVT_MIC_OnCaptureComplete(MICResult result, void *arg);

int CTVT_MIC_StopCapture(CtvtMic *mic);

u32 CTVT_MIC_IsCapturing(CtvtMic *mic);

u32 CTVT_MIC_GetReadyBytes(CtvtMic *mic);

u32 CTVT_MIC_GetBuffer(CtvtMic *mic);

extern const char gCtvtMicAllocSite[], gCtvtMicIirFilter[];

extern CtvtMic *gCtvtMic;

CtvtMic *CTVT_MIC_Create(u32 heap)
{
    CtvtMic *mic = func_02030734(heap, 36, 1, gCtvtMicAllocSite, 87);
    func_0208B24C();
    func_0208B8B0();
    func_0208BEF0(1);
    func_0208BF54(80);
    if (OS_IsRunOnTwl() == 1) SNDEXi_SetIirFilter(0, (void *)gCtvtMicIirFilter);
    CTVT_MIC_InitChannel(mic, heap);
    mic->buffer = GFL_NET_AllocAligned(heap, 51200, gCtvtMicAllocSite, 134);
    mic->capturedBytes = 0;
    mic->capturing = 0;
    mic->captureTicks = 0;
    gCtvtMic = mic;
    func_02005654((int)CTVT_MIC_OnVBlank, 0);
    return mic;
}

void CTVT_MIC_Delete(CtvtMic *mic)
{
    func_0200566C();
    gCtvtMic = 0;
    CTVT_MIC_StopCapture(mic);
    CTVT_MIC_FreeChannel(mic);
    func_0208BEF0(0);
    GFL_NET_FreeAligned(mic->buffer);
    func_020307B0(mic);
}

void CTVT_MIC_Update(CtvtMic *mic)
{
    u32 n;
    if (mic->capturing == 1) {
        n = (u32)func_0208B4B8();
        if (n == 0) mic->capturedBytes = 0;
        else {
            mic->capturedBytes = n - (u32)mic->buffer + 4;
            if (mic->capturedBytes > 51200) mic->capturedBytes = 51200;
        }
    }
    if (mic->playing == 1) {
        if (NNS_SndWaveOutIsPlaying(mic->channel) == 0) mic->playing = 0;
    }
    CTVT_MIC_PostUpdate(mic);
}

void CTVT_MIC_SetMode(int mode)
{
}

void CTVT_MIC_OnVBlank(void)
{
    CtvtMic *mic = gCtvtMic;
    if (mic->playing == 1) mic->playPos++;
    mic = gCtvtMic;
    if (mic->captureTicks < 180) mic->captureTicks++;
}

/*
 * extent: Callback at 021BA114 stores zero at r1+8 and 51200 at r1.
 */
int CTVT_MIC_StartCapture(CtvtMic *mic)
{
    MICAutoParam param;
    param.type = 3;
    param.size = 51200;
    param.buffer = mic->buffer;
    func_02082A7C(0, param.buffer, param.size);
    if (param.size & 31) param.size &= ~31;
    param.callback = CTVT_MIC_OnCaptureComplete;
    param.loop = 0;
    param.rate = 4097;
    param.arg = mic;
    if (func_0208B500(&param) == 0) {
        mic->capturing = 1;
        mic->capturedBytes = 0;
        return 1;
    }
    return 0;
}

void CTVT_MIC_OnCaptureComplete(MICResult result, void *arg)
{
    CtvtMic *mic = arg;
    mic->capturing = 0;
    mic->capturedBytes = 51200;
}

int CTVT_MIC_StopCapture(CtvtMic *mic)
{
    if (mic->capturing == 0) return 1;
    if (func_0208B528() == 0) {
        mic->capturedBytes = (u32)func_0208B4B8() - (u32)mic->buffer + 4;
        if (mic->capturedBytes > 51200) mic->capturedBytes = 51200;
        mic->capturing = 0;
        return 1;
    }
    return 0;
}

u32 CTVT_MIC_IsCapturing(CtvtMic *mic) { return mic->capturing; }

u32 CTVT_MIC_GetReadyBytes(CtvtMic *mic)
{
    if (mic->capturedBytes > 2048) return mic->capturedBytes - 2048;
    return 0;
}

u32 CTVT_MIC_GetBuffer(CtvtMic *mic) { return (u32)mic->buffer; }

extern void MI_CpuFill8(void *p, int v, int n);

extern int CTVT_ADPCM_Encode(void *a0, unsigned a1, void *a2);


extern int CTVT_ADPCM_Decode(int a, int b, int c);

extern int  NNS_SndWaveOutAllocChannel(int size);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void NNSi_SndWaveOutUnlockChannel(struct NnsWaveOutSlot *slot);

extern int NNS_SndWaveOutStart(void *s, int fmt, void *data, int loop,
                         int start, int end, int rate, int vol, int freq, int e);

extern void NNS_SndWaveOutStop(struct NnsWaveOutSlot *slot);

extern u32 func_0209C2B0(u32 a, u32 b);

int CTVT_MIC_EncodeAdpcm(int unused, void *a, void *buf, unsigned n);

int CTVT_MIC_DecodeAdpcm(int unused, int a, void *buf, unsigned n);




int CTVT_MIC_PlayVoice(CtvtMic *mic, char *buf, unsigned n, int vol, int freq);

void CTVT_MIC_StopVoice(CtvtMic *mic);

u32 CTVT_MIC_GetPlayState(CtvtMic *mic);

int CTVT_MIC_GetLength(CtvtMic *mic);

int CTVT_MIC_GetPlayPos(CtvtMic *mic);

int CTVT_MIC_GetPlayRatio(CtvtMic *mic);

int CTVT_MIC_IsCaptureDone(CtvtMic *mic);

/*
 * Zero-fills a byte buffer, then runs CTVT_ADPCM_Encode over it.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_MIC_EncodeAdpcm(int unused, void *a, void *buf, unsigned n)
{
    MI_CpuFill8(buf, 0, n);
    return CTVT_ADPCM_Encode(a, n, buf);
}

int CTVT_MIC_DecodeAdpcm(int unused, int a, void *buf, unsigned n)
{
    func_02082A7C(0, buf, n << 2);
    return CTVT_ADPCM_Decode(a, (int)n, (int)buf);
}

void CTVT_MIC_InitChannel(CtvtMic *mic, u32 heap)
{
    struct NnsWaveOutSlot *v = (struct NnsWaveOutSlot *)NNS_SndWaveOutAllocChannel(7);

    mic->channel = v;
    if (v == 0) {
        func_02034714((void *)0x021C7224, 0, (void *)0x021C7224);
    }
    mic->playing = 0;
}

void CTVT_MIC_FreeChannel(CtvtMic *mic)
{
    NNSi_SndWaveOutUnlockChannel(mic->channel);
}

void CTVT_MIC_PostUpdate(CtvtMic *mic)
{
}

/*
 * Starts a sample on the channel at +0x20 when n > 0x20; records the handle and span.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_MIC_PlayVoice(CtvtMic *mic, char *buf, unsigned n, int vol, int freq)
{
    if (n > 0x20) {
        int r = NNS_SndWaveOutStart(mic->channel, 1, buf + 0x800, 0, 0, (int)(n >> 1), 0x1FF4, vol, freq, 0x40);
        mic->playing = r;
        mic->playPos = 0;
        mic->length = (int)n;
        mic->freq = freq;
        return r;
    }
    return 0;
}

void CTVT_MIC_StopVoice(CtvtMic *mic)
{
    mic->playing = 0;
    NNS_SndWaveOutStop(mic->channel);
}

u32 CTVT_MIC_GetPlayState(CtvtMic *mic)
{
    return mic->playing;
}

int CTVT_MIC_GetLength(CtvtMic *mic)
{
    return mic->length;
}

int CTVT_MIC_GetPlayPos(CtvtMic *mic)
{
    return (u16)mic->playPos;
}

int CTVT_MIC_GetPlayRatio(CtvtMic *mic)
{
    return (u16)func_0209C2B0(mic->length << 15, mic->freq * 0x10e);
}

/*
 * Test the byte at +0x10 against 0xb4, unsigned.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_MIC_IsCaptureDone(CtvtMic *mic)
{
    if (mic->captureTicks >= 0xb4) {
        return 1;
    }
    return 0;
}
