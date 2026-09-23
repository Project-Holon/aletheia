/*
 * function: func_02027460
 * address:  0x02027460
 * packet:   pkt_02027460
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies four halfwords into the console's own beacon record (+4 of the
 * block): two BITFIELDS of the u16 at rec+0x48 (bits 8..10 and 11..15,
 * masks 0xF8FF / 0x07FF, the low byte being the one func_0202744C sets),
 * then rec+0x4a and rec+0x4c.  The caller func_020274B4 passes &own in r0
 * but this body ignores it and recomputes; the two-step `adds r,r0,#4;
 * adds r,#0x48` at every access is a pointer local `o = &g->own`, not a
 * held `g` (which folds to one `adds #0x4c`).
 * Unlabelled leaf (no lr save): the integrator should seed 0x02027460.
 *
 * symbols:
 *   g_GameBeacon  0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u8  pad[0x48];
    u16 lo : 8;
    u16 a  : 3;
    u16 b  : 5;
    u16 f4a;
    u16 f4c;
    u8  pad4e[0x60 - 0x4e];
};
struct Blk { u32 f00; struct Rec own; };
struct Src { u16 a; u16 b; u16 c; u16 d; };

extern struct Blk *g_GameBeacon;

void func_02027460(void *p, const struct Src *s)
{
    struct Rec *o = &g_GameBeacon->own;

    o->a = s->a;
    o->b = s->b;
    o->f4a = s->c;
    o->f4c = s->d;
}
