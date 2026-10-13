/*
 * function: WIFICLUB_DrawPhaseIcon
 * address: 0x021BE4BC
 * packet: pkt_ov099_021BE4BC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BE4EA.
 * symbols:
 *   WIFICLUB_GetPhaseIconTile 0x021BE448 thumb ov099
 *   WIFICLUB_DrawTileBlock 0x021BE3CC thumb ov099
 */
extern int WIFICLUB_GetPhaseIconTile(unsigned int,int);
extern void WIFICLUB_DrawTileBlock(char *,int,int,int,int,int);
void WIFICLUB_DrawPhaseIcon(char *p,int a,int b,int c,int d,unsigned int e,int f) {
 int value;
 value=WIFICLUB_GetPhaseIconTile(e,d);
 WIFICLUB_DrawTileBlock(p,a,b,c,value+f,0);
}
