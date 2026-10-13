/*
 * function: NHTTP_RAP_GetRecvBuffer
 * address: 0x021B97F4
 * packet: pkt_ov114_021B97F4
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
u8 *NHTTP_RAP_GetRecvBuffer(u8 *p) { if(p==0) return 0; return p+0x10; }
