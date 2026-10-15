/*
 * function: WIFI_2DCHAR_ReleaseBmpCells
 * address: 0x021C4080
 * packet: pkt_ov127_021C4080
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_2DCHAR_ReleasePalette 0x021C4594 thumb ov127
 *   WIFI_2DCHAR_ReleaseBmpAnims 0x021C45E0 thumb ov127
 *   WIFI_2DCHAR_ReleaseCell 0x021C4424 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void WIFI_2DCHAR_ReleasePalette(u8 *);
extern void WIFI_2DCHAR_ReleaseBmpAnims(u8 *);
extern void WIFI_2DCHAR_ReleaseCell(char *, int);
void WIFI_2DCHAR_ReleaseBmpCells(u8 *p)
{
    int i;
    WIFI_2DCHAR_ReleasePalette(p);
    WIFI_2DCHAR_ReleaseBmpAnims(p);
    for (i=0; i<16; i++) WIFI_2DCHAR_ReleaseCell((char *)p, i);
}
