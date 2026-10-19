/*
 * file:     dsp_g711.c
 * unit:     yes
 * function: DSPi_OpenStaticComponentG711Core, DSPi_LoadG711Core, DSPi_UnloadG711Core
 * address:  0x0270723C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libdsp_g711.TWL.HYB.a dsp_g711.o
 *
 * symbols:
 *   data_02707CB4  0x02707CB4  data twl a4
 *   data_02735940  0x02735940  data twl a4
 *   data_0273594C  0x0273594C  data twl a4
 *   DSP_InitProcessContext  0x027058D8  arm
 *   DSP_QuitProcess  0x02705E04  arm
 *   @38  0x02732D7C  data twl a1
 */
#include "../types.h"

typedef struct {
    u32 pad0;
    u32 pad1;
    u32 ready;
} Fs;

extern u32 data_02707CB4[];
extern Fs data_02735940;
extern u32 data_0273594C[];
extern int FS_IsAvailable(void);
extern void FS_Init(u32 a);
extern void FS_InitFile(u32 *file);
extern u32 FS_CreateFileFromMemory(u32 *file, void *addr, u32 size);
struct DspProc;
extern void DSP_InitProcessContext(struct DspProc *o, void *src);
extern u32 DSP_ExecuteProcess(u32 *a, u32 b, u32 c, u32 d);
extern void DSP_QuitProcess(struct DspProc *proc);

void DSPi_OpenStaticComponentG711Core(u32 *file);
u32 DSPi_LoadG711Core(u32 a, u32 b, u32 c);
void DSPi_UnloadG711Core(void);

void DSPi_OpenStaticComponentG711Core(u32 *file) {
    if (FS_IsAvailable() == 0) {
        FS_Init(-1);
    }
    FS_InitFile(file);
    FS_CreateFileFromMemory(file, data_02707CB4 /* start of the embedded data blob 0x02707CB4..0x0272E9E8 */, 0x1000000);
}

u32 DSPi_LoadG711Core(u32 file, u32 bankMaskA, u32 bankMaskB) {
    if (data_02735940.ready == 0) {
        DSP_InitProcessContext((struct DspProc *)data_0273594C, "g711");
        if (DSP_ExecuteProcess(data_0273594C, file, bankMaskA, bankMaskB) != 0) {
            data_02735940.ready = 1;
        }
    }
    return data_02735940.ready;
}

void DSPi_UnloadG711Core(void) {
    if (data_02735940.ready != 0) {
        DSP_QuitProcess((struct DspProc *)data_0273594C);
        data_02735940.ready = 0;
    }
}
