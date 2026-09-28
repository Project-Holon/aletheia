/*
 * function: func_021C9D70
 * address:  0x021C9D70
 * packet:   pkt_ov021_021C9D70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Commits the +0xe counter for the current kind and redraws.
 *
 * symbols:
 *   func_0200DB08  0x0200DB08  thumb
 *   func_0200DAEC  0x0200DAEC  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_021CA2DC  0x021CA2DC  thumb
 *   func_0200DB1C  0x0200DB1C  thumb
 *   func_0200DA14  0x0200DA14  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0200DB08(u32 h, u8 kind, u16 v);
extern void func_0200DAEC(u32 h, u8 kind, u16 v);
extern u32 func_02012EBC(u32 a);
extern void func_021CA2DC(u8 *p, u32 h, int flag, u16 v);
extern void func_0200DB1C(u32 h, u8 v);
extern void func_0200DA14(u32 h);

void func_021C9D70(u32 unused, u8 *p)
{
    u16 v = *(u16 *)(p + 0xe);
    u8 kind = p[9];
    u32 h = *(u32 *)(p + 0x74);

    func_0200DB08(h, kind, v);
    func_0200DAEC(h, kind, v);
    func_021CA2DC(p, func_02012EBC(*(u32 *)(p + 0x6c)), 1, v);
    func_0200DB1C(*(u32 *)(p + 0x74), kind);
    func_0200DA14(*(u32 *)(p + 0x70));
}
