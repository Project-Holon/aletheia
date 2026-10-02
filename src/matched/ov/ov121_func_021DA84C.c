/*
 * function: func_021DA84C
 * address: 0x021DA84C
 * packet: pkt_ov121_021DA84C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: sole overlay blocker of func_021D6E3C.
 */
typedef unsigned char u8;
typedef unsigned int u32;
void func_021DA84C(u8 *p,u32 i,u32 value)
{
    *(u32 *)(p+i*4+76)=value;
}
