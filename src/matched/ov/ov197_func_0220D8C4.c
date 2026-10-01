/*
 * function: func_0220D8C4
 * address: 0x0220D8C4
 * packet: pkt_ov197_0220D8C4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   func_02025D24 0x02025D24 thumb
 *   func_0220D98C 0x0220D98C thumb ov197
 *   d_0220DF90 0x0220DF90 data a4
 *   d_0220DF9C 0x0220DF9C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Struct_02025CD0;
struct Struct_02025D1C;
struct Struct_02025D24;
extern struct Struct_02025CD0 *func_02025CD0(u32, u32, u32, u32, u8, u16);
extern void func_02025D1C(struct Struct_02025D1C *);
extern void func_02025D24(struct Struct_02025D24 *);
extern void func_0220D98C(u8 *, u32);
extern const u32 d_0220DF90[], d_0220DF9C[];
void func_0220D8C4(u8 *p, u32 index, u32 value)
{
    *(struct Struct_02025CD0 **)(p + 0x144) = func_02025CD0(d_0220DF9C[index], d_0220DF90[index], (u32)p, *(u32 *)(p + 0x598), (u8)value, *(u16 *)(*(u8 **)p + 0xc));
    func_02025D1C(*(struct Struct_02025D1C **)(p + 0x144));
    func_02025D24(*(struct Struct_02025D24 **)(p + 0x144));
    func_0220D98C(p, value);
}
