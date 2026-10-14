/*
 * function: GDS_SOCKET_SetSslTemplate
 * address: 0x021D8BC0
 * packet: pkt_ov125_021D8BC0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gGdsSslTemplatePtr 0x021DAA88 data a4
 *   gGdsSslTemplate 0x021DAAAC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 gGdsSslTemplatePtr;
extern u32 gGdsSslTemplate;
void GDS_SOCKET_SetSslTemplate(u32 value)
{
    if (value != 0) gGdsSslTemplatePtr = value;
    else gGdsSslTemplatePtr = (u32)&gGdsSslTemplate;
}
