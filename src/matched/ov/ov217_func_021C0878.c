/*
 * function: func_021C0878
 * address:  0x021C0878
 * packet:   pkt_ov217_021C0878
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C3A28  0x021C3A28  data  a4
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Ent {
    u32 a;
    u32 b;
    u8 c;
    u8 pad[11];
};

extern const struct Ent d_021C3A28[];
extern void func_021C29E8(int obj, u32 a, u32 b, u8 c);

void func_021C0878(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C29E8(*(int *)(p + i * 4 + 0x324), d_021C3A28[i].a, d_021C3A28[i].b, d_021C3A28[i].c);
}
