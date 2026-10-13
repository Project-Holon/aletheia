/*
 * function: DSP_SetPipeCallback
 * address:  0x02706D28
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02734534  0x02734534  data twl a2
 *   data_02734554  0x02734554  data twl a2
 */

typedef void (*DspCb)(void *, int, int);

extern DspCb data_02734534[8];
extern void *data_02734554[8];

void DSP_SetPipeCallback(int i, DspCb a, void *b)
{
    data_02734534[i] = a;
    data_02734554[i] = b;
}
