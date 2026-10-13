/*
 * function: DSP_WriteProcessPipe
 * address:  0x02705F28
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * symbols:
 *   DSP_LoadPipe  0x02706D44  arm
 *   DSP_WritePipe  0x02706FCC  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct DSPPipe { u16 w[5]; } DSPPipe;
extern void DSP_LoadPipe(DSPPipe *pipe, int port, int dir);
extern void DSP_WritePipe(DSPPipe *pipe, void *buf, u32 len);

void DSP_WriteProcessPipe(u32 a0, int port, void *buf, u32 len)
{
    DSPPipe pipe;
    DSP_LoadPipe(&pipe, port, 1);
    DSP_WritePipe(&pipe, buf, (u16)len);
}
