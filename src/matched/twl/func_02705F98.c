/*
 * function: sound_handler
 * address:  0x02705F98
 * packet:   pkt_02705F98
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Alarm handler of DSPi_PipeCallbackForSound (hidden function in the pool gap after
 *  * DSPiShutterPostProcessCallback): clears a word of the DSP state block.
 *
 * symbols:
 *   DAT_027344D8   0x027344D8  data twl
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct DspSt { u16 f0; u16 pad; u32 pad1[4]; u32 f14; u32 f18; } DspSt;
extern DspSt DAT_027344D8;

void sound_handler(void)
{
    DAT_027344D8.f18 = 0;
}
