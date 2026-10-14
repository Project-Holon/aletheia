/*
 * function: func_0217E158
 * address: 0x0217E158
 * packet: pkt_ov176_0217E158
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   IRCNET_SetFilter 0x021799C0 thumb ov015
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void IRCNET_SetFilter(int);
void func_0217E158(u32 *p) {int n;if(*p>=2)GFL_NET_COMMAND_DeleteCommandTable(0x1f00);n=0;IRCNET_SetFilter(0);*p=n;}
