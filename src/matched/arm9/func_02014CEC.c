/*
 * function: func_02014CEC
 * address: 0x02014CEC
 * packet: pkt_02014CEC
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
void func_02014CEC(u8 *p, u32 value)
{
    *(u32 *)(p + 8) = value;
}
