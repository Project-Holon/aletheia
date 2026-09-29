/*
 * function: func_021B9238
 * address:  0x021B9238
 * packet:   pkt_ov021_021B9238
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021B97D0  0x021B97D0  thumb  ov021
 *   func_021B97FC  0x021B97FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a; u8 t; u8 c; u16 e; u16 d; } Out;
typedef struct { u16 t; u16 pad; void *p4; int p8; int pc; int p10; int p14; int p18; int p1c; u32 p20; void *p24; } In;

int func_021B97D0(void *a, void *b);
int func_021B97FC(void *a, void *b);

void func_021B9238(const In *p, Out *out)
{
    int v;
    u32 t;

    t = p->t;
    out->t = t;
    if (t == 0)
        v = func_021B97D0(p->p24, p->p4);
    else
        v = func_021B97FC(p->p24, p->p4);
    out->a = v;
    out->d = p->pc / 16;
    out->e = p->p14 / 16;
    out->c = p->p20;
}
