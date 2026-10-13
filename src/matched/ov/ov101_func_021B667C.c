/*
 * function: COMPATIBLE_IRC_SYS_RecvValueHandler
 * address: 0x021B667C
 * packet: pkt_ov101_021B667C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned int   u32;
extern u32 GFL_NET_IsParentAid(void);
extern void MI_CpuCopy8(void *,const void *,unsigned);
void COMPATIBLE_IRC_SYS_RecvValueHandler(unsigned a,int b,void *c,unsigned char *d) { unsigned v; if(GFL_NET_IsParentAid()) { MI_CpuCopy8(c,&v,4); *(unsigned *)(d+0x68+a*4)=v; } }
