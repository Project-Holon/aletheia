/*
 * function: DSPi_PlayShutterSoundCore
 * address:  0x02706174
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
 *   SNDEXi_PreProcessForShutterSound  0x02704858  arm twl a2
 *   DSPi_PlaySoundEx  0x027060B4  arm twl a2
 *   OS_SpinWaitSysCycles  0x02087A04  arm
 *   OS_Sleep  0x02085A38  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct DspSys { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; } DspSys;
extern DspSys data_027344D8;
extern u32 SNDEXi_PreProcessForShutterSound(void);
extern void DSPi_PlaySoundEx(u8 *, u32, u32, int);
extern void OS_SpinWaitSysCycles(u32);
extern void OS_Sleep(u32);

#define RD32(p, o) ((p)[(o)] | ((p)[(o) + 1] << 8) | ((p)[(o) + 2] << 16) | ((p)[(o) + 3] << 24))

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
