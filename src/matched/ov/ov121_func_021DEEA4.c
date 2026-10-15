/*
 * function: MYSTERY_NET_SetHandler
 * address: 0x021DEEA4
 * packet: pkt_ov121_021DEEA4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void MYSTERY_NET_SetHandler(u32 *p,void *f) {p[0]=(u32)f;p[2]=0;}
