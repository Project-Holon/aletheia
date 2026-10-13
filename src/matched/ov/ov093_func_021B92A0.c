/*
 * function: BTL_MAIN_SetKeepBgm
 * address: 0x021B92A0
 * packet: pkt_ov093_021B92A0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void BTL_MAIN_SetKeepBgm(u8 *p) { p[0x473]|=32; }
