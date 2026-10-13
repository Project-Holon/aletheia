/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ExchangeGetBuffer
 * address: 0x021B8BFC
 * packet: pkt_ov103_021B8BFC
 * region: ov103
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
u8 *IRC_COMPATIBLE_TOUCH_TEST_ExchangeGetBuffer(u32 a,u8 *p) { if(a == GFL_NET_SYSTEM_GetCurrentAid()) p += 0xe0; else p += 8; return p; }
