/*
 * function: STA_ACT_LIGHT_ElemOpA
 * address: 0x021F8044
 * packet: pkt_ov112_021F8044
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow code.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void STA_ACT_LIGHT_ElemOpA(void *unused,u32 *p,u32 *q) { q[0]=p[6]; q[1]=p[7]; q[2]=p[8]; }
