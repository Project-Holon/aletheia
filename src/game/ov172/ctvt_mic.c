/*
 * file:     ctvt_mic.c
 * unit:     yes
 * function: func_021B9F9C, func_021BA01C, func_021BA050, func_021BA094, func_021BA098, func_021BA0BC, func_021BA114, func_021BA120, func_021BA158, func_021BA15C, func_021BA170, func_021BA174, func_021BA194, func_021BA1B4, func_021BA1D8, func_021BA1E4, func_021BA1E8, func_021BA234, func_021BA244, func_021BA248, func_021BA24C, func_021BA254, func_021BA270
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
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_021BA234 0x021BA234 thumb ov172
 *   func_021BA1E8 0x021BA1E8 thumb ov172
 *   func_021BA194 0x021BA194 thumb ov172
 *   func_021BA270 0x021BA270 thumb ov172
 *   func_021BA244 0x021BA244 thumb ov172
 *   func_021BA248 0x021BA248 thumb ov172
 *   func_021BA24C 0x021BA24C thumb ov172
 *   func_021BA254 0x021BA254 thumb ov172
 *   func_021BA174 0x021BA174 thumb ov172
 *   func_0208B24C 0x0208B24C arm
 *   func_0208B8B0 0x0208B8B0 arm
 *   func_0208BEF0 0x0208BEF0 arm
 *   func_0208BF54 0x0208BF54 arm
 *   func_021BA1B4 0x021BA1B4 thumb ov172
 *   func_02005654 0x02005654 thumb
 *   d_021C7218 0x021C7218 data a4
 *   d_021C720C 0x021C720C data a4
 *   g_021C88EC 0x021C88EC data a4
 *   func_0200566C  0x0200566C  thumb
 *   func_021BA1D8  0x021BA1D8  thumb  ov172
 *   func_0208B4B8 0x0208B4B8 arm
 *   NNS_SndWaveOutIsPlaying 0x02072CC4 arm
 *   func_021BA1E4 0x021BA1E4 thumb ov172
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
#include "../../matched/include/Obj04554.h"
#include "../../matched/include/Obj08260.h"
#include "../../matched/include/Obj05447.h"
#include "../../matched/include/Obj24096.h"
#include "../../matched/include/Obj04555.h"
#include "../../matched/include/Obj24097.h"
#include "../../matched/include/Obj24098.h"
#include "../../matched/include/Obj24099.h"
#include "../../matched/include/Obj14306.h"
#include "../../matched/include/Obj24100.h"
#include "draw_system_shared_types.h"

extern u32 func_020307B0(void *p);

struct O;

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

extern void func_021BA1B4(char *, u32);

extern int func_02005654(int, int);

extern void func_0200566C(void);

extern void func_021BA1D8(void *p);

extern void *func_0208B4B8(void);

extern int NNS_SndWaveOutIsPlaying(struct O *);

extern void func_021BA1E4(void *);

extern MICResult func_0208B500(MICAutoParam *);

extern int func_0208B528(void);

void *func_021B9F9C(u32 heap);

void SNDEXi_SetIirFilter(int, void *);

void func_021BA01C(char *p);

void func_021BA050(u32 *p);

void func_021BA094(int v);

void func_021BA098(void);

int func_021BA0BC(u32 *p);

void func_021BA114(MICResult result, void *arg);

int func_021BA120(u32 *p);

u32 func_021BA158(u32 *p);

u32 func_021BA15C(u32 *p);

u32 func_021BA170(u32 *p);

extern const char d_021C7218[], d_021C720C[];

extern void *g_021C88EC;

void *func_021B9F9C(u32 heap)
{
    u32 *p = func_02030734(heap, 36, 1, d_021C7218, 87);
    func_0208B24C();
    func_0208B8B0();
    func_0208BEF0(1);
    func_0208BF54(80);
    if (OS_IsRunOnTwl() == 1) SNDEXi_SetIirFilter(0, (void *)d_021C720C);
    func_021BA1B4((char *)p, heap);
    p[1] = (u32)GFL_NET_AllocAligned(heap, 51200, d_021C7218, 134);
    p[0] = 0;
    p[2] = 0;
    *((u8 *)p + 16) = 0;
    g_021C88EC = p;
    func_02005654((int)func_021BA098, 0);
    return p;
}

void func_021BA01C(char *p)
{
    func_0200566C();
    *(u32 *)0x021C88EC = 0;
    func_021BA120((u32 *)p);
    func_021BA1D8(p);
    func_0208BEF0(0);
    GFL_NET_FreeAligned(((struct Obj04554 *)p)->f4);
    func_020307B0(p);
}

void func_021BA050(u32 *p)
{
    u32 n;
    if (p[2] == 1) {
        n = (u32)func_0208B4B8();
        if (n == 0) p[0] = 0;
        else {
            p[0] = n - p[1] + 4;
            if (p[0] > 51200) p[0] = 51200;
        }
    }
    if (p[3] == 1) {
        if (NNS_SndWaveOutIsPlaying((struct O *)p[8]) == 0) p[3] = 0;
    }
    func_021BA1E4(p);
}

void func_021BA094(int v)
{
}

void func_021BA098(void)
{
    u8 *p = g_021C88EC;
    if (((struct Obj08260 *)p)->fC == 1) (((struct Obj08260 *)p)->f14)++;
    p = g_021C88EC;
    if (p[16] < 180) p[16]++;
}

/*
 * extent: Callback at 021BA114 stores zero at r1+8 and 51200 at r1.
 */
int func_021BA0BC(u32 *p)
{
    MICAutoParam param;
    param.type = 3;
    param.size = 51200;
    param.buffer = (void *)p[1];
    func_02082A7C(0, param.buffer, param.size);
    if (param.size & 31) param.size &= ~31;
    param.callback = func_021BA114;
    param.loop = 0;
    param.rate = 4097;
    param.arg = p;
    if (func_0208B500(&param) == 0) {
        p[2] = 1;
        p[0] = 0;
        return 1;
    }
    return 0;
}

void func_021BA114(MICResult result, void *arg)
{
    u32 *p = arg;
    p[2] = 0;
    p[0] = 51200;
}

int func_021BA120(u32 *p)
{
    if (p[2] == 0) return 1;
    if (func_0208B528() == 0) {
        p[0] = (u32)func_0208B4B8() - p[1] + 4;
        if (p[0] > 51200) p[0] = 51200;
        p[2] = 0;
        return 1;
    }
    return 0;
}

u32 func_021BA158(u32 *p) { return p[2]; }

u32 func_021BA15C(u32 *p)
{
    if (p[0] > 2048) return p[0] - 2048;
    return 0;
}

u32 func_021BA170(u32 *p) { return p[1]; }

typedef unsigned int   u32_021BA1B4;

typedef unsigned int   u32_021BA1D8;

typedef struct Slot02072BDC Slot02072BDC;

typedef unsigned int   u32_021BA244;

typedef unsigned int   u32_021BA254;

extern void MI_CpuFill8(void *p, int v, int n);

extern int CTVT_ADPCM_Encode(void *a0, unsigned a1, void *a2);

extern void func_02082A7C(int v, void *p, unsigned n);

extern int CTVT_ADPCM_Decode(int a, int b, int c);

extern int  NNS_SndWaveOutAllocChannel(int size);

extern void func_02034714(const char *expr, u32_021BA1B4 line, const char *file);

extern void NNSi_SndWaveOutUnlockChannel(u32_021BA1D8 *p);

extern int NNS_SndWaveOutStart(void *s, int fmt, void *data, int loop,
                         int start, int end, int rate, int vol, int freq, int e);

extern void NNS_SndWaveOutStop(Slot02072BDC *s);

extern u32_021BA254 func_0209C2B0(u32_021BA254 a, u32_021BA254 b);

int func_021BA174(int unused, void *a, void *buf, unsigned n);

int func_021BA194(int unused, int a, void *buf, unsigned n);

void func_021BA1B4(char *p, u32_021BA1B4 a1);

void func_021BA1D8(void *p);

void func_021BA1E4(void *a0);

int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq);

void func_021BA234(void *p);

u32_021BA244 func_021BA244(void *p);

int func_021BA248(void *p);

int func_021BA24C(void *p);

int func_021BA254(void *p);

int func_021BA270(void *p);

/*
 * Zero-fills a byte buffer, then runs CTVT_ADPCM_Encode over it.
 *
 * Addresses are Black-image addresses.
 */
int func_021BA174(int unused, void *a, void *buf, unsigned n)
{
    MI_CpuFill8(buf, 0, n);
    return CTVT_ADPCM_Encode(a, n, buf);
}

int func_021BA194(int unused, int a, void *buf, unsigned n)
{
    func_02082A7C(0, buf, n << 2);
    return CTVT_ADPCM_Decode(a, (int)n, (int)buf);
}

void func_021BA1B4(char *p, u32_021BA1B4 a1)
{
    u32_021BA1B4 v = NNS_SndWaveOutAllocChannel(7);

    ((struct Obj05447 *)p)->f20 = v;
    if (v == 0) {
        func_02034714((void *)0x021C7224, 0, (void *)0x021C7224);
    }
    ((struct Obj05447 *)p)->fC = 0;
}

void func_021BA1D8(void *p)
{
    NNSi_SndWaveOutUnlockChannel((u32_021BA1D8 *)((struct Obj24096 *)p)->f20);
}

void func_021BA1E4(void *a0)
{
}

/*
 * Starts a sample on the channel at +0x20 when n > 0x20; records the handle and span.
 *
 * Addresses are Black-image addresses.
 */
int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq)
{
    if (n > 0x20) {
        int r = NNS_SndWaveOutStart((void *)self[8], 1, buf + 0x800, 0, 0, (int)(n >> 1), 0x1FF4, vol, freq, 0x40);
        self[3] = r;
        self[5] = 0;
        self[6] = (int)n;
        self[7] = freq;
        return r;
    }
    return 0;
}

void func_021BA234(void *p)
{
    ((struct Obj04555 *)p)->fC = 0;
    NNS_SndWaveOutStop(*(Slot02072BDC * *)&((struct Obj04555 *)p)->f20);
}

u32_021BA244 func_021BA244(void *p)
{
    return ((struct Obj24097 *)p)->fC;
}

int func_021BA248(void *p)
{
    return ((struct Obj24098 *)p)->f18;
}

int func_021BA24C(void *p)
{
    return (u16)((struct Obj24099 *)p)->f14;
}

int func_021BA254(void *p)
{
    return (u16)func_0209C2B0(((struct Obj14306 *)p)->f18 << 15,
                              ((struct Obj14306 *)p)->f1C * 0x10e);
}

/*
 * Test the byte at +0x10 against 0xb4, unsigned.
 *
 * Addresses are Black-image addresses.
 */
int func_021BA270(void *p)
{
    if (((struct Obj24100 *)p)->f10 >= 0xb4) {
        return 1;
    }
    return 0;
}
