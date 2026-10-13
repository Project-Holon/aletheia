/*
 * function: WIFICLUB_UpdateVchatIndicator
 * address: 0x021BFBBC
 * packet: pkt_ov099_021BFBBC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_RAP_GetVchatState 0x02156B68 thumb ov009
 *   WIFICLUB_DrawTileBlock 0x021BE3CC thumb ov099
 */
extern int DWC_RAP_GetVchatState(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WIFICLUB_DrawTileBlock(char *p, int a, u8 b, u8 c, u32 d, int e);
void WIFICLUB_UpdateVchatIndicator(char *p)
{
    if (DWC_RAP_GetVchatState(p)) {
        WIFICLUB_DrawTileBlock(p + 0x898, 1, 2, 1, 0x3c, 0);
    } else {
        WIFICLUB_DrawTileBlock(p + 0x898, 1, 2, 1, 0x33, 0);
    }
}
