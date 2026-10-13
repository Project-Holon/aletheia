/*
 * function: DSPi_LoadG711Core
 * address:  0x02707278
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02735940  0x02735940  data twl a4
 *   data_0273594C  0x0273594C  data twl a4
 *   DSP_InitProcessContext  0x027058D8  arm
 *   @19  0x02732D7C  data twl a1
 */

typedef unsigned int u32;

typedef struct {
    u32 pad0;
    u32 pad1;
    u32 ready;
} Fs;

extern Fs data_02735940;
extern u32 data_0273594C[];
extern void DSP_InitProcessContext(u32 *a, const char *b);
extern u32 DSP_ExecuteProcess(u32 *a, u32 b, u32 c, u32 d);

u32 DSPi_LoadG711Core(u32 a, u32 b, u32 c) {
    if (data_02735940.ready == 0) {
        DSP_InitProcessContext(data_0273594C, "g711");
        if (DSP_ExecuteProcess(data_0273594C, a, b, c) != 0) {
            data_02735940.ready = 1;
        }
    }
    return data_02735940.ready;
}
