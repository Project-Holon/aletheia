/*
 * function: DSPi_UnloadG711Core
 * address:  0x027072E0
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02735940  0x02735940  data twl a2
 *   data_0273594C  0x0273594C  data twl a2
 *   DSP_QuitProcess  0x02705E04  arm twl a2
 */

typedef unsigned int u32;

typedef struct {
    u32 pad0;
    u32 pad1;
    u32 ready;
} Fs;

extern Fs data_02735940;
extern u32 data_0273594C[];
extern void DSP_QuitProcess(u32 *a);

void DSPi_UnloadG711Core(void) {
    if (data_02735940.ready != 0) {
        DSP_QuitProcess(data_0273594C);
        data_02735940.ready = 0;
    }
}
