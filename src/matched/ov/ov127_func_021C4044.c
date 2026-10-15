/*
 * function: WIFI_2DCHAR_SetupCells
 * address: 0x021C4044
 * packet: pkt_ov127_021C4044
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFI_2DCHAR_RegisterPalette 0x021C4564 thumb ov127
 *   WIFI_2DCHAR_RegisterBmpAnims 0x021C45AC thumb ov127
 *   WIFI_2DCHAR_RegisterCell 0x021C435C thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void WIFI_2DCHAR_RegisterPalette(u8 *p, u32 a, u32 b, u32 heap);
extern void WIFI_2DCHAR_RegisterBmpAnims(u8 *p, u32 heap);
extern void WIFI_2DCHAR_RegisterCell(char *p, int i, int a, int b, int c, int mode);
void WIFI_2DCHAR_SetupCells(u8 *p,int a,int b,int c,int d)
{
    int i;
    WIFI_2DCHAR_RegisterPalette(p,a,c,d);
    WIFI_2DCHAR_RegisterBmpAnims(p,d);
    for(i=0;i<16;i++)WIFI_2DCHAR_RegisterCell((char *)p,i,a,b,d,1);
}
