/*
 * function: ZUKAN_DETAIL_FORM_SwapItems
 * address:  0x021C7D80
 * packet:   pkt_ov208_021C7D80
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Tri {
    u32 a;
    u32 b;
    u32 c;
};

struct Ov208Unit {
    u32 f0;
    u32 *f4;
    struct Ov208Tri e[5];
};

struct Ov208Battle {
    u32 pad0[3];
    struct Ov208Unit u[4];
    u8 pad11c[0x54e - 0x11c];
    u16 h54e;
    u16 h550;
};

void ZUKAN_DETAIL_FORM_SwapItems(void *unused, struct Ov208Battle *p)
{
    struct Ov208Tri t;
    struct Ov208Tri t2;
    u16 h;
    u32 w;
    u32 *q;
    u8 i;

    h = p->h54e;
    p->h54e = p->h550;
    p->h550 = h;
    w = p->u[0].f0;
    p->u[0].f0 = p->u[2].f0;
    p->u[2].f0 = w;
    q = p->u[0].f4;
    p->u[0].f4 = p->u[2].f4;
    p->u[2].f4 = q;
    if (p->u[0].f4 != 0)
        *p->u[0].f4 = 0;
    if (p->u[2].f4 != 0)
        *p->u[2].f4 = 2;
    w = p->u[1].f0;
    p->u[1].f0 = p->u[3].f0;
    p->u[3].f0 = w;
    q = p->u[1].f4;
    p->u[1].f4 = p->u[3].f4;
    p->u[3].f4 = q;
    if (p->u[1].f4 != 0)
        *p->u[1].f4 = 1;
    if (p->u[3].f4 != 0)
        *p->u[3].f4 = 3;
    for (i = 0; i < 5; i++) {
        t = p->u[0].e[i];
        p->u[0].e[i] = p->u[2].e[i];
        p->u[2].e[i] = t;
        t2 = p->u[1].e[i];
        p->u[1].e[i] = p->u[3].e[i];
        p->u[3].e[i] = t2;
    }
}
