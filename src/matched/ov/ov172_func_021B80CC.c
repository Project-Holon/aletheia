/*
 * function: func_021B80CC
 * address: 0x021B80CC
 * packet: pkt_ov172_021B80CC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned int u32;
u32 func_021B80CC(int unused, char *p)
{
    if (*(u32 *)(p + 8) == 12)
        return 1;
    return 0;
}
