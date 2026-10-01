/*
 * function: func_021DBF2C
 * address: 0x021DBF2C
 * packet: pkt_ov131_021DBF2C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DC2F8 0x021DC2F8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry { u32 a; u16 b, c, d, e; u8 f; u8 pad[3]; };
extern const struct Entry d_021DC2F8[];
u32 func_021DBF2C(u32 i, u32 field)
{
    switch (field) {
    case 0: return d_021DC2F8[i].a;
    case 1: return d_021DC2F8[i].b;
    case 2: return d_021DC2F8[i].c;
    case 3: return d_021DC2F8[i].d;
    case 4: return d_021DC2F8[i].e;
    case 5: return d_021DC2F8[i].f;
    default: return 0;
    }
}
