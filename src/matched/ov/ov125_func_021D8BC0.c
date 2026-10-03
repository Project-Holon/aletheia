/*
 * function: func_021D8BC0
 * address: 0x021D8BC0
 * packet: pkt_ov125_021D8BC0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021DAA88 0x021DAA88 data a4
 *   d_021DAAAC 0x021DAAAC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 d_021DAA88;
extern u32 d_021DAAAC;
void func_021D8BC0(u32 value)
{
    if (value != 0) d_021DAA88 = value;
    else d_021DAA88 = (u32)&d_021DAAAC;
}
