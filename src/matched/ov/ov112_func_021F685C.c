/*
 * function: MUSICAL_MCSS_AllocSmall
 * address: 0x021F685C
 * packet: pkt_ov112_021F685C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F83E4 0x021F83E4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16);extern const char d_021F83E4[];
void *MUSICAL_MCSS_AllocSmall(u32 heap) {u32 *p;int z;z=0;p=func_02030734(heap,48,0,d_021F83E4,194);p[1]=z;p[2]=z;p[3]=z;p[4]=z;p[5]=z;p[6]=z;p[7]=z;return p;}
