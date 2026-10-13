/*
 * function: func_021B8834
 * address: 0x021B8834
 * packet: pkt_ov104_021B8834
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
u8 *func_021B8834(int a,u8 *p) { if(a==GFL_NET_SYSTEM_GetCurrentAid()) return p+0x8c; else return p+8; }
