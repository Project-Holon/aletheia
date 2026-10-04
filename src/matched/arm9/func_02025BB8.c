/*
 * function: func_02025BB8
 * address: 0x02025BB8
 * packet: pkt_02025BB8
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0209FA34 0x0209FA34 data
 */
typedef unsigned int u32;
extern const unsigned char d_0209FA34[];
u32 func_02025BB8(u32 i)
{
    if (i < 19)
        return d_0209FA34[i * 12];
    return 0;
}
