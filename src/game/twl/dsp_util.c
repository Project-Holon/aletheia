/*
 * file:     dsp_util.c
 * unit:     yes
 * function: DSPiShutterPostProcessCallback, sound_handler, DSPi_PipeCallbackForSound, DSPi_PlaySoundEx, DSPi_PlayShutterSoundCore, DSPi_StopSoundCore, DSPi_IsShutterSoundPlayingCore
 * address:  0x02705F64
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libdsp.TWL.HYB.a dsp_util.o
 *
 * symbols:
 *   data_02732D78  0x02732D78  data twl a2
 *   SNDEXi_PostProcessForShutterSound  0x02704940  arm
 *   DSP_FindProcess  0x02705ED0  arm
 *   DSP_WriteProcessPipe  0x02705F28  arm
 *   DSP_SetPipeCallback  0x02706D28  arm
 *   DSP_LoadPipe  0x02706D44  arm
 *   DSP_ReadPipe  0x02706EC0  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Pipe control block of the DSP data RAM, 10 bytes. */
typedef struct DspRing {
    u16 base;
    u16 size;
    u16 rd;
    u16 wr;
    u16 id;
} DspRing;

typedef void (*DspCb)(void *, int, int);

/* 0x50 bytes: the OSAlarm at 0x027344FC (0x2C bytes) is the field at 0x24 and
   the object ends at data_02734528. */
typedef struct DspSys {
    u16 f0;
    u16 f2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 alarm[11];
} DspSys;

extern DspSys data_027344D8;
extern int data_02732D78;
extern void func_02088234(void);
extern void *DSP_FindProcess(int);
extern void DSP_WriteProcessPipe(void *, int, void *, u16);
extern u32 SNDEXi_PreProcessForShutterSound(void);
extern void SNDEXi_PostProcessForShutterSound(void (*cb)(u32), u32 v);
extern void DSP_SetPipeCallback(int i, DspCb a, void *b);
extern DspRing *DSP_LoadPipe(DspRing *out, int ch, int dir);
extern u16 DSP_GetPipeReadableSize(DspRing *r);
extern void DSP_ReadPipe(DspRing *r, u8 *buf, u16 count);
extern void func_02087254(void *alarm);
extern void func_0208738C(void *alarm, unsigned long long tick, void (*handler)(void), u32 arg);
extern void OS_SpinWaitSysCycles(u32);
extern void OS_Sleep(u32);

void DSPiShutterPostProcessCallback(u32 mode);
void sound_handler(void);
void DSPi_PipeCallbackForSound(void *a0, int port, int dir);
void DSPi_PlaySoundEx(u8 *a0, u32 a1, u32 a2, int a3);
u32 DSPi_PlayShutterSoundCore(u8 *p, u32 len);
void DSPi_StopSoundCore(void);
u32 DSPi_IsShutterSoundPlayingCore(void);

#define SWAP16(x) (((x) >> 16) | ((x) << 16))
#define RD32(p, o) ((p)[(o)] | ((p)[(o) + 1] << 8) | ((p)[(o) + 2] << 16) | ((p)[(o) + 3] << 24))

void DSPiShutterPostProcessCallback(u32 mode)
{
    if (mode == 3) {
        func_02088234();
    }
    if (mode != 0) {
        func_02088234();
    }
    data_027344D8.f14 = 0;
}

void sound_handler(void)
{
    data_027344D8.f18 = 0;
}

void DSPi_PipeCallbackForSound(void *a0, int port, int dir)
{
    DspRing pipe;
    u32 w[2];
    if (dir != 0) {
        return;
    }
    DSP_LoadPipe(&pipe, port, dir);
    if (DSP_GetPipeReadableSize(&pipe) < 8) {
        return;
    }
    DSP_ReadPipe(&pipe, (u8 *)w, 8);
    w[0] = (w[0] >> 16) | (w[0] << 16);
    w[1] = (w[1] >> 16) | (w[1] << 16);
    if ((w[0] & 0xF000) == 0x1000 && (w[0] & 0xF00) == 0x200) {
        u32 z = 0;
        func_02087254(&data_027344D8.alarm);
        func_0208738C(&data_027344D8.alarm, 0x3D5D, sound_handler, z);
        if (data_02732D78 == 0) {
            SNDEXi_PostProcessForShutterSound(DSPiShutterPostProcessCallback, z);
        }
        data_02732D78 = 0x20;
    }
    if ((w[0] & 0xF000) == 0x2000 && (w[0] & 0xF00) == 0x100) {
        data_027344D8.f0 = w[1];
    }
}

void DSPi_PlaySoundEx(u8 *a0, u32 a1, u32 a2, int a3)
{
    u32 msg[4];
    int zero = 0;
    void *h = DSP_FindProcess(zero);
    if (h == 0) {
        return;
    }
    if (data_02732D78 < a3) {
        return;
    }
    data_02732D78 = a3;
    DSP_SetPipeCallback(2, DSPi_PipeCallbackForSound, (void *)zero);
    data_027344D8.f18 = 1;
    msg[0] = SWAP16(a2 | 0x1100);
    msg[1] = SWAP16((u32)a0);
    msg[2] = SWAP16(a1 / 2);
    msg[3] = zero;
    DSP_WriteProcessPipe(h, 2, msg, 0x10);
}

u32 DSPi_PlayShutterSoundCore(u8 *p, u32 len)
{
    u32 v;
    u32 size;
    u32 mode;

    if (len < 0x2c) {
        return 0;
    }
    if (RD32(p, 0) != 0x46464952) {
        return 0;
    }
    if (RD32(p, 8) != 0x45564157) {
        return 0;
    }
    mode = data_027344D8.f4;
    v = RD32(p, 0x18);
    if ((mode == 0 && v != 0x7FDA) || (mode == 1 && v != 0xB9FA)) {
        return 0;
    }
    size = RD32(p, 0x28);
    if (len < size + 0x2c) {
        return 0;
    }
    OS_SpinWaitSysCycles(0x1EAB90);
    if (SNDEXi_PreProcessForShutterSound() != 0) {
        do {
            OS_Sleep(1);
        } while (SNDEXi_PreProcessForShutterSound() != 0);
    }
    DSPi_PlaySoundEx(p + 0x2c, size, 2, 0);
    data_027344D8.f14 = 1;
    return 1;
}

void DSPi_StopSoundCore(void)
{
    u32 msg[4];
    int zero = 0;
    void *h = DSP_FindProcess(zero);
    if (h == 0 || data_027344D8.f18 == 0) {
        return;
    }
    msg[0] = 0x12000000;
    msg[1] = zero;
    msg[2] = zero;
    msg[3] = zero;
    DSP_WriteProcessPipe(h, 2, msg, 0x10);
}

u32 DSPi_IsShutterSoundPlayingCore(void)
{
    return data_027344D8.f18 | data_027344D8.f14;
}
