/*
 * unit: no
 * function: GURU2_MAIN_PrintPlayerName
 * address: 0x021E0450
 * packet: pkt_ov137_021E0450
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_MAIN_PrintNameWindow 0x021E03D8 thumb ov137
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GURU2_MAIN_PrintNameWindow(u8 *,void *,int,int);
void GURU2_MAIN_PrintPlayerName(u8 *p,void *text,int index,int a){int c=0x440;if(a==GFL_NET_SYSTEM_GetCurrentAid())c=0xc80;GURU2_MAIN_PrintNameWindow(p,text,index,c);}
