/*
 * function: func_021C1828
 * address:  0x021C1828
 * packet:   pkt_ov093_021C1828
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The Rec build loads q[6] and q[0] first (ldrb, ldrh) only when both are
 * read into their own locals (c6 before a0), assigned after the second
 * func_021D5440 call; reading them straight into the fields interleaves
 * loads and stores.
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6848  0x021D6848  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Rec { u16 a; u16 b; u8 c; u8 d; u8 e; };

extern u8 func_021D5440(u8 *p);
extern void func_021D6848(u8 *c, struct Rec *r);
extern void func_021CD4B0(void *w, volatile u32 id, ...);

void func_021C1828(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w)
{
    struct Rec r;
    u8 c6;
    u16 a0;
    u8 n = func_021D5440(x);
    u8 m = func_021D5440(c);
    c6 = q[6];
    a0 = *(u16 *)q;
    r.a = a0;
    r.b = w;
    r.c = c6;
    r.d = n;
    r.e = b;
    func_021D6848(c, &r);
    func_021CD4B0(*(void **)(p + 0xc), 0x2d, m, n, b, q[6], *(u16 *)q, w);
}
