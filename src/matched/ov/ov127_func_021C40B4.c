/*
 * function: WIFI_2DCHAR_ReleaseBmp
 * address: 0x021C40B4
 * packet: pkt_ov127_021C40B4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_2DCHAR_ReleaseBmpHandles 0x021C4514 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
void WIFI_2DCHAR_ReleaseBmpHandles(char *p);
void WIFI_2DCHAR_ReleaseBmp(u8 *p)
{
    WIFI_2DCHAR_ReleaseBmpHandles((char *)p);
}
