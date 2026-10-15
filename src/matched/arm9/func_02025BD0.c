/*
 * function: BMP_OAM_GetRecordParam
 * address: 0x02025BD0
 * packet: pkt_02025BD0
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   d_0209FA35 0x0209FA35 data
 */
typedef unsigned int u32;
extern const unsigned char d_0209FA35[];
u32 BMP_OAM_GetRecordParam(u32 i)
{
    if (i < 19)
        return d_0209FA35[i * 12];
    return 18;
}
