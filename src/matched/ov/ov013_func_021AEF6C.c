/*
 * function: VCT_MAIN_Start
 * address:  0x021AEF6C
 * packet:   pkt_ov013_021AEF6C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Start the microphone module: allocate the 0x1A4C-byte work block (G)
 * and its sample buffer on first use, fill the auto-sampling parameter
 * block at G+0x1A20, open the sound channel at G+0x19B8 with
 * VCT_MAIN_StreamCallback as its callback, then start the worker from a 0x20-byte
 * parameter block on the stack (callback VCT_MAIN_OnEventGroup in state 3,
 * VCT_MAIN_OnEventPair otherwise).
 *
 * symbols:
 *   gVctWork     0x021B3C80  data  ov013
 *   DWC_RAPCOMMON_Alloc  0x02156F5C  thumb  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   VCT_MAIN_InitAudio  0x021AEB20  thumb  ov013
 *   func_0202EB0C  0x0202EB0C  thumb
 *   NNS_SndStrmAllocChannel  0x02073838  arm
 *   NNS_SndStrmSetVolume  0x02073AD0  arm
 *   NNS_SndStrmSetup  0x020738C0  arm
 *   VCT_MAIN_StreamCallback  0x021AEB7C  thumb  ov013
 *   func_02034714  0x02034714  arm
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 *   VCT_MAIN_OnEventGroup  0x021AED08  thumb  ov013
 *   VCT_MAIN_OnEventPair  0x021AED30  thumb  ov013
 *   VCT_Init  0x021B370C  arm  ov013
 *   VCT_SESSION_SetCodecMode  0x021B0C64  arm  ov013
 *   VCT_MAIN_StartStream  0x021AF124  thumb  ov013
 *   VCT_SESSION_SetFilterEnabled  0x021B0D08  arm  ov013
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct WorkerParam {
    void *state;
    int mode;
    int one;
    u8 kind;
    void *buf;
    u32 size;
    void (*cb)(void);
    int zero;
} WorkerParam;

typedef struct MicAutoParam {
    int type;
    void *buffer;
    u32 size;
    u32 rate;
    int loop;
    void *callback;
    void *arg;
} MicAutoParam;

typedef struct Work {
    u8 ring[0x880];
    void *f880;
    u8 f884[0x1984 - 0x884];
    int f1984;
    u8 f1988[0x19A8 - 0x1988];
    int f19A8;
    int f19AC;
    u16 f19B0;
    u8 pad19B2[0x19B8 - 0x19B2];
    u8 f19B8[0x1A1C - 0x19B8];
    int f1A1C;
    MicAutoParam mic;
    u8 pad1A3C[0x1A4B - 0x1A3C];
    u8 f1A4B;
} Work;

extern Work *gVctWork;

extern u32 DWC_RAPCOMMON_Alloc(u32 a, u32 b, u32 c);
extern void MI_CpuFill8(void *p, int v, u32 n);
extern void VCT_MAIN_InitAudio(void);
extern u32 func_0202EB0C(void);
extern int NNS_SndStrmAllocChannel(u8 *o, int n, u8 *src);
typedef signed int     s32;
struct Slot;
extern void NNS_SndStrmSetVolume(struct Slot *s, s32 v);
extern int NNS_SndStrmSetup(void *ch, int fmt, void *buf, u32 len, int rate,
                         int x, void (*cb)(void), void *arg);
extern void VCT_MAIN_StreamCallback(int mode, u32 n, void **bufs, u32 size, int unused, u32 arg6);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u8 DWC_GetMyAID(void);
extern void VCT_MAIN_OnEventGroup(int unused, int code, void *p);
extern void VCT_MAIN_OnEventPair(int a, int code, u32 *p);
extern void VCT_Init(WorkerParam *p);
extern int VCT_SESSION_SetCodecMode(int x);
extern void VCT_MAIN_StartStream(void);
extern void VCT_SESSION_SetFilterEnabled(int x);

void VCT_MAIN_Start(void *heap, int arg1, int mode)
{
    WorkerParam param;
    u8 vals[3] = {0, 0, 0};

    if (gVctWork == 0) {
        gVctWork = (Work *)DWC_RAPCOMMON_Alloc((u32)heap, sizeof(Work), 0x20);
        MI_CpuFill8(gVctWork, 0, sizeof(Work));
        gVctWork->f880 = (void *)DWC_RAPCOMMON_Alloc((u32)heap, mode * 0x23C0 + 0x20, 0x20);
        gVctWork->f1984 = 0;
        VCT_MAIN_InitAudio();
    }
    gVctWork->mic.type = 3;
    gVctWork->mic.buffer = gVctWork;
    gVctWork->mic.size = 0x880;
    if (func_0202EB0C() == 0) {
        gVctWork->mic.rate = 0x1040;
    } else {
        gVctWork->mic.rate = 0x1001;
    }
    gVctWork->mic.loop = 1;
    gVctWork->mic.callback = 0;
    gVctWork->mic.arg = 0;
    gVctWork->f1A4B = 1;
    NNS_SndStrmAllocChannel(gVctWork->f19B8, 1, vals);
    NNS_SndStrmSetVolume((struct Slot *)gVctWork->f19B8, 0);
    if (NNS_SndStrmSetup(gVctWork->f19B8, 1, gVctWork->f884, 0x880,
                      func_0202EB0C() ? 0x40 : 0x41, 2, (void (*)(void))VCT_MAIN_StreamCallback,
                      gVctWork) == 0) {
        func_02034714((void *)0x021B3C20, 0, (void *)0x021B3C20);
    }
    gVctWork->f19AC = 0;
    gVctWork->f1A1C = 0;
    gVctWork->f19A8 = param.one = 1;
    param.state = gVctWork->f1988;
    param.mode = mode;
    param.kind = DWC_GetMyAID();
    if (param.kind == -1) {
        func_02034714((void *)0x021B3C20, 0, (void *)0x021B3C20);
    }
    if (gVctWork->f19A8 == 3) {
        param.cb = (void (*)(void))VCT_MAIN_OnEventGroup;
    } else {
        param.cb = (void (*)(void))VCT_MAIN_OnEventPair;
    }
    param.zero = 0;
    param.buf = gVctWork->f880;
    param.size = mode * 0x23C0 + 0x20;
    VCT_Init(&param);
    gVctWork->f19B0 = 0;
    VCT_SESSION_SetCodecMode(arg1);
    VCT_MAIN_StartStream();
    VCT_SESSION_SetFilterEnabled(1);
}
