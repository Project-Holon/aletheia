/*
 * function: WIFI_2DCHAR_SetupBmpCell
 * address: 0x021C3FDC
 * packet: pkt_ov127_021C3FDC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFI_2DCHAR_IsBmpCellEnabled 0x021C4358 thumb ov127
 *   WIFI_2DCHAR_GetCellIndex 0x021C4354 thumb ov127
 *   WIFI_2DCHAR_RegisterCell 0x021C435C thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int WIFI_2DCHAR_IsBmpCellEnabled(int, int);
extern int WIFI_2DCHAR_GetCellIndex(int);
extern void WIFI_2DCHAR_RegisterCell(char *p, int i, int a, int b, int c, int mode);
void WIFI_2DCHAR_SetupBmpCell(u8 *p, int a, int b, int c, int d)
{
    WIFI_2DCHAR_IsBmpCellEnabled(a,c);
    WIFI_2DCHAR_RegisterCell((char *)p,WIFI_2DCHAR_GetCellIndex(a),b,c,d,0);
}
