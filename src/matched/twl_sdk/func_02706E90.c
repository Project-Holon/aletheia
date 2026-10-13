/*
 * function: DSP_GetPipeReadableSize
 * address:  0x02706E90
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
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

u16 DSP_GetPipeReadableSize(DspRing *r)
{
    int t = r->rd ^ r->wr;
    int d;

    if (t < 0x8000) {
        t = 0;
    } else {
        t = r->size;
    }
    d = r->wr - r->rd;
    return (d + t) & ~0x8000;
}
