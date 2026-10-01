/*
 * function: func_0219EAD8
 * address:  0x0219EAD8
 * packet:   pkt_ov021_0219EAD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: only residue is the order of the last ldrh/strh pair (the original loads s->h before storing w); tried per-field stores, struct copy, locals, an inline SetSize (swaps the two loads), an unrolled loop.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    u16 x, y, w, h;
} Rect;

typedef struct {
    u32 head;
    Rect r;
} Obj;

void func_0219EAD8(Obj *p, Rect *s)
{
    p->r = *s;
}
