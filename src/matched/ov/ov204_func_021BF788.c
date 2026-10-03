/*
 * function: func_021BF788
 * address: 0x021BF788
 * packet: pkt_ov204_021BF788
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Cast the scaled modular address to a pointer before adding 12 to prevent index folding.
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void func_021BF788(u8 *p,int index)
{
    *(int *)((u8 *)((u32)p+(u32)index*12)+12)=0;
}
