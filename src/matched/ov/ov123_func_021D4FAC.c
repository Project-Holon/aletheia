/*
 * function: GSYNC_MENU_PrintMessageNoStream
 * address: 0x021D4FAC
 * packet: pkt_ov123_021D4FAC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MENU_PrintMessage 0x021D4EF0 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GSYNC_MENU_PrintMessage(char *,int,int);
void GSYNC_MENU_PrintMessageNoStream(char *p) { GSYNC_MENU_PrintMessage(p,4,1); }
