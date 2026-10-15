/*
 * function: DSPi_PipeCallbackForSound
 * address:  0x02705FAC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_027344D8   0x027344D8  data twl
 *   DAT_027344FC   0x027344FC  data twl
 *   SNDEXi_PostProcessForShutterSound  0x02704940  arm
 *   DSPiShutterPostProcessCallback  0x02705F64  arm
 *   sound_handler  0x02705F98  arm
 *   DSP_LoadPipe  0x02706D44  arm
 *   DSP_ReadPipe  0x02706EC0  arm
 *   OS_CreateAlarm  0x02087254  arm  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct DSPPipe { u16 w[5]; } DSPPipe;
typedef struct DspSt { u16 f0; u16 pad; u32 pad1[4]; u32 f14; u32 f18; } DspSt;
extern DspSt DAT_027344D8;
extern u32 DAT_027344FC;
#define DAT_02732D78 (*(u32 *)0x02732D78)
extern void DSPiShutterPostProcessCallback(u32 mode);
extern void sound_handler(void);
extern void DSP_LoadPipe(DSPPipe *pipe, int port, int dir);
extern u32 DSP_GetPipeReadableSize(DSPPipe *pipe);
extern void DSP_ReadPipe(DSPPipe *pipe, void *buf, u32 len);
extern void OS_CreateAlarm(void *alarm);
extern void func_0208738C(void *alarm, unsigned long long tick, void (*handler)(void), u32 arg);
extern void SNDEXi_PostProcessForShutterSound(void (*cb)(u32), u32 v);

void DSPi_PipeCallbackForSound(u32 a0, int port, int dir)
{
    DSPPipe pipe;
    u32 w[2];
    if (dir != 0) {
        return;
    }
    DSP_LoadPipe(&pipe, port, dir);
    if (DSP_GetPipeReadableSize(&pipe) < 8) {
        return;
    }
    DSP_ReadPipe(&pipe, w, 8);
    w[0] = (w[0] >> 16) | (w[0] << 16);
    w[1] = (w[1] >> 16) | (w[1] << 16);
    if ((w[0] & 0xF000) == 0x1000 && (w[0] & 0xF00) == 0x200) {
        u32 z = 0;
        OS_CreateAlarm(&DAT_027344FC);
        func_0208738C(&DAT_027344FC, 0x3D5D, sound_handler, z);
        if (DAT_02732D78 == 0) {
            SNDEXi_PostProcessForShutterSound(DSPiShutterPostProcessCallback, z);
        }
        DAT_02732D78 = 0x20;
    }
    if ((w[0] & 0xF000) == 0x2000 && (w[0] & 0xF00) == 0x100) {
        DAT_027344D8.f0 = w[1];
    }
}
