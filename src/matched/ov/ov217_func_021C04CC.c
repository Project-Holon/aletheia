/*
 * function: func_021C04CC
 * address:  0x021C04CC
 * packet:   pkt_ov217_021C04CC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C37A4  0x021C37A4  data  a4
 *   func_02043678  0x02043678  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ent {
    u32 a;
    u32 b;
    u32 c;
    u32 pad[8];
};

extern const struct Ent d_021C37A4[];
extern int func_02043678(u32 a, u32 b, u32 c, u16 heap);

void func_021C04CC(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(int *)(p + i * 4 + 0x3B0) = func_02043678(d_021C37A4[i].a, d_021C37A4[i].b, d_021C37A4[i].c, *(u16 *)(p + 4));
}
