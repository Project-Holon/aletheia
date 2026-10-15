/*
 * function: LIVEBATTLEMATCH_IRC_EndSession
 * address: 0x0217E1C0
 * packet: pkt_ov176_0217E1C0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);
int LIVEBATTLEMATCH_IRC_EndSession(int *p) {switch(*p) {case 0:GFL_NET_COMMAND_DeleteCommandTable(0x1f00);GFL_NET_Exit(0);*p=1;break;case 1:if(GFL_NET_IsSessionNull())*p=2;break;case 2:return 1;}return 0;}
