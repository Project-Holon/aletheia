/*
 * function: STA_ACT_LIGHT_SetActorOffset
 * address: 0x021F8084
 * packet: pkt_ov112_021F8084
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void STA_ACT_LIGHT_SetActorOffset(void *unused,u32 *p,const u32 *q) { p[12]=q[0]; p[13]=q[1]; p[14]=q[2]; if(p[4]==1) p[13]=0; p[1]=1; }
