/*
 * function: DSPi_WaitForPipe
 * address:  0x02706CB4
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_0273452C  0x0273452C  data twl a2
 *   DSP_SyncPipe  0x02706DFC  arm twl a2
 *   OS_SleepThread  0x020857B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct DspRing {
    u16 base;
    u16 size;
    u16 rd;
    u16 wr;
    u16 id;
} DspRing;

extern u32 data_0273452C;
extern void OS_SleepThread(void *);
extern DspRing *DSP_SyncPipe(DspRing *);

static void DSPi_WaitForPipe(DspRing *r)
{
    OS_SleepThread(&data_0273452C);
    DSP_SyncPipe(r);
}
