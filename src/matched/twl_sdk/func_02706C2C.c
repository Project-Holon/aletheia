/*
 * function: DSPi_PipeCallbackToConsole
 * address:  0x02706C2C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DSP_LoadPipe  0x02706D44  arm twl a2
 *   DSP_GetPipeReadableSize  0x02706E90  arm twl a2
 *   DSP_ReadPipe  0x02706EC0  arm twl a2
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct DspRing {
    u16 base;
    u16 size;
    u16 rd;
    u16 wr;
    u16 id;
} DspRing;

extern void DSP_LoadPipe(DspRing *, int, int);
extern u32 DSP_GetPipeReadableSize(DspRing *);
extern void DSP_ReadPipe(DspRing *, u16 *, u16);

void DSPi_PipeCallbackToConsole(void *a0, int a1, int a2)
{
    DspRing ring;
    u16 buf[0x40];
    u16 done;
    u16 n;
    int left;
    u32 total;

    if (a2 != 0) {
        return;
    }
    DSP_LoadPipe(&ring, a1, a2);
    total = DSP_GetPipeReadableSize(&ring);
    done = 0;
    if (total == 0) {
        return;
    }
    while (done < total) {
        left = total - done;
        if (left >= 0x80) {
            left = 0x80;
        }
        n = left;
        DSP_ReadPipe(&ring, buf, n);
        done = done + n;
    }
}
