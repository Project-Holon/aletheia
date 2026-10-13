/*
 * function: DSPi_StopSoundCore
 * address:  0x027062C8
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_027344D8  0x027344D8  data twl a2
 *   DSP_FindProcess  0x02705ED0  arm twl a2
 *   DSP_WriteProcessPipe  0x02705F28  arm twl a2
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct DspSys { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; } DspSys;
extern DspSys data_027344D8;
extern void *DSP_FindProcess(int);
extern void DSP_WriteProcessPipe(void *, int, void *, u16);

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
