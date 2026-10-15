/*
 * function: CTVT_COMM_SetConnectMac
 * address: 0x021B80EC
 * packet: pkt_ov172_021B80EC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
void CTVT_COMM_SetConnectMac(int unused, char *p, const u8 *src)
{
    u8 i;
    for (i = 0; i < 6; i++)
        p[0x17c + i] = src[i];
}
