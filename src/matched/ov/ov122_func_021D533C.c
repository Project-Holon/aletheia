/*
 * function: func_021D533C
 * address: 0x021D533C
 * packet: pkt_ov122_021D533C
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: Declaring i before sum gives the original register allocation.
 * trailing: Two alignment bytes, then existing ov122_func_021D5368.c.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int func_021D533C(u8 *p) { int i; int sum; sum=0; for(i=0;i<16;i++) if(*(u16 *)(p+i*12+108)) sum+=*(u16 *)(p+i*12+110); return sum; }
