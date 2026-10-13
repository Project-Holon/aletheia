/*
 * function: DSP_SyncPipe
 * address:  0x02706DFC
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

extern DspRing *DSP_LoadPipe(DspRing *, int, int);

DspRing *DSP_SyncPipe(DspRing *r)
{
    return DSP_LoadPipe(r, (r->id & 0xFF) >> 1, r->id & 1);
}
