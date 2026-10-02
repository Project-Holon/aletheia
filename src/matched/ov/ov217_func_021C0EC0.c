/*
 * function: func_021C0EC0
 * address:  0x021C0EC0
 * packet:   pkt_ov217_021C0EC0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _u32_div_f  0x0209C0A4  arm

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct Ring {
    u32 *buf;
    u32 count;
    u32 pos;
};

u32 func_021C0EC0(struct Ring *r)
{
    u32 v;
    v = r->buf[r->pos];
    r->pos = (r->pos + 1) % r->count;
    return v;
}
