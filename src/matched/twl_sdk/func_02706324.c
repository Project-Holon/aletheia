/*
 * function: DSPi_IsShutterSoundPlayingCore
 * address:  0x02706324
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Function with no listing label.
 *
 * symbols:
 *   data_027344D8  0x027344D8  data twl a2
 */
typedef unsigned int u32;
typedef struct DspSys { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; } DspSys;
extern DspSys data_027344D8;

u32 DSPi_IsShutterSoundPlayingCore(void)
{
    return data_027344D8.f18 | data_027344D8.f14;
}
