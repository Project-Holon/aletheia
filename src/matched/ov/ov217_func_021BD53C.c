/*
 * function: func_021BD53C
 * address:  0x021BD53C
 * packet:   pkt_ov217_021BD53C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *   d_021C3260 0x021C3260 data a4
 *
 * Addresses are Black-image addresses.
 */

struct Entry021C3260 {
    int a;
    int b;
    unsigned char c;
    unsigned char pad[11];
};

extern const struct Entry021C3260 d_021C3260[];
typedef unsigned int   u32;
extern void func_021C29E8(void *p, u32 b, u32 c, u32 d);

void func_021BD53C(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C29E8((void *)p[i + 0x27], d_021C3260[i].a, d_021C3260[i].b, d_021C3260[i].c);
}
