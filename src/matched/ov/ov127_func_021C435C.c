/*
 * function: WIFI_2DCHAR_RegisterCell
 * address: 0x021C435C
 * packet: pkt_ov127_021C435C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   WIFI_2DCHAR_RegisterBmpCharCell 0x021C4380 thumb ov127
 *   WIFI_2DCHAR_RegisterCharCell 0x021C43E4 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void WIFI_2DCHAR_RegisterBmpCharCell(char *,int,u32,u32,u32);
extern void WIFI_2DCHAR_RegisterCharCell(u8 *p, int i, u32 a, u32 b, u32 c);
void WIFI_2DCHAR_RegisterCell(char *p, int i, int a, int b, int c, int mode) { if(mode==0) WIFI_2DCHAR_RegisterBmpCharCell(p,i,a,b,c); else WIFI_2DCHAR_RegisterCharCell((u8 *)p,i,a,b,c); }
