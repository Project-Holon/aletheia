/*
 * function: STA_ACT_LIGHT_ElemOpB
 * address: 0x021F8054
 * packet: pkt_ov112_021F8054
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
void STA_ACT_LIGHT_ElemOpB(void *unused,u32 *p,const u32 *q) { p[6]=q[0]; p[7]=q[1]; p[8]=q[2]; p[1]=1; }
