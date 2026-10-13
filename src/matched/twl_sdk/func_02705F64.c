/*
 * function: DSPiShutterPostProcessCallback
 * address:  0x02705F64
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
 *   OS_Terminate  0x02088234  arm  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct DspSt { u16 f0; u16 pad; u32 pad1[4]; u32 f14; u32 f18; } DspSt;
extern DspSt DAT_027344D8;
extern void OS_Terminate(void);

void DSPiShutterPostProcessCallback(u32 mode)
{
    if (mode == 3) {
        OS_Terminate();
    }
    if (mode != 0) {
        OS_Terminate();
    }
    DAT_027344D8.f14 = 0;
}
