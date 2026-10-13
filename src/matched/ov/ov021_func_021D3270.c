/*
 * function: FLD_VREQ_SetMainBlendBrightnessExt
 * address:  0x021D3270
 * packet:   pkt_ov021_021D3270
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

typedef struct {
    u16 f0;
    u16 pad2;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Rec;

void FLD_VREQ_SetMainBlendBrightnessExt(Rec *p, int a, int b, int c, int d, int e)
{
    p->f0 = 4;
    p->f4 = a;
    p->f8 = b;
    p->fC = c;
    p->f10 = d;
    p->f14 = e;
}
