/*
 * function: DSP_InitPipe
 * address:  0x02706CD4
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02734528  0x02734528  data twl a2
 *   data_02734534  0x02734534  data twl a2
 *   data_02734554  0x02734554  data twl a2
 *   DSPi_PipeCallbackToConsole  0x02706C2C  arm twl a2
 */

typedef unsigned int u32;

typedef void (*DspCb)(void *, int, int);

typedef struct DspIoState {
    void *f0;
    u32 f4;
    u32 f8;
    DspCb callback;
} DspIoState;

extern DspIoState data_02734528;
extern DspCb data_02734534[8];
extern void *data_02734554[8];
extern void DSPi_PipeCallbackToConsole(void *, int, int);

void DSP_InitPipe(void)
{
    int i;

    data_02734528.f0 = 0;
    data_02734528.f8 = 0;
    data_02734528.f4 = 0;
    for (i = 0; i < 8; i++) {
        data_02734534[i] = 0;
        data_02734554[i] = 0;
    }
    data_02734528.callback = DSPi_PipeCallbackToConsole;
}
