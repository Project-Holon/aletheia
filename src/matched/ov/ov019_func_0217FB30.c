/*
 * function: func_0217FB30
 * address:  0x0217FB30
 * packet:   pkt_ov019_0217FB30
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0217FA54  0x0217FA54  thumb  ov019
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct E { u32 a, b, c, d; u16 h; };
extern void func_0217FA54(u32 *p);

struct E *func_0217FB30(struct E *p)
{
    int i, best = 0;

    for (i = 0; i < 1; i++) {
        struct E *e = &p[i];
        if (e->d == 0) {
            return e;
        }
        if (e->h < p[best].h) {
            best = i;
        }
    }
    func_0217FA54((u32 *)(&p[best]));
    return &p[best];
}
